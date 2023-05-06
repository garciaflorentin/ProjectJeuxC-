#include "LifeWindow.hpp"

LifeWindow::LifeWindow(Heart* HeartPlayer) {

	lifePlayer = new Heart();
	lifePlayer = HeartPlayer;
	lifeTexture = new sf::RenderTexture();
	lifeTexture->create(1500, 80);
	lifeSprite = new sf::Sprite(lifeTexture->getTexture());
	lifeView = new sf::View(sf::FloatRect(-0.5f, -0.5f, 1000.0f, 200.f));
	lifeView->setViewport(sf::FloatRect(0.f, 0.f, 1, 1));
	lifeTexture->setView(*lifeView);
		
}


LifeWindow::~LifeWindow() {
	delete lifePlayer;
	delete lifeSprite;
	delete lifeTexture;
	delete lifeView;
}

void LifeWindow::drawTo(sf::RenderWindow* target) {

	updateWindow();
	target->draw(*lifeSprite);


}

void LifeWindow::updateWindow() {

	// dessiner la vue de la fenêtre de vie sur la render texture de la fenêtre de vie
	lifeTexture->setView(*lifeView);
	for (int i = 0; i < 3; i++) {
		lifeTexture->draw(*(*lifePlayer->getLife())[i]);
	}
	// dessiner les éléments de la fenêtre de vie
	lifeTexture->display();
	lifeSprite->setTexture(lifeTexture->getTexture());

}

