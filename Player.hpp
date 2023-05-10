#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Character.hpp"
#include "Sword.hpp"
#include "Chest.hpp"

class Player : public Character {

private:
	
	Sword* _sword;

public:

	Player(const char* nameObject, sf::Vector2f initPos): Character(nameObject, initPos){}
	~Player();
	void openChest(Chest* chest);


};
#endif