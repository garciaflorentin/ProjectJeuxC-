﻿#include "GameWindow.hpp"

// Constructor
GameWindow::GameWindow(void) {
std::cout << "debut GameWindow Constructeur" << std::endl;
    _view = new sf::View();
    event = new sf::Event();
    currentWindowPos = new std::vector<sf::Vector2f>(2);

    sf::Vector2f v1={0,0};
    sf::Vector2f v2={1024,768};
    currentWindowPos->push_back(v1);
    currentWindowPos->push_back(v2);
    // Window size : (16* 64) * ((10 * 64) + 64) = 1024 * 704
    window = nullptr; // initialisation � nullptr par mesure de securit�
    window = new sf::RenderWindow(sf::VideoMode(static_cast<int>(windowWidth), static_cast<int>(windowHeight)), "Game"); // creation de la fenetre
    window->setPosition(sf::Vector2i(100, 100));
    std::cout << "window create " << this << std::endl;
    _game = new GameGestion();
    Heart* test = new Heart();
    _lifeWindow = new LifeWindow((*_game->getPlayerVector())[0]->getlife());
std::cout << "fin GameWindow Constructeur" << std::endl;    
}



// Destructor
GameWindow::~GameWindow(void) {
    delete window;
    delete _game;
    delete event;
    delete _view;
    delete currentWindowPos;
    delete _lifeWindow;
    delete test;
    std::cout << "window delete " << this << std::endl;
}

// view

void GameWindow::setScrollingView() {

    _view->reset(sf::FloatRect(0,0,getWindowDim().x,getWindowDim().y)); // coordoné du coin haut gauche et du coin bas droit
   positionCentre = { getWindowDim().x / 2, getWindowDim().y / 2 };// coordoné du centre de l'ecran
   positionCentre.x= (*_game->getPlayerVector())[0]->getPosition().x + ((*_game->getPlayerVector())[0]->getBlockSize()/2) - (getWindowDim().x / 2);// si le perso passe la moitié de l'ecran selon x je change la position du centre 
   positionCentre.y = (*_game->getPlayerVector())[0]->getPosition().y + ((*_game->getPlayerVector())[0]->getBlockSize() / 2) - (getWindowDim().y / 2);// si le perso passe la moitié de l'ecran selon y je change la position du centre 
  

   //on ne peut pas filmer en dehors de la map  
   if (positionCentre.x < 0) {
       positionCentre.x = 0;
   }
   else if (positionCentre.y < -14400) {
       positionCentre.y = -14400;
   }
   else if (positionCentre.x > 14400)
       positionCentre.x = 14400;
   else if (positionCentre.y > 14400)
       positionCentre.y = 14400;
       

   // on met a jour la vu en changeant la position du coin haut gauche
   _view->reset(sf::FloatRect(positionCentre.x, positionCentre.y, getWindowDim().x, getWindowDim().y));
   
   // on applique la view a la window
   window->setView(*_view);

}

// gestion clavier et souris 

void GameWindow::pollEvent() {

    if (this->window->pollEvent(*event)) { //permet de v�rifier s'il y a un �v�nement en attente dans la file d'attente des �v�nements, si c'st le cas event stock l'evenement
        if (event->type == sf::Event::Closed) { // event=fermeture de la fenetre ?
            window->close();
        }
        else if(event->type == sf::Event::KeyPressed){// regarde si une touche du clavier à été pressé
            //std::cout << " key " << std::endl;
            _game->keyEvent(*event);// fait appel à la fonction move des sprites
            (*_game->getPlayerVector())[0]->updateSprite();
            //_game->getPlayerVector()[1]->updateSprite();
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

    std::vector<Object*>* toDraw= _game->toDrawUpdate(getCurrentWindowPos());
    for (int i = 0; i < toDraw->size() ; i++){
       Object* o = (*toDraw)[i];
       window->draw(*o->getSprite());

    }

    for (int i = 0; i < 1/*(*_game->getPlayerVector()).size()*/; i++){
        window->draw(*(*_game->getPlayerVector())[i]->getSprite());
    }
   
}


void GameWindow::display() {
        


   setScrollingView();
   draw();// dessine tout les sprites contenut dans la fenetre courante
   setLifeView();
   displayLifeWindow();
   window->display();
   clearWindow();

}


    void GameWindow::setCurrentWindowPos(){

    currentWindowPos->clear();
    sf::Vector2f center = {static_cast<float>(_view->getCenter().x),static_cast<float>(_view->getCenter().y)}; // Récupérer la position centrale de la vue
    sf::Vector2f size = {static_cast<float>(_view->getSize().x),static_cast<float>(_view->getSize().y)}; // Récupérer la taille de la vue
    sf::Vector2f topLeft = {center.x - size.x/2,center.y- size.y/2}; // Calculer la position du coin haut gauche
    (*currentWindowPos)[0]= topLeft;
    sf::Vector2f bottomRight = {center.x + size.x/2,center.y+ size.y/2}; // Calculer la position du coin haut gauche
    (*currentWindowPos)[1]= bottomRight;

    }

