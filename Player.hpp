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

	bool _canOpenChest = true;

	bool _canOpenChest = true;

public:

	Player(const char* nameObject, sf::Vector2f initPos);

	~Player() {
		delete attackSimple;
	};

	void openChest(Chest* chest);
	void setDamage(Character* target);
	void attack(Character* target) ;
	void move(sf::Vector2i deplacement);

	void collide(Object* o){}

	void useSword();
	


};
#endif