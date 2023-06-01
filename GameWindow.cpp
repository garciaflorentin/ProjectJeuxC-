#include "GameWindow.hpp"


GameWindow::GameWindow(void) : _game(*(new GameGestion())), _ui(*(new UserInterface())) {
    _view = sf::View();
    _event = sf::Event();
    _currentWindowPos = std::vector<sf::Vector2f>(2);

    sf::Vector2f v1={0,0};
    sf::Vector2f v2={1024,768};
    _currentWindowPos.push_back(v1);
    _currentWindowPos.push_back(v2);

    _window = nullptr;
    _window = new sf::RenderWindow(sf::VideoMode(static_cast<int>(_windowWidth), static_cast<int>(_windowHeight)), "Game"); // creation de la fenetre
    _window->setPosition(sf::Vector2i(100, 100));

    //_game = GameGestion();
    _lifeWindow = LifeWindow(_game.getPlayerVector()[0]->getlife());
    _lifeWindowP2 = LifeWindow(_game.getPlayerVector()[1]->getlife());
    //_ui = UserInterface();
    _keyWindow = KeyWindow(*_game.getPlayerVector()[0]);
}


GameWindow::~GameWindow(void) {
    delete[] _window;
}


void GameWindow::setScrollingView() {
    float viewX = getWindowDim().x - 300;
    float viewY = getWindowDim().y - 225;

    if (_game.getPlayerVector()[0]->isAlive()) {
        _view.reset(sf::FloatRect(0, 0, viewX, viewY));                                                                                         // coordoné du coin haut gauche et du coin bas droit
        _positionCentre = {getWindowDim().x / 2, getWindowDim().y / 2};                                                                           // coordoné du centre de l'ecran
        _positionCentre.x = _game.getPlayerVector()[0]->getPosition().x + _game.getPlayerVector()[0]->getBlockSize() / 2 - (viewX / 2); // si le perso passe la moitié de l'ecran selon x je change la position du centre
        _positionCentre.y = _game.getPlayerVector()[0]->getPosition().y + _game.getPlayerVector()[0]->getBlockSize() / 2 - (viewY / 2); // si le perso passe la moitié de l'ecran selon y je change la position du centre

        std::vector<float> limitMap;
        _game.getMap().getLimitMap(limitMap);

        // On ne peut pas filmer en dehors de la map
        if (_positionCentre.x < limitMap[2])
            _positionCentre.x = limitMap[2];
    
        else if (_positionCentre.x + 2 * (viewX / 2) > limitMap[0])
            _positionCentre.x = limitMap[0] - 2 * (viewX / 2);

        if (_positionCentre.y < limitMap[3])
            _positionCentre.y = limitMap[3];
        
        else if (_positionCentre.y + 2 * (viewY / 2) > limitMap[1])
            _positionCentre.y = limitMap[1] - 2 * (viewY / 2);
    }
    else if (_game.getPlayerVector()[1]->isAlive()) {
        _view.reset(sf::FloatRect(0, 0, viewX, viewY));                                                                                         // coordoné du coin haut gauche et du coin bas droit
        _positionCentre = {getWindowDim().x / 2, getWindowDim().y / 2};                                                                           // coordoné du centre de l'ecran
        _positionCentre.x = _game.getPlayerVector()[1]->getPosition().x + _game.getPlayerVector()[1]->getBlockSize() / 2 - (viewX / 2); // si le perso passe la moitié de l'ecran selon x je change la position du centre
        _positionCentre.y = _game.getPlayerVector()[1]->getPosition().y + _game.getPlayerVector()[1]->getBlockSize() / 2 - (viewY / 2); // si le perso passe la moitié de l'ecran selon y je change la position du centre
        
        std::vector<float> limitMap;
        _game.getMap().getLimitMap(limitMap);

        // On ne peut pas filmer en dehors de la map
        if (_positionCentre.x < limitMap[2])
            _positionCentre.x = limitMap[2];
        
        else if (_positionCentre.x + 2 * (viewX / 2) > limitMap[0])

            _positionCentre.x = limitMap[0] - 2 * (viewX / 2);    

        if (_positionCentre.y < limitMap[3])
            _positionCentre.y = limitMap[3];
        
        else if (_positionCentre.y + 2 * (viewY / 2) > limitMap[1])
            _positionCentre.y = limitMap[1] - 2 * (viewY / 2);
    }

    // on met a jour la vu en changeant la position du coin haut gauche
    _view.reset(sf::FloatRect(_positionCentre.x, _positionCentre.y, viewX, viewY));
   
    _window->setView(_view);
}

void GameWindow::setViewBoss(){
    float viewX=getWindowDim().x;
    float viewY=getWindowDim().y;

   // on met a jour la vu en changeant la position du coin haut gauche
   _view.reset(sf::FloatRect(9472,9600, viewX, viewY));
   
   // on applique la view a la window
   _window->setView(_view);
}


void GameWindow::pollEvent() {
    if(!_ui.isLaunched() || _ui.isPaused()  || _ui.isDead() || _ui.getWin()){
        if(!_ui.isLaunched()){
            _window->setActive(false); // Désactiver la fenêtre principale
            _window->setVisible(false);
            _ui.getWindow().setVisible(true);
            _ui.getWindow().setActive(true);
            _ui.getWindow().setVisible(true);  
            _ui.runLaunchedWindow();
            _ui.setIsLaunched(true);
            _ui.setIsPaused(false);
            _ui.getWindow().setVisible(false);
            _ui.getWindow().setActive(false);
            _window->setVisible(true);
            _window->setActive(true); //activer la fenêtre principale
        } else if (_ui.isPaused()) {
            _window->setActive(false); // Désactiver la fenêtre principale
            _window->setVisible(false);
            _ui.getWindow().setActive(true);
            _ui.getWindow().setVisible(true);
            _ui.runPausedWindow();
            _ui.setIsPaused(false);
            _ui.getWindow().setVisible(false);
            _ui.getWindow().setActive(false);
            _window->setVisible(true);
            _window->setActive(true); // activer la fenêtre principale
        } else if (_ui.isDead()) {
            _window->setActive(false); // Désactiver la fenêtre principale
            _window->setVisible(false);
            _ui.getWindow().setVisible(true);
            _ui.getWindow().setActive(true);
            _ui.getWindow().setVisible(true);  
            _ui.runDeathWindow();
        } else if (_ui.getWin()) { 
            _window->setActive(false); // Désactiver la fenêtre principale
            _window->setVisible(false);
            _ui.getWindow().setVisible(true);
            _ui.getWindow().setActive(true);
            _ui.getWindow().setVisible(true);  
            _ui.runVictoryWindow();
        }
    }

    if (this->_window->pollEvent(_event) ) { 
        //permet de v�rifier s'il y a un �v�nement en attente dans la file d'attente des �v�nements, si c'st le cas event stock l'evenement
        if (_event.type == sf::Event::Closed) // event=fermeture de la fenetre ?
            _window->close();
    
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if(!_ui.isPaused()) _ui.setIsPaused(true);
            else                _ui.setIsPaused(false);
        }

        _game.keyEvent(_event);// fait appel à la fonction move des sprites         
    }
}


const bool GameWindow::isRunning(void) const { // check si la fenetre est ouverte
    return _window->isOpen();
}

void GameWindow::limitFrameRate(int frame) { //limite le nombre de FPS
    this->_window->setFramerateLimit(frame);
}


int GameWindow::controlWindow(void) {
    this->pollEvent();
    int fin = _game.updateGame();

    if(fin==3){
        _ui.setIsDead(true);
        return 0;
    }

    return fin;
}


GameGestion& GameWindow::getGame(){
    return _game;
}


void GameWindow::draw() {
    std::vector<Object*>& toDraw = _game.toDrawUpdate(getCurrentWindowPos());
    for (int i = 0; i < toDraw.size() ; i++){
       Object& o = *toDraw[i];
       _window->draw(o.getSprite());
    }

    for (int i = 0; i < _game.getPlayerVector().size(); i++)
        _window->draw(_game.getPlayerVector()[i]->getSprite());
    

    if(_game.drawProjectile1(getCurrentWindowPos()))
        _window->draw(_game.getPlayerVector()[0]->getProjectile()->getSprite());

    std::vector<Projectile*> fireballs;
    if (_game.drawFireballs(getCurrentWindowPos(), fireballs)) {
        for (int i = 0; i < fireballs.size(); i++) 
            _window->draw(fireballs[i]->getSprite());
    }
   
    if(_game.drawProjectile2(getCurrentWindowPos())){
        _window->draw(_game.getPlayerVector()[1]->getProjectile()->getSprite());
    }

    if(!(_game.getMap().getPlayerDead() == nullptr) )
        _window->draw(*_game.getMap().getPlayerDead());
}


void GameWindow::display() {
    setScrollingView();

    if(_game.getPlayerVector()[0]->getIsInTheCave() || _game.getPlayerVector()[1]->getIsInTheCave()){
        if(_game.getPlayerVector()[0]->getIsInTheCave())
            _game.getPlayerVector()[1]->getSprite().setPosition({9984,9984});
        else
            _game.getPlayerVector()[0]->getSprite().setPosition({9984,9984});

        setViewBoss();
    }

    draw();// dessine tout les sprites contenut dans la fenetre courante
    setLifeViewPlayer1();
    displayLifeWindow();
    setLifeViewPlayer2();
    displayLifeWindowP2();
    setKeyView();
    displayKeyWindow();
    _window->display();
    clearWindow();
}


void GameWindow::setCurrentWindowPos(){
    _currentWindowPos.clear();

    sf::Vector2f center = {static_cast<float>(_view.getCenter().x),static_cast<float>(_view.getCenter().y)}; // Récupérer la position centrale de la vue
    sf::Vector2f size = {static_cast<float>(_view.getSize().x),static_cast<float>(_view.getSize().y)}; // Récupérer la taille de la vue
    sf::Vector2f topLeft = {center.x - size.x/2,center.y- size.y/2}; // Calculer la position du coin haut gauche

    _currentWindowPos[0]= topLeft;
    sf::Vector2f bottomRight = {center.x + size.x/2,center.y+ size.y/2}; // Calculer la position du coin haut gauche
    _currentWindowPos[1]= bottomRight;
}


void GameWindow::displayLifeWindow() {
    _lifeWindow.drawTo(this->getWindow());
}

void GameWindow::displayLifeWindowP2() {
    _lifeWindowP2.drawTo(this->getWindow());
}

void GameWindow::displayKeyWindow() {
    _keyWindow.drawTo(this->getWindow());
}

const sf::Vector2f& GameWindow::getPositionCentre() const {
    return _positionCentre;
}

sf::RenderWindow& GameWindow::getWindow() const {
    return *_window;
}

const UserInterface& GameWindow::getUi() const {
    return _ui;
}

const sf::Vector2f GameWindow::getWindowDim() const {
    sf::Vector2f dim = { _windowWidth,_windowHeight };
    return dim;
}

std::vector<sf::Vector2f>& GameWindow::getCurrentWindowPos() {
    setCurrentWindowPos();
    return _currentWindowPos;
}

void GameWindow::setLifeViewPlayer1() {
    _window->setView(_lifeWindow.getLifeView());
}

void GameWindow::setLifeViewPlayer2() {
    _window->setView(_lifeWindowP2.getLifeView());
}

void GameWindow::setKeyView(){
    _window->setView(_keyWindow.getKeyView());
}

const sf::View& GameWindow::getViewWindow() const {
    return _view;
}

void GameWindow::clearWindow() const {
    _window->clear();
}