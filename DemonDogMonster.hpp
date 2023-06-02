#ifndef DEMONDOG_MONSTER_HPP
#define DEMONDOG_MONSTER_HPP

#include "MeleeMonster.hpp"


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
        DemonDogMonster(string nameObject, sf::Vector2f initPos, /*Player& player1, Player& player2,*/ string name = "meat", int dmg = 3, int ar = 2, int vf = 100, float speed = 1) : 
        MeleeMonster(nameObject, initPos, /*player1, player2,*/ name, dmg, ar, vf, speed) {
            _anim.x = 0;
            _anim.y = 0;
            _sprite.scale(1, 1);

            updateSprite();

            if (!_footStepSound->openFromFile("/home/garcia/Bureau/ProjetC++  (travail)  (copie)/ProjectJeuxC-/GameSFX/FootStep/bigMonsterStep.wav"))
                throw runtime_error("Could not open bigMonsterStep.wav");
            if (!_takeDamageMusic->openFromFile("die_monster.wav"))
                throw runtime_error("Could not open die_monster.wav");
            if (!_crySound->openFromFile("roar3_monster.wav")) 
                throw runtime_error("Could not open roar3_monster.wav");
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
         * @brief Met à jour le monstre.
         *
         * @param pl Joueur
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