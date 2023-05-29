#ifndef MINI_FROG_MONSTER_HPP
#define MINI_FROG_MONSTER_HPP

#include "Monster.hpp"
#include "MeleeMonster.hpp"

/**
 * @class MiniFrogMonster
 * @brief Classe représentant un mini monstre grenouille, un type spécifique de monstre.
 *
 * La classe `MiniFrogMonster` hérite de la classe `MeleeMonster` et implémente les fonctionnalités spécifiques à un mini monstre grenouille.
 */
class MiniFrogMonster : public MeleeMonster {
private:

    /**
     * @brief Déplace le monstre grenouille vers le joueur.
     */
    virtual void goToPlayer();

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
    MiniFrogMonster(const char* nameObject, sf::Vector2f initPos, string name = "MiniFrogMonster", int dmg = 2, int ar = 1, int vf = 50, float speed = 3) :
        MeleeMonster(nameObject, initPos, name, dmg, ar, vf, speed)
    {
        anim->x = 15;
        anim->y = 34;
        OBJECT_SIZE = 48;
        updateSprite();

        if (!footStepSound.openFromFile("/home/garcia/Bureau/ProjetC++  (travail)  (copie)/ProjectJeuxC-/GameSFX/Bounce Jump/MiniFrogStep.wav"))
        {
            std::cout << "erreur de chargement de footStepSound" << std::endl;
        }
        if (!takeDamageMusic.openFromFile("die_monster.wav"))
        {
            std::cout << "erreur de chargement de takeDamageMusic" << std::endl;
        }
        if (!crySound.openFromFile("/home/garcia/Bureau/ProjetC++  (travail)  (copie)/ProjectJeuxC-/bruit/18_orc_charge.wav"))
        {
            std::cout << "erreur de chargement de crySound" << std::endl;
        }
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
     * @brief Met à jour le monstre grenouille en fonction du joueur.
     *
     * @param pl Pointeur vers le joueur
     */
    virtual void update(Player* pl);
};

#endif
