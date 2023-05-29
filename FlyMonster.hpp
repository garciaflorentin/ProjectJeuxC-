#ifndef FLY_MONSTER_HPP
#define FLY_MONSTER_HPP

#include "Monster.hpp"
#include "MeleeMonster.hpp"

class FlyMonster : public MeleeMonster {

private:

    /**
     * @brief Déplace le monstre vers le joueur.
     */
    virtual void goToPlayer();

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
    FlyMonster(const char* nameObject, sf::Vector2f initPos, string name = "FlyMonster", int dmg = 3, int ar = 2, int vf = 100, float speed = 1.5) : MeleeMonster(nameObject, initPos, name, dmg, ar, vf, speed) {
        anim->x = 12;
        anim->y = 34;
        OBJECT_SIZE = 48;
        updateSprite();
        if (!footStepSound.openFromFile("wingSound.wav")) {
            std::cout << "Erreur de chargement de footStepSound" << std::endl;
        }
        if (!takeDamageMusic.openFromFile("die_monster.wav")) {
            std::cout << "Erreur de chargement de takeDamageMusic" << std::endl;
        }
        if (!crySound.openFromFile("hurt3_monster.wav")) {
            std::cout << "Erreur de chargement de crySound" << std::endl;
        }
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
    virtual void update(Player* pl);
};

#endif
