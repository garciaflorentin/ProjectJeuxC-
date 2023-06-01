#ifndef GAMEGESTION_HPP
#define GAMEGESTION_HPP

#include "ColisionInterface.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "SoundsLib.hpp"


using namespace std;


class GameGestion : public ColisionInterface {
    private:
        vector<Player*> _playerVector; /**< Vecteur de pointeurs vers les joueurs */
        Player _player; /**< Pointeur vers le joueur */
        Player _player2; /**< Pointeur vers le deuxième joueur */

        sf::Clock _time; /**< Horloge utilisée pour la gestion du temps */

        Map& _map; /**< Pointeur vers la carte du jeu */

        sf::Music* _ForestMusic; /**< Musique de la forêt */
        sf::Music* _TownMusic; /**< Musique de la ville */
        sf::Music* _MountainMusic; /**< Musique de la montagne */
        sf::Music* _BeachMusic; /**< Musique de la plage */
        vector<sf::Music*> _music; /**< Vecteur de pointeurs vers les musiques */
        int _currentZoneMusic; /**< Indice de la musique de la zone actuelle */

    public:
        /**
         * @brief Constructeur par défaut de GameGestion.
         */
        GameGestion();

        GameGestion& operator=(const GameGestion& other);

        /**
         * @brief Destructeur de GameGestion.
         */
        ~GameGestion();

        /**
         * @brief Enumération des orientations possibles des joueurs.
         */
        enum Orientation { Down, Left, Right, Up };

        // Gestion des joueurs

        /**
         * @brief Définit le joueur principal.
         * @param player Pointeur vers le sprite du joueur.
         */
        void setPlayer(sf::Sprite& player);

        /**
         * @brief Gère les événements clavier.
         * @param e Événement SFML associé à une touche clavier pressée.
         */
        void keyEvent(sf::Event e);

        /**
         * @brief Récupère le vecteur de pointeurs vers les joueurs.
         * @return Vecteur de pointeurs vers les joueurs.
         */
        const std::vector<Player*>& getPlayerVector() const;

        // Mise à jour du jeu

        /**
         * @brief Met à jour le jeu.
         * @return Résultat de la mise à jour du jeu.
         */
        int updateGame();

        std::vector<Object*>& toDrawUpdate(std::vector<sf::Vector2f>& currentWindow);
        const bool drawProjectile1(std::vector<sf::Vector2f>& currentWindow);
        const bool drawProjectile2(std::vector<sf::Vector2f>& currentWindow);
        const bool drawFireballs(std::vector<sf::Vector2f>& currentWindow,  std::vector<Projectile*>& toFill);

        /**
         * @brief Met à jour les monstres et les autres objets mobiles.
         */
        void updateMobs();

        void updateFireballs(std::vector<Projectile*>& fireballs, int curr_ind, std::vector<Object*>& wallList);

        // Collision

        /**
         * @brief Visiteurs de collision entre le joueur et un objet.
         * @param player Pointeur vers l'objet joueur.
         * @param o Pointeur vers l'objet à tester pour la collision.
         */
        void collideVisitor(Object& player, Object& o);

        /**
         * @brief Gère la collision avec les murs.
         */
        void collideWallGestion();

        /**
         * @brief Gère la collision avec les projectiles.
         */
        void collideProjectileGestion();

        /**
         * @brief Gère la collision avec les monstres.
         */
        void collideMonsterGestion();

        /**
         * @brief Détermine la position de collision entre deux objets.
         * @param object1 Pointeur vers le premier objet.
         * @param object2 Pointeur vers le deuxième objet.
         * @return Résultat de la collision entre les deux objets.
         */
        int collidePosition(Object& object1, Object& object2);

        /**
         * @brief Gère la collision avec les murs.
         * @param o Pointeur vers l'objet à tester pour la collision.
         * @param wallList Liste des objets murs.
         * @param info Informations sur la collision.
         */
        void collideWall(Object& o, std::vector<Object*>& wallList, std::vector<int>& info);

        /**
         * @brief Gère la collision avec les monstres.
         * @param o Pointeur vers l'objet à tester pour la collision.
         * @param wallList Liste des objets monstres.
         * @param info Informations sur la collision.
         */
        void collideMonster(Object& o, std::vector<Monster*>& wallList, std::vector<int>& info);

    /**
         * @brief Gère la collision avec les Joueurs.
         * @param o Pointeur vers l'objet à tester pour la collision.
         * @param p Joueur en question.
         * @param info Informations sur la collision.
         */
        void collidePlayer(Object& o, Player& p, std::vector<int>& info);

        // Limites de la carte

        /**
         * @brief Gère les limites de la carte.
         */
        void LimitMap();

        /**
         * @brief Gère les limites de la carte du boss.
         */
        void LimitMapBoss();

        // Gestion de la musique

        /**
         * @brief Gère la musique du jeu.
         */
        void musicGestion();

        /**
         * @brief Vérifie la vie des monstres et contrôle la musique.
         * @param control Vecteur de contrôle des monstres.
         */
        void checkLifeMonster(std::vector<bool>& control);

        /**
         * @brief Applique un fondu sur la musique.
         * @param music Pointeur vers la musique à appliquer le fondu.
         */
        void musicFade(sf::Music* music);

        // Autres méthodes

        /**
         * @brief Récupère la carte du jeu.
         * @return Pointeur vers la carte du jeu.
         */
        Map& getMap() const;

        /**
         * @brief Récupère la taille de l'objet.
         * @return Taille de l'objet.
         */
        const int getObjectSize() const;
};


#endif