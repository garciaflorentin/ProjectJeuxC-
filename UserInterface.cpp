#include "UserInterface.hpp"

UserInterface::UserInterface(){
	
    event = new sf::Event();
    window = new sf::RenderWindow(sf::VideoMode(static_cast<int>(windowWidth), static_cast<int>(windowHeight)), "Tales of the Monster Hunter"); 
	window->setPosition(sf::Vector2i(100, 100));
    UiTexture1 = new sf::Texture();
    if (!(UiTexture1->loadFromFile("Uistart.png"))){
			std::cout<<"probleme dans la creation de l'interface"<<std::endl;
		}
    UiTexture2 = new sf::Texture();
    if (!(UiTexture2->loadFromFile("UiPause.png"))){
			std::cout<<"probleme dans la creation de l'interface"<<std::endl;
		}
    Background=new sf::Sprite();
    Background->setTexture(*UiTexture1);
     UiTexture = new sf::Texture();
    if (!(UiTexture->loadFromFile("GUI.png"))){
			std::cout<<"probleme dans la creation de l'interface"<<std::endl;
		}
    button1= new sf::Sprite();
    button2= new sf::Sprite();
    button2->scale(10,8);
    button3= new sf::Sprite();
    cadre = new sf::Sprite();

    button1->setTexture(*UiTexture);
    button2->setTexture(*UiTexture);
    button3->setTexture(*UiTexture);
    cadre->setTexture(*UiTexture);

	UiView = new sf::View(sf::FloatRect(0.f, 0.f, windowWidth, windowHeight));
	UiView->setViewport(sf::FloatRect(0.f, 0.f, 1, 1));
    _isPaused=true;
    _isLaunched=false;
		
}

UserInterface::~UserInterface(){
    delete UiView;
	delete UiTexture;
	delete Background;
    delete window;
    delete event;
    delete UiTexture1;
    delete button1;
    delete button2;
    delete button3;
    delete cadre;
    delete UiTexture2;
}


/*void UserInterface::setStartScreen() {
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
}*/



void UserInterface::runPausedWindow(){
    bool finish=false;
sf::Vector2u windowSize = window->getSize();
        button2->setTextureRect(sf::IntRect(64,142,32,16));
        button1->setTextureRect(sf::IntRect(112,80,32,16));

        sf::Vector2f TextSize = {button2->getGlobalBounds().width,button2->getGlobalBounds().height};
        sf::Vector2f buttonSize = {button1->getGlobalBounds().width,button1->getGlobalBounds().height};
        float spritePosX = (windowSize.x - buttonSize.x) / 2;
        float spritePosY = (windowSize.y - buttonSize.y) / 2;
        button1->setPosition(spritePosX,spritePosY-150);
        sf::Vector2f sprite2Position;
        sprite2Position.x = spritePosX + (buttonSize.x - TextSize.x) / 2;
        sprite2Position.y = spritePosY + (buttonSize.y - TextSize.y) / 2;
        button2->setPosition(sprite2Position.x,sprite2Position.y-165);

		while(window->isOpen()){
            button1->setTextureRect(sf::IntRect(112,80,32,16));  
            button2->setColor(sf::Color::White);
            std::cout<<"appuer sur space pour reprendre"<<std::endl;
			while(window->pollEvent(*event)){
                    
				if (event->type == sf::Event::KeyPressed) {
                    button1->setTextureRect(sf::IntRect(112,96,32,16));
                    button2->setColor(sf::Color::Green);
                    if((event->key.code == sf::Keyboard::Space)) {
                         button1->setTextureRect(sf::IntRect(112,96,32,16));
                         button2->setColor(sf::Color::Green);
                         finish=true;
                         
                    }
                 } 
			}
            Background->setTexture(*UiTexture2);

			window->clear(sf::Color::Green);
            window->draw(*Background);
            window->draw(*button1);
            window->draw(*button2);
			window->display();
            sf::sleep(sf::seconds(0.05));
            if(finish==true){return;}
		}
	}
    void UserInterface::runLaunchedWindow(){
        sf::Vector2u windowSize = window->getSize();
        cadre->setTextureRect(sf::IntRect(64,142,32,16));
        cadre->scale(10,8);
        button1->setTextureRect(sf::IntRect(112,80,32,16));
        button1->scale(10,8);

        sf::Vector2f TextSize = {cadre->getGlobalBounds().width,cadre->getGlobalBounds().height};
        sf::Vector2f buttonSize = {button1->getGlobalBounds().width,button1->getGlobalBounds().height};
        float spritePosX = (windowSize.x - buttonSize.x) / 2;
        float spritePosY = (windowSize.y - buttonSize.y) / 2;
        button1->setPosition(spritePosX,spritePosY-150);
        sf::Vector2f sprite2Position;
        sprite2Position.x = spritePosX + (buttonSize.x - TextSize.x) / 2;
        sprite2Position.y = spritePosY + (buttonSize.y - TextSize.y) / 2;
        cadre->setPosition(sprite2Position.x,sprite2Position.y-165);

		while(window->isOpen()){

			while(window->pollEvent(*event)){
				if (button1->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y)) {
                    button1->setTextureRect(sf::IntRect(112,96,32,16));
                    cadre->setColor(sf::Color::Magenta);
                    if (event->mouseButton.button == sf::Mouse::Left) {
                        return;
                    }
                 } else {
                     button1->setTextureRect(sf::IntRect(112,80,32,16));  
                      cadre->setColor(sf::Color::White);
                      }
			}

			window->clear();
            window->draw(*Background);
            window->draw(*button1);
            window->draw(*cadre);



			window->display();
		}
	}