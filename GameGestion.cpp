#include "GameGestion.hpp"


GameGestion::GameGestion() {
		std::cout<<"a"<<std::endl;
		player = new Player("object.png", {0,0});
		std::cout<<"a"<<std::endl;
		_map= new Map();
		//_map->createMap();
		playerVector[0]=player;
		playerVector[1]=nullptr;
		std::cout << "GameGestion Constructeur" << std::endl;

	}

	GameGestion::~GameGestion() {
		delete player;
		delete _map;
	}


	std::vector<Object*>* GameGestion::toDrawUpdate(std::vector<sf::Vector2i> currentWindow){
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
			player->move({5,0});
		}
	}

	std::cout << "x =" << player->getPosition().x<< std::endl;
	std::cout << "y =" << player->getPosition().y<< std::endl;

}



	void GameGestion::setPlayer(sf::Sprite* sprite) {
		playerVector[0]->setUpCharacter();
		playerVector[1]->setUpCharacter();

	}
