#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Player.hpp"
#include "Gain.hpp"
#include "TexturesLib.hpp"
#include "Tile.hpp"
#include "Object.hpp"
#include "Character.hpp"
#include "Chest.hpp"
#include "Ground.hpp"
#include "TypeGround.hpp"
#include "Wall.hpp"
#include "TypeWall.hpp"
#include "Projectile.hpp"
#include "MeleeMonster.hpp"
#include "GoldenChest.hpp"
#include "Door.hpp"
#include "RangedMonster.hpp" 
#include "DemonDogMonster.hpp"

#include "FinalBoss.hpp"

#include "MiniOgre.hpp"
#include "GuerrierOgre.hpp"
#include "FlyMonster.hpp"
#include "MiniFrogMonster.hpp"
#include "DoorWall.hpp"
#include "WallZone.hpp"


#define SPAWN_FREQUENCY 600

using namespace std;

/**
 * @class Map
 * @brief Classe représentant la carte du jeu.
 *
 * La classe `Map` gère la création, la mise à jour et l'affichage de la carte du jeu.
 */
class Map {
private:
    std::vector<Object*>* toDraw;
    std::vector<Object*>* _map;
    std::vector<Object*>* _wallList;
    std::vector<Monster*>* _monsterList;
    Door* door;
    DoorWall* doorWall1;
    DoorWall* doorWall2;
    DoorWall* doorWall3;

    float LIMITE_Xneg = 0;
    float LIMITE_Y = 4992.f;
    float LIMITE_X = 9540;
    float LIMITE_Yneg = -4896.f;
    float LIMITE_XnegBoss = 9472.f;
    float LIMITE_YnegBoss = 9600.f;
    float LIMITE_XBoss = 10456.f;
    float LIMITE_YBoss = 10328.f;
    bool _spf = false;
    bool _spm = false;
    bool _spb = false;
    bool _spt = false;
    int nbDoorWall;
    sf::Sprite* playerDead;

public:
    /**
     * @brief Constructeur de la classe `Map`.
     */
    Map();

    /**
     * @brief Destructeur de la classe `Map`.
     */
    ~Map();

    /**
     * @brief Récupère les limites de la carte.
     *
     * @param limit Vecteur dans lequel stocker les limites de la carte (limites horizontales et verticales)
     */
    void getLimitMap(std::vector<float>& limit);

    /**
     * @brief Récupère les limites de la carte du boss.
     *
     * @param limit Vecteur dans lequel stocker les limites de la carte du boss (limites horizontales et verticales)
     */
    void getLimitMapBoss(std::vector<float>& limit);

    /**
     * @brief Récupère les objets à afficher sur la carte.
     *
     * @param currentWindow Fenêtre actuelle du jeu
     * @return Vecteur contenant les objets à afficher sur la carte
     */
    std::vector<Object*>* objectToDraw(std::vector<sf::Vector2f>* currentWindow);

    /**
     * @brief Ajoute un objet à la carte.
     *
     * @param w Objet mur à ajouter
     */
    void addObject(Wall* w);

    /**
     * @brief Ajoute un objet à la carte.
     *
     * @param c Objet coffre à ajouter
     */
    void addObject(Chest* c);

    /**
     * @brief Ajoute un objet à la carte.
     *
     * @param g Objet sol à ajouter
     */
    void addObject(Ground* g);

    /**
     * @brief Ajoute un monstre à la carte.
     *
     * @param m Monstre à ajouter
     */
    void addObject(Monster* m);

void addObject(Projectile* p);

    /**
     * @brief Supprime un objet de la carte.
     *
     * @param o Objet à supprimer
     */
    void removeObject(Object* o);

    /**
     * @brief Crée la carte du jeu.
     */
    void createMap();

    /**
     * @brief Place les objets à afficher sur la carte.
     *
     * @param pos Position des objets à afficher
     */
    void putObjectToDraw(std::vector<sf::Vector2f>* pos);

    /**
     * @brief Obtient la carte du jeu.
     *
     * @return Vecteur contenant les objets de la carte
     */
    std::vector<Object*>* getMap();

    /**
     * @brief Obtient la liste des murs de la carte.
     *
     * @return Vecteur contenant les murs de la carte
     */
    std::vector<Object*>* getWallList();

    /**
     * @brief Obtient la liste des monstres présents sur la carte.
     *
     * @return Vecteur contenant les monstres présents sur la carte
     */
    std::vector<Monster*>* getMonsters();

    /**
     * @brief Met à jour les objets de la carte en fonction du joueur.
     *
     * @param player Pointeur vers le joueur
     */
    void updateObjects(Player* player);

    /**
     * @brief Met à jour les animations des objets de la carte.
     */
    void updateAnimateObject();

    /**
     * @brief Fait apparaître des monstres sur la carte dans une zone spécifique.
     *
     * @param area Zone d'apparition des monstres
     */
    void spawnMobs(string area);

    /**
     * @brief Ajoute le sprite du joueur mort.
     *
     * @param sprite Sprite du joueur mort
     */
    void addPlayerDead(sf::Sprite* sprite);

    /**
     * @brief Obtient le sprite du joueur mort.
     *
     * @return Sprite du joueur mort
     */
    sf::Sprite* getPlayerDead();
};

#endif
