#ifndef LIFEWINDOW_HPP
#define LIFEWINDOW_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Heart.hpp"
#include "Object.hpp"


class LifeWindow {

private:

	const float windowWidth = 1024.0, windowHeight = 55;
	sf::View* lifeView;
	sf::RenderTexture* lifeTexture;
	sf::Sprite* lifeSprite;
	Heart* lifePlayer;

public:

	LifeWindow(Heart* HeartPlayer);
	~LifeWindow();
	void drawTo(sf::RenderWindow* target);
	void updateWindow();
	sf::View* getLifeView() {
		return lifeView;
	}


};
#endif