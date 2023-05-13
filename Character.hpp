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


	sf::Vector2i* anim;
	Heart* life;
    virtual void setDamage(Character* target) = 0;
	
public:

Character(const char* nameObject, sf::Vector2f initPos): Object(nameObject, initPos) {
	anim = new sf::Vector2i; // probleme du segmentation fault
	anim->x = 1;
	anim->y = Down;

	life = new Heart();

	_isAlive = true;
}

~Character() {
	delete life;
}


	void takeDamage(int heartQuarters);
	virtual void attack(Character* target) = 0;
	virtual void move(sf::Vector2i deplacement) = 0;
	const bool isAlive() const{
		return _isAlive;
	}

	sf::Vector2i* getAnim(){
		return anim;
	}

	Heart* getlife() const {
		return life;
	}

	void setAnim(int i,int y);

	void setUpCharacter();

	void updateSprite();

	 const int getBlockSize() override;



};
#endif

