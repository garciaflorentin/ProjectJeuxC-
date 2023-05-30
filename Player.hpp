#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>
#include <ctime>
#include "Character.hpp"
#include "Chest.hpp"
#include "Projectile.hpp"
#include "Monster.hpp"

class Chest;
class Projectile;
class Monster;

/**
 * @class Player
 * @brief Classe représentant le joueur du jeu.
 *
 * La classe `Player` hérite de la classe `Character` et implémente les fonctionnalités spécifiques au joueur.
 */
class Player : public Character {
private:
    sf::Clock time; /**< Horloge pour le chronométrage des actions du joueur */

    sf::Music* bowAttack; /**< Son d'attaque à l'arc */
    sf::Music* wandAttack; /**< Son d'attaque à la baguette */

    int swordAnim; /**< Animation de l'attaque à l'épée */
    int bowAnim; /**< Animation de l'attaque à l'arc */
    int wandAnim; /**< Animation de l'attaque à la baguette */

    bool _isInTheCave; /**< Indique si le joueur est dans la grotte */
    Projectile* projectile; /**< Projectile du joueur */

    bool _canOpenChest = true; /**< Indique si le joueur peut ouvrir un coffre */
    int hitAnim;

public:
    /**
     * @brief Constructeur de la classe `Player`.
     *
     * @param nameObject Nom de l'objet
     * @param initPos Position initiale du joueur
     */
    Player(const char* nameObject, sf::Vector2f initPos);

    /**
     * @brief Destructeur de la classe `Player`.
     */
    ~Player();

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
    void openChest(Chest* chest);

    /**
     * @brief Applique les dégâts au personnage cible.
     *
     * @param target Personnage cible
     */
    void setDamage(Character* target);

    /**
     * @brief Effectue une attaque sur le personnage cible.
     *
     * @param target Personnage cible
     */
    void attack(Character* target);

    /**
     * @brief Gère la collision avec un objet donné.
     *
     * @param o Objet avec lequel le joueur entre en collision
     */
    void collide(Object* o);

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
    sf::Sprite* deadGestion();

    /**
     * @brief Détermine les cibles dans la portée du joueur.
     *
     * @param targetList Liste des monstres
     * @param indiceToKill Indices des cibles à éliminer
     */
    void targetInRange(std::vector<Monster*>& targetList, std::vector<int> indiceToKill);
};

#endif
