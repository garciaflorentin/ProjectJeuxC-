#include "Map.hpp"

Map::Map() {
toDraw = new std::vector<Object*>;
_wallList =new std::vector<Object*>;

_map = new std::vector<Object*>(10);
for(int i= 0; i<10 ;i++){
	_map->push_back(nullptr);
}


}

Map::~Map() {
	delete toDraw;
	delete _map;
	delete _wallList;

}

void Map::putObjectToDraw(sf::Vector2f pos){

	
	for (auto it = _map->begin(); it != _map->end(); ++it) {
		

		// V�rifier si le pointeur n'est pas nul
		if (*it) {

			// Acc�der � l'objet point�*
			Object* obj = *it;

			if (obj->getPosition().x == pos.x && obj->getPosition().y == pos.y) {
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

			if ((obj->getPosition().x >= ((*pos)[0].x - 200) && obj->getPosition().y >= ((*pos)[0].y)-200) && (obj->getPosition().x <= ((*pos)[1].x+50) && obj->getPosition().y < ((*pos)[1].y)+50) )  {
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
	toDraw->clear();
	putObjectToDraw2(currentWindow);
	//std::cout<<"toDraw->size()=="<<toDraw->size()<<std::endl;
	return toDraw;	


}

void Map::addObject(Ground* g) {

	sf::Vector2f pos = g->getPosition();
/*
	if (getObject(pos) != nullptr) {
		std::cout<<"erreur"<<std::endl;
		removeObject(getObject(pos));
	}*/
	_map->push_back(g);

}

void Map::addObject(Wall* w) {
	_map->push_back(w);
	_wallList->push_back(w);
}

void Map::addObject(Chest* c) {
	
	_map->push_back(c->getGain());
	//_wallList->push_back(c);
	_map->push_back(c);
	_wallList->push_back(c);


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


std::vector<Object*>* Map::getWallList(){
	return _wallList;
}
	

void Map::createMap(){

//creation du sol
for (float x = 0; x < 50; x++) {
    for (float y = -25; y < 25; y++) {
        if (x < 50) {
            if (y <0) {
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
            if (y < 0) {
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
//creation des murs
for (float x = 0; x < 50; x++) {
    for (float y = -25; y < 25; y++) {
        if (x < 50) {
            if (y <0) {
				if (rand() % 63 == 0) {
    				addObject(new Wall("World2.png",{x, y}, TypeWall::GrosseBranche)); 
				}else if(rand()%40==0){
					addObject(new Wall("World2.png",{x, y}, TypeWall::GrandSapin));
				}else if ( rand()%201==0){
					addObject(new Chest("Chests.png",{x,y}));
				}
			}
		}
	}
}

addObject(new Chest("Chests.png",{4,-50}));

}