#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include <cmath>

#include "Projectile.hpp"
#include "Character.hpp"
#include "Player.hpp"


/**
 * @brief Cette classe represente une boule de feu
 * 
 */
class Fireball : public Projectile {
    private:
        sf::Vector2f _initPos;  ///< Position initiale
        sf::Vector2f _dirVect;  ///< Position ciblee

        int _dmg;   ///< Degats que le fireball inflige

    public:
        /**
         * @brief Constructeurt par defaut
         * 
         */
        Fireball() : Projectile() {};

        /**
         * @brief Constructeur
         * 
         * @param nameObject Nom de la texture a charger
         * @param initPos Position initiale
         * @param player Joueur a qui est destine le fireball
         * @param angle Angle sous lequel est lance le fireball
         * @param dmg Degats infliges par le fireball
         */
        Fireball(string nameObject, sf::Vector2f initPos, Character& player, float angle = 0, int dmg = 2);

        /**
         * @brief Operatur d'assignement
         * 
         * @param other Fireball a assigner
         * @return Fireball& - Fireball assigne
         */
        Fireball& operator=(const Fireball& other);

        /**
         * @brief Destructeur
         * 
         */
        ~Fireball() { cout << "Destroying Fireball" << endl; };

        /**
         * @brief Calcule la trajectoire a suivre par le fireball
         * 
         * @param player Joueur destinateire
         * @param angle Angle sous lequel le fireball est lance
         */
        void computeTrajectory(Character& player, float angle);

        /**
         * @brief Initialide le fireball lors de son lancement et le dessine
         * 
         */
        void initProjectile();

        /**
         * @brief Suit la trajectoire du fireball
         * 
         */
        void goTo();

        /**
         * @brief Gere les collisions avec les objets
         * 
         * @param o Objet en collision
         */
        void collide(Object& o);
};


#endif