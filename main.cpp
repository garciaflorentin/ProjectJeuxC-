
#include "GameWindow.hpp"
#include "Object.hpp"
#include "GameGestion.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include "Heart.hpp"
sf::Texture* _texture = new sf::Texture();
sf::Sprite* _sprite = new sf::Sprite;
sf::Texture* _texture2 = new sf::Texture();
sf::Sprite* _sprite2 = new sf::Sprite;


int main(void) {

    Heart* _life = new Heart();

    if (!_texture->loadFromFile(("object.png"), sf::IntRect(153,3,48,48))) {
        std::cout << "error image "<< std::endl;
    }
    _sprite->setTexture(*_texture);
    _sprite->setPosition(100, 100);


    GameWindow _window;// cree la fenetre
    _window.getGame()->setPlayer(_window.getGame()->getPlayerSprite());// decoupe le sprite en ses differentes orientation , l'ajoute au vecteur de sprite de GameGestion et initialise le vecteur de mouvement.
 
    
    while (_window.isRunning()) {

        for (int i = 0; i < 3; i++) {
            _window.getWindow()->draw(*(*_life->getLife())[i]);
        }
        _window.setScrollingView();
        _window.controlWindow();
        _window.draw();// dessine tout les sprites que contient la GameGestion
        _window.getWindow()->draw(*_sprite);
        _window.display();
        _window.clearWindow();

    }

    delete _sprite;
    delete _texture;
    //delete _life;

    return EXIT_SUCCESS;
};