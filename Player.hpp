#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Character.hpp"
//#include "Sword.hpp"
#include "Chest.hpp"

class Player : public Character {

private:
	
	//Sword* _sword;

	Heart* _heart;

public:

Player(const char* nameObject, sf::Vector2f initPos): Character(nameObject,initPos) {
std::cout<<"player_constructeur"<< std::endl;
	speed = 3;
	damageAttack = 3;
	//_sword = new Sword();

}

~Player() {
	//delete _sword;
}

	void openChest(Chest* chest);
	virtual void setDamage(Character* target);
	virtual void attack(Character* target) override;
	virtual void move(sf::Vector2i deplacement);

	Heart* getLife() { return _heart; };

};
#endif