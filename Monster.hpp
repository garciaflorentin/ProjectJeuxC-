#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <math.h>

#include "Player.hpp"

#define SPR_SIZE 48


class Player;


/**
 * @brief Cette classe represente un monstre
 * 
 */
class Monster : public Character {
    protected:
        static int _serial; /**< Compteur de sérialisation des monstres */

        sf::Music* _crySound; /**< Son de cri du monstre */

        int _this_serial; /**< Numéro de sérialisation du monstre */
        bool _isAttacking; /**< Indique si le monstre est en train d'attaquer */
        
        float _attack_radius; /**< Rayon d'attaque du monstre */
        float _vision_field; /**< Champ de vision du monstre */

        int _attack_cooldown = 20;  ///< Limite du temps entre les deux attaques

        /**
         * @brief Deplace le monstre vers la cible
         * 
         * @param target La cible
         */
        virtual void goToPlayer(Player& target);

        /**
         * @brief Verifie si le joueur est visible
         * 
         * @param p1 Premier joueur de la carte
         * @param p2 Deuxieme joueur de la carte
         * @param dist1 Distance entre le monstre et le premier joueur
         * @param dist2 Distance entre le monstre et le deuxieme joueur
         * @return true - Le joueur est vu
         * @return false - Le joueur n'est pas vu
         */
        bool playerSeen(Player& p1, Player& p2, float* dist1, float* dist2) const;

        /**
         * @brief Verifie si le joueur est atteignable 
         * 
         * @param target La cible
         * @return true - Le joueur est atteignable
         * @return false - Le joueur est hors portee
         */
        bool playerInRange(Player& target) const;

        /**
         * @brief Applique les dégâts au personnage cible.
         *
         * @param target Personnage cible
         */
        void makeDamage(Character& target) {};

        sf::Clock _upd; /**< Horloge pour la mise à jour du monstre */

        bool _canOpenChest = false; /**< Indique si le monstre peut ouvrir un coffre */

    public:
        /**
         * @brief Constructeur de la classe `Monster`.
         *
         * @param nameObject Nom de l'objet
         * @param initPos Position initiale du monstre
         * @param name Nom du monstre
         * @param dmg Dommages infligés par le monstre
         * @param ar Rayon d'attaque du monstre
         * @param vf Champ de vision du monstre
         * @param speed Vitesse du monstre
         */
        Monster(string nameObject, sf::Vector2f initPos, string name = "meat", int dmg = 1, int ar = 3, int vf = 5, float speed = 1);

        /**
         * @brief Destructeur de la classe `Monster`.
         */
        ~Monster();

        /**
         * @brief Effectue une attaque sur le personnage cible.
         *
         * @param target Personnage cible
         */
        virtual void attack(Player& target);

        /**
         * @brief Met a jour le joueur
         * 
         * @param target1 Premier joueur de la carte
         * @param target2 Deuxieme joueur de la carte
         */
        virtual void update(Player& target1, Player& target2);

        /**
         * @brief Gère la collision du monstre avec un objet.
         *
         * @param o Objet avec lequel le monstre est en collision
         */
        virtual void collide(Object& o);

        /**
         * @brief Ouvre un coffre.
         *
         * @param chest Coffre à ouvrir
         */
        void openChest(Chest& chest);

        /**
         * @brief Met à jour le sprite du monstre.
         */
        virtual void updateSprite();

        /**
         * @brief Calcule la durée de vie du monstre en secondes.
         *
         * @return Durée de vie du monstre en secondes
         */
        float lifetime_secs();

        /**
         * @brief Obtient le numéro de sérialisation du monstre.
         *
         * @return Numéro de sérialisation du monstre
         */
        int getSerial();

        /**
         * @brief Getteur des projectiles eventuelles
         * 
         * @return NULL - fonction pour les monstres qui savent tirer
         */
        virtual Projectile* getProjectile() { return nullptr; }

        /**
         * @brief Getteur du tableau projectiles eventuel
         * 
         * @return NULL - fonction pour les monstres qui savent tirer
         */
        virtual std::vector<Projectile*>* getProjectiles() { return nullptr; };
};


#endif