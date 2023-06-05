#ifndef MINI_OGRE_HPP
#define MINI_OGRE_HPP

#include "MeleeMonster.hpp"


/**
 * @brief Cette classe represente un petit ogre
 * 
 */
class MiniOgre : public MeleeMonster {
    private:

        int _attack_cooldown = 40;  ///< Limite du temps entre deux attaques

    public:
        /**
         * @brief Constructeur de la classe `MiniOgre`.
         *
         * @param nameObject Nom de l'objet
         * @param initPos Position initiale du mini ogre
         * @param name Nom du mini ogre
         * @param dmg Dommages infligés par le mini ogre
         * @param ar Rayon d'attaque du mini ogre
         * @param vf Champ de vision du mini ogre
         * @param speed Vitesse du mini ogre
         */
        MiniOgre(string nameObject, sf::Vector2f initPos, string name = "MiniOgre", int dmg = 2.5, int ar = 1, int vf = 30, float speed = 8) :
        MeleeMonster(nameObject, initPos, name, dmg, ar, vf, speed) {
            _anim.x = 3;
            _anim.y = 0;
            _object_size = 32;

            updateSprite();

            _footStepSound = SoundsLib::assignSound("Sounds/littleMonsterStep.wav");
            _takeDamageMusic = SoundsLib::assignSound("Sounds/die_monster.wav");
            _crySound = SoundsLib::assignSound("Sounds/zombie attack.wav");
        };

        /**
         * @brief Destructeur de la classe `MiniOgre`.
         */
        ~MiniOgre() {};

        /**
         * @brief Met à jour le sprite du mini ogre.
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