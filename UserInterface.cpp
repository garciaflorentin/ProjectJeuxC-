#include "UserInterface.hpp"


UserInterface::UserInterface() : 
_UiTexture(TexturesLib::assignTexture("GUITextures/GUI.png")), _UiTexture1(TexturesLib::assignTexture("GUITextures/Uistart.png")), 
_UiTexture2(TexturesLib::assignTexture("GUITextures/UiPause.png")), _Background(*(new sf::Sprite(_UiTexture1))),
_button1(*(new sf::Sprite(_UiTexture))), _button2(*(new sf::Sprite(_UiTexture))), _button3(*(new sf::Sprite(_UiTexture))), _cadre(*(new sf::Sprite(_UiTexture))) {
    _event = sf::Event();

    _window = new sf::RenderWindow(sf::VideoMode(static_cast<int>(_windowWidth), static_cast<int>(_windowHeight)), "Tales of the Monster Hunter"); 
	_window->setPosition(sf::Vector2i(100, 100));

    _Background.setTexture(_UiTexture1);

    _button2.scale(10,8);

    // _button1.setTexture(_UiTexture);
    // _button2.setTexture(_UiTexture);
    // _button3.setTexture(_UiTexture);
    // _cadre.setTexture(_UiTexture);

	_UiView = sf::View(sf::FloatRect(0.f, 0.f, _windowWidth, _windowHeight));
	_UiView.setViewport(sf::FloatRect(0.f, 0.f, 1, 1));
    _isPaused=true;
    _isLaunched=false;
    _isDead=false;
    _win=false;

    _police = sf::Font();
    if (!_police.loadFromFile("Fonts/antiquity-print.ttf")) 
		throw runtime_error("Unable to load antiquity-print.ttf file");

    _StartMusic = SoundsLib::assignSound("Sounds/StartingMusic.wav");
}


UserInterface& UserInterface::operator=(const UserInterface& other) {
    _UiView = other._UiView;

    _window = other._window;

    _event = other._event;
    _videoMode = other._videoMode;
    _UiTexture = other._UiTexture;
    _UiTexture1 = other._UiTexture1;
    _UiTexture2 = other._UiTexture2;
    _police = other._police;

    _StartMusic = SoundsLib::assignSound("Sounds/StartingMusic.wav");

    _Background = other._Background;
    _button1 = other._button1;
    _button2 = other._button2;
    _button3 = other._button3;
    _cadre = other._cadre;

    _isPaused = other._isPaused; 
    _isLaunched = other._isLaunched; 
    _isDead = other._isDead; 
    _win = other._win;

    return *this;
}


UserInterface::~UserInterface(){
    delete[] _window;
}


void UserInterface::runPausedWindow(){
    sf::Text text;
    text.setFont(_police);
    text.setCharacterSize(32);

    bool finish=false;
    sf::Vector2u windowSize = _window->getSize();

    _button1.setTextureRect(sf::IntRect(112,80,32,16));

    sf::Vector2f TextSize = {text.getGlobalBounds().width,text.getGlobalBounds().height};
    sf::Vector2f buttonSize = {_button1.getGlobalBounds().width, _button1.getGlobalBounds().height};

    float spritePosX = (windowSize.x - buttonSize.x) / 2;
    float spritePosY = (windowSize.y - buttonSize.y) / 2;

    _button1.setPosition(spritePosX,spritePosY-150);

    sf::Vector2f sprite2Position;
    sprite2Position.x = spritePosX + (buttonSize.x - TextSize.x) / 2;
    sprite2Position.y = spritePosY + (buttonSize.y - TextSize.y) / 2;
    text.setFillColor(sf::Color::White);
    text.setString("Press Space");

    while(_window->isOpen()){
        _button1.setTextureRect(sf::IntRect(112,80,32,16));  
        text.setPosition(sprite2Position.x-120, sprite2Position.y-165);

        while(_window->pollEvent(_event)){
            if (_event.type == sf::Event::KeyPressed) {
                _button1.setTextureRect(sf::IntRect(112,96,32,16));
                text.setFillColor(sf::Color::White);

                if((_event.key.code == sf::Keyboard::Space)) {
                    _button1.setTextureRect(sf::IntRect(112,96,32,16));
                    text.setFillColor(sf::Color::Green);

                    finish=true;   
                }
            } 
        }

        _Background.setTexture(_UiTexture2);

        _window->clear(sf::Color::Green);
        _window->draw(_Background);
        _window->draw(_button1);
        _window->draw(text);
        _window->display();

        sf::sleep(sf::seconds(0.05));
        if(finish==true)    return;
    }
}


void UserInterface::runLaunchedWindow() {
    sf::Vector2u windowSize = _window->getSize();

    sf::Text text;
    sf::Text titre;
    titre.setFont(_police);
    titre.setCharacterSize(32);
    titre.setFillColor(sf::Color::Black);
    titre.setString("Tales of the Monster Hunter");

    text.setFont(_police);
    text.setCharacterSize(32);

    _button1.setTextureRect(sf::IntRect(112,80,32,16));
    _button1.scale(10,8);

    sf::Vector2f TextSize = {text.getGlobalBounds().width,text.getGlobalBounds().height};
    sf::Vector2f TitreSize = {titre.getGlobalBounds().width,titre.getGlobalBounds().height};
    sf::Vector2f buttonSize = {_button1.getGlobalBounds().width, _button1.getGlobalBounds().height};

    float spritePosX = (windowSize.x - buttonSize.x) / 2;
    float spritePosY = (windowSize.y - buttonSize.y) / 2;

    sf::Vector2f titrePos;
    titrePos.x= (windowSize.x - TitreSize.x) / 2;
    titrePos.y= (windowSize.y - TitreSize.y) / 2;

    _button1.setPosition(spritePosX,spritePosY-150);
    titre.setPosition({titrePos.x,titrePos.y-250});
    sf::Vector2f sprite2Position;
    sprite2Position.x = spritePosX + (buttonSize.x - TextSize.x) / 2;
    sprite2Position.y = spritePosY + (buttonSize.y - TextSize.y) / 2;

    text.setFillColor(sf::Color::White);
    text.setString("Start");

    while(_window->isOpen()){
        text.setPosition(sprite2Position.x-50,sprite2Position.y-165);

        while(_window->pollEvent(_event)){
            
            if (_button1.getGlobalBounds().contains(sf::Mouse::getPosition(*_window).x,sf::Mouse::getPosition(*_window).y)) {
                _button1.setTextureRect(sf::IntRect(112,96,32,16));
                
                text.setFillColor(sf::Color::Magenta);

                if (_event.mouseButton.button == sf::Mouse::Left) {
                    _StartMusic->stop();
                    return;
                }
            } else {
                _button1.setTextureRect(sf::IntRect(112,80,32,16));  
                text.setFillColor(sf::Color::White);
                }
        }

        _window->clear();
        _window->draw(_Background);
        _window->draw(_button1);
        _window->draw(text);
        _window->draw(titre);
        _window->display();
    }
}


void UserInterface::runVictoryWindow(){
    sf::Vector2u windowSize = _window->getSize();
    sf::Text titre;

    titre.setFont(_police);
    titre.setCharacterSize(64);
    titre.setFillColor(sf::Color::White);
    titre.setString("You Win!");

    sf::Texture texture = TexturesLib::assignTexture("GUITextures/uiVictoire.png");
    _Background.setTexture(texture);

    sf::Vector2f TitreSize = {titre.getGlobalBounds().width,titre.getGlobalBounds().height};
    sf::Vector2f buttonSize = {_button1.getGlobalBounds().width, _button1.getGlobalBounds().height};

    float spritePosX = (windowSize.x - buttonSize.x) / 2;
    float spritePosY = (windowSize.y - buttonSize.y) / 2;

    sf::Vector2f titrePos;
    titrePos.x= (windowSize.x - TitreSize.x) / 2;
    titrePos.y= (windowSize.y - TitreSize.y) / 2;

    _button1.setPosition(spritePosX,spritePosY-150);
    titre.setPosition({titrePos.x,titrePos.y-250});

    sf::Vector2f sprite2Position;

    while(_window->isOpen()){
        while(_window->pollEvent(_event)){
            if (_event.type == sf::Event::Closed) 
                _window->close();
                
        _window->clear();
        _window->draw(_Background);
        _window->draw(titre);
        _window->display();
        }
    }
}


void UserInterface::runDeathWindow() {
    sf::Vector2u windowSize = _window->getSize();

    sf::Text titre;
    titre.setFont(_police);
    titre.setCharacterSize(64);
    titre.setFillColor(sf::Color::White);
    titre.setString("Game Over");

    sf::Texture texture = TexturesLib::assignTexture("GUITextures/uiDefaite.png");
    _Background.setTexture(texture);
    

    sf::Vector2f TitreSize = {titre.getGlobalBounds().width,titre.getGlobalBounds().height};
    sf::Vector2f buttonSize = {_button1.getGlobalBounds().width, _button1.getGlobalBounds().height};

    float spritePosX = (windowSize.x - buttonSize.x) / 2;
    float spritePosY = (windowSize.y - buttonSize.y) / 2;

    sf::Vector2f titrePos;
    titrePos.x= (windowSize.x - TitreSize.x) / 2;
    titrePos.y= (windowSize.y - TitreSize.y) / 2;

    _button1.setPosition(spritePosX,spritePosY-150);
    titre.setPosition({titrePos.x,titrePos.y-250});

    sf::Vector2f sprite2Position;

    while(_window->isOpen()){
        while(_window->pollEvent(_event)){
            if (_event.type == sf::Event::Closed) 
                _window->close();
            
        _window->clear();
        _window->draw(_Background);
        _window->draw(titre);
        _window->display();
        }
    }
}


void UserInterface::fade(sf::Music& music){
    music.setLoop(true);  // Désactiver la lecture en boucle automatique
    music.setVolume(100);  // Définir le volume initial de la musique

    sf::Time fadeDuration = sf::seconds(2.0f);  // Durée du fondu en secondes
    sf::Time fadeDelay = sf::seconds(0.1f);     // Délai entre chaque étape du fondu

    if (music.getStatus() == sf::SoundSource::Playing){
        // Vérifier si la musique est en train de se terminer
        if (music.getPlayingOffset() + fadeDuration >= music.getDuration()) {
            // Calculer le volume en fonction du temps restant avant la fin
            float fadeFactor = 1.0f - ((music.getDuration() - music.getPlayingOffset()) / fadeDuration);
            music.setVolume(100 * fadeFactor);
        }

        sf::sleep(fadeDelay);
    } else {
        music.stop();
        music.play();
    }
}