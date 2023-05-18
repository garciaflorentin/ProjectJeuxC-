
#include "GameWindow.hpp"
#include "Object.hpp"
#include "GameGestion.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include "Heart.hpp"

using namespace std;

int main(void) {

    std::srand(std::time(nullptr));
    
    GameWindow _window;// cree la fenetre
    GameGestion* g=_window.getGame();
    Player* p= (*g->getPlayerVector())[0];
    sf::Sprite* sp= p->getSprite();
    g->setPlayer(sp);// decoupe le sprite en ses differentes orientation , l'ajoute au vecteur de sprite de GameGestion et initialise le vecteur de mouvement.

    _window.limitFrameRate(100);
    while (_window.isRunning()) {
        g->updateMobs();
        
        _window.controlWindow();
        _window.display();
    }

    return EXIT_SUCCESS;
};