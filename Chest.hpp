#ifndef CHEST_HPP
#define CHEST_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Gain.hpp"
#include "TexturesLib.hpp"
#include "Tile.hpp"
#include "Object.hpp"
#include "Character.hpp"
//#include "Player.hpp"
//#include "Projectile.hpp"

class Gain;

class Chest : public Tile {

protected:
    int CHEST_SIZE = 35; /**< Taille d'un bloc du coffre */
    bool _isOpen; /**< Indique si le coffre est ouvert */
    Gain* _gain; /**< Gain contenu dans le coffre */
    sf::Vector2i* chestAnim; /**< Animation du coffre */

public:
    /**
     * @brief Constructeur de la classe `Chest`.
     *
     * @param nameObject Nom de l'objet
     * @param initPos Position initiale
     */
    Chest(const char* nameObject, sf::Vector2f initPos) : Tile(nameObject, initPos), _isOpen(false) {
        chestAnim = new sf::Vector2i();
        _gain = new Gain("Health potion.png", { getPosition().x, getPosition().y });
        chestAnim->x = 0;
        chestAnim->y = 1;
        _sprite->setTextureRect(sf::IntRect(chestAnim->x * CHEST_SIZE, chestAnim->y * CHEST_SIZE, CHEST_SIZE, CHEST_SIZE));
    }

    /**
     * @brief Destructeur de la classe `Chest`.
     */
    ~Chest() {
        delete _gain;
        delete chestAnim;
    }

    /**
     * @brief Ouvre le coffre.
     *
     * @return Le nombre de gains obtenus.
     */
    int open();

    /**
     * @brief Récupère le sprite du coffre.
     *
     * @return Le sprite du coffre.
     */
    sf::Sprite* getSpriteChest() {
        return _sprite;
    }

    /**
     * @brief Récupère la position du coffre.
     *
     * @return La position du coffre.
     */
    sf::Vector2f getPosition() {
        return _sprite->getPosition();
    }

    /**
     * @brief Vérifie si le coffre est ouvert.
     *
     * @return `true` si le coffre est ouvert, sinon `false`.
     */
    bool isOpen() {
        return _isOpen;
    }

    /**
     * @brief Gère la collision avec un objet.
     *
     * @param o Objet avec lequel il y a collision.
     */
    virtual void collide(Object* o);

    /**
     * @brief Récupère la taille d'un bloc du coffre.
     *
     * @return La taille d'un bloc du coffre.
     */
    const int getBlockSize() {
        return CHEST_SIZE;
    }

    /**
     * @brief Récupère le gain du coffre.
     *
     * @return Le gain du coffre.
     */
    Gain* getGain() {
        return _gain;
    }
};

#endif
