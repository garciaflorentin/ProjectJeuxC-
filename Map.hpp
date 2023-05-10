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

class Map {

private:

	std::vector<Object*>* toDraw;
	std::vector<Object*>* _map;


public:

	Map();
	~Map();

	void objectToDraw(std::vector<sf::Vector2i> currentWindow);	//retourne rien

	void addObject(Object* o);
	void removeObject(Object* o);
	
	void createMap();

	Object* getObject(sf::Vector2f pos);

	std::vector<Object*>* getMap() {
		return _map;
	}


	
};
#endif
/* {

		//
		for (int i = 0; i < _tiles->size(); i++) {
			for (int a = 0; a < _tiles[i].size(); a++) {
				//check si la tile est dans la currentWindow ou non
				if ((_tiles.)[i][a]->getPosition().x >= currentWindow[1].x || _tiles[i][a]->getPosition().x <= currentWindow[2].x) && (_tiles[i][a]->getPosition().y >= currentWindow[1].y || _tiles[i][a]->getPosition().y <= currentWindow[2].y)) {
					// si oui
					sf::Texture* t = TexturesLib::findTexture(i, 1);
					toDraw->insert(std::make_pair(t, sf::Vector2i(_tiles[i][a]->getPosition().x, _tiles[i][a]->getPosition().y)));



				}
			}
		}
		/*
		for (int i = 0; i < _tiles.size(); i++) {
			for (int a = 0; a < _tiles[i].size(); a++) {
				//check si la tile est dans la currentWindow ou non
				if ((_tiles[i][a]->getPosition().x >= currentWindow[1].x || _tiles[i][a]->getPosition().x <= currentWindow[2].x) && (_tiles[i][a]->getPosition().y >= currentWindow[1].y || _tiles[i][a]->getPosition().y <= currentWindow[2].y)) {
					// si oui
					toDraw->insert(std::make_pair(TexturesLib::findTexture(i, 1), new sf::Vector2i(_tiles[i][a]->getPosition().x, _tiles[i][a]->getPosition().y)));



				}
			}
		}
	}*/
	/*
		for (int i = 0; i < _chests.size(); i++) {
			for (int a = 0; a < _chests[i].size(); a++) {
				//check si la tile est dans la currentWindow ou non
				if ((_chests[i][a]->getPosition().x >= currentWindow[1].x || _chests[i][a]->getPosition().x <= currentWindow[2].x) && (_chests[i][a]->getPosition().y >= currentWindow[1].y || _chests
					[i][a]->getPosition().y <= currentWindow[2].y)) {
					// si oui
					sf::Texture* t = TexturesLib::findTexture(i, 3);
					toDraw->insert(std::make_pair(t, sf::Vector2i(_chests[i][a]->getPosition().x, _chests[i][a]->getPosition().y)));




				}
			}
		}

		return toDraw;
	}
	*/
