#ifndef _GAMEGESTION_HPP_
#define _GAMEGESTION_HPP_

/// Special library
#include <SFML/Graphics.hpp>

/// STL
#include <iostream>
#include <vector>
#include <string>

/// Header create
//#include "Player.hpp"
#include "Object.hpp"

class GameGestion{
private:

	//sf::Sprite* player1; //sprite du joueur
	sf::Vector2i anim;
	std::vector< sf::Sprite*> spriteVector;
	Object* player;
	sf::Clock time;


public:

	GameGestion() {
		player = new Object("object.png", {0,0});
		std::cout << "GameGestion Constructeur" << std::endl;

	}

	~GameGestion() {
		delete player;
	}


	enum Orientation { Down, Left, Right, Up };

	sf::Sprite* getPlayerSprite() const;// retourne le sprites du joueur

	const int getObjectSize() const {
		return player->getBlockSize();
	}

	std::vector< sf::Sprite*>& getSpriteVector() {
		return spriteVector;
	}

	
	sf::Vector2i& getAnimVector() {
		return anim;
	}

	void setPlayer(sf::Sprite* player); // ajoute un joeur au jeu

	void keyEvent(sf::Event e);//focntion interaction 


};
#endif
