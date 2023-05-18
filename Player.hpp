#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>
#include "Character.hpp"
#include "Chest.hpp"
#include "Projectile.hpp"
class Chest;
class Projectile;

class Player : public Character {

private:
	
	sf::Music* SwordAttack;
	sf::Music* bowAttack;
	sf::Music* wandAttack;

	int swordAnim;
	int bowAnim;
	int wandAnim;


	Projectile* projectile;

	bool _canOpenChest = true;


public:

	Player(const char* nameObject, sf::Vector2f initPos);

	~Player();

	
	void openChest(Chest* chest);
	void setDamage(Character* target);
	void attack(Character* target) ;
	void move(sf::Vector2i deplacement);

	void collide(Object* o){};

	//weapon
	void initWeapon();
	bool WeaponIsUsed();
	void useSword();
	void useBow();
	void useWand();
	bool swordIsUsed(){
		return swordAnim!=0;
	}
	bool bowIsUsed(){
		return bowAnim!=0;
	}
	bool wandIsUsed(){
		return wandAnim!=0;
	}

	Projectile* getProjectile(){
		return projectile;
	}


};
#endif