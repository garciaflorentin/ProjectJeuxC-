#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>
#include "Object.hpp"
#include "EnumOrientation.hpp"
#include "Heart.hpp"
#include "Chest.hpp"


class Character : public Object {

protected:
	int damageAttack;
	double speed;
	EnumOrientation _enumOrientation;
	enum Orientation { Up, Left, Down, Right };
	bool _isAlive;
	int OBJECT_SIZE;
	int orientation;
	int key;
	std::vector<bool> killedallMobs ={false,false,false,false};

	sf::Vector2i* anim;
	Heart* life;
    virtual void setDamage(Character* target) = 0;

	bool _canOpenChest = false;
	
public:
	void updateKilledallMobs(std::vector<bool>& _killedallMobs){
		killedallMobs=_killedallMobs;
	}
	std::vector<bool>& getKilledallMobs(){
		return killedallMobs;
	}


	Character(const char* nameObject, sf::Vector2f initPos);

	~Character();

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

	bool canOpenChest() const { return _canOpenChest; };
	virtual void openChest(Chest* chest)=0;

	int getKey(){
		return key;
	}

	void addKey(){
		if(key<4){
			key++;
		}
	}

};
#endif

