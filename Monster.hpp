#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <math.h>

#include "Player.hpp"

#define SPR_SIZE 48


class Player;


class Monster : public Character {
    protected:
        // Player& _player1; /**< Pointeur vers le joueur */
        // Player& _player2;

        static int _serial; /**< Compteur de sérialisation des monstres */

        sf::Music* _crySound; /**< Son de cri du monstre */

        int _this_serial; /**< Numéro de sérialisation du monstre */
        bool _isAttacking; /**< Indique si le monstre est en train d'attaquer */
        
        float _attack_radius; /**< Rayon d'attaque du monstre */
        float _vision_field; /**< Champ de vision du monstre */

        int _attack_cooldown = 50;

        //sf::Music _crySound; /**< Son de cri du monstre */

        /**
         * @brief Détermine le comportement du monstre pour se déplacer vers le joueur.
         */
        virtual void goToPlayer(Player& target);

        /**
         * @brief Vérifie si le joueur est visible par le monstre.
         *
         * @return `true` si le joueur est visible, `false` sinon
         */
        bool playerSeen(Player& p1, Player& p2, float* dist1, float* dist2) const;

        /**
         * @brief Vérifie si le joueur est à portée d'attaque du monstre.
         *
         * @return `true` si le joueur est à portée d'attaque, `false` sinon
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
        Monster(string nameObject, sf::Vector2f initPos, /*Player& player1, Player& player2,*/ string name = "meat", int dmg = 1, int ar = 3, int vf = 5, float speed = 1);

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
         * @brief Met à jour le monstre en fonction du joueur.
         *
         * @param pl Pointeur vers le joueur
         */
        virtual void update(Player& target1, Player& target2);

        /**
         * @brief Gère la collision du monstre avec un objet.
         *
         * @param o Objet avec lequel le monstre est en collision
         */
        void collide(Object& o);

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

        virtual Projectile* getProjectile() { return nullptr; }
        virtual std::vector<Projectile*>* getProjectiles() { return nullptr; };
};


#endif