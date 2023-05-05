#include "GameGestion.hpp"

void GameGestion::keyEvent(sf::Event e) {
	if (time.getElapsedTime().asMilliseconds() >= 50) { // si le temps qui c'est ecoulé est plus grand que 50 ms on fait le move
		if (e.key.code == sf::Keyboard::Down) {
			//std::cout << " D " << std::endl;
			anim.x++;
			anim.y = Down;
			player->getSprite()->move(0, 5);
		}
		else if ((e.key.code == sf::Keyboard::Up)) {
			//std::cout << " U " << std::endl;
			anim.x++;
			anim.y = Up;
			player->getSprite()->move(0, -5);
		}
		else if ((e.key.code == sf::Keyboard::Right)) {
			//std::cout << " R " << std::endl;
			anim.x++;
			anim.y = Right;
			player->getSprite()->move(5, 0);
		}
		else if ((e.key.code == sf::Keyboard::Left)) {
			//std::cout << " L " << std::endl;
			anim.x++;
			anim.y = Left;
			player->getSprite()->move(-5, 0);
		}
	}

	std::cout << "x =" << player->getSprite()->getPosition().x << std::endl;
	std::cout << "y =" << player->getSprite()->getPosition().y<< std::endl;

}

	sf::Sprite* GameGestion::getPlayerSprite() const{
		return player->getSprite();
	}

	void GameGestion::setPlayer(sf::Sprite* sprite) {
		//player->setSprite(*sprite);
		anim.x = 1;
		anim.y = Down;
		sprite->setTextureRect(sf::IntRect(anim.x * getObjectSize() + 3, anim.y * getObjectSize() + 3, 48, 48));
		spriteVector.push_back(player->getSprite());
	}
