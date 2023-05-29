#ifndef MINI_OGRE_HPP
#define MINI_OGRE_HPP

#include "Monster.hpp"
#include "MeleeMonster.hpp"

/**
 * @class MiniOgre
 * @brief Classe représentant un mini ogre, un type spécifique de monstre.
 *
 * La classe `MiniOgre` hérite de la classe `MeleeMonster` et implémente les fonctionnalités spécifiques à un mini ogre.
 */
class MiniOgre : public MeleeMonster {
private:

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
    MiniOgre(const char* nameObject, sf::Vector2f initPos, string name = "MiniOgre", int dmg = 2.5, int ar = 1, int vf = 30, float speed = 2.5) :
        MeleeMonster(nameObject, initPos, name, dmg, ar, vf, speed)
    {
        anim->x = 3;
        anim->y = 0;
        OBJECT_SIZE = 32;
        updateSprite();

        if (!footStepSound.openFromFile("/home/garcia/Bureau/ProjetC++  (travail)  (copie)/ProjectJeuxC-/GameSFX/FootStep/littleMonsterStep.wav"))
        {
            std::cout << "erreur de chargement de footStepSound" << std::endl;
        }
        if (!takeDamageMusic.openFromFile("die_monster.wav"))
        {
            std::cout << "erreur de chargement de takeDamageMusic" << std::endl;
        }
        if (!crySound.openFromFile("zombie attack.wav"))
        {
            std::cout << "erreur de chargement de crySound" << std::endl;
        }
    }

    /**
     * @brief Destructeur de la classe `MiniOgre`.
     */
    ~MiniOgre() {}

    /**
     * @brief Met à jour le sprite du mini ogre.
     */
    void updateSprite();

    /**
     * @brief Met à jour le mini ogre en fonction du joueur.
     *
     * @param pl Pointeur vers le joueur
     */
    virtual void update(Player* pl);
};

#endif
