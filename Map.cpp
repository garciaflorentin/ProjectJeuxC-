#include "Map.hpp"

Map::Map() {
toDraw = new std::vector<Object*>;
_wallList =new std::vector<Object*>;
_monsterList =new std::vector<Monster*>;
playerDead= new sf::Sprite();
playerDead=nullptr;

_map = new std::vector<Object*>(10);
for(int i= 0; i<10 ;i++){
	_map->push_back(nullptr);
}

nbDoorWall=0;


}

Map::~Map() {
	delete[] toDraw;
	delete[] _map;
	delete[] _wallList;
	delete[] _monsterList;
    delete playerDead;
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

    if(typeid(*w) == typeid(DoorWall)){
        std::cout<<"ajoutDoorWall"<<std::endl;
		    DoorWall* doorWall=dynamic_cast<DoorWall*>(w);
            if(nbDoorWall==0){
            doorWall1=doorWall;
            nbDoorWall++;
            }else if(nbDoorWall==1){
                doorWall2=doorWall;
                nbDoorWall++;
            }else if(nbDoorWall==2){
                doorWall3=doorWall;
                nbDoorWall++;
            }
    }else if(typeid(*w) == typeid(Door)){
		    Door* _door=dynamic_cast<Door*>(w);
            this->door=_door;
    }
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
    for (float y = -102; y < 104; y++) {
        
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
				if (rand() % 100 == 0) {
    				addObject(new Wall("World2.png",{x, y}, TypeWall::GrosseBranche)); 
				}else if(rand()%100==0){
					addObject(new Wall("World2.png",{x, y}, TypeWall::GrandSapin));
				}else if ( rand()%300==0){
					addObject(new Chest("Chests.png",{x,y}));
				}else if(rand()%300==0){
					//addObject(new Wall("World2.png",{x, y}, TypeWall::LacForest));
				}else if(rand()%100==0){
					addObject(new Wall("World2.png",{x, y}, TypeWall::RocherForest));
				}else if(rand()%100==0){
					addObject(new Wall("World2.png",{x, y}, TypeWall::DeadTree));
				}
		}else {
                // Monde 2 : montagnes
                if (rand() % 100 == 0) {
                    addObject(new Wall("World2.png", {x, y}, TypeWall::SnowTree));
                } else if(rand() % 300 == 0){
                    addObject(new Wall("World2.png",{x, y}, TypeWall::MonsterSkeleton));
                }
                else if (rand() % 300 == 0) {
                   // addObject(new Wall("World2.png",{x, y}, TypeWall::LacMountain));
                }
				else if (rand() % 100 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::TombStone));
                }
				else if (rand() % 100 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::DeadTree));
                }
                else if (rand() % 200 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::FrozenScarecrow));
                }
            }
        } else {
            if (y < 0) {
                // Monde 3 : plage
                if (rand() % 100 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::RocherBeatch));
                } else if(rand() % 100 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::CoconutTree));
                }
                else if(rand() % 100 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::Barrel));
                }else if(rand() % 100 == 0) {
                   // addObject(new Wall("World2.png",{x, y}, TypeWall::lacBeatch));
                }
            } else {
                // Monde 4 : ville
                 if (rand() % 100 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::Well));
                } else if(rand() % 100 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::sign));
                }
                else if(rand() % 100 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::Barrel));
                }else if(rand() % 200 == 0) {
                    addObject(new Wall("World2.png",{x, y}, TypeWall::KnightStatue));
                }
            }
        }
    
    }
}
for(float x=0;x<49;x++){
    for(float y=-102;y<-100;y++){
                            addObject(new Wall("World2.png",{x, y}, TypeWall::GrandSapin));
    }
}
for(float x=51;x<95;x++){
    for(float y=-102;y<-100;y++){
                            addObject(new Wall("World2.png",{x, y}, TypeWall::GrandSapin));
    }
}
for(float x=105;x<149;x++){
    for(float y=-102;y<-100;y++){
                            addObject(new Wall("World2.png",{x, y}, TypeWall::CoconutTree));
    }
}
for(float x=151;x<200;x++){
    for(float y=-102;y<-100;y++){
                            addObject(new Wall("World2.png",{x, y}, TypeWall::CoconutTree));
    }
}
for(float x=100;x<149;x++){
    for(float y=100;y<102;y++){
                            addObject(new Wall("World2.png",{x, y}, TypeWall::KnightStatue));
    }
}
for(float x=151;x<200;x++){
    for(float y=100;y<102;y++){
                            addObject(new Wall("World2.png",{x, y}, TypeWall::KnightStatue));
    }
}
for(float x=0;x<49;x++){
    for(float y=100;y<102;y++){
                            addObject(new Wall("World2.png",{x, y}, TypeWall::SnowTree));
    }
}
for(float x=51;x<100;x++){
    for(float y=100;y<102;y++){
                            addObject(new Wall("World2.png",{x, y}, TypeWall::SnowTree));
    }
}

addObject(new Wall("World2.png",{49, -102}, TypeWall::ChestForestBack));
addObject(new Wall("World2.png",{149, -102}, TypeWall::ChestBeatchBack));
addObject(new Wall("World2.png",{149, 102}, TypeWall::ChestTownBack));
addObject(new Wall("World2.png",{49, 102}, TypeWall::ChestMountainBack));
addObject(new Wall("World2.png",{48, -101}, TypeWall::ForetsPylone));
addObject(new Wall("World2.png",{48, -100}, TypeWall::ForetsPylone));
addObject(new Wall("World2.png",{51, -101}, TypeWall::ForetsPylone));
addObject(new Wall("World2.png",{51, -100}, TypeWall::ForetsPylone));

addObject(new Wall("World2.png",{48, 100}, TypeWall::MountainPylone));
addObject(new Wall("World2.png",{48, 101}, TypeWall::MountainPylone));
addObject(new Wall("World2.png",{51, 100}, TypeWall::MountainPylone));
addObject(new Wall("World2.png",{51, 101}, TypeWall::MountainPylone));
addObject(new Wall("World2.png",{148, -101}, TypeWall::BeatchPylone));
addObject(new Wall("World2.png",{148, -100}, TypeWall::BeatchPylone));
addObject(new Wall("World2.png",{151, -101}, TypeWall::BeatchPylone));
addObject(new Wall("World2.png",{151, -100}, TypeWall::BeatchPylone));
addObject(new Wall("World2.png",{148, 100}, TypeWall::TownPylone));
addObject(new Wall("World2.png",{148, 101}, TypeWall::TownPylone));
addObject(new Wall("World2.png",{151, 100}, TypeWall::TownPylone));
addObject(new Wall("World2.png",{151, 101}, TypeWall::TownPylone));
 addObject(new GoldenChest("Chests.png",{49.5, -100}));
 addObject(new GoldenChest("Chests.png",{149.5, -100}));
 addObject(new GoldenChest("Chests.png",{49.5, 101}));
 addObject(new GoldenChest("Chests.png",{149.5, 101}));
 addObject(new Wall("World2.png",{95, -102}, TypeWall::DeadTree));
  addObject(new Wall("World2.png",{95, -101}, TypeWall::DeadTree));
  addObject(new Wall("World2.png",{96, -102}, TypeWall::DeadTree));
    addObject(new Wall("World2.png",{96, -101}, TypeWall::DeadTree));
  addObject(new Wall("World2.png",{97, -101}, TypeWall::DeadTree));

  addObject(new Wall("World2.png",{96.5, -101}, TypeWall::DragonStatue));
addObject(new Wall("World2.png",{104, -102}, TypeWall::DeadTree));
addObject(new Wall("World2.png",{104, -101}, TypeWall::DeadTree));
addObject(new Wall("World2.png",{103, -102}, TypeWall::DeadTree));
addObject(new Wall("World2.png",{103, -101}, TypeWall::DeadTree));
addObject(new Wall("World2.png",{102, -102}, TypeWall::DeadTree));

addObject(new Wall("World2.png",{102, -101}, TypeWall::DragonStatue));

 addObject(new Door("!Demon Door.png",{98.5,-102},TypeWall::DragonStatue));

 for(float x=-11;x<11;x++){
    for(float y=-11;y<11;y++){
            addObject(new Ground("World2.png",{x+208, y+208}, TypeGround::BossGround));
            
    }
 }
 for(float x=-10;x<10;x++){
    for(float y=-10;y<10;y++){
            if (rand() % 50 == 0) {
                    addObject(new Wall("World2.png",{x+208, y+208}, TypeWall::BrokenBossColone1));
                }else if(rand() % 70 == 0) {
                    addObject(new Wall("World2.png",{x+208, y+208}, TypeWall::BrokenBossColone2));
                }
                else if(rand() % 50 == 0) {
                    addObject(new Wall("World2.png",{x+208, y+208}, TypeWall::BossColone));
                }else if(rand() % 200 == 0) {
                    addObject(new Wall("World2.png",{x+208, y+208}, TypeWall::BossSqueleton));
                }
    }
 }
for(float i=0;i<50;i++){
     addObject(new WallZone("World.png",{i, 0}, TypeWall::WallZoneHorizontal));
}
for(float i=52;i<150;i++){
     addObject(new WallZone("World.png",{i, 0}, TypeWall::WallZoneHorizontal));
}
for(float i=152;i<200;i++){
     addObject(new WallZone("World.png",{i, 0}, TypeWall::WallZoneHorizontal));
}

for(float i=-97;i<50;i++){
     addObject(new WallZone("World.png",{100, i}, TypeWall::WallZoneVertical));
}
for(float i=52;i<100;i++){
     addObject(new WallZone("World.png",{100, i}, TypeWall::WallZoneVertical));
}
addObject(new Wall("World2.png",{97, -99}, TypeWall::GrandSapin));
addObject(new Wall("World2.png",{97, -100}, TypeWall::GrandSapin));
addObject(new Wall("World2.png",{99, -98}, TypeWall::GrandSapin));
addObject(new Wall("World2.png",{98, -98}, TypeWall::GrandSapin));
addObject(new Wall("World2.png",{97, -98}, TypeWall::GrandSapin));



addObject(new DoorWall("Door.png",{49.5, -1}, TypeWall::WallZoneHorizontal,1,0));
addObject(new DoorWall("Door.png",{102, 49.5}, TypeWall::WallZoneHorizontal,2,90));
addObject(new DoorWall("Door.png",{149, -1}, TypeWall::WallZoneHorizontal,3,0));






 //addObject(new Monster("MonsterSheet1.png", {20,-10}));
}


	//creation des monstres
	// for (float x = 0; x < 200; x++) {
	// 	for (float y = -150; y < 150; y++) {
	// 		if (x < 100) {
	// 			if (y <0) {
	// 				if (rand() % 100 == 0)	addObject(new MeleeMonster("crying_cat.png", {x,y}));
	// 			} else {
    //                 if (rand() % 100 == 0)	addObject(new RangedMonster("standing_cat.png", {x,y}));
    //             }
	// 		}
	// 	}
	// }



void Map::spawnMobs(string area) {
    for (int i = 0; i < _monsterList->size(); i++) {
        auto iter = find(_map->begin(), _map->end(), (*_monsterList)[i]);
        if (iter != _map->end())    _map->erase(iter);
    }
    _monsterList->clear();

    if (area == "forest") {
        cout << "adding forest monsters" << endl;

        for (float x = 0; x < 100; x++)
            for (float y = -100; y < 0; y++){
                if(_monsterList->size()<0){
                if (rand() % 200 == 0)	addObject(new MeleeMonster("MonsterSheet1.png", {x,y}));
                if (rand() % 500 == 0)	addObject(new DemonDogMonster("DemonDogMonster.png", {x,y}));
                }

            }
    } else if (area == "mountain") {
        cout << "adding mountain monsters" << endl;

        for (float x = 0; x < 100; x++)
            for (float y = 0; y < 100; y++){
               // if (rand() % SPAWN_FREQUENCY == 0)	addObject(new RangedMonster("MonsterSheet2.png", {x,y}));
               // if (rand() % SPAWN_FREQUENCY == 0)	addObject(new MeleeMonster("MonsterSheet2.png", {x,y}));

            }
    } else if (area == "beach") {
        cout << "adding beach monsters" << endl;

        for (float x = 100; x < 200; x++)
            for (float y = -100; y < 0; y++)
               if(_monsterList->size()<30){
                if (rand() % 200 == 0)	addObject(new FlyMonster("object.png", {x,y}));
                if (rand() % 400 == 0)	addObject(new MiniFrogMonster("object.png", {x,y}));
                }

 
    } else if (area == "town") {
        cout << "adding town monsters" << endl;

        for (float x = 100; x < 200; x++)
            for (float y = 0; y < 100; y++)
               if(_monsterList->size()<30){
                if (rand() % 200 == 0)	addObject(new MiniOgre("MonsterSheet1.png", {x,y}));
                if (rand() % 300 == 0)	addObject(new GuerrierOgre("MonsterSheet1.png", {x,y}));
               }
  
    }
}





void Map::updateObjects(Player* player) {
    sf::Vector2f ppose = player->getPosition();
    //cout << "player x = " << ppose.x << ", y = " << ppose.y << endl;
    
    if ((ppose.x < 100*SPR_SIZE)&&(ppose.y < 0)&&(!_spf)) {
        cout << "in forest area" << endl;
        _spf=true;
        _monsterList->clear();
        spawnMobs("forest");
    } else if ((ppose.x < 100*SPR_SIZE)&&(ppose.y > 0)&&(!_spm)) {
        cout << "in mountain area" << endl;
        _spm=true;
        _monsterList->clear();
        spawnMobs("mountain");
    } else if ((ppose.x > 100*SPR_SIZE)&&(ppose.y < 0)&&(!_spb)) {
        cout << "in beach area" << endl;
        _spb=true;
        _monsterList->clear();
        spawnMobs("beach");
    } else if ((ppose.x > 100*SPR_SIZE)&&(ppose.y>0)&&(!_spt)) {
        cout << "in town area" << endl;
        _spt=true;
        _monsterList->clear();
        spawnMobs("town");
    }

	for (int i=0;i<_monsterList->size();i++)
	{
		if (!(*_monsterList)[i]->isAlive())
		{

         _monsterList->erase(_monsterList->begin() + i);
		}
		else
		{
			//cout << "updating monsters in the list _map" << endl;
			(*_monsterList)[i]->update(player);
		}

        // if ((*_monsterList)[i]->lifetime_secs() > 10) { 
        //     Monster* temp = (*_monsterList)[i];
        //     _monsterList->erase(next(_monsterList->begin(),i-1));
        //     for (int j = 0; j < _map->size(); j++) {
        //         if ((*_map)[j]->getSerial() == temp->getSerial())   _map->erase(next(_map->begin(),j-1));
        //     }
        //     delete[] temp;
        // }

	}
    updateAnimateObject();
    std::cout<<"nbMonster= "<<_monsterList->size()<<std::endl;
    //std::cout<<"nombre de monstre total="<<_monsterList->size()<<std::endl;
}

void Map::updateAnimateObject(){
			door->animDoor();	
            doorWall1->animDoor();
            doorWall2->animDoor();
            doorWall3->animDoor();
}

void Map::getLimitMap(std::vector<float>& limit){
		limit={LIMITE_X,LIMITE_Y,LIMITE_Xneg,LIMITE_Yneg};
	}

	void Map::getLimitMapBoss(std::vector<float>& limit){
		limit={LIMITE_XnegBoss,LIMITE_YnegBoss,LIMITE_XBoss,LIMITE_YBoss};
	}

    std::vector<Object*>* Map::getMap() {
		return _map;
	}

    void Map::addPlayerDead(sf::Sprite* sprite){
		playerDead = sprite;
	}

	sf::Sprite* Map::getPlayerDead(){
		return playerDead;
	}