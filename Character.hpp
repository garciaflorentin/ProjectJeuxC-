#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Object.hpp"
#include "EnumOrientation.hpp"
#include "Heart.hpp"


class Character : public Object {

protected:
	int damageAttack;
	double speed;
	EnumOrientation _enumOrientation;
	enum Orientation { Down, Left, Right, Up };
	bool _isAlive;

	sf::Vector2i anim;
	virtual void setDamage() = 0;
	Heart* life;

public:

	Character();
	void takeDamage(int heartQuarters);
	virtual void attack(Character* target) = 0;
	virtual void moveTo(sf::Vector2i nextPos) = 0;
	const bool isAlive() const{
		return _isAlive;
	}


};
#endif

