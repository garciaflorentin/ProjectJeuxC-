
#ifndef _GAMEWINDOW_H_
#define _GAMEWINDOW_H_

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include "GameGestion.hpp"

/// Window class and start the game
class GameWindow {
private:
    const int windoWwidth = 1024, windowHeight = 768;

    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode; //VideoMode defines a video mode (width, height, bpp) 

   GameGestion* _game;

   void pollEvent();// declaration d'un event

    void drawSprite(sf::Sprite sprite); //dessine un sprites sur la main window

    void drawText(sf::Text Text);

    void drawVectorSprite(std::vector <sf::Sprite> vector);

    void drawVectorText(std::vector <sf::Text> vector);



public:
    ////////////////////////////////////////

    /// Default Constructor
    GameWindow(void);

    /// Destructor
    ~GameWindow(void);

    GameGestion* getGame();


    ////////////////////////////////////////

    /// \return true if the window is open
    bool isRunning(void);

    ////////////////////////////////////////

    /// Limit FPS
    /// \param frame FPS number
    void limitFrameRate(int frame);

    ///
    void controlWindow(void); //check les event

    void updateWindow(void);// fais la maj de la windwow a chaquqe fps

    void updateWindow(std::vector<sf::Sprite> _sprites);

    void clearWindow() const{
        window->clear();
    }

    void DisplayTile(std::vector<sf::Sprite> v);

    void draw();// draw tout les sprites

    sf::RenderWindow* getWindow() {
        return window;
    }

    void display() {
        window->display();
    }

    //void verificationWindow(void);
};

#endif