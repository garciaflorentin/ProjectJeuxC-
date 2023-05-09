#include "Map.hpp"

Map::Map() {

toDraw = new std::vector<Object*>;
_map = new std::vector<Object*>;


}

Map::~Map() {
	delete toDraw;
	delete _map;

}

Object* Map::getObject(sf::Vector2f pos){

	
	for (auto it = _map->begin(); it != _map->end(); ++it) {

		// Vérifier si le pointeur n'est pas nul
		if (*it) {

			// Accéder à l'objet pointé
			Object* obj = *it;

			if (obj->getPosition().x == pos.x && obj->getPosition().y == pos.y) {
				return obj;
			}

		}
	}

}

const std::vector<Object*>& Map::objectToDraw(std::vector<sf::Vector2i> currentWindow) {

	for (int _x = currentWindow[1].x; _x < currentWindow[2].x; _x+=48) {
		for (int _y = currentWindow[1].y; _y < currentWindow[2].y; _y+=48) {
			toDraw->push_back(getObject(sf::Vector2f(_x, _y)));
		}
	}


}

void Map::addObject(Object* o) {

	sf::Vector2f pos = o->getPosition();

	if (getObject(pos) != nullptr) {

		removeObject(getObject(pos));
		_map->push_back(o);
	}
}

void Map::removeObject(Object* o) {

	sf::Vector2f pos = o->getPosition();
	int i = 0;
	while ((*_map)[i]->getPosition().x != pos.x && (*_map)[i]->getPosition().y != pos.y) {
		i++;
	}
	delete (*_map)[i]; // supprimer l'objet pointé
	(*_map)[i] = nullptr; // définir le pointeur à null
	_map->erase(_map->begin() + i); // enlever l'élément du vecteur

}

void Map::createMap(){


	

}