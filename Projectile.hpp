#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>
#include "Object.hpp"
#include "Player.hpp"
#include "TexturesLib.hpp"
#include "Monster.hpp"

class Player;
class Monster;

/**
 * @brief La classe Projectile représente un projectile tiré par le joueur.
 */
class Projectile: public Object {

protected:
    Player* _player; ///< Le joueur qui a tiré le projectile.
    bool _isShot; ///< Indique si le projectile a été tiré.
    int direction; ///< La direction dans laquelle le projectile se déplace.
    int distance; ///< La distance parcourue par le projectile.

public:

    /**
     * @brief Constructeur par défaut de la classe Projectile.
     */
    Projectile() : Object() {};

    /**
     * @brief Constructeur de la classe Projectile.
     * @param nameObject Le nom de l'objet projectile.
     * @param initPos La position initiale du projectile.
     * @param player Le joueur qui a tiré le projectile.
     */
    Projectile(const char* nameObject, sf::Vector2f initPos, Player* player);

    /**
     * @brief Destructeur de la classe Projectile.
     */
    ~Projectile(){}

    /**
     * @brief Constructeur de copie de la classe Projectile.
     * @param other L'autre projectile à copier.
     */
    Projectile(const Projectile& other);

    /**
     * @brief Opérateur d'assignation de la classe Projectile.
     * @param other L'autre projectile à assigner.
     * @return Une référence sur le projectile assigné.
     */
    Projectile& operator=(const Projectile& other);

    /**
     * @brief Déplace le projectile vers sa nouvelle position en fonction de sa direction.
     */
    virtual void goTo();

    /**
     * @brief Initialise le projectile.
     */
    virtual void initProjectile();

    /**
     * @brief Gère la collision du projectile avec un autre objet.
     * @param o L'objet avec lequel le projectile entre en collision.
     */
    virtual void collide(Object* o);

    /**
     * @brief Récupère la taille du projectile.
     * @return La taille du projectile.
     */
    const int getBlockSize() { return 32; }

    /**
     * @brief Vérifie si le projectile a été tiré.
     * @return `true` si le projectile a été tiré, sinon `false`.
     */
    bool isShot() {
        return _isShot;
    }

    /**
     * @brief Définit l'état du projectile (tiré ou non).
     * @param state L'état du projectile.
     */
    void setIsShot(bool state) {
        _isShot = state;
    }

    /**
     * @brief Récupère la direction du projectile.
     * @return La direction du projectile.
     */
    int getDirection() {
        return direction;
    }

    /**
     * @brief Définit la direction du projectile.
     * @param _direction La direction du projectile.
     */
    void setDirection(int _direction) {
        direction = _direction;
    }

    /**
     * @brief Récupère la distance parcourue par le projectile.
     * @return La distance parcourue par le projectile.
     */
    int getDistance() {
        return distance;
    }

    /**
     * @brief Incrémente la distance parcourue par le projectile.
     */
    void incrementeDistance() {
        distance++;
    }

    /**
     * @brief Définit la distance parcourue par le projectile.
     * @param i La distance parcourue par le projectile.
     */
    void setDistance(int i) {
        distance = i;
    }

    /**
     * @brief Gère le dépassement de limite du projectile (hors des limites de l'écran).
     */
    void arrowOutOfBounds();
};

#endif
