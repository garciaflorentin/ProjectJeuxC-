#include "UserInterface.hpp"

UserInterface::UserInterface(){
	
	UiTexture = new sf::RenderTexture();
	UiTexture->create(windowWidth, windowHeight);
    UiSprite=new sf::Sprite(UiTexture->getTexture());
	UiView = new sf::View(sf::FloatRect(0.f, 0.f, windowWidth, windowHeight));
	UiView->setViewport(sf::FloatRect(0.f, 0.f, 1, 1));
	UiTexture->setView(*UiView);
		
}

UserInterface::~UserInterface(){
    delete UiView;
	delete UiTexture;
	delete UiSprite;
}


void UserInterface::setStartScreen() {
    // Création de l'image de fond
    sf::Texture startBackgroundTexture;
    if (!startBackgroundTexture.loadFromFile("start_background.png")) {
        // Gestion de l'erreur si l'image de fond ne peut pas être chargée
        // ...
    }
    sf::Sprite startBackgroundSprite(startBackgroundTexture);

    // Création du bouton "Start"
    sf::Texture startButtonTexture;
    if (!startButtonTexture.loadFromFile("start_button.png")) {
        // Gestion de l'erreur si l'image du bouton "Start" ne peut pas être chargée
        // ...
    }
    sf::Sprite startButtonSprite(startButtonTexture);
    startButtonSprite.setPosition(windowWidth / 2.f - startButtonTexture.getSize().x / 2.f, windowHeight / 2.f - startButtonTexture.getSize().y / 2.f);

    // Dessin de l'image de fond et du bouton "Start" sur la texture de rendu
    UiTexture->clear();
    UiTexture->draw(startBackgroundSprite);
    UiTexture->draw(startButtonSprite);
    UiTexture->display();

    // Affichage de la texture de rendu sur la fenêtre principale
    sf::Sprite uiSprite(UiTexture->getTexture());
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Start Screen");
    window.setView(*UiView);
    window.draw(uiSprite);
    window.display();

    // Attente du clic sur le bouton "Start"
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (startButtonSprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                        // Affichage de l'écran de chargement
                        sf::Texture loadingTexture;
                        if (!loadingTexture.loadFromFile("loading_screen.png")) {
                            // Gestion de l'erreur si l'image de l'écran de chargement ne peut pas être chargée
                            // ...
                        }
                        sf::Sprite loadingSprite(loadingTexture);
                        window.clear();
                        window.draw(loadingSprite);
                        window.display();

                        // Attente de 30 secondes
                        sf::sleep(sf::seconds(30));

                        // Fermeture de la fenêtre
                        window.close();
                    }
                }
            }
        }
    }
}

void UserInterface::drawTo(sf::RenderWindow* target) {
	
	target->draw(*UiSprite);


}