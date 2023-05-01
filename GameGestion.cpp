#include "GameGestion.hpp"

void GameGestion::keyEvent(sf::Event e) {

	if (e.key.code == sf::Keyboard::Down) {
		std::cout << " D " << std::endl;
		anim.x++;
		anim.y = Down;
		player1->move(0, 5);
	}
	else if ((e.key.code == sf::Keyboard::Up)) {
		std::cout << " U " << std::endl;
		anim.x++;
		anim.y = Up;
		player1->move(0, -5);
	}
	else if ((e.key.code == sf::Keyboard::Right)) {
		std::cout << " R " << std::endl;
		anim.x++;
		anim.y = Right;
		player1->move(5, 0);
	}
	else if ((e.key.code == sf::Keyboard::Left)) {
		std::cout << " L " << std::endl;
		anim.x++;
		anim.y = Left;
		player1->move(-5, 0);
	}
}

	sf::Sprite* GameGestion::getPlayer1() const{
		return player2;
	}

	void GameGestion::setPlayer1(sf::Sprite* sprite) {
		player1 = sprite;
		anim.x = 1;
		anim.y = Down;
		sprite->setTextureRect(sf::IntRect(anim.x * playerSize +3, anim.y * playerSize+3, 48, 48));
		spriteVector.push_back(player1);
	}
