
#ifndef _GAMEWINDOW_H_
#define _GAMEWINDOW_H_

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "LifeWindow.hpp"
#include "GameGestion.hpp"
#include "Heart.hpp"



/// Window class and start the game
class GameWindow {
private:


    float windowWidth = 1024.0, windowHeight = 768.0;
    sf::RenderWindow* _window;
    sf::Event* _event;
    sf::VideoMode _videoMode; //VideoMode defines a video mode (width, height, bpp) 
    sf::View* _view;
    std::vector<sf::Vector2i>* _currentWindowPos;
    sf::Vector2f _positionCentre;
    Heart* _test;

    //class
    GameGestion* _game;
    LifeWindow* _lifeWindow;

    void pollEvent();// declaration d'un event

    void drawSprite(sf::Sprite sprite); //dessine un sprites sur la main window

    void drawText(sf::Text Text);

    void drawVectorSprite(std::vector <sf::Sprite> vector);

    void drawVectorText(std::vector <sf::Text> vector);

    void displayLifeWindow() {
        _lifeWindow->drawTo(this->getWindow());
    }

    void setCurrentWindowPos(){
            /*sf::Vector2i windowTopLeft = window->getPosition();
            sf::Vector2i windowBottomRight = window->getPosition() + sf::Vector2i(window->getSize().x, window->getSize().y);
            currentWindowPos->push_back(windowBottomRight);
            currentWindowPos->push_back(windowTopLeft);
            */
        sf::FloatRect viewport = _window->getView().getViewport();
        sf::Vector2i viewTopLeft(viewport.left * _window->getSize().x, viewport.top * _window->getSize().y);
        sf::Vector2i viewBottomRight((viewport.left + viewport.width) * _window->getSize().x, (viewport.top + viewport.height) * _window->getSize().y);
        _currentWindowPos->push_back(viewBottomRight);
        _currentWindowPos->push_back(viewTopLeft);

    }

public:
    ////////////////////////////////////////

    /// Default Constructor
    GameWindow(void);

    /// Destructor
    ~GameWindow(void);


    //getteur

    GameGestion* getGame();

    sf::RenderWindow* getWindow() {
        return _window;
    }

    //view

    sf::Vector2f getWindowDim() {
        sf::Vector2f dim = { windowWidth,windowHeight };
        return dim;
    }

    std::vector<sf::Vector2i>* getCurrentWindowPos(){
        setCurrentWindowPos();
        return _currentWindowPos;
    }

    void setLifeView() {
        _window->setView(*_lifeWindow->getLifeView());
    }

    sf::View* getViewWindow() {
        return _view;
    }


    // control

    /// \return true if the window is open
    bool isRunning(void);
    void controlWindow(void); //check les event


    /// Limit FPS
    /// \param frame FPS number
    void limitFrameRate(int frame);



    // affichage

    void updateWindow(void);// fais la maj de la windwow a chaquqe fps

    void updateWindow(std::vector<sf::Sprite> _sprites);

    void clearWindow() const {
        _window->clear();
    }

    void DisplayTile(std::vector<sf::Sprite> v);

    void draw();// draw tout les sprites

    void display();

    void setScrollingView();
    //void verificationWindow(void);


};
#endif
