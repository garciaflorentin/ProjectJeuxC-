#ifndef TILE_HPP
#define TILE_HPP

#include "Object.hpp"


/**
 * @brief Classe de base représentant une tuile.
 *
 * La classe `Tile` hérite de la classe `Object` et sert de classe de base pour les tuiles du jeu.
 */
class Tile: public Object {
     protected:
          int _tile_size = 48; /**< La taille d'une tuile en pixels. */

     public:
          /**
           * @brief Constructeur par defaut
           * 
           */
          Tile() {};

          /**
          * @brief Constructeur de la classe `Tile`.
          *
          * @param nameObject Nom de l'objet
          * @param initPos Position initiale
          */
          Tile(string nameObject, sf::Vector2f initPos) : Object(nameObject,initPos){};
};


#endif