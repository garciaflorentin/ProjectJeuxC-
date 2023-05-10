#include "Map.hpp"

Map::Map() {

toDraw = new std::vector<Object*>;
_map = new std::vector<Object*>;
for(int i= 0; i<1000 ;i++){
	_map->push_back(nullptr);
}


}

Map::~Map() {
	delete toDraw;
	delete _map;

}

Object* Map::getObject(sf::Vector2f pos){

	
	for (auto it = _map->begin(); it != _map->end(); ++it) {

		// V�rifier si le pointeur n'est pas nul
		if (*it) {

			// Acc�der � l'objet point�
			Object* obj = *it;

			if (obj->getPosition().x == pos.x && obj->getPosition().y == pos.y) {
				return obj;
			}

		}
	}

	return nullptr;	//faut bien retourner quelque chose s'il y a un type de retour 
}

void Map::objectToDraw(std::vector<sf::Vector2i> currentWindow) {	//retourne rien, modifie un attribut

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
	delete (*_map)[i]; // supprimer l'objet point�
	(*_map)[i] = nullptr; // définir le pointeur � null
	_map->erase(_map->begin() + i); // enlever l'�l�ment du vecteur

}

void Map::createMap(){

	addObject(new Ground("World.png", {100,100}, TypeGround::grass) );
	addObject(new Ground("World.png", {200,200}, TypeGround::ice) );

	

}