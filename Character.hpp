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
	int _damageAttack;
	double _speed;
	EnumOrientation _enumOrientation;
	enum Orientation { Down, Left, Right, Up };
	bool _isAlive;

	int OBJECT_SIZE = 48;

	sf::Vector2i* _anim;
	//virtual void setDamage(Character* target) = 0;
	Heart* _life;

public:

	Character();
	Character(const char* nameObject, sf::Vector2f initPos);

	~Character() {
		delete[] _life;
	};	//Declarer un destructeur

	void takeDamage(int heartQuarters);
	virtual void attack(Character* target) = 0;
	void move(sf::Vector2f nextPos);	//methode non virtuelle 
	const bool isAlive() const{
		return _isAlive;
	}

	sf::Vector2i* getAnim(){
		return _anim;
	}

	Heart* getlife() const {
		    cout << "ici" << endl;
		return _life;
	}

	void setAnim(int i,int y);

	void setUpCharacter();

	void updateSprite();

	const int getBlockSize();
};

#endif

