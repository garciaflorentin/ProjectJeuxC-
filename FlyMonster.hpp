#ifndef FLY_MONSTER_HPP
#define FLY_MONSTER_HPP

#include "MeleeMonster.hpp"


/**
 * @brief Cette classe represente un monstre volant
 * 
 */
class FlyMonster : public MeleeMonster {
    private:
        int _attack_cooldown = 40; ///< Limite de temps entre deux attaques

        /**
         * @brief Fait suivre un joueur
         * 
         * @param target Le joueur a suivre
         */
        virtual void goToPlayer(Player &target);

    public:

        /**
         * @brief Constructeur de la classe FlyMonster.
         * @param nameObject Le nom de l'objet.
         * @param initPos La position initiale de l'objet.
         * @param name Le nom du monstre.
         * @param dmg Les points de dégâts du monstre.
         * @param ar Les points d'armure du monstre.
         * @param vf Les points de vie du monstre.
         * @param speed La vitesse de déplacement du monstre.
         */
        FlyMonster(string nameObject, sf::Vector2f initPos, string name = "FlyMonster", int dmg = 3, int ar = 2, int vf = 100, float speed = 5) : 
        MeleeMonster(nameObject, initPos, name, dmg, ar, vf, speed) {
            _anim.x = 12;
            _anim.y = 34;
            _object_size = 48;

            updateSprite();

            _footStepSound = SoundsLib::assignSound("Sounds/wingSound.wav");
            _takeDamageMusic = SoundsLib::assignSound("Sounds/die_monster.wav");
            _crySound = SoundsLib::assignSound("Sounds/hurt3_monster.wav");
        }

        /**
         * @brief Destructeur de la classe FlyMonster.
         */
        ~FlyMonster() {}


        /**
         * @brief Met à jour le sprite du monstre.
         */
        void updateSprite();

        /**
         * @brief Met a jour le monstre
         * 
         * @param pl1 Premier joueur de la carte
         * @param pl2 Deuxieme joueur de la carte
         */
        virtual void update(Player& pl1, Player& pl2);
};


#endif