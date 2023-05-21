#ifndef KEYWINDOW_HPP
#define KEYWINDOW_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Player.hpp"



class KeyWindow {

private:

	const float windowWidth = 1024.0, windowHeight = 55;
	sf::View* keyView;
	sf::RenderTexture* keyTexture;
	sf::Sprite* keySprite;
    sf::Texture* texture;
    Player* player;

public:

	KeyWindow(Player* p);
	~KeyWindow();
	void drawTo(sf::RenderWindow* target);
	void updateWindow();
	sf::View* getKeyView() {
		return keyView;
	}


};
#endif