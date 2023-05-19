#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstring>

class UserInterface{

    private:

    const float windowWidth = 1024.f, windowHeight = 768.f;
	sf::View* UiView;
	sf::RenderWindow* window;
    sf::Event* event;
	sf::VideoMode videoMode;
	sf::Texture* UiTexture;
	sf::Texture* UiTexture1;
	sf::Texture* UiTexture2;


	sf::Sprite* Background;
	sf::Sprite* button1;
	sf::Sprite *button2;
	sf::Sprite *button3;
	sf::Sprite *cadre;


	bool _isPaused, _isLaunched;


    public:

    UserInterface();
	~UserInterface();
	void drawTo(sf::RenderWindow* target);
	void updateUi();
	sf::View* getUiView() {
		return UiView;
	}

	bool isPaused(){
		return _isPaused;
	}

	bool isLaunched(){
		return _isLaunched;
	}

	void setIsPaused(bool state){
		_isPaused=state;
	}

	void setIsLaunched(bool state){
		_isLaunched=state;
	}

    void setStartScreen();

	void runPausedWindow();
	void runLaunchedWindow();


	sf::RenderWindow* getWindow(){
		return window;
	}
};

#endif