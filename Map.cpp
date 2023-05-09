#include "Map.hpp"

Map::Map() {

	map<int, std::vector<Tile*>>* _tiles = new map<int, std::vector<Tile*>>();

	/*// Initialisez _tiles avec des vecteurs vides pour chaque clé.
	for (int i = 0; i < 10; i++) {
		(*_tiles)[i] = std::vector<Tile*>();
	}*/
	map<int, std::vector<Player*>>* _player = new map<int, std::vector<Player*>>();
	map<int, std::vector<Chest*>>* _chests = new map<int, std::vector<Chest*>>();
	map<sf::Texture*, sf::Vector2i>* toDraw = new map<sf::Texture*, sf::Vector2i>();
	std::vector<Object*>* _map = new std::vector<Object*>();

}

Map::~Map() {
	delete _tiles;
	delete _player;
	delete _chests;
	delete toDraw;
	delete _map;

}