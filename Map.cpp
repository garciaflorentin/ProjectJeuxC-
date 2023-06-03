#include "Map.hpp"

Map::Map() /*: _playerDead(*(new sf::Sprite)), _door(*(new Door())), _doorWall1(*(new DoorWall())), _doorWall2(*(new DoorWall())), _doorWall3(*(new DoorWall())) */{
	for(int i= 0; i<1000 ;i++)
		_map.push_back(nullptr);
}


Map& Map::operator=(const Map& other) {
	_toDraw = other._toDraw;
	_map = other._map;
	_wallList = other._wallList;
	_monsterList = other._monsterList;

	_door = other._door;
	_doorWall1 = other._doorWall1;
	_doorWall2 = other._doorWall2;
	_doorWall3 = other._doorWall3;

	_nbDoorWall = other._nbDoorWall;
    _playerDead = other._playerDead;

    _LIMITE_Xneg = 0;
    _LIMITE_Y = 4992.f;
    _LIMITE_X = 9540;
    _LIMITE_Yneg = -4896.f;
    _LIMITE_XnegBoss = 9472.f;
    _LIMITE_YnegBoss = 9600.f;
    _LIMITE_XBoss = 10456.f;
    _LIMITE_YBoss = 10328.f;
    _spf = false;
    _spm = false;
    _spb = false;
    _spt = false;

    return *this;
}


Map::~Map() {
    for (auto it = _map.begin(); it != _map.end(); ++it)
		delete* it;

    for (auto it = _toDraw.begin(); it != _toDraw.end(); ++it)
		delete* it;
}


void Map::putObjectToDraw(std::vector<sf::Vector2f>& pos) {
	for (auto it = _map.begin(); it != _map.end(); ++it)
		if (*it)
			if (((*it)->getPosition().x >= (pos[0].x - 200) && (*it)->getPosition().y >= (pos[0].y)-200) && ((*it)->getPosition().x <= (pos[1].x+50) && (*it)->getPosition().y < (pos[1].y)+50))
				_toDraw.push_back((*it));	
}


std::vector<Object*>& Map::objectToDraw(std::vector<sf::Vector2f>& currentWindow) {
	_toDraw.clear();
	putObjectToDraw(currentWindow);
	return _toDraw;	
}


void Map::addObject(Ground* g) {
	_map.push_back(g);
}


void Map::addObject(Wall* w) {
	_map.push_back(w);
	_wallList.push_back(w);

    if(typeid(w) == typeid(DoorWall)){
		DoorWall& doorWall = dynamic_cast<DoorWall&>(*w);

		if(_nbDoorWall==0){
			_doorWall1 = doorWall;
			_nbDoorWall++;
		} else if (_nbDoorWall==1) {
			_doorWall2 = doorWall;
			_nbDoorWall++;
		} else if (_nbDoorWall==2){
			_doorWall3 = doorWall;
			_nbDoorWall++;
		}
    } else if (typeid(w) == typeid(Door)){
		Door& door = dynamic_cast<Door&>(*w);
		this->_door = door;
    }
}


void Map::addObject(Chest* c) {
	_map.push_back(c);
	_wallList.push_back(c);
	_map.push_back(&(c->getPrise()));
}


void Map::addObject(Monster* m) {
	_map.push_back(m);
	_monsterList.push_back(m);
}


void Map::removeObject(Object& o) {
	sf::Vector2f pos = o.getPosition();
	int i = 0;

	while (_map[i]->getPosition().x != pos.x && _map[i]->getPosition().y != pos.y)
		i++;
	
	delete[] _map[i]; // supprimer l'objet point�
	_map[i] = nullptr; // définir le pointeur � null
	_map.erase(_map.begin() + i); // enlever l'�l�ment du vecteur
}


std::vector<Object*>& Map::getWallList(){
	return _wallList;
}

std::vector<Monster*>& Map::getMonsters(){
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
                        addObject(new Ground("WorldTextures/World2.png", {x, y}, TypeGround::floorTile));
                    } else {
                        addObject(new Ground("WorldTextures/World2.png", {x, y}, TypeGround::grass));
                    }
                    if (rand() % 20 == 0) {
                        addObject(new Ground("WorldTextures/World2.png",{x, y}, TypeGround::stone));
                    }
				} else {
                    // Monde 2 : montagnes
                    if (rand() % 5 == 0) {
                        addObject(new Ground("WorldTextures/World2.png", {x, y}, TypeGround::Rock));
                    } else {
                        addObject(new Ground("WorldTextures/World2.png",{x, y}, TypeGround::floorTile));
                    }
                    if (rand() % 20 == 0) {
                        addObject(new Ground("WorldTextures/World2.png",{x, y}, TypeGround::cobblestone));
                    }
                }
            } else {
                if (y < 0) {
                    // Monde 3 : plage
                    if (rand() % 10 == 0) {
                        addObject(new Ground("WorldTextures/World2.png",{x, y}, TypeGround::sand));
                    } else {
                        addObject(new Ground("WorldTextures/World2.png",{x, y}, TypeGround::floorTile));
                    }
                    if (rand() % 20 == 0) {
                        addObject(new Ground("WorldTextures/World2.png",{x, y}, TypeGround::ice));
                    }
                } else {
                    // Monde 4 : ville
                    if (rand() % 10 == 0) {
                        addObject(new Ground("WorldTextures/World2.png",{x, y}, TypeGround::brick));
                    } else {
                        addObject(new Ground("WorldTextures/World2.png",{x, y}, TypeGround::floorTile));
                    }
                    if (rand() % 20 == 0) {
                        addObject(new Ground("WorldTextures/World2.png",{x, y}, TypeGround::cobblestone2));
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
                        addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::GrosseBranche)); 
                    }else if(rand()%100==0){
                        addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::GrandSapin));
                    }else if ( rand()%300==0){
                        addObject(new Chest("OtherTextures/Chests.png",{x,y}));
                    }else if(rand()%300==0){
                        //addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::LacForest));
                    }else if(rand()%100==0){
                        addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::RocherForest));
                    }else if(rand()%100==0){
                        addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::DeadTree));
                    }
            } else {
                    // Monde 2 : montagnes
                    if (rand() % 100 == 0) {
                        addObject(new Wall("WorldTextures/World2.png", {x, y}, TypeWall::SnowTree));
                    } else if(rand() % 300 == 0){
                        addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::MonsterSkeleton));
                    }
                    else if (rand() % 300 == 0) {
                    // addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::LacMountain));
                    }
                    else if (rand() % 100 == 0) {
                        addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::TombStone));
                    }
                    else if (rand() % 100 == 0) {
                        addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::DeadTree));
                    }
                    else if (rand() % 200 == 0) {
                        addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::FrozenScarecrow));
                    }
                }
            } else {
                if (y < 0) {
                    // Monde 3 : plage
                    if (rand() % 100 == 0) {
                        addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::RocherBeatch));
                    } else if(rand() % 100 == 0) {
                        addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::CoconutTree));
                    }
                    else if(rand() % 100 == 0) {
                        addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::Barrel));
                    }else if(rand() % 100 == 0) {
                    // addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::lacBeatch));
                    }
                } else {
                    // Monde 4 : ville
                    if (rand() % 100 == 0) {
                        addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::Well));
                    } else if(rand() % 100 == 0) {
                        addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::sign));
                    }
                    else if(rand() % 100 == 0) {
                        addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::Barrel));
                    }else if(rand() % 200 == 0) {
                        addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::KnightStatue));
                    }
                }
            }
        }
    }


    for(float x=0;x<49;x++)
        for(float y=-102;y<-100;y++)
            addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::GrandSapin));
        
    for(float x=51;x<95;x++)
        for(float y=-102;y<-100;y++)
            addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::GrandSapin));
  
    for(float x=105;x<149;x++)
        for(float y=-102;y<-100;y++)
            addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::CoconutTree));

    for(float x=151;x<200;x++)
        for(float y=-102;y<-100;y++)
            addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::CoconutTree));
 
    for(float x=100;x<149;x++)
        for(float y=100;y<102;y++)
            addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::KnightStatue));
 
    for(float x=151;x<200;x++)
        for(float y=100;y<102;y++)
            addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::KnightStatue));
    
    for(float x=0;x<49;x++)
        for(float y=100;y<102;y++)
            addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::SnowTree));
    
    for(float x=51;x<100;x++)
        for(float y=100;y<102;y++)
            addObject(new Wall("WorldTextures/World2.png",{x, y}, TypeWall::SnowTree));

    addObject(new Wall("WorldTextures/World2.png",{49, -102}, TypeWall::ChestForestBack));
    addObject(new Wall("WorldTextures/World2.png",{149, -102}, TypeWall::ChestBeatchBack));
    addObject(new Wall("WorldTextures/World2.png",{149, 102}, TypeWall::ChestTownBack));
    addObject(new Wall("WorldTextures/World2.png",{49, 102}, TypeWall::ChestMountainBack));
    addObject(new Wall("WorldTextures/World2.png",{48, -101}, TypeWall::ForetsPylone));
    addObject(new Wall("WorldTextures/World2.png",{48, -100}, TypeWall::ForetsPylone));
    addObject(new Wall("WorldTextures/World2.png",{51, -101}, TypeWall::ForetsPylone));
    addObject(new Wall("WorldTextures/World2.png",{51, -100}, TypeWall::ForetsPylone));
    addObject(new Wall("WorldTextures/World2.png",{48, 100}, TypeWall::MountainPylone));
    addObject(new Wall("WorldTextures/World2.png",{48, 101}, TypeWall::MountainPylone));
    addObject(new Wall("WorldTextures/World2.png",{51, 100}, TypeWall::MountainPylone));
    addObject(new Wall("WorldTextures/World2.png",{51, 101}, TypeWall::MountainPylone));
    addObject(new Wall("WorldTextures/World2.png",{148, -101}, TypeWall::BeatchPylone));
    addObject(new Wall("WorldTextures/World2.png",{148, -100}, TypeWall::BeatchPylone));
    addObject(new Wall("WorldTextures/World2.png",{151, -101}, TypeWall::BeatchPylone));
    addObject(new Wall("WorldTextures/World2.png",{151, -100}, TypeWall::BeatchPylone));
    addObject(new Wall("WorldTextures/World2.png",{148, 100}, TypeWall::TownPylone));
    addObject(new Wall("WorldTextures/World2.png",{148, 101}, TypeWall::TownPylone));
    addObject(new Wall("WorldTextures/World2.png",{151, 100}, TypeWall::TownPylone));
    addObject(new Wall("WorldTextures/World2.png",{151, 101}, TypeWall::TownPylone));

    addObject(new GoldenChest("OtherTextures/Chests.png",{49.5, -100}));
    addObject(new GoldenChest("OtherTextures/Chests.png",{149.5, -100}));
    addObject(new GoldenChest("OtherTextures/Chests.png",{49.5, 101}));
    addObject(new GoldenChest("OtherTextures/Chests.png",{149.5, 101}));

    addObject(new Wall("WorldTextures/World2.png",{95, -102}, TypeWall::DeadTree));
    addObject(new Wall("WorldTextures/World2.png",{95, -101}, TypeWall::DeadTree));
    addObject(new Wall("WorldTextures/World2.png",{96, -102}, TypeWall::DeadTree));
    addObject(new Wall("WorldTextures/World2.png",{96, -101}, TypeWall::DeadTree));
    addObject(new Wall("WorldTextures/World2.png",{97, -101}, TypeWall::DeadTree));
    addObject(new Wall("WorldTextures/World2.png",{96.5, -101}, TypeWall::DragonStatue));
    addObject(new Wall("WorldTextures/World2.png",{104, -102}, TypeWall::DeadTree));
    addObject(new Wall("WorldTextures/World2.png",{104, -101}, TypeWall::DeadTree));
    addObject(new Wall("WorldTextures/World2.png",{103, -102}, TypeWall::DeadTree));
    addObject(new Wall("WorldTextures/World2.png",{103, -101}, TypeWall::DeadTree));
    addObject(new Wall("WorldTextures/World2.png",{102, -102}, TypeWall::DeadTree));
    addObject(new Wall("WorldTextures/World2.png",{102, -101}, TypeWall::DragonStatue));

    addObject(new Door("WorldTextures/!Demon Door.png",{98.5,-102},TypeWall::DragonStatue));

    for(float x=-11;x<11;x++)
        for(float y=-11;y<11;y++)
            addObject(new Ground("WorldTextures/World2.png",{x+208, y+208}, TypeGround::BossGround));
       
    for(float x=-10;x<10;x++) {
        for(float y=-10;y<10;y++) {
			if (rand() % 50 == 0) {
					addObject(new Wall("WorldTextures/World2.png",{x+208, y+208}, TypeWall::BrokenBossColone1));
				} else if (rand() % 70 == 0) {
					addObject(new Wall("WorldTextures/World2.png",{x+208, y+208}, TypeWall::BrokenBossColone2));
				} else if (rand() % 50 == 0) {
					addObject(new Wall("WorldTextures/World2.png",{x+208, y+208}, TypeWall::BossColone));
				} else if(rand() % 200 == 0) {
					addObject(new Wall("WorldTextures/World2.png",{x+208, y+208}, TypeWall::BossSqueleton));
				}
        }
    }

    for(float i=0;i<50;i++)
        addObject(new WallZone("WorldTextures/World.png",{i, 0}, TypeWall::WallZoneHorizontal));
    
    for(float i=52;i<150;i++)
        addObject(new WallZone("WorldTextures/World.png",{i, 0}, TypeWall::WallZoneHorizontal));
    
    for(float i=152;i<200;i++)
        addObject(new WallZone("WorldTextures/World.png",{i, 0}, TypeWall::WallZoneHorizontal));

    for(float i=-97;i<50;i++)
        addObject(new WallZone("WorldTextures/World.png",{100, i}, TypeWall::WallZoneVertical));
    
    for(float i=52;i<100;i++)
        addObject(new WallZone("WorldTextures/World.png",{100, i}, TypeWall::WallZoneVertical));
    
    addObject(new Wall("WorldTextures/World2.png",{97, -99}, TypeWall::GrandSapin));
    addObject(new Wall("WorldTextures/World2.png",{97, -100}, TypeWall::GrandSapin));
    addObject(new Wall("WorldTextures/World2.png",{99, -98}, TypeWall::GrandSapin));
    addObject(new Wall("WorldTextures/World2.png",{98, -98}, TypeWall::GrandSapin));
    addObject(new Wall("WorldTextures/World2.png",{97, -98}, TypeWall::GrandSapin));

    addObject(new DoorWall("WorldTextures/Door.png",{49.5, -1}, TypeWall::WallZoneHorizontal,1,0));
    addObject(new DoorWall("WorldTextures/Door.png",{102, 49.5}, TypeWall::WallZoneHorizontal,2,90));
    addObject(new DoorWall("WorldTextures/Door.png",{149, -1}, TypeWall::WallZoneHorizontal,3,0));

	for(float i=-97;i<50;i++)
		addObject(new WallZone("WorldTextures/World.png",{100, i}, TypeWall::WallZoneVertical));
	
	for(float i=52;i<100;i++)
		addObject(new WallZone("WorldTextures/World.png",{100, i}, TypeWall::WallZoneVertical));
	
	addObject(new Wall("WorldTextures/World2.png",{97, -99}, TypeWall::GrandSapin));
	addObject(new Wall("WorldTextures/World2.png",{97, -100}, TypeWall::GrandSapin));
	addObject(new Wall("WorldTextures/World2.png",{99, -98}, TypeWall::GrandSapin));
	addObject(new Wall("WorldTextures/World2.png",{98, -98}, TypeWall::GrandSapin));
	addObject(new Wall("WorldTextures/World2.png",{97, -98}, TypeWall::GrandSapin));

	addObject(new DoorWall("WorldTextures/Door.png",{49.5, -1}, TypeWall::WallZoneHorizontal,1,0));
	addObject(new DoorWall("WorldTextures/Door.png",{102, 49.5}, TypeWall::WallZoneHorizontal,2,90));
	addObject(new DoorWall("WorldTextures/Door.png",{149, -1}, TypeWall::WallZoneHorizontal,3,0));
}


void Map::spawnMobs(string area) {
    for (int i = 0; i < _monsterList.size(); i++) {
        auto iter = find(_map.begin(), _map.end(), _monsterList[i]);
        if (iter != _map.end())    _map.erase(iter);
    }

    _monsterList.clear();

    /* Boss final spawn en plein milieu A DEPLACER */
    addObject(new FinalBoss());

    if (area == "forest") {
        for (float x = 0; x < 100; x++)
            for (float y = -100; y < 0; y++){
                if(_monsterList.size()<0) {
					if (rand() % 200 == 0)	addObject(new MeleeMonster("MonsterTextures/MonsterSheet1.png", {x,y}));
					if (rand() % 500 == 0)	addObject(new DemonDogMonster("MonsterTextures/DemonDogMonster.png", {x,y}));
                }

            }
    } else if (area == "mountain") {
        for (float x = 0; x < 100; x++)
            for (float y = 1; y < 100; y++){
                if(_monsterList.size()<30){
					if (rand() % 200 == 0)	addObject(new RangedMonster("MonsterTextures/MonsterSheet2.png", {x,y}));
					if (rand() % 500 == 0)	addObject(new MeleeMonster("MonsterTextures/MonsterSheet2.png", {x,y}));
                }
            }
    } else if (area == "beach") {
        for (float x = 101; x < 200; x++)
            for (float y = -100; y < 0; y++)
               	if(_monsterList.size()<30){
					if (rand() % 200 == 0)	addObject(new FlyMonster("object.png", {x,y}));
					if (rand() % 400 == 0)	addObject(new MiniFrogMonster("object.png", {x,y}));
                } 
    } else if (area == "town") {
        for (float x = 101; x < 200; x++)
            for (float y = 1; y < 100; y++)
               	if(_monsterList.size()<30){
					if (rand() % 200 == 0)	addObject(new MiniOgre("MonsterTextures/MonsterSheet1.png", {x,y}));
					if (rand() % 300 == 0)	addObject(new GuerrierOgre("MonsterTextures/MonsterSheet1.png", {x,y}));
               	}
  
    }
}


void Map::updateObjects(Player& player1, Player& player2) {
    sf::Vector2f ppose = player1.getPosition();

    if ((ppose.x < 100*SPR_SIZE)&&(ppose.y < 0)&&(!_spf)) {
        _spf=true;
        _monsterList.clear();
        spawnMobs("forest");
    } else if ((ppose.x < 100*SPR_SIZE)&&(ppose.y > 0)&&(!_spm)) {
        _spm=true;
        _monsterList.clear();
        spawnMobs("mountain");
    } else if ((ppose.x > 100*SPR_SIZE)&&(ppose.y < 0)&&(!_spb)) {
        _spb=true;
        _monsterList.clear();
        spawnMobs("beach");
    } else if ((ppose.x > 100*SPR_SIZE)&&(ppose.y>0)&&(!_spt)) {
        _spt=true;
        _monsterList.clear();
        spawnMobs("town");
    }

	for (int i=0;i<_monsterList.size();i++) {
		if (!_monsterList[i]->isAlive()) {
         	_monsterList.erase(_monsterList.begin() + i);
		}
		else {
			_monsterList[i]->update(player1, player2);
		}
	}

    updateAnimateObject();
}


void Map::updateAnimateObject(){
	_door.animDoor();	
	_doorWall1.animDoor();
	_doorWall2.animDoor();
	_doorWall3.animDoor();
}


void Map::getLimitMap(std::vector<float>& limit){
	limit={_LIMITE_X,_LIMITE_Y,_LIMITE_Xneg,_LIMITE_Yneg};
}

void Map::getLimitMapBoss(std::vector<float>& limit){
	limit={_LIMITE_XnegBoss,_LIMITE_YnegBoss,_LIMITE_XBoss,_LIMITE_YBoss};
}

std::vector<Object*>& Map::getMap() {
	return _map;
}


void Map::addPlayerDead(sf::Sprite* sprite){
	_playerDead = *sprite;
}

sf::Sprite* Map::getPlayerDead(){
	return &_playerDead;
}