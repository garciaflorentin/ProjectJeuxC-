#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>
#include "Character.hpp"
#include "Chest.hpp"
class Chest;

class Player : public Character {

private:
	
	sf::Music* attackSimple;

public:

	Player(const char* nameObject, sf::Vector2f initPos);

	~Player() {
		delete attackSimple;
	};

	void openChest(Chest* chest);
	virtual void setDamage(Character* target);
	virtual void attack(Character* target) override;
	void move(sf::Vector2i deplacement);

	void collide(Object* o){}

	void useSword();
	


};
#endif