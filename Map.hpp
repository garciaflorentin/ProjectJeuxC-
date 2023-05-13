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


class Map {

private:

	std::vector<Object*>* toDraw;
	std::vector<Object*>* _map;
	int LIMITE_Xneg= 0;
	int LIMITE_Y=14400;
	int LIMITE_X= 14400;
	int LIMITE_Yneg=-14400;



public:

	Map();
	~Map();

	void getLimitMap(std::vector<int>& limit){
		limit={LIMITE_X,LIMITE_Y,LIMITE_Xneg,LIMITE_Yneg};
	}

	std::vector<Object*>* objectToDraw(std::vector<sf::Vector2f>* currentWindow);

	void addObject(Object* o);
	void removeObject(Object* o);
	
	void createMap();

	void putObjectToDraw(sf::Vector2f pos);
	void putObjectToDraw2(std::vector<sf::Vector2f>* pos);
	Object* getObject(sf::Vector2f pos);


	std::vector<Object*>* getMap() {
		return _map;
	}


	
};
#endif
