
#include "GameWindow.hpp"
#include "Object.hpp"
#include "GameGestion.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include "Heart.hpp"

#include "Monster.hpp"  //a des fins educatifs

sf::Texture* _texture = new sf::Texture();
sf::Sprite* _sprite = new sf::Sprite();




int main(void) {

    if (!_texture->loadFromFile(("object.png"), sf::IntRect(153,3,48,48))) {
        std::cout << "error image "<< std::endl;
    }
    _sprite->setTexture(*_texture);
    _sprite->setPosition(100, 100);


    GameWindow window;// cree la fenetre

    GameGestion* g=window.getGame();
    Player* p= (*g->getPlayerVector())[0];
    sf::Sprite* sp= p->getSprite();
    g->setPlayer(sp);// decoupe le sprite en ses differentes orientation , l'ajoute au vecteur de sprite de GameGestion et initialise le vecteur de mouvement.

    /* Code degueulasse juste pour tester - a reecrire comme il faut apres */
    window.getGame()->getMap()->addObject(new Monster());
    
    while (window.isRunning()) {

  
 
        window.getWindow()->draw(*_sprite);
        window.controlWindow();
        window.display();


    }

    delete _sprite;
    delete _texture;
   
  

    return EXIT_SUCCESS;
};