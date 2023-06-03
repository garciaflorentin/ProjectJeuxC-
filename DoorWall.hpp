#ifndef DOOR_WALL_HPP
#define DOOR_WALL_HPP

#include "Door.hpp"


class DoorWall : public Door {

    private:
        int _nbKey; /**< Nombre de clés nécessaires pour ouvrir la porte */

    public:
        DoorWall() {};

        /**
         * @brief Constructeur de la classe `DoorWall`.
         *
         * @param nameObject Nom de l'objet
         * @param initPos Position initiale
         * @param _typeWall Type de mur de la porte
         * @param nbKey Nombre de clés nécessaires pour ouvrir la porte
         * @param rotate Angle de rotation de la porte
         */
        DoorWall(string nameObject, sf::Vector2f initPos, TypeWall _typeWall, int nbKey, int rotate) : 
        Door(nameObject, initPos, _typeWall) {
            _nbKey = nbKey;
            _sprite.setTextureRect(sf::IntRect(_anim.x, _anim.y * 64, 96, 64));
            _sprite.scale(1.5, 1.5);
            _sprite.rotate(rotate);
            _resistance=1000000;
        }

        DoorWall& operator=(const DoorWall& other) {
            Door::operator=(other);

            _nbKey=other._nbKey;

            return *this;
        }

        /**
         * @brief Destructeur de la classe `DoorWall`.
         */
        ~DoorWall() {}

        /**
         * @brief Anime la porte.
         */
        virtual void animDoor();

        /**
         * @brief Gère la collision avec un objet.
         *
         * @param o Objet avec lequel il y a collision.
         */
        virtual void collide(Object& o);
};


#endif