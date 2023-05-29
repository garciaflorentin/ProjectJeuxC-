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
    _isDead=false;
    _win=false;

    police=new sf::Font();
    if (!police->loadFromFile("antiquity-print.ttf")) {
			std::cout<<"probleme dans la creation de la police d'ecriture de l'interface"<<std::endl;
    }

     if (!StartMusic.openFromFile("StartingMusic.wav"))
    {
        std::cout<<"erreur de chargement de StartingMusic"<<std::endl;
    }


		
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
    delete police;
}


void UserInterface::runPausedWindow(){

    sf::Text text;
        text.setFont(*police);
        text.setCharacterSize(32);

    bool finish=false;
    sf::Vector2u windowSize = window->getSize();
        button1->setTextureRect(sf::IntRect(112,80,32,16));

        sf::Vector2f TextSize = {text.getGlobalBounds().width,text.getGlobalBounds().height};
        sf::Vector2f buttonSize = {button1->getGlobalBounds().width,button1->getGlobalBounds().height};
        float spritePosX = (windowSize.x - buttonSize.x) / 2;
        float spritePosY = (windowSize.y - buttonSize.y) / 2;
        button1->setPosition(spritePosX,spritePosY-150);
        sf::Vector2f sprite2Position;
        sprite2Position.x = spritePosX + (buttonSize.x - TextSize.x) / 2;
        sprite2Position.y = spritePosY + (buttonSize.y - TextSize.y) / 2;
        text.setFillColor(sf::Color::White);
        text.setString("Press Space");

		while(window->isOpen()){
            button1->setTextureRect(sf::IntRect(112,80,32,16));  
            text.setPosition(sprite2Position.x-120, sprite2Position.y-165);

			while(window->pollEvent(*event)){
                    
				if (event->type == sf::Event::KeyPressed) {
                    button1->setTextureRect(sf::IntRect(112,96,32,16));
                    text.setFillColor(sf::Color::White);

                    if((event->key.code == sf::Keyboard::Space)) {
                         button1->setTextureRect(sf::IntRect(112,96,32,16));
                        text.setFillColor(sf::Color::Green);

                         finish=true;
                         
                    }
                 } 
			}
            Background->setTexture(*UiTexture2);

			window->clear(sf::Color::Green);
            window->draw(*Background);
            window->draw(*button1);
             window->draw(text);
			window->display();
            sf::sleep(sf::seconds(0.05));
            if(finish==true){return;}
		}
	}
    void UserInterface::runLaunchedWindow(){
        sf::Vector2u windowSize = window->getSize();
        sf::Text text;
        sf::Text titre;
        titre.setFont(*police);
        titre.setCharacterSize(32);
        titre.setFillColor(sf::Color::Black);
        titre.setString("Tales of the Monster Hunter");

        text.setFont(*police);
        text.setCharacterSize(32);

        button1->setTextureRect(sf::IntRect(112,80,32,16));
        button1->scale(10,8);

        sf::Vector2f TextSize = {text.getGlobalBounds().width,text.getGlobalBounds().height};
        sf::Vector2f TitreSize = {titre.getGlobalBounds().width,titre.getGlobalBounds().height};
        sf::Vector2f buttonSize = {button1->getGlobalBounds().width,button1->getGlobalBounds().height};
        float spritePosX = (windowSize.x - buttonSize.x) / 2;
        float spritePosY = (windowSize.y - buttonSize.y) / 2;
        sf::Vector2f titrePos;
        titrePos.x= (windowSize.x - TitreSize.x) / 2;
        titrePos.y= (windowSize.y - TitreSize.y) / 2;
        button1->setPosition(spritePosX,spritePosY-150);
        titre.setPosition({titrePos.x,titrePos.y-250});
        sf::Vector2f sprite2Position;
        sprite2Position.x = spritePosX + (buttonSize.x - TextSize.x) / 2;
        sprite2Position.y = spritePosY + (buttonSize.y - TextSize.y) / 2;
        text.setFillColor(sf::Color::White);
        text.setString("Start");
		while(window->isOpen()){
        text.setPosition(sprite2Position.x-50,sprite2Position.y-165);
        fade(StartMusic);

			while(window->pollEvent(*event)){
                
				if (button1->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y)) {
                    button1->setTextureRect(sf::IntRect(112,96,32,16));
                    
                        text.setFillColor(sf::Color::Magenta);
                    if (event->mouseButton.button == sf::Mouse::Left) {
                        StartMusic.stop();
                        return;
                    }
                 } else {
                     button1->setTextureRect(sf::IntRect(112,80,32,16));  
                        text.setFillColor(sf::Color::White);
                      }
			}

			window->clear();
            window->draw(*Background);
            window->draw(*button1);
            window->draw(text);
                window->draw(titre);




			window->display();
		}
	}

     void UserInterface::runVictoryWindow(){
        sf::Vector2u windowSize = window->getSize();
        sf::Text titre;
        titre.setFont(*police);
        titre.setCharacterSize(64);
        titre.setFillColor(sf::Color::White);
        titre.setString("You Win!");

       sf::Texture texture;
       if (!(texture.loadFromFile("uiVictoire.png"))){
			std::cout<<"probleme dans la creation de l'interface"<<std::endl;
		}
        Background->setTexture(texture);


        sf::Vector2f TitreSize = {titre.getGlobalBounds().width,titre.getGlobalBounds().height};
        sf::Vector2f buttonSize = {button1->getGlobalBounds().width,button1->getGlobalBounds().height};
        float spritePosX = (windowSize.x - buttonSize.x) / 2;
        float spritePosY = (windowSize.y - buttonSize.y) / 2;
        sf::Vector2f titrePos;
        titrePos.x= (windowSize.x - TitreSize.x) / 2;
        titrePos.y= (windowSize.y - TitreSize.y) / 2;
        button1->setPosition(spritePosX,spritePosY-150);
        titre.setPosition({titrePos.x,titrePos.y-250});
        sf::Vector2f sprite2Position;
		while(window->isOpen()){

			while(window->pollEvent(*event)){
                 if (event->type == sf::Event::Closed) {
            window->close();
                 }
				

			window->clear();
            window->draw(*Background);
           //window->draw(*button1);
            window->draw(titre);

			window->display();
		}
	}}

     void UserInterface::runDeathWindow(){
        sf::Vector2u windowSize = window->getSize();
        sf::Text titre;
        titre.setFont(*police);
        titre.setCharacterSize(64);
        titre.setFillColor(sf::Color::White);
        titre.setString("Game Over");

       sf::Texture texture;
       if (!(texture.loadFromFile("uiDefaite.png"))){
			std::cout<<"probleme dans la creation de l'interface"<<std::endl;
		}
        Background->setTexture(texture);
       

        sf::Vector2f TitreSize = {titre.getGlobalBounds().width,titre.getGlobalBounds().height};
        sf::Vector2f buttonSize = {button1->getGlobalBounds().width,button1->getGlobalBounds().height};
        float spritePosX = (windowSize.x - buttonSize.x) / 2;
        float spritePosY = (windowSize.y - buttonSize.y) / 2;
        sf::Vector2f titrePos;
        titrePos.x= (windowSize.x - TitreSize.x) / 2;
        titrePos.y= (windowSize.y - TitreSize.y) / 2;
        button1->setPosition(spritePosX,spritePosY-150);
        titre.setPosition({titrePos.x,titrePos.y-250});
        sf::Vector2f sprite2Position;
		while(window->isOpen()){
			while(window->pollEvent(*event)){
                 if (event->type == sf::Event::Closed) {
            window->close();
                 }
				

			window->clear();
            window->draw(*Background);
            //window->draw(*button1);
            window->draw(titre);

			window->display();
		}
	}}

    void UserInterface::fade(sf::Music& music){
    music.setLoop(true);  // Désactiver la lecture en boucle automatique
    music.setVolume(100);  // Définir le volume initial de la musique
     sf::Time fadeDuration = sf::seconds(2.0f);  // Durée du fondu en secondes
    sf::Time fadeDelay = sf::seconds(0.1f);     // Délai entre chaque étape du fondu
    if (music.getStatus() == sf::SoundSource::Playing){

        // Vérifier si la musique est en train de se terminer
        if (music.getPlayingOffset() + fadeDuration >= music.getDuration())
        {
            // Calculer le volume en fonction du temps restant avant la fin
            float fadeFactor = 1.0f - ((music.getDuration() - music.getPlayingOffset()) / fadeDuration);
            music.setVolume(100 * fadeFactor);
        }

        sf::sleep(fadeDelay);
    }else{
    music.stop();
    music.play();
    }

    
}
