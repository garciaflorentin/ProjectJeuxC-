#ifndef MELEE_MONSTER_HPP
#define MELEE_MONSTER_HPP

#include "Monster.hpp"


/**
 * @class MeleeMonster
 * @brief Classe représentant un monstre de mêlée, un type spécifique de monstre.
 *
 * La classe `MeleeMonster` hérite de la classe `Monster` et implémente les fonctionnalités spécifiques à un monstre de mêlée.
 */
class MeleeMonster : public Monster {
    private:

    public:
        /**
         * @brief Constructeur de la classe `MeleeMonster`.
         *
         * @param nameObject Nom de l'objet
         * @param initPos Position initiale du monstre de mêlée
         * @param name Nom du monstre de mêlée
         * @param dmg Dommages infligés par le monstre de mêlée
         * @param ar Rayon d'attaque du monstre de mêlée
         * @param vf Champ de vision du monstre de mêlée
         * @param speed Vitesse du monstre de mêlée
         */
        MeleeMonster(string nameObject, sf::Vector2f initPos, string name = "Zombie", int dmg = 1, int ar = 1, int vf = 30, float speed = 8) :
        Monster(nameObject, initPos, name, dmg, ar, vf, speed) {
            _anim.x = 0;
            _anim.y = 0;
            updateSprite();

            _footStepSound = SoundsLib::assignSound("Sounds/littleMonsterStep.wav");
            _takeDamageMusic = SoundsLib::assignSound("Sounds/die_monster.wav");
            _crySound = SoundsLib::assignSound("Sounds/roar4_monster.wav");
        };

        /**
         * @brief Destructeur de la classe `MeleeMonster`.
         */
        ~MeleeMonster() {};

        /**
         * @brief Attaque le personnage cible.
         *
         * @param target Personnage cible de l'attaque
         */
        void attack(Character& target);

        /**
         * @brief Met à jour le sprite du monstre de mêlée.
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