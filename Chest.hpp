#ifndef CHEST_HPP
#define CHEST_HPP

#include "Tile.hpp"
#include "Prise.hpp"
#include "Projectile.hpp"
#include "Character.hpp"


/**
 * @brief Cette classe representre un coffre
 * 
 */
class Chest : public Tile {
    protected:
        int _chest_size = 35; /**< Taille d'un bloc du coffre */
        bool _isOpen; /**< Indique si le coffre est ouvert */
        Prise& _prise; /**< Gain contenu dans le coffre */
        sf::Vector2i _chestAnim; /**< Animation du coffre */

    public:
        /**
         * @brief Constructeur de la classe `Chest`.
         *
         * @param nameObject Nom de l'objet
         * @param initPos Position initiale
         */
        Chest(string nameObject, sf::Vector2f initPos) : 
        Tile(nameObject, initPos), _isOpen(false), _prise(*(new Prise("OtherTextures/Health potion.png", { getPosition().x, getPosition().y }))) {
            _chestAnim.x = 0;
            _chestAnim.y = 1;
            _sprite.setTextureRect(sf::IntRect(_chestAnim.x * _chest_size, _chestAnim.y * _chest_size, _chest_size, _chest_size));
        }

        /**
         * @brief Destructeur de la classe `Chest`.
         */
        ~Chest() {};

        /**
         * @brief Ouvre le coffre.
         *
         * @return Le nombre de gains obtenus.
         */
        const int open();

        /**
         * @brief Récupère le sprite du coffre.
         *
         * @return Le sprite du coffre.
         */
        const sf::Sprite& getSpriteChest() const {
            return _sprite;
        }

        /**
         * @brief Récupère la position du coffre.
         *
         * @return La position du coffre.
         */
        const sf::Vector2f getPosition() const {
            return _sprite.getPosition();
        }

        /**
         * @brief Vérifie si le coffre est ouvert.
         *
         * @return `true` si le coffre est ouvert, sinon `false`.
         */
        const bool isOpen() const {
            return _isOpen;
        }

        /**
         * @brief Gère la collision avec un objet.
         *
         * @param o Objet avec lequel il y a collision.
         */
        virtual void collide(Object& o);

        /**
         * @brief Récupère la taille d'un bloc du coffre.
         *
         * @return La taille d'un bloc du coffre.
         */
        const int getBlockSize() const {
            return _chest_size;
        }

        /**
         * @brief Récupère le gain du coffre.
         *
         * @return Le gain du coffre.
         */
        Prise& getPrise() const {
            return _prise;
        }
};


#endif