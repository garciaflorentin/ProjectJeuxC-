
#include "GameWindow.hpp"
#include "Object.hpp"
#include "GameGestion.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include "Heart.hpp"

int main(void) {


    GameWindow _window;// cree la fenetre
    GameGestion* g=_window.getGame();
    Player* p= (*g->getPlayerVector())[0];
    sf::Sprite* sp= p->getSprite();
    g->setPlayer(sp);// decoupe le sprite en ses differentes orientation , l'ajoute au vecteur de sprite de GameGestion et initialise le vecteur de mouvement.

    /* Code de test */
    // sf::Vector2f m_pos;
    // m_pos.x = 100;
    // m_pos.y = 100;
    // Monster* test_mob = new Monster("filename.png", m_pos);
    /* -------------*/

    _window.limitFrameRate(100);
    while (_window.isRunning()) {
        _window.controlWindow();
        _window.display();
    }

    return EXIT_SUCCESS;
};