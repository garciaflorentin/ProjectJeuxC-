#include "GameGestion.hpp"
#include <memory>

GameGestion::GameGestion() {
		player = new Player("player1.png", {0,0});
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

	bool GameGestion::drawProjectile(std::vector<sf::Vector2f>* currentWindow){
			Projectile* _projectile= (*playerVector)[0]->getProjectile();
			if(_projectile->isShooted()){
			std::cout<<"projX="<<(*playerVector)[0]->getProjectile()->getPosition().x<<std::endl;
			std::cout<<"projY="<<(*playerVector)[0]->getProjectile()->getPosition().y<<std::endl;
			}
			if (_projectile->isShooted() && (_projectile->getPosition().x >= ((*currentWindow)[0].x - 200) && _projectile->getPosition().y >= ((*currentWindow)[0].y)-200) && (_projectile->getPosition().x <= ((*currentWindow)[1].x+50) && _projectile->getPosition().y < ((*currentWindow)[1].y)+50) )  {
					return !((*playerVector)[0]->getProjectile()==nullptr);
			}else{return false;}
	}


void GameGestion::keyEvent(sf::Event e) {

if(time.getElapsedTime().asMilliseconds()>= 100){
		if(!player->WeaponIsUsed()){
			if (e.key.code == sf::Keyboard::Down) {
				//std::cout << " D " << std::endl;
				player->getAnim()->x++;
				player->getAnim()->y = 0;
				player->setOrientation(2);
				player->move({0,5});
			}
			else if ((e.key.code == sf::Keyboard::Up)) {
				//std::cout << " U " << std::endl;
				player->getAnim()->x++;
				player->getAnim()->y = 4;
				player->setOrientation(0);
				player->move({0,-5});
			}
			else if ((e.key.code == sf::Keyboard::Right)) {
				//std::cout << " R " << std::endl;
				player->getAnim()->x++;
				player->getAnim()->y = 2;
				player->setOrientation(3);
				player->move({5,0});
			}
			else if ((e.key.code == sf::Keyboard::Left)) {
				//std::cout << " L " << std::endl;
				player->getAnim()->x++;
				player->getAnim()->y = 6;
				player->setOrientation(1);
				player->move({-5,0});
			}
			(*getPlayerVector())[0]->updateSprite();

		}
		
			if ((e.key.code == sf::Keyboard::A )) 
			{
				player->useSword();
			}else if ((e.key.code == sf::Keyboard::Z)) 
			{
				player->useBow();
			}else if ((e.key.code == sf::Keyboard::E)) 
			{
				player->useWand();
			}



	}
}

void GameGestion::updateGame(){

	if(player->WeaponIsUsed()){
		if(player->swordIsUsed()){player->useSword();}
		else if(player->bowIsUsed()){player->useBow();}
		else{player->useWand();}
		}
		
	player->getProjectile()->arrowOutOfBounds();
	collideProjectileGestion();
	collideWallGestion();
	LimitMap();
		
}


void GameGestion::setPlayer(sf::Sprite* sprite) {
		(*playerVector)[0]->setUpCharacter();
		//(*playerVector)[1]->setUpCharacter();
}

//interface colision


int GameGestion::collidePosition(Object* object1, Object* object2) {
	sf::Sprite sprite1=*object1->getSprite();
	sf::Sprite sprite2=*object2->getSprite();

    sf::FloatRect rect1 = sprite1.getGlobalBounds();
    sf::FloatRect rect2 = sprite2.getGlobalBounds();
    
    if (!rect1.intersects(rect2)) {
        return -1; 
    }

    float overlapX = std::min(rect1.left + rect1.width, rect2.left + rect2.width) - std::max(rect1.left, rect2.left);
    float overlapY = std::min(rect1.top + rect1.height, rect2.top + rect2.height) - std::max(rect1.top, rect2.top);

    if (overlapX + 16 > overlapY) {
        if (rect1.top< rect2.top) { std::cout<<"up"<<std::endl;
            return 1;
        } else {	std::cout<<"down"<<std::endl;						
            return 2;
        }
    } else {
        if (rect1.left < rect2.left) {			std::cout<<"left"<<std::endl;				

            return 3;
        } else {						std::cout<<"right"<<std::endl;

            return 4;
        }
    }
}

void GameGestion::collideWall(Object* o, std::vector <Object*>& wallList,std::vector<int>& info) {
	bool collide =false;

    for (int x = 0; x < wallList.size(); x++) {

		int colision =collidePosition(o, (wallList)[x]);

        if (colision!=-1) {
			std::cout<<"collide: collideWall"<<std::endl;
			info.push_back(x);
			info.push_back(colision);
			collide=true;
            
        }
    }
	if(!collide){
		info.push_back(-1);
		info.push_back(-1);
	}
}


void GameGestion::LimitMap(){
std::vector<float> limit;
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

	sf::Vector2f newpos;
	std::vector<int> infoPlayer;
	std::vector<Object*> wallList;
	wallList = *_map->getWallList();
	collideWall(player,wallList,infoPlayer);
	int indice=infoPlayer[0];
	int typeCollide =infoPlayer[1];
	


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

void GameGestion::collideProjectileGestion(){

	std::vector<int> infoProjectile;
	std::vector<Object*> wallList;
	Projectile* _projectile;// = new Projectile(*(*playerVector)[0]->getProjectile());
	//std::shared_ptr<Projectile> _projectile = std::make_shared<Projectile(*(*playerVector)[0]->getProjectile())>();
	_projectile=(*playerVector)[0]->getProjectile();

	if(_projectile->isShooted()){	

		std::cout<<"projectilTire"<<std::endl;
		wallList = *_map->getWallList();
		collideWall(_projectile,wallList,infoProjectile);

		int indice =infoProjectile[0];
		int typeCollide=infoProjectile[1];


		if(indice!= -1 && typeCollide!= -1){
			std::cout<<"colisionProjectile : GameGestion"<<std::endl;
			collideVisitor(_projectile,wallList[indice]);
			//delete _projectile;

		}
}
}



void GameGestion::collideVisitor(Object* o1,Object * o2){
	o1->collide(o2);
	o2->collide(o1);
}




/*
void GameGestion::addMonster(Monster& mst) {
	_map->addObject(&mst);
} 
*/