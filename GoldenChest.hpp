#ifndef GOLDENCHEST_HPP
#define GOLDENCHEST_HPP

#include "Chest.hpp"
#include "Player.hpp"


class GoldenChest : public Chest {

    private:
        int _key = 1; /**< Clé nécessaire pour ouvrir le coffre */

    public:
         /**
         * @brief Constructeur de la classe `GoldenChest`.
         *
         * @param nameObject Nom de l'objet
         * @param initPos Position initiale
         */
        GoldenChest(string nameObject, sf::Vector2f initPos) : Chest(nameObject, initPos) {
            _chestAnim.x = 0;
            _chestAnim.y = 6;
            _sprite.setTextureRect(sf::IntRect(_chestAnim.x * _chest_size, 233, 32, 24));
            _sprite.scale(1.5,1.5);

        }

        /**
         * @brief Destructeur de la classe `GoldenChest`.
         */
        ~GoldenChest() {}

        /**
         * @brief Gère la collision avec un objet.
         *
         * @param o Objet avec lequel il y a collision.
         */
        void collide(Object& o);

        /**
         * @brief Ouvre le coffre.
         */
        void open();
};


#endif