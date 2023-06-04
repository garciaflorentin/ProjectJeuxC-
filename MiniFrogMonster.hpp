#ifndef MINI_FROG_MONSTER_HPP
#define MINI_FROG_MONSTER_HPP

#include "MeleeMonster.hpp"


/**
 * @class MiniFrogMonster
 * @brief Classe représentant un mini monstre grenouille, un type spécifique de monstre.
 *
 * La classe `MiniFrogMonster` hérite de la classe `MeleeMonster` et implémente les fonctionnalités spécifiques à un mini monstre grenouille.
 */
class MiniFrogMonster : public MeleeMonster {
    private:

        int _attack_cooldown = 40;

        /**
         * @brief Déplace le monstre grenouille vers le joueur.
         */
        virtual void goToPlayer(Player& target);

    public:
        /**
         * @brief Constructeur de la classe `MiniFrogMonster`.
         *
         * @param nameObject Nom de l'objet
         * @param initPos Position initiale du monstre grenouille
         * @param name Nom du monstre grenouille
         * @param dmg Dommages infligés par le monstre grenouille
         * @param ar Rayon d'attaque du monstre grenouille
         * @param vf Champ de vision du monstre grenouille
         * @param speed Vitesse du monstre grenouille
         */
        MiniFrogMonster(string nameObject, sf::Vector2f initPos, /*Player& player1, Player& player2,*/ string name = "MiniFrogMonster", int dmg = 2, int ar = 1, int vf = 50, float speed = 3) :
        MeleeMonster(nameObject, initPos, /*player1, player2,*/ name, dmg, ar, vf, speed) {
            _anim.x = 15;
            _anim.y = 34;
            _object_size = 48;
            updateSprite();

            _footStepSound = SoundsLib::assignSound("Sounds/MiniFrogStep.wav");
            _takeDamageMusic = SoundsLib::assignSound("Sounds/die_monster.wav");
            _crySound = SoundsLib::assignSound("Sounds/18_orc_charge.wav");
        }


        /**
         * @brief Destructeur de la classe `MiniFrogMonster`.
         */
        ~MiniFrogMonster() {}

        /**
         * @brief Met à jour le sprite du monstre grenouille.
         */
        virtual void updateSprite();

        /**
         * @brief Met a jour le monstre
         * 
         * @param pl1 Premier joueur de la carte
         * @param pl2 Deuxieme joueur de la carte
         */
        virtual void update(Player& pl1, Player& pl2);
};


#endif