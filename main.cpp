
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
    
    _window.getGame().setPlayer1(&_sprite);
 
    
    while (_window.getWindow()->isOpen()) {
        _window.draw();
        _window.controlWindow();
        _window.display();
        _window.clearWindow();

    }

    return EXIT_SUCCESS;
};