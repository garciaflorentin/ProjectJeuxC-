#ifndef FATE_HPP
#define FATE_HPP

#include "Projectile.hpp"

class Fate : public Projectile {

public:

    /**
     * @brief Constructeur de la classe Fate.
     * @param nameObject Le nom de l'objet.
     * @param initPos La position initiale de l'objet.
     * @param player Le joueur associé au projectile.
     */
    Fate(const char* nameObject, sf::Vector2f initPos, Player* player);

    /**
     * @brief Destructeur de la classe Fate.
     */
    ~Fate(){};

    /**
     * @brief Initialise le projectile.
     */
    void initProjectile();

};

#endif
