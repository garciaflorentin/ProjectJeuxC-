#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>

class UserInterface{

    private:

    const float windowWidth = 1024.f, windowHeight = 768.f;
	sf::View* UiView;
	sf::RenderTexture* UiTexture;
	sf::Sprite* UiSprite;


    public:

    UserInterface();
	~UserInterface();
	void drawTo(sf::RenderWindow* target);
	void updateUi();
	sf::View* getUiView() {
		return UiView;
	}

    void setStartScreen();

	
};

#endif