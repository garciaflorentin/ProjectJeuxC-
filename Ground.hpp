#ifndef _GROUND_H_
#define _GROUND_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Tile.hpp"
#include "TypeGround.hpp"

class Ground: public Tile {

public:

    /**
     * @brief Obtient la taille du bloc de sol.
     * @return La taille du bloc de sol.
     */
    const int getBlockSize() {
        return TILE_SIZE;
    }

    /**
     * @brief Gère la collision avec un objet.
     * @param o L'objet avec lequel la collision s'est produite.
     */
    void collide(Object* o) {}

    /**
     * @brief Constructeur de la classe Ground.
     * @param nameObject Le nom de l'objet.
     * @param initPos La position initiale de l'objet.
     * @param _typeGround Le type de sol.
     */
    Ground(const char* nameObject, sf::Vector2f initPos, TypeGround _typeGround) : Tile(nameObject, initPos) {
        TILE_SIZE = 48;

        int t = static_cast<int>(_typeGround);
        if (t < 9) {
            _sprite->setTextureRect(sf::IntRect(2 * t * 48 + 2 + 48, 14 * 48 + 6, 48, 48));
        }
        else {
            switch (t) {
                case 9:
                    _sprite->setTextureRect(sf::IntRect(698, 1181, 48, 48));
                    break;
                case 10:
                    _sprite->setTextureRect(sf::IntRect(445, 1062, 26, 48));
                    break;
                case 11:
                    _sprite->setTextureRect(sf::IntRect(445, 1062, 26, 48));
                    break;
            }
        }
    }
};

#endif
