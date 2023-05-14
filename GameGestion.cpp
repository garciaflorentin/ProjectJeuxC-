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
	collideWallGestion();
	LimitMap();

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
			std::cout<<"up"<<std::endl;
        return 1; //up collide
    } else if (sprite1x < sprite2x + SPRITE_SIZE && sprite1x + SPRITE_SIZE > sprite2x + SPRITE_SIZE &&
               sprite1y + SPRITE_SIZE > sprite2y && sprite1y + SPRITE_SIZE < sprite2y + SPRITE_SIZE) {
							std::cout<<"left"<<std::endl;

        return 2;//LEFT_COLLIDE; o2 tape sur la gauche de o1
    } else if (sprite1x < sprite2x && sprite1x + SPRITE_SIZE > sprite2x && sprite1y < sprite2y + SPRITE_SIZE &&
               sprite1y + SPRITE_SIZE > sprite2y) {
							std::cout<<"right"<<std::endl;

        return 3;//RIGHT_COLLIDE;
    } else if (sprite1x < sprite2x + SPRITE_SIZE && sprite1x + SPRITE_SIZE > sprite2x &&
               sprite1y + SPRITE_SIZE > sprite2y && sprite1y + SPRITE_SIZE < sprite2y + SPRITE_SIZE) {
							std::cout<<"down"<<std::endl;

        return 4;//DOWN_COLLIDE;
    }
	std::cout<<"rien"<<std::endl;
    return -1;//NO_COLLIDE;
}

int GameGestion::collidePosition2(Object* object1, Object* object2) {
	sf::Sprite sprite1=*object1->getSprite();
	sf::Sprite sprite2=*object2->getSprite();

    sf::FloatRect rect1 = sprite1.getGlobalBounds();
    sf::FloatRect rect2 = sprite2.getGlobalBounds();
    
    if (!rect1.intersects(rect2)) {
        return -1;
    }

    float overlapX = std::min(rect1.left + rect1.width, rect2.left + rect2.width) - std::max(rect1.left, rect2.left);
    float overlapY = std::min(rect1.top + rect1.height, rect2.top + rect2.height) - std::max(rect1.top, rect2.top);

    if (overlapX + 24 > overlapY) {
        if (rect1.top< rect2.top) {std::cout<<"up"<<std::endl;
            return 1;
        } else {							std::cout<<"down"<<std::endl;

            return 2;
        }
    } else {
        if (rect1.left < rect2.left) {							std::cout<<"left"<<std::endl;

            return 3;
        } else {							std::cout<<"right"<<std::endl;

            return 4;
        }
    }
}

void GameGestion::collideWall(Character* c, std::vector <Object*>& wallList,std::vector<int>& info) {
	std::cout<<"collideWall"<<std::endl;
	bool collide =false;

    for (int x = 0; x < wallList.size(); x++) {

		int colision =collidePosition2(c, (wallList)[x]);

        if (colision!=-1) {
			info.push_back(x);
			info.push_back(colision);
			collide=true;
            
        }
    }
	if(!collide){
		info.push_back(-1);
		info.push_back(-1);
	}
    std::cout<<"info size= "<<info.size()<<std::endl;
}


void GameGestion::LimitMap(){
std::vector<int> limit;
_map->getLimitMap(limit);
sf::Vector2f newpos;

   if(player->getPosition().x < limit[2]){
	newpos= {limit[2],player->getPosition().y};
	player->setPosition(newpos);
   }else if(player->getPosition().x >= limit[0]){
		newpos={ limit[0],player->getPosition().y};
		player->setPosition(newpos);
   }else if(player->getPosition().y > limit[1]){
		newpos={player->getPosition().x,limit[1]};
		player->setPosition(newpos);
   }
   else if(player->getPosition().y < limit[3]){
		newpos={player->getPosition().x,limit[3]};
		player->setPosition(newpos);
   }

}

void GameGestion::collideWallGestion(){
	std::cout<<"collideWallGestion"<<std::endl;

	sf::Vector2f newpos;
	std::vector<int> info;
	std::vector<Object*> wallList;
	wallList = *_map->getWallList();
	collideWall(player,wallList,info);

	int indice=info[0];
	int typeCollide =info[1];

	 if(indice!= -1 && typeCollide!= -1){
		switch (typeCollide){//orientation de la colision
			case -1:break;

			case 1:// colision du joueur allant vers le bas
			//on empeche le joueur de traverser le Wall
			newpos=  {player->getPosition().x,wallList[indice]->getPosition().y-48};
			player->setPosition(newpos);
			break;
			case 2:// colision du joueur allant vers la haut
			newpos= {player->getPosition().x,wallList[indice]->getPosition().y+wallList[indice]->getSprite()->getGlobalBounds().height};
			player->setPosition(newpos);
			break;
			case 3:// colision du joueur allant vers la droite
			newpos=  {wallList[indice]->getPosition().x-48,player->getPosition().y};
			player->setPosition(newpos);
			break;
			case 4:// colision du joueur allant vers le gauche
			newpos=  {wallList[indice]->getPosition().x+48,player->getPosition().y};
			player->setPosition(newpos);
			break;
		}
		collideVisitor(player,wallList[indice]);
	}
}

void GameGestion::collideVisitor(Object* player,Object * o){
	std::cout<<"collideVisitor"<<std::endl;
	o->collide(player);
}