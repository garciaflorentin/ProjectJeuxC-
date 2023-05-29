#ifndef _GAMEGESTION_HPP_
#define _GAMEGESTION_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Player.hpp"
#include "Map.hpp"
#include "ColisionInterface.hpp"
#include "Character.hpp"
#include "Monster.hpp"
#include "Projectile.hpp"

using namespace std;

/**
 * @class GameGestion
 * @brief Classe principale de gestion du jeu.
 *
 * La classe GameGestion gère le déroulement du jeu, y compris la gestion des joueurs, des collisions,
 * des mises à jour, des limites de la carte et de la musique.
 */
class GameGestion : public ColisionInterface {
/**
 * @class GameGestion
 * @brief Classe principale de gestion du jeu.
 *
 * La classe GameGestion gère le déroulement du jeu, y compris la gestion des joueurs, des collisions,
 * des mises à jour, des limites de la carte et de la musique.
 */
class GameGestion : public ColisionInterface {
private:
    std::vector<Player*>* playerVector; /**< Vecteur de pointeurs vers les joueurs */
    Player* player; /**< Pointeur vers le joueur */
    Player* player2; /**< Pointeur vers le deuxième joueur */
    sf::Clock time; /**< Horloge utilisée pour la gestion du temps */
    Map* _map; /**< Pointeur vers la carte du jeu */
    sf::Music* forestMusic; /**< Musique de la forêt */
    sf::Music* townMusic; /**< Musique de la ville */
    sf::Music* MountainMusic; /**< Musique de la montagne */
    sf::Music* BeatchMusic; /**< Musique de la plage */
    std::vector<sf::Music*> musics; /**< Vecteur de pointeurs vers les musiques */
    int currentZoneMusic; /**< Indice de la musique de la zone actuelle */
    std::vector<Player*>* playerVector; /**< Vecteur de pointeurs vers les joueurs */
    Player* player; /**< Pointeur vers le joueur */
    Player* player2; /**< Pointeur vers le deuxième joueur */
    sf::Clock time; /**< Horloge utilisée pour la gestion du temps */
    Map* _map; /**< Pointeur vers la carte du jeu */
    sf::Music* forestMusic; /**< Musique de la forêt */
    sf::Music* townMusic; /**< Musique de la ville */
    sf::Music* MountainMusic; /**< Musique de la montagne */
    sf::Music* BeatchMusic; /**< Musique de la plage */
    std::vector<sf::Music*> musics; /**< Vecteur de pointeurs vers les musiques */
    int currentZoneMusic; /**< Indice de la musique de la zone actuelle */

public:
    /**
     * @brief Constructeur par défaut de GameGestion.
     */
    GameGestion();
    /**
     * @brief Constructeur par défaut de GameGestion.
     */
    GameGestion();

    /**
     * @brief Destructeur de GameGestion.
     */
    ~GameGestion();
    /**
     * @brief Destructeur de GameGestion.
     */
    ~GameGestion();

    /**
     * @brief Enumération des orientations possibles des joueurs.
     */
    enum Orientation { Down, Left, Right, Up };
    /**
     * @brief Enumération des orientations possibles des joueurs.
     */
    enum Orientation { Down, Left, Right, Up };

    // Gestion des joueurs
    // Gestion des joueurs

    /**
     * @brief Définit le joueur principal.
     * @param player Pointeur vers le sprite du joueur.
     */
    void setPlayer(sf::Sprite* player);
    /**
     * @brief Définit le joueur principal.
     * @param player Pointeur vers le sprite du joueur.
     */
    void setPlayer(sf::Sprite* player);

    /**
     * @brief Gère les événements clavier.
     * @param e Événement SFML associé à une touche clavier pressée.
     */
    void keyEvent(sf::Event e);
    /**
     * @brief Gère les événements clavier.
     * @param e Événement SFML associé à une touche clavier pressée.
     */
    void keyEvent(sf::Event e);

    /**
     * @brief Récupère le vecteur de pointeurs vers les joueurs.
     * @return Vecteur de pointeurs vers les joueurs.
     */
    std::vector<Player*>* getPlayerVector();
    /**
     * @brief Récupère le vecteur de pointeurs vers les joueurs.
     * @return Vecteur de pointeurs vers les joueurs.
     */
    std::vector<Player*>* getPlayerVector();

    // Mise à jour du jeu
    // Mise à jour du jeu

    /**
     * @brief Met à jour le jeu.
     * @return Résultat de la mise à jour du jeu.
     */
    int updateGame();
    /**
     * @brief Met à jour le jeu.
     * @return Résultat de la mise à jour du jeu.
     */
    int updateGame();

    /**
     * @brief Met à jour les objets à dessiner sur l'écran.
     * @param currentWindow Vecteur de positions des objets à dessiner.
     * @return Vecteur de pointeurs vers les objets à dessiner.
     */
    std::vector<Object*>* toDrawUpdate(std::vector<sf::Vector2f>* currentWindow);

    /**
     * @brief Dessine le projectile 1 sur l'écran.
     * @param currentWindow Vecteur de positions des objets à dessiner.
     * @return Booléen indiquant si le projectile a été dessiné.
     */
    bool drawProjectile1(std::vector<sf::Vector2f>* currentWindow);

    /**
     * @brief Dessine le projectile 2 sur l'écran.
     * @param currentWindow Vecteur de positions des objets à dessiner.
     * @return Booléen indiquant si le projectile a été dessiné.
     */
    bool drawProjectile2(std::vector<sf::Vector2f>* currentWindow);
    /**
     * @brief Met à jour les objets à dessiner sur l'écran.
     * @param currentWindow Vecteur de positions des objets à dessiner.
     * @return Vecteur de pointeurs vers les objets à dessiner.
     */
    std::vector<Object*>* toDrawUpdate(std::vector<sf::Vector2f>* currentWindow);

    /**
     * @brief Dessine le projectile 1 sur l'écran.
     * @param currentWindow Vecteur de positions des objets à dessiner.
     * @return Booléen indiquant si le projectile a été dessiné.
     */
	//bool drawProjectile(std::vector<sf::Vector2f>* currentWindow);
	bool drawFireballs(std::vector<sf::Vector2f>* currentWindow,  std::vector<Projectile*>* toFill);
    bool drawProjectile1(std::vector<sf::Vector2f>* currentWindow);

    /**
     * @brief Dessine le projectile 2 sur l'écran.
     * @param currentWindow Vecteur de positions des objets à dessiner.
     * @return Booléen indiquant si le projectile a été dessiné.
     */
    bool drawProjectile2(std::vector<sf::Vector2f>* currentWindow);

    /**
     * @brief Met à jour les monstres et les autres objets mobiles.
     */
    void updateMobs();
    /**
     * @brief Met à jour les monstres et les autres objets mobiles.
     */
    void updateMobs();

    // Collision
    // Collision

    /**
     * @brief Visiteurs de collision entre le joueur et un objet.
     * @param player Pointeur vers l'objet joueur.
     * @param o Pointeur vers l'objet à tester pour la collision.
     */
    void collideVisitor(Object* player, Object* o);
    /**
     * @brief Visiteurs de collision entre le joueur et un objet.
     * @param player Pointeur vers l'objet joueur.
     * @param o Pointeur vers l'objet à tester pour la collision.
     */
    void collideVisitor(Object* player, Object* o);

    /**
     * @brief Gère la collision avec les murs.
     */
    void collideWallGestion();
    /**
     * @brief Gère la collision avec les murs.
     */
    void collideWallGestion();

    /**
     * @brief Gère la collision avec les projectiles.
     */
    void collideProjectileGestion();
    /**
     * @brief Gère la collision avec les projectiles.
     */
    void collideProjectileGestion();

    /**
     * @brief Gère la collision avec les monstres.
     */
    void collideMonsterGestion();
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
    int collidePosition(Object* object1, Object* object2);
    /**
     * @brief Détermine la position de collision entre deux objets.
     * @param object1 Pointeur vers le premier objet.
     * @param object2 Pointeur vers le deuxième objet.
     * @return Résultat de la collision entre les deux objets.
     */
    int collidePosition(Object* object1, Object* object2);

    /**
     * @brief Gère la collision avec les murs.
     * @param o Pointeur vers l'objet à tester pour la collision.
     * @param wallList Liste des objets murs.
     * @param info Informations sur la collision.
     */
    void collideWall(Object* o, std::vector<Object*>& wallList, std::vector<int>& info);

    /**
     * @brief Gère la collision avec les monstres.
     * @param o Pointeur vers l'objet à tester pour la collision.
     * @param wallList Liste des objets monstres.
     * @param info Informations sur la collision.
     */
    void collideMonster(Object* o, std::vector<Monster*>& wallList, std::vector<int>& info);
    /**
     * @brief Gère la collision avec les murs.
     * @param o Pointeur vers l'objet à tester pour la collision.
     * @param wallList Liste des objets murs.
     * @param info Informations sur la collision.
     */
    void collideWall(Object* o, std::vector<Object*>& wallList, std::vector<int>& info);

    /**
     * @brief Gère la collision avec les monstres.
     * @param o Pointeur vers l'objet à tester pour la collision.
     * @param wallList Liste des objets monstres.
     * @param info Informations sur la collision.
     */
    void collideMonster(Object* o, std::vector<Monster*>& wallList, std::vector<int>& info);
void collidePlayer(Object* o, Player*p, std::vector<int>& info);

    // Limites de la carte
    // Limites de la carte

    /**
     * @brief Gère les limites de la carte.
     */
    void LimitMap();

    /**
     * @brief Gère les limites de la carte du boss.
     */
    void LimitMapBoss();
    /**
     * @brief Gère les limites de la carte.
     */
    void LimitMap();

    /**
     * @brief Gère les limites de la carte du boss.
     */
    void LimitMapBoss();

    // Gestion de la musique
    // Gestion de la musique

    /**
     * @brief Gère la musique du jeu.
     */
    void musicGestion();
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
    Map* getMap();

    /**
     * @brief Récupère la taille de l'objet.
     * @return Taille de l'objet.
     */
    const int getObjectSize() const;
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
    Map* getMap();

    /**
     * @brief Récupère la taille de l'objet.
     * @return Taille de l'objet.
     */
    const int getObjectSize() const;
};


#endif
