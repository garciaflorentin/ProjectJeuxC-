#ifndef FLY_MONSTER_HPP
#define FLY_MONSTER_HPP

#include "MeleeMonster.hpp"


class FlyMonster : public MeleeMonster {

    private:

        int _attack_cooldown = 40;

        /**
         * @brief Déplace le monstre vers le joueur.
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
        FlyMonster(string nameObject, sf::Vector2f initPos, /*Player& player1, Player& player2,*/ string name = "FlyMonster", int dmg = 3, int ar = 2, int vf = 100, float speed = 1.5) : 
        MeleeMonster(nameObject, initPos, /*player1, player2,*/ name, dmg, ar, vf, speed) {
            _anim.x = 12;
            _anim.y = 34;
            _object_size = 48;

            updateSprite();

            if (!_footStepSound->openFromFile("wingSound.wav"))
                throw runtime_error("Failed to open wingSound.wav");
            if (!_takeDamageMusic->openFromFile("die_monster.wav"))
                throw runtime_error("Failed to open die_monster.wav");
            if (!_crySound->openFromFile("hurt3_monster.wav")) 
                throw runtime_error("Failed to open hurt3_monster.wav");
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
         * @brief Met à jour le monstre.
         * @param pl Le joueur.
         */
        //virtual void update(Player& pl1, Player& pl2);
};


#endif