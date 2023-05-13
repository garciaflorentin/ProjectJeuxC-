#include "Map.hpp"

Map::Map() {
toDraw = new std::vector<Object*>;
_map = new std::vector<Object*>(10);
for(int i= 0; i<10 ;i++){
	_map->push_back(nullptr);
}


}

Map::~Map() {
	delete toDraw;
	delete _map;

}

void Map::putObjectToDraw(sf::Vector2f pos){

	
	for (auto it = _map->begin(); it != _map->end(); ++it) {
		

		// V�rifier si le pointeur n'est pas nul
		if (*it) {

			// Acc�der � l'objet point�*
			Object* obj = *it;
			/*std::cout<<"obj->getPosition.x="<<obj->getPosition().x<<std::endl;
			std::cout<<"obj->getPosition.y="<<obj->getPosition().y<<std::endl;*/
			if (obj->getPosition().x == pos.x && obj->getPosition().y == pos.y) {
				std::cout<<"toDraw++"<<std::endl;
				toDraw->push_back(obj);
			}

		}
	}
	
}

void Map::putObjectToDraw2(std::vector<sf::Vector2f>* pos){

	
	for (auto it = _map->begin(); it != _map->end(); ++it) {
		

		// V�rifier si le pointeur n'est pas nul
		if (*it) {

			// Acc�der � l'objet point�*
			Object* obj = *it;
			/*std::cout<<"obj->getPosition.x="<<obj->getPosition().x<<std::endl;
			std::cout<<"obj->getPosition.y="<<obj->getPosition().y<<std::endl;*/
			if ((obj->getPosition().x >= ((*pos)[0].x - 50) && obj->getPosition().y >= ((*pos)[0].y)-50) && (obj->getPosition().x <= ((*pos)[1].x+50) && obj->getPosition().y < ((*pos)[1].y)+50) )  {
				std::cout<<"toDraw++"<<std::endl;
				toDraw->push_back(obj);
			}

		}
	}
	
}

Object* Map::getObject(sf::Vector2f pos){

	
	for (auto it = _map->begin(); it != _map->end(); ++it) {

		// V�rifier si le pointeur n'est pas nul
		if (*it) {

			// Acc�der � l'objet point�*
			Object* obj = *it;

			if (obj->getPosition().x == pos.x && obj->getPosition().y == pos.y) {
				return obj;
			}

		}
	}
	return nullptr;	
}


std::vector<Object*>* Map::objectToDraw(std::vector<sf::Vector2f>* currentWindow) {
	/*std::cout<<"currentWindow[0].x=="<<(*currentWindow)[0].x<<std::endl;	
	std::cout<<"currentWindow[0].y=="<<(*currentWindow)[0].y<<std::endl;
	std::cout<<"currentWindow[1].x=="<<(*currentWindow)[1].x<<std::endl;
	std::cout<<"currentWindow[1].y=="<<(*currentWindow)[1].y<<std::endl;
	*/
	toDraw->clear();

	/*for (int _x = (*currentWindow)[0].x; _x < (*currentWindow)[1].x; _x=_x+48) {
		for (int _y = (*currentWindow)[0].y; _y < (*currentWindow)[1].y; _y=_y+48) {
			putObjectToDraw(sf::Vector2i(_x, _y));
		}
	}*/
	putObjectToDraw2(currentWindow);
	std::cout<<"toDraw->size()=="<<toDraw->size()<<std::endl;
	return toDraw;	


}

void Map::addObject(Object* o) {
	std::cout<<"addObject()"<< std::endl;

	sf::Vector2f pos = o->getPosition();
/*
	if (getObject(pos) != nullptr) {
		std::cout<<"erreur"<<std::endl;
		removeObject(getObject(pos));
	}*/
	_map->push_back(o);

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
/*for (float i = 0 ; i<22 ;i++){
	for(float j=0;j<16;j++){
		addObject(new Ground("World2.png", {i,j}, TypeGround::ice));

	}
}
for (float i = 0 ; i<22 ;i++){
	for(float j=-16;j<0;j++){
		addObject(new Ground("World2.png", {i,j}, TypeGround::grass));

	}
}*/
for (int x = 0; x < 300; x++) {
    for (int y = 0; y < 300; y++) {
        if (x < 150) {
            if (y <150) {
                // Monde 1 : forêt
                if (rand() % 10 == 0) {
                    addObject(new Ground("World2.png", {x, y}, TypeGround::floorTile));
                } else {
                    addObject(new Ground("World2.png", {x, y}, TypeGround::grass));
                }
                if (rand() % 20 == 0) {
                    addObject(new Ground("World2.png",{x, y}, TypeGround::stone));
                }
            } else {
                // Monde 2 : montagnes
                if (rand() % 5 == 0) {
                    addObject(new Ground("World2.png", {x, y}, TypeGround::Rock));
                } else {
                    addObject(new Ground("World2.png",{x, y}, TypeGround::floorTile));
                }
                if (rand() % 20 == 0) {
                    addObject(new Ground("World2.png",{x, y}, TypeGround::cobblestone));
                }
            }
        } else {
            if (y < 150) {
                // Monde 3 : plage
                if (rand() % 10 == 0) {
                    addObject(new Ground("World2.png",{x, y}, TypeGround::sand));
                } else {
                    addObject(new Ground("World2.png",{x, y}, TypeGround::floorTile));
                }
                if (rand() % 20 == 0) {
                    addObject(new Ground("World2.png",{x, y}, TypeGround::ice));
                }
            } else {
                // Monde 4 : ville
                if (rand() % 10 == 0) {
                    addObject(new Ground("World2.png",{x, y}, TypeGround::brick));
                } else {
                    addObject(new Ground("World2.png",{x, y}, TypeGround::floorTile));
                }
                if (rand() % 20 == 0) {
                    addObject(new Ground("World2.png",{x, y}, TypeGround::cobblestone2));
                }
            }
        }
    }
}


}