#include "GameGestion.hpp"

void GameGestion::keyEvent(sf::Event e) {

	if (e.key.code == sf::Keyboard::Down) {
		std::cout << " D " << std::endl;
		anim.x++;
		anim.y = Down;
		player->getSprite()->move(0, 5);
	}
	else if ((e.key.code == sf::Keyboard::Up)) {
		std::cout << " U " << std::endl;
		anim.x++;
		anim.y = Up;
		player->getSprite()->move(0, -5);
	}
	else if ((e.key.code == sf::Keyboard::Right)) {
		std::cout << " R " << std::endl;
		anim.x++;
		anim.y = Right;
		player->getSprite()->move(5, 0);
	}
	else if ((e.key.code == sf::Keyboard::Left)) {
		std::cout << " L " << std::endl;
		anim.x++;
		anim.y = Left;
		player->getSprite()->move(-5, 0);
	}
}

	sf::Sprite* GameGestion::getPlayerSprite() const{
		return player->getSprite();
	}

	void GameGestion::setPlayer(sf::Sprite* sprite) {
		//player->setSprite(*sprite);
		anim.x = 1;
		anim.y = Down;
		sprite->setTextureRect(sf::IntRect(anim.x * playerSize +3, anim.y * playerSize+3, 48, 48));
		spriteVector.push_back(player->getSprite());
	}
