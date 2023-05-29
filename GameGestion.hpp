#ifndef _GAMEGESTION_HPP_
#define _GAMEGESTION_HPP_

/// Special library
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
/// STL
#include <iostream>
#include <vector>
#include <string>

/// Header create
#include "Player.hpp"
//#include "Object.hpp"
#include "Map.hpp"
#include "ColisionInterface.hpp"
#include "Character.hpp"
#include "Monster.hpp"
#include "Projectile.hpp"

using namespace std;

class GameGestion : public ColisionInterface{
private:

	std::vector< Player*>* playerVector;
	Player* player;
	Player* player2;
	sf::Clock time;
	Map* _map;
	sf::Music* forestMusic;
	sf::Music townMusic;
	sf::Music MountainMusic;
	sf::Music BeatchMusic;


public:

	GameGestion();

	~GameGestion();

	enum Orientation { Down, Left, Right, Up };

	Map* getMap(){
		return _map;
	}

	const int getObjectSize() const {
		return player->getBlockSize();
	}

	std::vector< Player*>* getPlayerVector() {
		return playerVector;
	}


	void setPlayer(sf::Sprite* player); // ajoute un joeur au jeu

	void keyEvent(sf::Event e);//focntion interaction 

	std::vector<Object*>* toDrawUpdate(std::vector<sf::Vector2f>* currentWindow);
	//bool drawProjectile(std::vector<sf::Vector2f>* currentWindow);
	bool drawFireballs(std::vector<sf::Vector2f>* currentWindow,  std::vector<Projectile*>* toFill);
	bool drawProjectile1(std::vector<sf::Vector2f>* currentWindow);
	bool drawProjectile2(std::vector<sf::Vector2f>* currentWindow);


	int updateGame();

//interface colision

	void collideVisitor(Object* player,Object * o);



void collideWallGestion();

void collideProjectileGestion();

void collideMonsterGestion();

int collidePosition(Object* object1, Object* object2);

void collideWall(Object* o, std::vector <Object*>& wallList,std::vector<int>& info) ;
void collideMonster(Object* o, std::vector <Monster*>& wallList,std::vector<int>& info);
void collidePlayer(Object* o, Player*p, std::vector<int>& info);


	void LimitMap();
	void LimitMapBoss();




	//mise a jour des monstres (et autres objets qui bougent eventuellement)
	void updateMobs();


//musique gestion

void musicGestion();

void checkLifeMonster(std::vector<bool>& control);

};
#endif
