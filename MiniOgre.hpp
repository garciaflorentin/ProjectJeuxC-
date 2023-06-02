#ifndef MINI_OGRE_HPP
#define MINI_OGRE_HPP

#include "MeleeMonster.hpp"


class MiniOgre : public MeleeMonster {
    private:

        int _attack_cooldown = 40;

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
        MiniOgre(string nameObject, sf::Vector2f initPos, /*Player& player1, Player& player2,*/ string name = "MiniOgre", int dmg = 2.5, int ar = 1, int vf = 30, float speed = 2.5) :
        MeleeMonster(nameObject, initPos, /*player1, player2,*/ name, dmg, ar, vf, speed) {
            _anim.x = 3;
            _anim.y = 0;
            _object_size = 32;

            updateSprite();

            if (!_footStepSound->openFromFile("/home/garcia/Bureau/ProjetC++  (travail)  (copie)/ProjectJeuxC-/GameSFX/FootStep/littleMonsterStep.wav"))
                throw runtime_error("Failed to open littleMonsterStep.wav");
            if (!_takeDamageMusic->openFromFile("die_monster.wav"))
                throw runtime_error("Failed to open die_monster.wav");
            if (!_crySound->openFromFile("zombie attack.wav"))
                throw runtime_error("Failed to open zombie attack.wav");

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
         * @brief Met à jour le mini ogre en fonction du joueur.
         *
         * @param pl Pointeur vers le joueur
         */
        //virtual void update(Player& pl);
};


#endif