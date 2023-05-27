
#ifndef _GAMEWINDOW_H_
#define _GAMEWINDOW_H_

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "LifeWindow.hpp"
#include "KeyWindow.hpp"
#include "GameGestion.hpp"
#include "Heart.hpp"
#include "Projectile.hpp"
#include "UserInterface.hpp"



/// Window class and start the game
class GameWindow {
private:


    float windowWidth = 1024.0, windowHeight = 768.0;
    sf::RenderWindow* window;
    sf::Event* event;
    sf::VideoMode videoMode; //VideoMode defines a video mode (width, height, bpp) 
    sf::View* _view;
    std::vector<sf::Vector2f>* currentWindowPos;
    sf::Vector2f positionCentre;
    Heart* test;

    //class
    GameGestion* _game;
    LifeWindow* _lifeWindow;
    KeyWindow* _keyWindow;
    UserInterface* ui;

    void pollEvent();// declaration d'un event

    void drawSprite(sf::Sprite sprite); //dessine un sprites sur la main window

    void drawText(sf::Text Text);

    void drawVectorSprite(std::vector <sf::Sprite> vector);

    void drawVectorText(std::vector <sf::Text> vector);

    void displayLifeWindow() {
        _lifeWindow->drawTo(this->getWindow());
    }

    void displayKeyWindow() {
        _keyWindow->drawTo(this->getWindow());
    }


    void setCurrentWindowPos();
public:
    ////////////////////////////////////////

    /// Default Constructor
    GameWindow(void);

    /// Destructor
    ~GameWindow(void);


    //getteur

    GameGestion* getGame();

    sf::Vector2f& getPositionCentre(){
        return positionCentre;
    }

    sf::RenderWindow* getWindow() {
        return window;
    }

    //UI
    UserInterface* getUi(){
        return ui;
    }

  //  void ControlUi();

    //view

    sf::Vector2f getWindowDim() {
        sf::Vector2f dim = { windowWidth,windowHeight };
        return dim;
    }

    std::vector<sf::Vector2f>* getCurrentWindowPos(){
        setCurrentWindowPos();
        return currentWindowPos;
    }

    void setLifeView() {
        window->setView(*_lifeWindow->getLifeView());
    }

    void setKeyView(){
        window->setView(*_keyWindow->getKeyView());
    }

    sf::View* getViewWindow() {
        return _view;
    }


    // control

    /// \return true if the window is open
    bool isRunning(void);
    int controlWindow(void); 


    /// Limit FPS
    /// \param frame FPS number
    void limitFrameRate(int frame);



    // affichage

    void updateWindow(void);// fais la maj de la windwow a chaquqe fps

    void updateWindow(std::vector<sf::Sprite> _sprites);

    void clearWindow() const {
        window->clear();
    }

    void DisplayTile(std::vector<sf::Sprite> v);

    void draw();// draw tout les sprites

    void display();

    void setScrollingView();

    void setViewBoss();


    //void verificationWindow(void);


    

};
#endif
