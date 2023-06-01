#include "LifeWindow.hpp"


LifeWindow::LifeWindow(Heart& HeartPlayer) : _lifePlayer(HeartPlayer) {
	// _lifePlayer = Heart();
	// _lifePlayer = HeartPlayer;

	_lifeTexture.create(1500, 80);
	_lifeSprite = sf::Sprite(_lifeTexture.getTexture());

	_lifeView = sf::View(sf::FloatRect(0.f, 0.f, 1000.0f, 200.f));
	_lifeView.setViewport(sf::FloatRect(0.f, 0.f, 1, 1));
	_lifeTexture.setView(_lifeView);
}


LifeWindow& LifeWindow::operator=(const LifeWindow& other) {
    _lifeView = other._lifeView;
    
    _lifeTexture.create(1500, 80);
    _lifeTexture.setView(_lifeView);

    _lifeSprite = other._lifeSprite;
    _lifePlayer = other._lifePlayer;

	return *this;
}


void LifeWindow::drawTo(sf::RenderWindow& target) {
	updateWindow();
	target.draw(_lifeSprite);
}


void LifeWindow::updateWindow() {
	_lifeTexture.clear(sf::Color::Transparent);

	// dessiner la vue de la fenêtre de vie sur la render texture de la fenêtre de vie
	_lifeTexture.setView(_lifeView);
	for (int i = 0; i < 3; i++) 
		_lifeTexture.draw(*(_lifePlayer.getLife())[i]);

	// dessiner les éléments de la fenêtre de vie
	_lifeTexture.display();
	_lifeSprite.setTexture(_lifeTexture.getTexture());
}


const sf::View& LifeWindow::getLifeView() const {
	return _lifeView;
}