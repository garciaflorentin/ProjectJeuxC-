#include "LifeWindow.hpp"

LifeWindow::LifeWindow(Heart* HeartPlayer) {
	    
	_lifePlayer = new Heart();
	
	_lifePlayer = HeartPlayer;
	    
	_lifeTexture = new sf::RenderTexture();
	
	_lifeTexture->create(1500, 80);
	
	_lifeSprite = new sf::Sprite(_lifeTexture->getTexture());
	
	_lifeView = new sf::View(sf::FloatRect(-0.5f, -0.5f, 1000.0f, 200.f));
	
	_lifeView->setViewport(sf::FloatRect(0.f, 0.f, 1, 1));
	
	_lifeTexture->setView(*_lifeView);
		
}


LifeWindow::~LifeWindow() {
	delete[] _lifePlayer;
	delete[] _lifeSprite;
	delete[] _lifeTexture;
	delete[] _lifeView;
}

void LifeWindow::drawTo(sf::RenderWindow* target) {

	updateWindow();
	target->draw(*_lifeSprite);

}

void LifeWindow::updateWindow() {

	// dessiner la vue de la fenêtre de vie sur la render texture de la fenêtre de vie
	_lifeTexture->setView(*_lifeView);
	for (int i = 0; i < 3; i++) {
		_lifeTexture->draw(*(*_lifePlayer->getLife())[i]);
	}
	// dessiner les éléments de la fenêtre de vie
	_lifeTexture->display();
	_lifeSprite->setTexture(_lifeTexture->getTexture());

}

