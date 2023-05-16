#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Character.hpp"
//#include "Sword.hpp"
#include "Chest.hpp"
class Chest;

class Player : public Character {

private:
	
	//Sword* _sword;

	bool _canOpenChest = true;

public:

	Player(const char* nameObject, sf::Vector2f initPos);

	~Player();

	void openChest(Chest* chest);
	void setDamage(Character* target);
	void attack(Character* target) ;
	void move(sf::Vector2i deplacement);

	void collide(Object* o){}
	


};
#endif