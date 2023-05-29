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
    MeleeMonster(const char* nameObject, sf::Vector2f initPos, string name = "Zombie", int dmg = 1, int ar = 1, int vf = 30, float speed = 3) :
        Monster(nameObject, initPos, name, dmg, ar, vf, speed)
    {
        anim->x = 0;
        anim->y = 0;
        updateSprite();

        if (!footStepSound.openFromFile("/home/garcia/Bureau/ProjetC++  (travail)  (copie)/ProjectJeuxC-/GameSFX/FootStep/littleMonsterStep.wav"))
        {
            std::cout << "erreur de chargement de footStepSound" << std::endl;
        }
        if (!takeDamageMusic.openFromFile("die_monster.wav"))
        {
            std::cout << "erreur de chargement de takeDamageMusic" << std::endl;
        }
        if (!crySound.openFromFile("roar4_monster.wav"))
        {
            std::cout << "erreur de chargement de crySound" << std::endl;
        }
    }

    /**
     * @brief Destructeur de la classe `MeleeMonster`.
     */
    ~MeleeMonster() {}

    /**
     * @brief Attaque le personnage cible.
     *
     * @param target Personnage cible de l'attaque
     */
    void attack(Character* target);

    /**
     * @brief Met à jour le sprite du monstre de mêlée.
     */
    virtual void updateSprite();

    /**
     * @brief Met à jour le monstre de mêlée en fonction du joueur.
     *
     * @param pl Pointeur vers le joueur
     */
    virtual void update(Player* pl);
};

#endif
