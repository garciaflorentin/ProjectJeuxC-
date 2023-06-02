#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Audio.hpp>

#include "Object.hpp"
#include "EnumOrientation.hpp"
#include "Heart.hpp"
#include "Chest.hpp"

#define DEFAULT_DMG 1
#define DEFAULT_SPEED 4

class Chest;


class Character : public Object {
    protected:
        int _damageAttack; /**< Dégâts de l'attaque du personnage */
        float _speed; /**< Vitesse de déplacement du personnage */
        EnumOrientation _enumOrientation; /**< Orientation du personnage */
        enum Orientation { Up, Left, Down, Right }; /**< Enumération des orientations possibles */
        bool _isAlive; /**< Indique si le personnage est en vie */
        int _object_size; /**< Taille de l'objet */
        int _orientation; /**< Orientation actuelle du personnage */
        int _keys; /**< Nombre de clés possédées par le personnage */
        vector<bool> _killedallMobs = { false, false, false, false }; /**< Tableau indiquant si tous les monstres ont été tués */
        sf::Music* _footStepSound; /**< Son des pas du personnage */
        sf::Music* _takeDamageMusic; /**< Son de dégâts subis par le personnage */
        sf::Clock _clock; /**< Horloge pour le chronométrage des actions */

        sf::Vector2i _anim; /**< Animation du personnage */
        Heart& _life; /**< Vie du personnage */
        bool _canOpenChest = false; /**< Indique si le personnage peut ouvrir un coffre */


        /**
         * @brief Applique les dégâts au personnage cible.
         *
         * @param target Personnage cible
         */
        virtual void setDamage(Character* target) {};

    public:
        Character() : Object(), _life(*(new Heart())) {};

        /**
         * @brief Constructeur de la classe `Character`.
         *
         * @param nameObject Nom de l'objet
         * @param initPos Position initiale du personnage
         */
        Character(string nameObject, sf::Vector2f initPos);

        Character& operator=(const Character& other);

        /**
         * @brief Destructeur de la classe `Character`.
         */
        virtual ~Character();


        /**
         * @brief Met à jour l'état des monstres tués.
         *
         * @param _killedallMobs Tableau indiquant si tous les monstres ont été tués
         */
        void updateKilledallMobs(std::vector<bool>& _killedallMobs);

        /**
         * @brief Obtient l'état des monstres tués.
         *
         * @return Tableau indiquant si tous les monstres ont été tués
         */
        std::vector<bool>& getKilledallMobs();

        /**
         * @brief Obtient la vitesse de déplacement du personnage.
         *
         * @return Vitesse de déplacement
         */
        const double getSpeed() const;

        /**
         * @brief Définit la vitesse de déplacement du personnage.
         *
         * @param _speed Vitesse de déplacement
         */
        void setSpeed(double _speed);

        /**
         * @brief Déplace le personnage selon le déplacement spécifié.
         *
         * @param deplacement Vecteur de déplacement
         */
        void move(sf::Vector2f deplacement);

        /**
         * @brief Vérifie si le personnage est en vie.
         *
         * @return `true` si le personnage est en vie, `false` sinon
         */
        virtual const bool isAlive() const;

        /**
         * @brief Inflige des dégâts au personnage en fonction du nombre de quarts de vie.
         *
         * @param heartQuarters Nombre de quarts de vie
         */
        virtual void takeDamage(int heartQuarters);

        /**
         * @brief Effectue une attaque sur le personnage cible.
         *
         * @param target Personnage cible
         */
        virtual void attack(Character* target) {};

        /**
         * @brief Obtient l'orientation du personnage.
         *
         * @return Orientation du personnage
         */
        const int getOrientation() const;

        /**
         * @brief Définit l'orientation du personnage.
         *
         * @param _orientation Orientation du personnage
         */
        void setOrientation(int _orientation);

        /**
         * @brief Obtient l'animation du personnage.
         *
         * @return Animation du personnage
         */
        sf::Vector2i& getAnim();

        /**
         * @brief Définit l'animation du personnage.
         *
         * @param i Animation en X
         * @param y Animation en Y
         */
        void setAnim(int i, int y);

        /**
         * @brief Met à jour le sprite du personnage.
         */
        void updateSprite();


        /**
         * @brief initialise le 'Character'.
         */
        void setUpCharacter();


        /**
         * @brief Obtient la vie du personnage.
         *
         * @return Vie du personnage
         */
        Heart& getlife() const;

        /**
         * @brief Obtient la taille de bloc.
         *
         * @return Taille de bloc
         */
        const int getBlockSize() const;

        /**
         * @brief Vérifie si le personnage peut ouvrir un coffre.
         *
         * @return `true` si le personnage peut ouvrir un coffre, `false` sinon
         */
        const bool canOpenChest() const;

        /**
         * @brief Ouvre un coffre donné.
         *
         * @param chest Coffre à ouvrir
         */
        virtual void openChest(Chest& chest) {};

        /**
         * @brief Getteur pour obtenir le projectile du personnage.
         *
         * @return Retourne un pointeur sur le Projectile du personnage.
         */
        virtual Projectile* getProjectile() const { return nullptr; };

        /**
         * @brief Obtient le nombre de clés possédées par le personnage.
         *
         * @return Nombre de clés possédées
         */
        const int getKey() const;

        /**
         * @brief Ajoute une clé au personnage.
         */
        void addKey();

        /**
         * @brief modifie le nombre de clé du personnage.
         * 
         *  @param nbKey Nouveau nombre de clé du personnage.
         */
        void setKey(int nbKey);
};



#endif