#include "GameWindow.hpp"

// Constructor
GameWindow::GameWindow(void) {
    // Window size : (16* 64) * ((10 * 64) + 64) = 1024 * 704
    window = nullptr; // initialisation � nullptr par mesure de securit�
    window = new sf::RenderWindow(sf::VideoMode(windoWwidth, windowHeight), "Game"); // creation de la fenetre
    window->setPosition(sf::Vector2i(100, 100));
    std::cout << "window create " << this << std::endl;
    _game = new GameGestion();
    std::cout << "GameWindow Constructeur" << std::endl;
}



// Destructor
GameWindow::~GameWindow(void) {
    delete[] window;
    delete[] _game;
    std::cout << "window delete " << this << std::endl;
}

// gestion clavier et souris 

void GameWindow::pollEvent() {
    if (this->window->pollEvent(this->event)) { //permet de v�rifier s'il y a un �v�nement en attente dans la file d'attente des �v�nements, si c'st le cas event stock l'evenement
        if (this->event.type == sf::Event::Closed) { // event=fermeture de la fenetre ?
            this->window->close();
        }
        else if(this->event.type == sf::Event::KeyPressed){// regarde si une touche du clavier à été pressé
            std::cout << " key " << std::endl;
            _game->keyEvent(this->event);// fait appel à la fonction move

            if (_game->getAnimVector().x * _game->getPlayerSize() >= _game->getPlayerSize() * 3) { _game->getAnimVector().x = 0; }
            _game->getPlayerSprite()->setTextureRect(sf::IntRect(_game->getAnimVector().x * _game->getPlayerSize()+3, _game->getAnimVector().y * _game->getPlayerSize()+3, 48, 48));

        }

    }
    
}

void GameWindow::drawSprite(sf::Sprite sprite) {
    this->window->draw(sprite);
}

void GameWindow::drawText(sf::Text text) {
    this->window->draw(text);
}

void GameWindow::drawVectorSprite(std::vector <sf::Sprite> vector) {
    for (int number = 0; number < vector.size(); number++) {
        drawSprite(vector[number]);
    }
}

void GameWindow::drawVectorText(std::vector <sf::Text> vector) {
    for (int number = 0; number < vector.size(); number++) {
        drawText(vector[number]);
    }
}

bool GameWindow::isRunning(void) { // check si la fenetre est ouverte
    return window->isOpen();
}

void GameWindow::limitFrameRate(int frame) { //limite le nombre de FPS
    this->window->setFramerateLimit(frame);
}

void GameWindow::updateWindow(std::vector<sf::Sprite> _sprites) { // met a jour la fentre en utilisation des methodes priv�s
    this->window->clear();
    this->drawVectorSprite(_sprites);//this->drawVectorSprite(this->_game.getDrawingSprite());
   // this->drawVectorText(_texts);//this->_game.getDrawingText())
    this->window->display();
}

inline void GameWindow::DisplayTile(std::vector<sf::Sprite> v) {
    drawVectorSprite(v);
    window->display();
}

/*void GameWindow::verificationWindow(void) { // regarde dans quel etat doit se trouver la fenetre
    this->Game.executionGame();
    if (!this->Game.playerIsAlive()) {
        this->window->close();
    }
}*/

void GameWindow::controlWindow(void) {
    this->pollEvent();
}

GameGestion* GameWindow::getGame() {
    return _game;
}

void GameWindow::draw() {
    for (int i = 0; i < _game->getSpriteVector().size(); i++)
        window->draw(*_game->getSpriteVector()[i]);
}