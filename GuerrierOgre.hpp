#ifndef GUERRIER_OGRE_HPP
#define GUERRIER_OGRE_HPP

#include "MeleeMonster.hpp"


class GuerrierOgre : public MeleeMonster {

    private:
        virtual void goToPlayer();

    public:
        /**
         * @brief Constructeur de la classe `GuerrierOgre`.
         *
         * @param nameObject Nom de l'objet
         * @param initPos Position initiale
         * @param name Nom du monstre
         * @param dmg Dommages du monstre
         * @param ar Armure du monstre
         * @param vf Valeur de vie du monstre
         * @param speed Vitesse du monstre
         */
        GuerrierOgre(const char* nameObject, sf::Vector2f initPos, Player& player, string name = "GuerrierOgre", int dmg = 4, int ar = 1, int vf = 30, float speed = 1.5) : 
        MeleeMonster(nameObject, initPos, player, name, dmg, ar, vf, speed) {
            _anim.x = 3;
            _anim.y = 4;
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
         * @brief Destructeur de la classe `GuerrierOgre`.
         */
        ~GuerrierOgre(){};

        /**
         * @brief Met à jour le sprite du monstre.
         */
        void updateSprite();

        /**
         * @brief Met à jour le monstre.
         *
         * @param pl Joueur
         */
        virtual void update(Player& pl);
};


#endif