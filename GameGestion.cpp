#include "GameGestion.hpp"


GameGestion::GameGestion() {
		player = new Player("object.png", {0,0});
		_map= new Map();
		_map->createMap();
		playerVector = new std::vector<Player*>{ player, nullptr };

	}

	GameGestion::~GameGestion() {
		delete player;
		delete _map;
	}


	std::vector<Object*>* GameGestion::toDrawUpdate(std::vector<sf::Vector2f>* currentWindow){
		return _map->objectToDraw(currentWindow);
	}


void GameGestion::keyEvent(sf::Event e) {
	if (time.getElapsedTime().asMilliseconds() >= 50) { // si le temps qui c'est ecoul� est plus grand que 50 ms on fait le move
		if (e.key.code == sf::Keyboard::Down) {
			//std::cout << " D " << std::endl;
			player->getAnim()->x++;
			player->getAnim()->y = Down;
			player->move({0,5});
		}
		else if ((e.key.code == sf::Keyboard::Up)) {
			//std::cout << " U " << std::endl;
			player->getAnim()->x++;
			player->getAnim()->y = Up;
			player->move({0,-5});
		}
		else if ((e.key.code == sf::Keyboard::Right)) {
			//std::cout << " R " << std::endl;
			player->getAnim()->x++;
			player->getAnim()->y = Right;
			player->move({5,0});
		}
		else if ((e.key.code == sf::Keyboard::Left)) {
			//std::cout << " L " << std::endl;
			player->getAnim()->x++;
			player->getAnim()->y = Left;
			player->move({-5,0});
		}
	}
	collideGestion();

	std::cout << "x =" << player->getPosition().x<< std::endl;
	std::cout << "y =" << player->getPosition().y<< std::endl;

}



void GameGestion::setPlayer(sf::Sprite* sprite) {
		(*playerVector)[0]->setUpCharacter();
		//(*playerVector)[1]->setUpCharacter();
}

//interface colision

int GameGestion::collidePosition(Object* object1, Object* object2){;

int SPRITE_SIZE = object1->getBlockSize();

    float sprite1x = object1->getPosition().x;
    float sprite1y = object1->getPosition().y;
	float sprite2x = object2->getPosition().x;
    float sprite2y = object2->getPosition().y;

    if (sprite1x < sprite2x + SPRITE_SIZE && sprite1x + SPRITE_SIZE > sprite2x && sprite1y < sprite2y + SPRITE_SIZE &&
        sprite1y + SPRITE_SIZE > sprite2y) {
        return 1; //up collide
    } else if (sprite1x < sprite2x + SPRITE_SIZE && sprite1x + SPRITE_SIZE > sprite2x + SPRITE_SIZE &&
               sprite1y + SPRITE_SIZE > sprite2y && sprite1y + SPRITE_SIZE < sprite2y + SPRITE_SIZE) {
        return 2;//LEFT_COLLIDE; o2 tape sur la gauche de o1
    } else if (sprite1x < sprite2x && sprite1x + SPRITE_SIZE > sprite2x && sprite1y < sprite2y + SPRITE_SIZE &&
               sprite1y + SPRITE_SIZE > sprite2y) {
        return 3;//RIGHT_COLLIDE;
    } else if (sprite1x < sprite2x + SPRITE_SIZE && sprite1x + SPRITE_SIZE > sprite2x &&
               sprite1y + SPRITE_SIZE > sprite2y && sprite1y + SPRITE_SIZE < sprite2y + SPRITE_SIZE) {
        return 4;//DOWN_COLLIDE;
    }
    return 0;//NO_COLLIDE;
}

std::vector<int>& GameGestion::collideWall(Character* c, std::vector <Object*>& wallList) {
    for (int x = 0; x < wallList.size(); x++) {
		int colision =collidePosition(c, (wallList)[x]);
        if (colision!=0) {
			std::vector<int> info;
			info.push_back(x);
			info.push_back(colision);
            return info;
        }
    }
    std::vector<int> info;
			info.push_back(-1);
			info.push_back(-1);
            return info;
}

std::vector<Object*>& GameGestion::getWallMap(){
	std::vector<Object*> wallList;
	for(int i=0;i< _map->getMap()->size();i++){
		if(!(*_map->getMap())[i]->isPassable()){
			wallList.push_back((*_map->getMap())[i]);
		}
	}
	return wallList;
}

void GameGestion::collideGestion(){
	 if(collideWall(player,getWallMap())[0]!= -1 && collideWall(player,getWallMap())[1]!= -1){
		switch ((collideWall(player,getWallMap())[1])){//orientatioj de la colision
			case 0:break;

			case 1:// colision du joueur allant vers le haut
			//on empeche le joueur de traverser le Wall
			sf::Vector2f newpos(player->getPosition().x,getWallMap()[collideWall(player,getWallMap())[0]]->getPosition().y - 48);
			player->setPosition(newpos);
			break;
			case 2:// colision du joueur allant vers la gauche
			sf::Vector2f newpos(getWallMap()[collideWall(player,getWallMap())[0]]->getPosition().x + 48,player->getPosition().y);
			player->setPosition(newpos);
			break;
			case 3:// colision du joueur allant vers la droite
			sf::Vector2f newpos(getWallMap()[collideWall(player,getWallMap())[0]]->getPosition().x + 48,player->getPosition().y);
			player->setPosition(newpos);
			case 4:// colision du joueur allant vers le bas
			sf::Vector2f newpos(player->getPosition().x,getWallMap()[collideWall(player,getWallMap())[0]]->getPosition().y);
			player->setPosition(newpos);
			break;
		}
	}
}
