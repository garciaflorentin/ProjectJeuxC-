#ifndef RANGED_MONSTER_HPP
#define RANGED_MONSTER_HPP

#include "Monster.hpp"
#include "Fireball.hpp"


/**
 * @brief Cette classe represente un monstre qui peut tirer les projectiles
 * 
 */
class RangedMonster : public Monster {
    private:
        Fireball& _fireball;    ///< Fireball tire par le monstre

    public:
        /**
         * @brief Constructeur
         * 
         * @param nameObject Nom de la texture a charger
         * @param initPos Position initiale
         * @param name Nom du monstre
         * @param dmg Degats du monstre
         * @param ar Rayon d'attaque
         * @param vf Rayon de la vue
         * @param speed Vitesse
         */
        RangedMonster(string nameObject, sf::Vector2f initPos, string name="meat", int dmg=1, int ar=5, int vf=50,float speed=1) : 
        Monster(nameObject, initPos, name, dmg, ar, vf,speed), _fireball(*(new Fireball())) {
            _anim.x = 9;
	        _anim.y = 0;

            updateSprite();

            _footStepSound = SoundsLib::assignSound("Sounds/footStep.wav");
            _crySound = SoundsLib::assignSound("Sounds/Retro Roar 02.wav");
        };

        /**
         * @brief Destructeur
         * 
         */
        ~RangedMonster(){};

        /**
         * @brief Attaque la cible
         * 
         * @param target La cible
         */
        void attack(Character& target);

        /**
         * @brief Getteur de _fireball
         * 
         * @return Projectile* - Fireball tire
         */
        Projectile* getProjectile() { return &_fireball; };
        
        /**
         * @brief Met a jour le sprite
         * 
         */
        void updateSprite();

        /**
         * @brief Met a jour le monstre
         * 
         * @param target1 Premier joueur de la carte
         * @param target2 Deuxieme joueur de la carte
         */
        virtual void update(Player& target1, Player& target2);
};


#endif