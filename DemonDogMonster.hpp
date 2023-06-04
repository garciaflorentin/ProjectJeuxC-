#ifndef DEMONDOG_MONSTER_HPP
#define DEMONDOG_MONSTER_HPP

#include "MeleeMonster.hpp"


/**
 * @brief Cette classe represente un monstre DemonDog
 * 
 */
class DemonDogMonster : public MeleeMonster {
    private:
        int _attack_cooldown = 20;
        
    public:
        /**
         * @brief Constructeur de la classe `DemonDogMonster`.
         *
         * @param nameObject Nom de l'objet
         * @param initPos Position initiale
         * @param name Nom du monstre
         * @param dmg Dommages du monstre
         * @param ar Rayon d'attaque du monstre
         * @param vf Valeur de vie du monstre
         * @param speed Vitesse du monstre
         */
        DemonDogMonster(string nameObject, sf::Vector2f initPos, string name = "meat", int dmg = 3, int ar = 2, int vf = 100, float speed = 1) : 
        MeleeMonster(nameObject, initPos, name, dmg, ar, vf, speed) {
            _anim.x = 0;
            _anim.y = 0;
            _sprite.scale(1, 1);

            updateSprite();

            _footStepSound = SoundsLib::assignSound("Sounds/bigMonsterStep.wav");
            _takeDamageMusic = SoundsLib::assignSound("Sounds/ie_monster.wav");
            _crySound = SoundsLib::assignSound("Sounds/roar3_monster.wav");
        }

        /**
         * @brief Destructeur de la classe `DemonDogMonster`.
         */
        ~DemonDogMonster() {};

        /**
         * @brief Met à jour le sprite du monstre.
         */
        void updateSprite() {
            if (_anim.x * 96 >= 96 * 3)
                _anim.x = 0;
            
            _sprite.setTextureRect(sf::IntRect(_anim.x * 96, _anim.y * 48, 96, 48));
        }

        /**
         * @brief Met a jour le monster
         * 
         * @param target1 Premier joueur sur la carte
         * @param target2 Deuxieme joueur sur la carte
         */
        void update(Player& target1, Player& target2) {
            float dist1, dist2;
    
            if (target1.isAlive() || target2.isAlive()) {
                if (playerSeen(target1, target2, &dist1, &dist2)) {
                    if (dist1 < dist2 && !playerInRange(target1))
                        goToPlayer(target1);
                    else if (dist1 > dist2 && !playerInRange(target2))
                        goToPlayer(target2);
                }
                
                if (_upd.getElapsedTime().asMilliseconds() % _attack_cooldown == 0) {
                    if (playerInRange(target1))
                        attack(target1);
                    if (playerInRange(target2))
                        attack(target2);
                }
                    
            }
        }
};


#endif