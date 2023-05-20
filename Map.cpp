#include "Map.hpp"

Map::Map() {
toDraw = new std::vector<Object*>;
_wallList =new std::vector<Object*>;
_monsterList =new std::vector<Monster*>;

_map = new std::vector<Object*>(10);
for(int i= 0; i<10 ;i++){
	_map->push_back(nullptr);
}


}

Map::~Map() {
	delete[] toDraw;
	delete[] _map;
	delete[] _wallList;
	delete[] _monsterList;
}



void Map::putObjectToDraw(std::vector<sf::Vector2f>* pos){

	
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

std::vector<Object*>* Map::objectToDraw(std::vector<sf::Vector2f>* currentWindow) {
	toDraw->clear();
	putObjectToDraw(currentWindow);
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
	
	_map->push_back(c);
	_wallList->push_back(c);
	_map->push_back(c->getGain());
}

void Map::addObject(Monster* m) {
	_map->push_back(m);
	_monsterList->push_back(m);
	//_wallList->push_back(m);
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

std::vector<Monster*>* Map::getMonsters(){
	return _monsterList;
}
	

void Map::createMap(){
int a=rand();
//creation du sol
for (float x = 0; x < 200; x++) {
    for (float y = -100; y < 100; y++) {
        
        if (x < 100) {
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
for (float x = 0; x < 200; x++) {
    for (float y = -100; y < 100; y++) {
        if (x < 100) {
            if (y <0) {//foret
				if (rand() % 80 == 0) {
    				addObject(new Wall("World2.png",{x, y}, TypeWall::GrosseBranche)); 
				}else if(rand()%80==0){
					addObject(new Wall("World2.png",{x, y}, TypeWall::GrandSapin));
				}else if ( rand()%200==0){
					addObject(new Chest("Chests.png",{x,y}));
				}else if(rand()%150==0){
					addObject(new Wall("World2.png",{x, y}, TypeWall::LacForest));
				}else if(rand()%80==0){
					addObject(new Wall("World2.png",{x, y}, TypeWall::RocherForest));
				}else if(rand()%80==0){
					addObject(new Wall("World2.png",{x, y}, TypeWall::DeadTree));
				}
		}else {
                // Monde 2 : montagnes
                if (rand() % 80 == 0) {
                    addObject(new Wall("World2.png", {x, y}, TypeWall::SnowTree));
                } else if(rand() % 200 == 0){
                    addObject(new Wall("World2.png",{x, y}, TypeWall::MonsterSkeleton));
                }
                else if (rand() % 150 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::LacMountain));
                }
				else if (rand() % 80 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::TombStone));
                }
				else if (rand() % 80 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::DeadTree));
                }
                else if (rand() % 150 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::FrozenScarecrow));
                }
            }
        } else {
            if (y < 0) {
                // Monde 3 : plage
                if (rand() % 80 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::RocherBeatch));
                } else if(rand() % 80 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::CoconutTree));
                }
                else if(rand() % 80 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::Barrel));
                }else if(rand() % 100 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::lacBeatch));
                }
            } else {
                // Monde 4 : ville
                 if (rand() % 80 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::Well));
                } else if(rand() % 80 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::sign));
                }
                else if(rand() % 80 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::Barrel));
                }else if(rand() % 150 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::KnightStatue));
                }
            }
        }
    
    }
}
	


	//creation des monstres
	for (float x = 0; x < 300; x++) {
		for (float y = -150; y < 150; y++) {
			if (x < 50) {
				if (y <0) {
					if (rand() % 200 == 0)	addObject(new Monster("crying_cat.png", {x,y}));
				}
			}
		}
	}

}



void Map::updateObjects(Player* player) {

	for (int i=0;i<_monsterList->size();i++)
	{
		if (!(*_monsterList)[i]->isAlive())
		{
			(*_monsterList)[i]->getSprite()->scale(0, 0);
		}
		else
		{
			//cout << "updating monsters in the list _map" << endl;
			(*_monsterList)[i]->update(player);
		}
	}
}