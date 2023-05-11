#include "GameGestion.hpp"

GameGestion::GameGestion() {
	_player = new Player("object.png", {0,0});
	_map= new Map();
	_map->createMap();
	_playerVector = new std::vector<Player*>{ _player, nullptr };

}

GameGestion::~GameGestion() {
	delete[] _player;
	delete _map;
}

std::vector<Object*>* GameGestion::toDrawUpdate(std::vector<sf::Vector2i> currentWindow){
		return _map->objectToDraw(currentWindow);
}

void GameGestion::keyEvent(sf::Event e) {
	if (_time.getElapsedTime().asMilliseconds() >= 50) { // si le temps qui c'est ecoulï¿½ est plus grand que 50 ms on fait le move
		if (e.key.code == sf::Keyboard::Down) {
			//std::cout << " D " << std::endl;
			_player->getAnim()->x++;
			_player->getAnim()->y = Down;
			_player->move({0,5});
		}
		else if ((e.key.code == sf::Keyboard::Up)) {
			//std::cout << " U " << std::endl;
			_player->getAnim()->x++;
			_player->getAnim()->y = Up;
			_player->move({0,-5});
		}
		else if ((e.key.code == sf::Keyboard::Right)) {
			//std::cout << " R " << std::endl;
			_player->getAnim()->x++;
			_player->getAnim()->y = Right;
			_player->move({5,0});
		}
		else if ((e.key.code == sf::Keyboard::Left)) {
			//std::cout << " L " << std::endl;
			_player->getAnim()->x++;
			_player->getAnim()->y = Left;
			_player->move({-5,0});
		}
	}

	std::cout << "x =" << _player->getPosition().x<< std::endl;
	std::cout << "y =" << _player->getPosition().y<< std::endl;

}

	sf::Sprite* GameGestion::getPlayerSprite() const{
		return _player->getSprite();
	}

	void GameGestion::setPlayer(sf::Sprite* sprite) {
		(*_playerVector)[0]->setUpCharacter();
		//(*playerVector)[1]->setUpCharacter();
	}
