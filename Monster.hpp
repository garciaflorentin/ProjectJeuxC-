#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "Character.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
class Player;


#define SPR_SIZE 48

/**
 * @class Monster
 * @brief Classe représentant un monstre du jeu.
 *
 * La classe `Monster` hérite de la classe `Character` et implémente les fonctionnalités spécifiques à un monstre.
 */
class Monster : public Character {
protected:
    static Player* _player; /**< Pointeur vers le joueur */

    static int _serial; /**< Compteur de sérialisation des monstres */

    int _this_serial; /**< Numéro de sérialisation du monstre */
    bool isAttacking; /**< Indique si le monstre est en train d'attaquer */
    int _damage; /**< Dommages infligés par le monstre */
    float _attack_radius; /**< Rayon d'attaque du monstre */
    float _vision_field; /**< Champ de vision du monstre */
    float speed; /**< Vitesse du monstre */
    sf::Music crySound; /**< Son de cri du monstre */

    /**
     * @brief Détermine le comportement du monstre pour se déplacer vers le joueur.
     */
    virtual void goToPlayer();

    /**
     * @brief Vérifie si le joueur est visible par le monstre.
     *
     * @return `true` si le joueur est visible, `false` sinon
     */
    bool playerSeen() const;

    /**
     * @brief Vérifie si le joueur est à portée d'attaque du monstre.
     *
     * @return `true` si le joueur est à portée d'attaque, `false` sinon
     */
    bool playerInRange() const;

    /**
     * @brief Applique les dégâts au personnage cible.
     *
     * @param target Personnage cible
     */
    void setDamage(Character* target);

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
    Monster(const char* nameObject, sf::Vector2f initPos, string name = "meat", int dmg = 1, int ar = 2, int vf = 5, float speed = 1);

    /**
     * @brief Destructeur de la classe `Monster`.
     */
    ~Monster();

    /**
     * @brief Effectue une attaque sur le personnage cible.
     *
     * @param target Personnage cible
     */
    virtual void attack(Character* target);

    /**
     * @brief Déplace le monstre selon un vecteur donné.
     *
     * @param deplacement Vecteur de déplacement
     */
    void move(sf::Vector2f deplacement);

    /**
     * @brief Met à jour le monstre en fonction du joueur.
     *
     * @param pl Pointeur vers le joueur
     */
    virtual void update(Player* pl);

    /**
     * @brief Gère la collision du monstre avec un objet.
     *
     * @param o Objet avec lequel le monstre est en collision
     */
    void collide(Object* o);

    /**
     * @brief Ouvre un coffre.
     *
     * @param chest Coffre à ouvrir
     */
    void openChest(Chest* chest);

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

        static int _serial;

        int _this_serial;
        bool isAttacking;
        int _damage;
        float _attack_radius;
        float _vision_field;
        float speed;

        //void hitPlayer(Character& target);
        void goToPlayer();
        bool playerSeen() const;
        virtual bool playerInRange()const;

        //std::vector<Object*>* _map;

        void setDamage(Character* target) {};

        sf::Clock _upd;

        bool _canOpenChest = false;

    public :
        Monster(const char* nameObject, sf::Vector2f initPos, string name="meat", int dmg=1, int ar=2, int vf=5, float speed=1);
        ~Monster();
        
        virtual void attack(Character* target);
        void move(sf::Vector2f deplacement);
        
        virtual void update(Player* pl);      

        void collide(Object* o);

        void openChest(Chest* chest) {};

        virtual void updateSprite(){;

}
        float lifetime_secs() { return _upd.getElapsedTime().asSeconds(); };

        int getSerial() { return _this_serial; };

        virtual Projectile* getProjectile() { return nullptr; }
        virtual std::vector<Projectile*>* getProjectiles() { return nullptr; };

};

#endif
