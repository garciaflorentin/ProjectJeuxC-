#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	enum Orientation { Down, Up, Right, Left };
	bool _isAlive;
	int OBJECT_SIZE = 32;
	int orientation;


	sf::Vector2i* anim;
	Heart* life;
    void setDamage(Character* target);
	
public:

	Character(const char* nameObject, sf::Vector2f initPos);

	virtual ~Character();

	int getOrientation(){
		return orientation;
	}

	void setOrientation(int _orientation){
		orientation=_orientation;
	}
	void takeDamage(int heartQuarters);
	virtual void attack(Character* target) = 0;
	virtual void move(sf::Vector2i deplacement);
	const bool isAlive() const{
		return _isAlive;
	};

	sf::Vector2i* getAnim(){
		return anim;
	};

	Heart* getlife() const {
		return life;
	};

	void setAnim(int i,int y);

	void setUpCharacter();

	void updateSprite();

	const int getBlockSize();




};
#endif

