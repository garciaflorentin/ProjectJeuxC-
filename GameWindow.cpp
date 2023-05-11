#include "GameWindow.hpp"

// Constructor
GameWindow::GameWindow(void) {

    std::cout << "debut GameWindow Constructeur" << std::endl;
    _view = new sf::View();
    _event = new sf::Event();
    _currentWindowPos = new std::vector<sf::Vector2i>();
    // Window size : (16* 64) * ((10 * 64) + 64) = 1024 * 704
    _window = nullptr; // initialisation � nullptr par mesure de securit�
    _window = new sf::RenderWindow(sf::VideoMode(static_cast<int>(windowWidth), static_cast<int>(windowHeight)), "Game"); // creation de la fenetre
    _window->setPosition(sf::Vector2i(100, 100));
    std::cout << "window create " << this << std::endl;
    _game = new GameGestion();
    Heart* test = new Heart();

    _lifeWindow = new LifeWindow((*_game->getPlayerVector())[0]->getlife());
    std::cout << "fin GameWindow Constructeur" << std::endl;    
    
}



// Destructor
GameWindow::~GameWindow(void) {
    delete[] _window;
    delete[] _game;
    delete[] _event;
    delete[] _view;
    delete[] _currentWindowPos;
    delete[] _lifeWindow;
    delete[] _test;
    std::cout << "window delete " << this << std::endl;
}

// view

void GameWindow::setScrollingView() {

   _view->reset(sf::FloatRect(0,0,getWindowDim().x,getWindowDim().y)); // coordoné du coin haut gauche et du coin bas droit
   _positionCentre = { getWindowDim().x / 2, getWindowDim().y / 2 };// coordoné du centre de l'ecran
   _positionCentre.x= (*_game->getPlayerVector())[0]->getPosition().x + ((*_game->getPlayerVector())[0]->getBlockSize()/2) - (getWindowDim().x / 2);// si le perso passe la moitié de l'ecran selon x je change la position du centre 
   _positionCentre.y = (*_game->getPlayerVector())[0]->getPosition().y + ((*_game->getPlayerVector())[0]->getBlockSize() / 2) - (getWindowDim().y / 2);// si le perso passe la moitié de l'ecran selon y je change la position du centre 
   //on ne peut pas filmer en dehors de la map  
   if (_positionCentre.x < 0) {
       _positionCentre.x = 0;
   }
   else if (_positionCentre.y < 0) {
       _positionCentre.y = 0;
   }
   else if (_positionCentre.x > 10000)// 10000 au pif pour le moment
       _positionCentre.x = 10000;
   else if (_positionCentre.y > 10000)
       _positionCentre.y = 10000;

   // on met a jour la vu en changeant la position du coin haut gauche
   _view->reset(sf::FloatRect(_positionCentre.x, _positionCentre.y, getWindowDim().x, getWindowDim().y));
   
   // on applique la view a la window
   _window->setView(*_view);

}

// gestion clavier et souris 

void GameWindow::pollEvent() {
    if (this->_window->pollEvent(*_event)) { //permet de v�rifier s'il y a un �v�nement en attente dans la file d'attente des �v�nements, si c'st le cas event stock l'evenement
        if (_event->type == sf::Event::Closed) { // event=fermeture de la fenetre ?
            _window->close();
        }
        else if(_event->type == sf::Event::KeyPressed){// regarde si une touche du clavier à été pressé
            //std::cout << " key " << std::endl;
            _game->keyEvent(*_event);// fait appel à la fonction move des sprites
            (*_game->getPlayerVector())[0]->updateSprite();
            //_game->getPlayerVector()[1]->updateSprite();
        }

    }    
}

void GameWindow::drawSprite(sf::Sprite sprite) {
    this->_window->draw(sprite);
}

void GameWindow::drawText(sf::Text text) {
    this->_window->draw(text);
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
    return _window->isOpen();
}

void GameWindow::limitFrameRate(int frame) { //limite le nombre de FPS
    this->_window->setFramerateLimit(frame);
}

void GameWindow::updateWindow(std::vector<sf::Sprite> _sprites) { // met a jour la fentre en utilisation des methodes priv�s
    this->_window->clear();
    this->drawVectorSprite(_sprites);//this->drawVectorSprite(this->_game.getDrawingSprite());
   // this->drawVectorText(_texts);//this->_game.getDrawingText())
    this->_window->display();
}

inline void GameWindow::DisplayTile(std::vector<sf::Sprite> v) {
    drawVectorSprite(v);
    _window->display();
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
        _window->draw(*_game->getSpriteVector()[i]);
}


void GameWindow::display() {

    std::cout<<"debut GameWindow::display() "<<std::endl;


    setLifeView();
    displayLifeWindow();
    std::cout<<"etape1"<<std::endl;

    setScrollingView();
    std::cout<<"etape2"<<std::endl;
    draw();// dessine tout les sprites contenut dans la fenetre courante
    std::cout<<"etape3"<<std::endl;


    _window->display();
    clearWindow();

    std::cout<<"fin GameWindow::display() "<<std::endl;
}

