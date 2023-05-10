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
	int OBJECT_SIZE = 48;


	sf::Vector2i anim;
	void setDamage();	//methode commune a tous les personnages 
	Heart* life;
    virtual void setDamage(Character* target) = 0;
	
public:

	Character();
	Character(const char* nameObject, sf::Vector2f initPos) : Object(nameObject, initPos) {};

	~Character();	//Declarer un destructeur

	void takeDamage(int heartQuarters);
	virtual void attack(Character* target) = 0;
	void moveTo(sf::Vector2f nextPos);	//methode non virtuelle 
	const bool isAlive() const{
		return _isAlive;
	}

	

};
#endif

