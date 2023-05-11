#include "Map.hpp"

Map::Map() {

	_toDraw = new std::vector<Object*>;
	_map = new std::vector<Object*>;
	for(int i= 0; i<1000 ;i++){
		_map->push_back(nullptr);
}


}

Map::~Map() {
	delete[] _toDraw;
	delete[] _map;

}


void Map::putObjectToDraw(sf::Vector2i pos){

	
	for (auto it = _map->begin(); it != _map->end(); ++it) {

		// Vï¿½rifier si le pointeur n'est pas nul
		if (*it) {

			// Accï¿½der ï¿½ l'objet pointï¿½*
			Object* obj = *it;

			if (obj->getPosition().x == pos.x && obj->getPosition().y == pos.y) {
				std::cout<<"toDraw++"<<std::endl;
				_toDraw->push_back(obj);
			}

		}
	}
	
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

std::vector<Object*>* Map::objectToDraw(std::vector<sf::Vector2i> currentWindow) {
	std::cout<<"currentWindow[1].x=="<<currentWindow[1].x<<std::endl;
	std::cout<<"currentWindow[2].x=="<<currentWindow[2].x<<std::endl;
	std::cout<<"currentWindow[1].y=="<<currentWindow[1].y<<std::endl;
	std::cout<<"currentWindow[2].y=="<<currentWindow[2].y<<std::endl;
	_toDraw->clear();

	for (int _x = currentWindow[1].x; _x < currentWindow[2].x; _x=64+_x) {
		for (int _y = currentWindow[1].y; _y < currentWindow[2].y; _y=64+_y) {
			putObjectToDraw(sf::Vector2i(_x, _y));
		}
	}
	std::cout<<"toDraw->size()=="<<_toDraw->size()<<std::endl;
	return _toDraw;


}

void Map::addObject(Object* o) {

	std::cout<<"addObject()"<< std::endl;

	sf::Vector2f pos = o->getPosition();

	if (getObject(pos) != nullptr) {
		removeObject(getObject(pos));
	}
	_map->push_back(o);
}

void Map::removeObject(Object* o) {

	sf::Vector2f pos = o->getPosition();
	int i = 0;
	while ((*_map)[i]->getPosition().x != pos.x && (*_map)[i]->getPosition().y != pos.y) {
		i++;
	}
	delete[] (*_map)[i]; // supprimer l'objet point�
	(*_map)[i] = nullptr; // définir le pointeur � null
	_map->erase(_map->begin() + i); // enlever l'�l�ment du vecteur

}

void Map::createMap(){

	addObject(new Ground("World.png", {100,100}, TypeGround::grass) );
	addObject(new Ground("World.png", {200,200}, TypeGround::ice) );

	

}