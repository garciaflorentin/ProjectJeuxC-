#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cmath>

#include "Character.hpp"
#include "Arrow.hpp"
#include "Monster.hpp"
#include "SoundsLib.hpp"


class Monster;


/**
 * @class Player
 * @brief Classe représentant le joueur du jeu.
 *
 * La classe `Player` hérite de la classe `Character` et implémente les fonctionnalités spécifiques au joueur.
 */
class Player : public Character {
    private:
        sf::Clock _time; /**< Horloge pour le chronométrage des actions du joueur */

        sf::Music* _bowAttack; /**< Son d'attaque à l'arc */
        sf::Music* _wandAttack; /**< Son d'attaque à la baguette */

        int _swordAnim; /**< Animation de l'attaque à l'épée */
        int _bowAnim; /**< Animation de l'attaque à l'arc */
        int _wandAnim; /**< Animation de l'attaque à la baguette */

        bool _isInTheCave; /**< Indique si le joueur est dans la grotte */
        Arrow& _projectile; /**< Projectile du joueur */

        bool _canOpenChest = true; /**< Indique si le joueur peut ouvrir un coffre */
        int _hitAnim;   ///< Numero du sprite a afficher pour animer l'attaque

        static int _keys;   ///< Nombre des cles ramassees

    public:
        /**
         * @brief Constructeur par defaut
         * 
         */
        Player() : Character(), _projectile(*(new Arrow("OtherTextures/arrow.png",{0,0},*this))) {};

        /**
         * @brief Constructeur
         * 
         * @param nameObject Nom de la texture a charger
         * @param initPos Position initiale
         * @param nameProjectile Nom de la texture de la fleche a charger
         */
        Player(string nameObject, sf::Vector2f initPos, string nameProjectile);

        /**
         * @brief Operateur d'assignement
         * 
         * @param other Joueur a assigner
         * @return Player& - Joueur assigne
         */
        Player& operator=(const Player& other);

        /**
         * @brief Destructeur de la classe `Player`.
         */
        ~Player();

        /**
         * @brief Prendre des degats
         * 
         * @param heartQuarters Le degat
         */
        void takeDamage(int heartQuarters);

        /**
         * @brief Getteur de _isAlive
         * 
         * @return true - Le joueur est vivant
         * @return false - Le joueur est mort
         */
        bool isAlive() { 
            //cout << _name << " is alive : " << _isAlive << endl;
            return _isAlive; 
        }

        /**
         * @brief Indique si le joueur est dans la grotte.
         *
         * @param state État du joueur dans la grotte
         */
        void isInTheCave(bool state);

        /**
         * @brief Vérifie si le joueur est dans la grotte.
         *
         * @return `true` si le joueur est dans la grotte, `false` sinon
         */
        bool getIsInTheCave();

        /**
         * @brief Retourne l'etat de l'animation , "joeur est frappé par un monstre"
         *
         * @return Retourne l'etat de l'animation
         */
        int getHitAnim();

    /**
         * @brief Incremente l'etat de l'animation, "joeur est frappé par un monstre"
         *
         */
        void incrHitAnim();

        /**
         * @brief Met l'animation "joeur est frappé par un monstre" à un état precis
         *
         *
         * @param nbAnim etat de l'animation
         */
        void setHitAnim(int nbAnim);

        /**
         * @brief Ouvre un coffre donné.
         *
         * @param chest Coffre à ouvrir
         */
        void openChest(Chest& chest);

        /**
         * @brief Applique les dégâts au personnage cible.
         *
         * @param target Personnage cible
         */
        void makeDamage(Character& target);

        /**
         * @brief Effectue une attaque sur le personnage cible.
         *
         * @param target Personnage cible
         */
        void attack(Character& target);

        /**
         * @brief Gère la collision avec un objet donné.
         *
         * @param o Objet avec lequel le joueur entre en collision
         */
        void collide(Object& o);

        // Partie Weapon

        /**
         * @brief Initialise les armes du joueur.
         */
        void initWeapon();

        /**
         * @brief Vérifie si une arme est utilisée.
         *
         * @return `true` si une arme est utilisée, `false` sinon
         */
        bool WeaponIsUsed();


        /**
         * @brief Utilise l'arc comme arme.
         */
        void useBow();

        /**
         * @brief Utilise la baguette comme arme.
         */
        void useWand();


        /**
         * @brief Vérifie si l'arc est utilisé.
         *
         * @return `true` si l'arc est utilisé, `false` sinon
         */
        bool bowIsUsed();

        /**
         * @brief Vérifie si la baguette est utilisée.
         *
         * @return `true` si la baguette est utilisée, `false` sinon
         */
        bool wandIsUsed();

        /**
         * @brief Obtient le projectile du joueur.
         *
         * @return Projectile du joueur
         */
        Projectile* getProjectile();

        /**
         * @brief Gère la situation de mort du joueur.
         *
         * @return Sprite correspondant à la situation de mort du joueur
         */
        sf::Sprite& deadGestion();

        /**
         * @brief Détermine les cibles dans la portée du joueur.
         *
         * @param targetList Liste des monstres
         * @param indiceToKill Indices des cibles à éliminer
         */
        void targetInRange(std::vector<Monster*>& targetList, std::vector<int> indiceToKill);

        /**
         * @brief Obtient le nombre de clés possédées par le personnage.
         *
         * @return Nombre de clés possédées
         */
        const int getKey() const { return _keys; };

        /**
         * @brief Ajoute une clé au personnage.
         */
        static void addKey() { _keys++; };

        /**
         * @brief modifie le nombre de clé du personnage.
         * 
         *  @param nbKey Nouveau nombre de clé du personnage.
         */
        static void setKey(int nbKey) { _keys = nbKey; };
};


#endif 