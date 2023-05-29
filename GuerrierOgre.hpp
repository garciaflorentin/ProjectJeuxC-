#ifndef GUERRIER_OGRE_HPP
#define GUERRIER_OGRE_HPP

#include "Monster.hpp"
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
    GuerrierOgre(const char* nameObject, sf::Vector2f initPos, string name = "GuerrierOgre", int dmg = 4, int ar = 1, int vf = 30, float speed = 1.5) : MeleeMonster(nameObject, initPos, name, dmg, ar, vf, speed) {
        anim->x = 3;
        anim->y = 4;
        OBJECT_SIZE = 32;
        updateSprite();

        if (!footStepSound.openFromFile("/home/garcia/Bureau/ProjetC++  (travail)  (copie)/ProjectJeuxC-/GameSFX/FootStep/littleMonsterStep.wav")) {
            std::cout << "erreur de chargement de footStepSound" << std::endl;
        }
        if (!takeDamageMusic.openFromFile("die_monster.wav")) {
            std::cout << "erreur de chargement de takeDamageMusic" << std::endl;
        }
        if (!crySound.openFromFile("zombie attack.wav")) {
            std::cout << "erreur de chargement de crySound" << std::endl;
        }
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
    virtual void update(Player* pl);

};


#endif
