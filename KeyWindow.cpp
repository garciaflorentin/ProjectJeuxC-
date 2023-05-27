#include "KeyWindow.hpp"


KeyWindow::KeyWindow(Player* p) {

	this->player=p;
	keyTexture = new sf::RenderTexture();
	keyTexture->create(1024, 768);
	keySprite = new sf::Sprite(keyTexture->getTexture());
	keyView = new sf::View(sf::FloatRect(0, 0.f, 1024.0f, 768.f));
	keyView->setViewport(sf::FloatRect(0.f, 0.f, 1, 1));
	keyTexture->setView(*keyView);
    texture = new sf::Texture();
    if (!(texture->loadFromFile("key.png"))){
			std::cout<<"probleme dans la creation de key"<<std::endl;
		}
		
}


KeyWindow::~KeyWindow() {
	delete player;
	delete keySprite;
	delete keyTexture;
	delete keyView;
    delete texture;
}

void KeyWindow::drawTo(sf::RenderWindow* target) {
	
	updateWindow();
	target->draw(*keySprite);


}

void KeyWindow::updateWindow() {
	
	keyTexture->clear(sf::Color::Transparent);
	// dessiner la vue de la fenêtre de vie sur la render texture de la fenêtre de vie
	keyTexture->setView(*keyView);
    sf::Sprite key1,key2,key3,key4;
	key1.setTexture(*texture);
	key2.setTexture(*texture);
	key3.setTexture(*texture);
	key4.setTexture(*texture);
	key1.scale(1.5,1.5);
	key2.scale(1.5,1.5);
    key3.scale(1.5,1.5);
    key4.scale(1.5,1.5);
    key1.setPosition(0,50);
	key2.setPosition(32,50);
    key3.setPosition(64,50);
    key4.setPosition(96,50);

	switch(player->getKey()){
        case 0:break;
		case 1:
		keyTexture->draw(key1);
		break;
		case 2:
		keyTexture->draw(key1);
		keyTexture->draw(key2);
		break;
		case 3:
		keyTexture->draw(key1);
		keyTexture->draw(key2);
		keyTexture->draw(key3);
		break;
		case 4:
		keyTexture->draw(key1);
		keyTexture->draw(key2);
		keyTexture->draw(key3);
		keyTexture->draw(key4);
		break;
	}
	// dessiner les éléments de la fenêtre de vie
	keyTexture->display();
	keySprite->setTexture(keyTexture->getTexture());

}

	


