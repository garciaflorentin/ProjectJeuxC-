#include "GameGestion.hpp"


GameGestion::GameGestion() : 
_map(*(new Map())), _player(*(new Player("PlayerTextures/player1.png", {2, 1}, "OtherTextures/arrow.png"))), 
_player2(*(new Player("PlayerTextures/player2.png", {1, 1}, "OtherTextures/fate.png"))) {
	_currentZoneMusic= -1;

	_map.createMap();
	
	_playerVector.push_back(&_player);
	_playerVector.push_back(&_player2);

	_ForestMusic = SoundsLib::assignSound("Sounds/ForestMood.wav");
	_TownMusic = SoundsLib::assignSound("Sounds/TownMood.wav");
	_MountainMusic = SoundsLib::assignSound("Sounds/MountainMood.wav");
	_BeachMusic = SoundsLib::assignSound("Sounds/BeachMood.ogg");

	_music.push_back(_ForestMusic);
	_music.push_back(_MountainMusic);
	_music.push_back(_TownMusic);
	_music.push_back(_BeachMusic);

	setPlayer();
}


GameGestion& GameGestion::operator=(const GameGestion& other) {
	ColisionInterface::operator=(other);

    _playerVector = other._playerVector; /**< Vecteur de pointeurs vers les joueurs */
    _player = other._player; /**< Pointeur vers le joueur */
    _player2 = other._player2; /**< Pointeur vers le deuxième joueur */

    _time = other._time; /**< Horloge utilisée pour la gestion du temps */

    _map = other._map; /**< Pointeur vers la carte du jeu */

	_ForestMusic = SoundsLib::assignSound("Sounds/ForestMood.wav");
	_TownMusic = SoundsLib::assignSound("Sounds/TownMood.wav");
	_MountainMusic = SoundsLib::assignSound("Sounds/MountainMood.wav");
	_BeachMusic = SoundsLib::assignSound("Sounds/BeachMood.ogg");

	_music = other._music;

    _currentZoneMusic = other._currentZoneMusic;

	return *this;
}


GameGestion::~GameGestion() {
	for (auto it = _playerVector.begin(); it != _playerVector.end(); ++it)
		delete *it;

	for (auto it = _music.begin(); it != _music.end(); ++it)
		delete *it;
}


std::vector<Object*>& GameGestion::toDrawUpdate(std::vector<sf::Vector2f>& currentWindow) {
	return _map.objectToDraw(currentWindow);
}


const bool GameGestion::drawProjectile1(std::vector<sf::Vector2f>& currentWindow) {
	if ((_player.getProjectile()->isShot()) && (_player.getProjectile()->getPosition().x >= currentWindow[0].x - 200) && (_player.getProjectile()->getPosition().y >= currentWindow[0].y - 200) && (_player.getProjectile()->getPosition().x <= currentWindow[1].x + 50) && (_player.getProjectile()->getPosition().y < currentWindow[1].y + 50))
		return !(_player.getProjectile() == nullptr);
	
	else
	    return false;
}


const bool GameGestion::drawProjectile2(std::vector<sf::Vector2f>& currentWindow) {
	if ((_player2.getProjectile()->isShot()) && (_player2.getProjectile()->getPosition().x >= currentWindow[0].x - 200) && (_player2.getProjectile()->getPosition().y >= currentWindow[0].y - 200) && (_player2.getProjectile()->getPosition().x <= currentWindow[1].x + 50) && (_player2.getProjectile()->getPosition().y < currentWindow[1].y + 50))
		return !(_player2.getProjectile() == nullptr);
	
	else
		return false;
	
}


const bool GameGestion::drawFireballs(std::vector<sf::Vector2f>& currentWindow, std::vector<Projectile*>& toFill) {
	int indice = 0;

	for (int i=0; i<_map.getMonsters().size(); i++) {
		if ((_map.getMonsters())[i]->getProjectile() != nullptr) {
			toFill.push_back((_map.getMonsters())[i]->getProjectile());

			if (!(toFill[indice]->isShot() && toFill[indice]->getPosition().x >= currentWindow[0].x - 200 && toFill[indice]->getPosition().y >= currentWindow[0].y-200 && toFill[indice]->getPosition().x <= currentWindow[1].x+50 && toFill[indice]->getPosition().y < currentWindow[1].y+50 ))  {
                indice--;
                toFill.pop_back();
			}

			indice++;
		}
		
		else if ((_map.getMonsters())[i]->getProjectiles() != nullptr) {
			for (int j = 0; j < (_map.getMonsters())[i]->getProjectiles()->size(); j++) {
				if ((*(_map.getMonsters()[i]->getProjectiles()))[j] != nullptr) {
					toFill.push_back((*(_map.getMonsters()[i]->getProjectiles()))[j]);
				}

                if (!(toFill[indice]->isShot() && toFill[indice]->getPosition().x >= currentWindow[0].x - 200 && toFill[indice]->getPosition().y >= currentWindow[0].y-200 && toFill[indice]->getPosition().x <= currentWindow[1].x+50 && toFill[indice]->getPosition().y < currentWindow[1].y+50))  {
                        indice--;
                        toFill.pop_back();
                }

                indice++;
			}
		}
	}

	return (indice > 0);
}



void GameGestion::keyEvent(sf::Event e) {
	_player.setSpeed(_map.getMonsters().size() / 5);
	float vitesse = _player.getSpeed();
	if (vitesse <= 3) {
		_player.setSpeed(4);
		vitesse = 4;
	}

	_player2.setSpeed(_map.getMonsters().size() / 5);
	vitesse = _player2.getSpeed();
	if (vitesse <= 3) {
		_player2.setSpeed(4);
		vitesse = 4;
	}

    if(!_player.WeaponIsUsed()){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            _player.getAnim().x++;
            _player.getAnim().y = 0;
            _player.setOrientation(2);
            _player.move({0, vitesse});
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            _player.getAnim().x++;
            _player.getAnim().y = 4;
            _player.setOrientation(0);
            _player.move({0, -vitesse});
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            // std::cout << " R " << std::endl;
            _player.getAnim().x++;
            _player.getAnim().y = 2;
            _player.setOrientation(3);
            _player.move({vitesse, 0});
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            // std::cout << " L " << std::endl;
            _player.getAnim().x++;
            _player.getAnim().y = 6;
            _player.setOrientation(1);
            _player.move({-vitesse, 0});
        }

        _player.updateSprite();
    }

    if(!_player2.WeaponIsUsed()){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            _player2.getAnim().x++;
            _player2.getAnim().y = 0;
            _player2.setOrientation(2);
            _player2.move({0, vitesse});
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            _player2.getAnim().x++;
            _player2.getAnim().y = 4;
            _player2.setOrientation(0);
            _player2.move({0, -vitesse});
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            _player2.getAnim().x++;
            _player2.getAnim().y = 2;
            _player2.setOrientation(3);
            _player2.move({vitesse, 0});
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            _player2.getAnim().x++;
            _player2.getAnim().y = 6;
            _player2.setOrientation(1);
            _player2.move({-vitesse, 0});
        }
            
        _player2.updateSprite();
    }
        
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        if(_player2.isAlive())	_player2.useWand();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        if(_player.isAlive()) 	_player.useBow();
}


int GameGestion::updateGame() {
	if(_player2.getKey() != _player.getKey()){
		int tempo=_player2.getKey();
		_player2.setKey(_player2.getKey()+ _player.getKey());
		_player.setKey(tempo+ _player.getKey());
	}

    if (_player.bowIsUsed())
        _player.useBow();
    
	_player.getProjectile()->arrowOutOfBounds();
	
    if (_player2.wandIsUsed())//&& !_player.getProjectile().isShot())
        _player2.useWand();
    
	_player2.getProjectile()->arrowOutOfBounds();
	
	collideProjectileGestion();
	collideMonsterGestion();
	collideWallGestion();

	if (_player.getIsInTheCave())
		LimitMapBoss();
	else
		LimitMap();
	
	checkLifeMonster(_player.getKilledallMobs());
	checkLifeMonster(_player2.getKilledallMobs());

	if (!_player.isAlive() || !_player2.isAlive()) {
		if(!_player.isAlive() && !_player2.isAlive()){
			return 3;
		} else if (!_player.isAlive()) {
			_map.addPlayerDead(&_player.deadGestion());
			return 1;
		} else {
			_map.addPlayerDead(&_player2.deadGestion());
			return 2;
		}
	}

	return 0;
}


void GameGestion::setPlayer() {
	_player.setUpCharacter();
	_player2.setUpCharacter();
}


int GameGestion::collidePosition(Object& object1, Object& object2) {
	sf::Sprite sprite1 = object1.getSprite();
	sf::Sprite sprite2 = object2.getSprite();

	sf::FloatRect rect1 = sprite1.getGlobalBounds();
	sf::FloatRect rect2 = sprite2.getGlobalBounds();

	if (!rect1.intersects(rect2))
	    return -1;

	float overlapX = std::min(rect1.left + rect1.width, rect2.left + rect2.width) - std::max(rect1.left, rect2.left);
	float overlapY = std::min(rect1.top + rect1.height, rect2.top + rect2.height) - std::max(rect1.top, rect2.top);

	if (overlapX > overlapY) {
		if (rect1.top < rect2.top)
			return 1;
		else
			return 2;
	}
	else {
		if (rect1.left < rect2.left)
			return 3;
		else
			return 4;
	}
}


void GameGestion::collideWall(Object& o, std::vector<Object*>& wallList, std::vector<int>& info) {
	bool collide = false;

	for (int x = 0; x < wallList.size(); x++) {
		int colision = collidePosition(o, *(wallList[x]));

		if (colision != -1) {
			info.push_back(x);
			info.push_back(colision);
			collide = true;
		}
	}

	if (!collide) {
		info.push_back(-1);
		info.push_back(-1);
	}
}



void GameGestion::collideMonster(Object& o, std::vector<Monster*>& wallList, std::vector<int>& info) {
	bool collide = false;

	for (int x = 0; x < wallList.size(); x++) {
        int colision = collidePosition(o, *(wallList[x]));

		if (colision != -1) {

			cout << "Monster touched by projectile" << endl;

			info.push_back(x);
			info.push_back(colision);
			collide = true;
		}
	}

	if (!collide) {
		info.push_back(-1);
		info.push_back(-1);
	}
}


void GameGestion::collidePlayer(Object& o, Player& p ,std::vector<int>& info) {
	bool collide = false;

    int colision =collidePosition(o, p);

    if (colision!=-1) {
        info.push_back(0);
        info.push_back(colision);
        collide=true;
    }

	if (!collide) {
		info.push_back(-1);
		info.push_back(-1);
	}
}


void GameGestion::LimitMap() {
	std::vector<float> limit;
	_map.getLimitMap(limit);
	sf::Vector2f newpos;

	if (_player.getPosition().x < limit[2]) {
		newpos = {limit[2], _player.getPosition().y};
		_player.setPosition(newpos);
	}
	else if (_player.getPosition().x >= limit[0]) {
		newpos = {limit[0], _player.getPosition().y};
		_player.setPosition(newpos);
	}
	else if (_player.getPosition().y > limit[1]) {
		newpos = {_player.getPosition().x, limit[1]};
		_player.setPosition(newpos);
	}
	else if (_player.getPosition().y < limit[3]) {
		newpos = {_player.getPosition().x, limit[3]};
		_player.setPosition(newpos);
	}

	if(_player.isAlive() && _player2.isAlive()){
        if (_player2.getPosition().x < _player.getPosition().x-362) {
            newpos = {_player.getPosition().x-362, _player2.getPosition().y};
            _player2.setPosition(newpos);
        }
        if (_player2.getPosition().x >= _player.getPosition().x+362) {
            newpos = {_player.getPosition().x+362, _player2.getPosition().y};
            _player2.setPosition(newpos);
        }
        if (_player2.getPosition().y > _player.getPosition().y+271) {
            newpos = {_player2.getPosition().x, _player.getPosition().y+271};
            _player2.setPosition(newpos);
        }
        if (_player2.getPosition().y < _player.getPosition().y-271) {
            newpos = {_player2.getPosition().x, _player.getPosition().y-271};
            _player2.setPosition(newpos);
        }
    } else if (_player2.isAlive()) {
        if (_player2.getPosition().x < limit[2]) {
            newpos = {limit[2], _player2.getPosition().y};
            _player2.setPosition(newpos);
        }
        else if (_player2.getPosition().x >= limit[0]) {
            newpos = {limit[0], _player2.getPosition().y};
            _player2.setPosition(newpos);
        }
        else if (_player2.getPosition().y > limit[1]) {
            newpos = {_player2.getPosition().x, limit[1]};
            _player2.setPosition(newpos);
        }
        else if (_player2.getPosition().y < limit[3]) {
            newpos = {_player2.getPosition().x, limit[3]};
            _player2.setPosition(newpos);
        }
	}
}


void GameGestion::LimitMapBoss()
{
	std::vector<float> limit;
	_map.getLimitMapBoss(limit);
	sf::Vector2f newpos;

	if (_player.getPosition().x < limit[0]) {
		newpos = {limit[0], _player.getPosition().y};
		_player.setPosition(newpos);
	}
	if (_player.getPosition().x >= limit[2]) {
		newpos = {limit[2], _player.getPosition().y};
		_player.setPosition(newpos);
	}
	if (_player.getPosition().y > limit[3]) {
		newpos = {_player.getPosition().x, limit[3]};
		_player.setPosition(newpos);
	}
	if (_player.getPosition().y < limit[1]) {
		newpos = {_player.getPosition().x, limit[1]};
		_player.setPosition(newpos);
	}
	if (_player2.getPosition().x < limit[0]) {
		newpos = {limit[0], _player2.getPosition().y};
		_player2.setPosition(newpos);
	}
	if (_player2.getPosition().x >= limit[2]) {
		newpos = {limit[2], _player2.getPosition().y};
		_player2.setPosition(newpos);
	}
	if (_player2.getPosition().y > limit[3]) {
		newpos = {_player2.getPosition().x, limit[3]};
		_player2.setPosition(newpos);
	}
	if (_player2.getPosition().y < limit[1]) {
		newpos = {_player2.getPosition().x, limit[1]};
		_player2.setPosition(newpos);
	}
}


void GameGestion::collideWallGestion() {
	sf::Vector2f newpos;
	std::vector<int> infoPlayer;
	std::vector<int> infoPlayer2;

	std::vector<Object*> wallList;
	wallList = _map.getWallList();
	collideWall(_player, wallList, infoPlayer);
	collideWall(_player2, wallList, infoPlayer2);

	int indice = infoPlayer[0];
	int typeCollide = infoPlayer[1];
	int indice2 = infoPlayer2[0];
	int typeCollide2 = infoPlayer2[1];

	if (indice != -1 && typeCollide != -1) {
		switch (typeCollide) { // orientation de la colision
		case -1:
			break;

		case 1: // colision du joueur allant vers le bas
			// on empeche le joueur de traverser le Wall
			newpos = {_player.getPosition().x, wallList[indice]->getPosition().y - 48};
			_player.setPosition(newpos);
			break;
		case 2: // colision du joueur allant vers la haut
			newpos = {_player.getPosition().x, wallList[indice]->getPosition().y + wallList[indice]->getSprite().getGlobalBounds().height};
			_player.setPosition(newpos);
			break;
		case 3: // colision du joueur allant vers la droite
			newpos = {wallList[indice]->getPosition().x - 48, _player.getPosition().y};
			_player.setPosition(newpos);
			break;
		case 4: // colision du joueur allant vers le gauche
			newpos = {wallList[indice]->getPosition().x + 48, _player.getPosition().y};
			_player.setPosition(newpos);
			break;
		}

		collideVisitor(_player, *wallList[indice]);
	}

	if (indice2 != -1 && typeCollide2 != -1) {
		switch (typeCollide2) { // orientation de la colision
		case -1:
			break;

		case 1: // colision du joueur allant vers le bas
			// on empeche le joueur de traverser le Wall
			newpos = {_player2.getPosition().x, wallList[indice2]->getPosition().y - 48};
			_player2.setPosition(newpos);
			break;
		case 2: // colision du joueur allant vers la haut
			newpos = {_player2.getPosition().x, wallList[indice2]->getPosition().y + wallList[indice2]->getSprite().getGlobalBounds().height};
			_player2.setPosition(newpos);
			break;
		case 3: // colision du joueur allant vers la droite
			newpos = {wallList[indice2]->getPosition().x - 48, _player2.getPosition().y};
			_player2.setPosition(newpos);
			break;
		case 4: // colision du joueur allant vers le gauche
			newpos = {wallList[indice2]->getPosition().x + 48, _player2.getPosition().y};
			_player2.setPosition(newpos);
			break;
		}

		collideVisitor(_player2, *wallList[indice2]);
	}
}


void GameGestion::collideProjectileGestion() {
	std::vector<int> infoWall;
	std::vector<int> infoWall2;

	std::vector<int> infoMonster;
	std::vector<int> infoMonster2;

	std::vector<Object*> wallList;
	std::vector<Monster*> monsterList;

	Projectile& _projectile = *_player.getProjectile();
	Projectile& _projectile2 = *_player2.getProjectile();
	if (_projectile.isShot() || _projectile2.isShot()) {
		wallList = _map.getWallList();
		collideWall(_projectile, wallList, infoWall);
		collideWall(_projectile2, wallList, infoWall2);

		monsterList = _map.getMonsters();
		collideMonster(_projectile, monsterList, infoMonster);
		collideMonster(_projectile2, monsterList, infoMonster2);

		int indice = infoWall[0];
		int typeCollide = infoWall[1];
		int indiceMonster = infoMonster[0];
		int TypeCollideMonster = infoMonster[1];
		int indice2 = infoWall2[0];
		int typeCollide2 = infoWall2[1];
		int indiceMonster2 = infoMonster2[0];
		int TypeCollideMonster2 = infoMonster2[1];

		if (indice != -1 && typeCollide != -1) 
			collideVisitor(_projectile, *wallList[indice]);
		
		if (indiceMonster != -1 && TypeCollideMonster != -1) 
			collideVisitor(_projectile, *monsterList[indiceMonster]);
		
		if (indice2 != -1 && typeCollide2 != -1)
			collideVisitor(_projectile2, *wallList[indice2]);

		if (indiceMonster2 != -1 && TypeCollideMonster2 != -1)
			collideVisitor(_projectile2, *monsterList[indiceMonster2]);
	}
}


void GameGestion::collideMonsterGestion() {
	sf::Vector2f newpos;
	std::vector<int> infoPlayer;
	std::vector<int> infoPlayer2;

	std::vector<Monster*> MonsterList;
	MonsterList = _map.getMonsters();
	collideMonster(_player, MonsterList, infoPlayer);
	collideMonster(_player2, MonsterList, infoPlayer2);

	int indice = infoPlayer[0];
	int typeCollide = infoPlayer[1];
	int indice2 = infoPlayer2[0];
	int typeCollide2 = infoPlayer2[1];
	std::vector<int> MonsterToKill;

	if ((indice != -1 && typeCollide != -1)) {
		switch (typeCollide) { // orientation de la colision
		case -1:
			break;

		case 1: // colision du joueur allant vers le bas
			// on empeche le joueur de traverser le Wall
			newpos = {_player.getPosition().x, MonsterList[indice]->getPosition().y - 48};
			_player.setPosition(newpos);
			break;
		case 2: // colision du joueur allant vers la haut
			newpos = {_player.getPosition().x, MonsterList[indice]->getPosition().y + MonsterList[indice]->getSprite().getGlobalBounds().height};
			_player.setPosition(newpos);
			break;
		case 3: // colision du joueur allant vers la droite
			newpos = {MonsterList[indice]->getPosition().x - 48, _player.getPosition().y};
			_player.setPosition(newpos);
			break;
		case 4: // colision du joueur allant vers le gauche
			newpos = {MonsterList[indice]->getPosition().x + 48, _player.getPosition().y};
			_player.setPosition(newpos);
			break;
		}

		collideVisitor(_player, *MonsterList[indice]);
	}

	if ((indice2 != -1 && typeCollide2 != -1)) {
		switch (typeCollide2) { // orientation de la colision
		case -1:
			break;

		case 1: // colision du joueur allant vers le bas
			// on empeche le joueur de traverser le Wall
			newpos = {_player2.getPosition().x, MonsterList[indice2]->getPosition().y - 48};
			_player2.setPosition(newpos);
			break;
		case 2: // colision du joueur allant vers la haut
			newpos = {_player2.getPosition().x, MonsterList[indice2]->getPosition().y + MonsterList[indice2]->getSprite().getGlobalBounds().height};
			_player2.setPosition(newpos);
			break;
		case 3: // colision du joueur allant vers la droite
			newpos = {MonsterList[indice2]->getPosition().x - 48, _player2.getPosition().y};
			_player2.setPosition(newpos);
			break;
		case 4: // colision du joueur allant vers le gauche
			newpos = {MonsterList[indice2]->getPosition().x + 48, _player2.getPosition().y};
			_player2.setPosition(newpos);
			break;
		}
		collideVisitor(_player2, *MonsterList[indice2]);
	}
}


void GameGestion::collideVisitor(Object& o1, Object& o2) {
	o2.collide(o1);
	o1.collide(o2);
}


void GameGestion::updateMobs() {
	_map.updateObjects(_player, _player2);
		
    std::vector<Object*> wallList;
    std::vector<Monster*> monsters;
    wallList = _map.getWallList();
    monsters = _map.getMonsters();

    std::vector<Projectile*> fireballs;

    for (int i = 0; i < monsters.size(); i++) {
        if (monsters[i]->getProjectile() != nullptr) {
            fireballs.push_back(monsters[i]->getProjectile());

            int curr_ind = fireballs.size()-1;

            updateFireballs(fireballs, curr_ind, wallList);
        }

        if (monsters[i]->getProjectiles() != nullptr) {
            for (int j = 0; j < monsters[i]->getProjectiles()->size(); j++) {
                if ((*(monsters[i]->getProjectiles()))[j] != nullptr) {
                    fireballs.push_back((*(monsters[i]->getProjectiles()))[j]);

                    int curr_ind = fireballs.size()-1;

                    updateFireballs(fireballs, curr_ind, wallList);
                }
            }
        }
    }	

	for (Monster* mnt : monsters) {
		sf::Vector2f newpos;
		std::vector<int> info;

		collideWall(*mnt, wallList, info);

		int indice = info[0];
		int typeCollide = info[1];

		if (indice != -1 && typeCollide != -1) {
			switch (typeCollide) { // orientation de la colision
			case -1:
				break;

			case 1: // colision du joueur allant vers le bas
				// on empeche le joueur de traverser le Wall
				newpos = {mnt->getPosition().x, wallList[indice]->getPosition().y - 48};
				mnt->setPosition(newpos);
				break;
			case 2: // colision du joueur allant vers la haut
				newpos = {mnt->getPosition().x, wallList[indice]->getPosition().y + wallList[indice]->getSprite().getGlobalBounds().height};
				mnt->setPosition(newpos);
				break;
			case 3: // colision du joueur allant vers la droite
				newpos = {wallList[indice]->getPosition().x - 48, mnt->getPosition().y};
				mnt->setPosition(newpos);
				break;
			case 4: // colision du joueur allant vers le gauche
				newpos = {wallList[indice]->getPosition().x + 48, mnt->getPosition().y};
				mnt->setPosition(newpos);
				break;
			}

			collideVisitor(*mnt, *wallList[indice]);
		}
	}
}


void GameGestion::updateFireballs(std::vector<Projectile*>& fireballs, int curr_ind, std::vector<Object*>& wallList) {
	std::vector<int> infoWall;
	std::vector<int> infoPlayer;

	if (fireballs[curr_ind] != nullptr) {
		fireballs[curr_ind]->arrowOutOfBounds();

		if(fireballs[curr_ind]->isShot()) {
			collideWall(*fireballs[curr_ind],wallList,infoWall);
			collidePlayer(*fireballs[curr_ind],_player,infoPlayer);

			int indice =infoWall[0];
			int typeCollide=infoWall[1];
			int indicePlayer=infoPlayer[0];
			int TypeCollidePlayer=infoPlayer[1];

			if(indice!= -1 && typeCollide!= -1){
				collideVisitor(*fireballs[curr_ind],*wallList[indice]);
			}

			if(indicePlayer!= -1 && TypeCollidePlayer!= -1){
				collideVisitor(*fireballs[curr_ind],_player);
			}
		}
	}
}


void GameGestion::checkLifeMonster(std::vector<bool> &control) {
	control = {true, true, true, true};

	std::vector<Monster*> monsters;
	monsters = _map.getMonsters();

	std::vector<float> limit;
	_map.getLimitMap(limit);

	for (int i = 0; i < monsters.size(); i++) {
		if (monsters[i]->getPosition().x >= 0 && monsters[i]->getPosition().x <= limit[0]/2 && monsters[i]->getPosition().y >= limit[3] && monsters[i]->getPosition().y <= 0)
			control[0] = false;
		
		else if (monsters[i]->getPosition().x >= 0 && monsters[i]->getPosition().x <= limit[0]/2 && monsters[i]->getPosition().y <= limit[1] && monsters[i]->getPosition().y >= 0)
			control[1] = false;
		
		else if (monsters[i]->getPosition().x >= limit[0]/2 && monsters[i]->getPosition().x <= limit[0] && monsters[i]->getPosition().y <= limit[1] && monsters[i]->getPosition().y >= 0)
			control[2] = false;
		
		else if ((monsters[i]->getPosition().x >= limit[0]/2 && monsters[i]->getPosition().x <= limit[0] && monsters[i]->getPosition().y <=0 && monsters[i]->getPosition().y >= limit[3]))
			control[3] = false;
		
	}
}


Map& GameGestion::getMap() const {
    return _map;
}

const int GameGestion::getObjectSize() const {
    return _player.getBlockSize();
}

std::vector<Player*>& GameGestion::getPlayerVector() {
    return _playerVector;
}
