
#include "GameWindow.hpp"
#include "Object.hpp"
#include "GameGestion.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
sf::CircleShape c;
sf::Texture _texture;
sf::Sprite _sprite;


int main(void) {
    
    GameWindow _window;// cree la fenetre

   /* switch (_texture.loadFromFile("object.png"))
    {
    case false: std::cout << "erreur chargement de la texture" << std::endl; break;
    case true: std::cout << " texture charge " << std::endl; break;

    }
    _texture.setSmooth(true);
    _sprite.setTexture(_texture);*/
    
    _window.getGame()->setPlayer(_window.getGame()->getPlayerSprite());// decoupe le sprite en ses differentes orientation , l'ajoute au vecteur de sprite de GameGestion et initialise le vecteur de mouvement.
 
    
    while (_window.getWindow()->isOpen()) {
        _window.draw();// dessine tout les sprites que contient la GameGestion
        _window.controlWindow();
        _window.display();
        _window.clearWindow();

    }

    return EXIT_SUCCESS;
};