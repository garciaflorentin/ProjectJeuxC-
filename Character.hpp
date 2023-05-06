#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Object.hpp"
#include "EnumOrientation.hpp"
//#include "Hearth.hpp"


class Character : public Object {

private:
	int damageAttack;
	double speed;
	EnumOrientation _enumOrientation;
	sf::Vector2i anim;
	virtual void setDamage() = 0;
	//Hearth* life;

public:

	Character();
	void takeDamage(int heartQuarters);
	virtual void attack(Character* target) = 0;
	virtual void moveTo(sf::Vector2i nextPos) = 0;


};
#endif

