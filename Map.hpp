#ifndef MAP_HPP
#define MAP_HPP

#include "Object.hpp"
#include "Monster.hpp"
#include "Door.hpp"
#include "DoorWall.hpp"
#include "Ground.hpp"
#include "GoldenChest.hpp"
#include "WallZone.hpp"
#include "FinalBoss.hpp"
#include "MeleeMonster.hpp"
#include "DemonDogMonster.hpp"
#include "RangedMonster.hpp"
#include "FlyMonster.hpp"
#include "MiniFrogMonster.hpp"
#include "MiniOgre.hpp"
#include "GuerrierOgre.hpp"


using namespace std;


/**
 * @brief Cette classe represente une carte
 * 
 */
class Map {
    private:
        vector<Object*> _toDraw;                    ///< Les objets qu'il faut dessiner
        vector<Object*> _map;                       ///< Liste des objets sur la carte
        std::vector<Object*> _wallList;             ///< Liste des murs
        std::vector<Monster*> _monsterList;         ///< Liste des monstres
        std::vector<GoldenChest*> _goldChestList;   ///< Liste des coffres contenants une cle

        Door _door;                                 ///< La porte vers le boss final
        DoorWall _doorWall1, _doorWall2, doorWall3; ///< Les portes incrustees dans les murs entre les zones

        float _LIMITE_Xneg = 0, _LIMITE_Y = 4992.f, _LIMITE_X = 9540,_LIMITE_Yneg = -4896.f;    ///< Limites de la carte normale
        float _LIMITE_XnegBoss = 9472.f, _LIMITE_XBoss = 10456.f, _LIMITE_YBoss = 10328.f;      ///< Limites de la zone du boss

        bool _spf = false, _spm = false, _spb = false, _spt = false;    ///< Gerent les apparitions des monstres des diferentes zones

        int _nbDoorWall;    ///< Compte le nombres des portes dans les murs

        sf::Sprite _playerDead; ///< Sprite du joueur mort

        bool _gameWon = false;  ///< Compte la victoire

    public:
        /**
         * @brief Constructeur de la classe `Map`.
         */
        Map();

        /**
         * @brief Operateur d'assignement
         * 
         * @param other Carte a assigner
         * @return Map& - Carte assignee
         */
        Map& operator=(const Map& other);

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
        std::vector<Object*>& objectToDraw(std::vector<sf::Vector2f>& currentWindow);

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
        void removeObject(Object& o);

        /**
         * @brief Crée la carte du jeu.
         */
        void createMap();

        /**
         * @brief Place les objets à afficher sur la carte.
         *
         * @param pos Position des objets à afficher
         */
        void putObjectToDraw(std::vector<sf::Vector2f>& pos);

        /**
         * @brief Obtient la carte du jeu.
         *
         * @return Vecteur contenant les objets de la carte
         */
        std::vector<Object*>& getMap();

        /**
         * @brief Obtient la liste des murs de la carte.
         *
         * @return Vecteur contenant les murs de la carte
         */
        std::vector<Object*>& getWallList();

        /**
         * @brief Obtient la liste des monstres présents sur la carte.
         *
         * @return Vecteur contenant les monstres présents sur la carte
         */
        std::vector<Monster*>& getMonsters();

        /**
         * @brief Met a jour la carte
         * 
         * @param player1 Premier joueur 
         * @param player2 Deuxieme joueur
         */
        void updateObjects(Player& player1, Player& player2);

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

        /**
         * @brief Getteur de _goldChestList
         * 
         * @return vector<GoldenChest*>& Liste des coffres a cle
         */
        vector<GoldenChest*>& getGoldenChestList() { 
            //cout << "there are " << _goldChestList.size() << " golden chests" << endl;
            return _goldChestList; 
        }

        /**
         * @brief Getteur de _gameWon
         * 
         * @return true - Victoire
         * @return false - Pas de victoire - pour l'instant
         */
        const bool gameWon() const { return _gameWon; };
};


#endif
