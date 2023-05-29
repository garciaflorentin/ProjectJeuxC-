#ifndef DEMONDOG_MONSTER_HPP
#define DEMONDOG_MONSTER_HPP

#include "MeleeMonster.hpp"


class DemonDogMonster : public MeleeMonster {
        
public:
    /**
     * @brief Constructeur de la classe `DemonDogMonster`.
     *
     * @param nameObject Nom de l'objet
     * @param initPos Position initiale
     * @param name Nom du monstre
     * @param dmg Dommages du monstre
     * @param ar Rayon d'attaque du monstre
     * @param vf Valeur de vie du monstre
     * @param speed Vitesse du monstre
     */
    DemonDogMonster(const char* nameObject, sf::Vector2f initPos, string name = "meat", int dmg = 3, int ar = 2, int vf = 100, float speed = 1) : MeleeMonster(nameObject, initPos, name, dmg, ar, vf, speed) {
        anim->x = 0;
        anim->y = 0;
        _sprite->scale(1, 1);
        //_attack_radius=ar*96;
        updateSprite();
        if (!footStepSound.openFromFile("/home/garcia/Bureau/ProjetC++  (travail)  (copie)/ProjectJeuxC-/GameSFX/FootStep/bigMonsterStep.wav")) {
            std::cout << "erreur de chargement de footStepSound" << std::endl;
        }
        if (!takeDamageMusic.openFromFile("die_monster.wav")) {
            std::cout << "erreur de chargement de takeDamageMusic" << std::endl;
        }
        if (!crySound.openFromFile("roar3_monster.wav")) {
            std::cout << "erreur de chargement de crySound" << std::endl;
        }
    }

    /**
     * @brief Destructeur de la classe `DemonDogMonster`.
     */
    ~DemonDogMonster() {};

    /**
     * @brief Met à jour le sprite du monstre.
     */
    void updateSprite() {
        if (anim->x * 96 >= 96 * 3) {
            anim->x = 0;
        }
        _sprite->setTextureRect(sf::IntRect(anim->x * 96, anim->y * 48, 96, 48));
    }

    /**
     * @brief Met à jour le monstre.
     *
     * @param pl Joueur
     */
    void update(Player* pl) {
        //cout << "Updating monster" << endl;
        this->_player = pl;

        if (playerSeen() && !playerInRange()) {
            goToPlayer();
        }
        if (_upd.getElapsedTime().asMilliseconds() % 20 == 0) {
            //cout << "Attack cooldown" << endl;
            if (playerInRange()) {
                attack(pl);
            }
        }
    }
};

#endif
