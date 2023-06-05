#ifndef FINALBOSS_HPP
#define FINALBOSS_HPP


#include <cmath>

#include "Monster.hpp"
#include "Fireball.hpp"

#define PI 3.14159

#define FIREBALL_NUMBER 6


/**
 * @brief Cette classe represente le boss final
 * 
 */
class FinalBoss : public Monster {
    private :
        int _meleeRange = 4;                ///< Distance a laquelle le personnage peut attacker sans tirer
        vector<Projectile*>& _fireballs;    ///< Tableau des fireball que peut tirer le personnage

        /**
         * @brief Indique si la cible est atteignable
         * 
         * @param target La cible
         * @param range Rayon dans lequel le personnage peut atteindre la cible
         * @return true - Cible atteignable
         * @return false - mCible inatteignable
         */
        const bool playerInRange(Player& target, int range) const;

    public:
        /**
         * @brief Constructeur
         * 
         */
        FinalBoss();

        /**
         * @brief Attecket une cible
         * 
         * @param target La cible
         * @param type Tyoe d'attaque
         */
        void attack(Character& target, char type);

        /**
         * @brief Met a jour le personnage
         * 
         * @param pl1 Premier joueur de la carte
         * @param pl2 Deuxieme joueur de la carte
         */
        void update(Player& pl1, Player& pl2);

        /**
         * @brief Getteur de _fireballs
         * 
         * @return std::vector<Projectile*>* - Tableau des fireball tires par le personnage
         */
        virtual std::vector<Projectile*>* getProjectiles() { 
            //cout << "There are " << _fireballs.size() << " fireballs launched" << endl;
            return &_fireballs; 
        };

        /**
         * @brief Met a jour le sprite
         * 
         */
        void updateSprite();

        /**
         * @brief Gere les collisions avec les differents objets
         * 
         * @param o Objet en collision 
         */
        void collide(Object& o);
};


#endif