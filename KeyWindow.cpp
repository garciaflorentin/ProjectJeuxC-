#include "KeyWindow.hpp"


KeyWindow::KeyWindow(Player& p) : _player(p) {
	_keyTexture.create(1024, 768);
	_keySprite = sf::Sprite(_keyTexture.getTexture());

	_keyView = sf::View(sf::FloatRect(0, 0.f, 1024.0f, 768.f));
	_keyView.setViewport(sf::FloatRect(0.f, 0.f, 1, 1));
	_keyTexture.setView(_keyView);

    _texture = TexturesLib::assignTexture("OtherTextures/key.png");
}


KeyWindow& KeyWindow::operator=(const KeyWindow& other) {
    _keyView = other._keyView;
    
    _keyTexture.create(1024, 768);
    _keyTexture.setView(_keyView);

    _keySprite = other._keySprite;
    _texture = other._texture;
    _player = other._player;

    return *this;
}


void KeyWindow::drawTo(sf::RenderWindow& target) {
	updateWindow();
	target.draw(_keySprite);
}


void KeyWindow::updateWindow() {
	_keyTexture.clear(sf::Color::Transparent);

	// dessiner la vue de la fenêtre de vie sur la render texture de la fenêtre de vie
	_keyTexture.setView(_keyView);

    sf::Sprite key1,key2,key3,key4;
	key1.setTexture(_texture);
	key2.setTexture(_texture);
	key3.setTexture(_texture);
	key4.setTexture(_texture);
	key1.scale(1.5,1.5);
	key2.scale(1.5,1.5);
    key3.scale(1.5,1.5);
    key4.scale(1.5,1.5);
    key1.setPosition(0,50);
	key2.setPosition(32,50);
    key3.setPosition(64,50);
    key4.setPosition(96,50);

	switch(_player.getKey()){
        case 0:
            break;
		case 1:
		    _keyTexture.draw(key1);
		    break;
		case 2:
            _keyTexture.draw(key1);
            _keyTexture.draw(key2);
            break;
		case 3:
            _keyTexture.draw(key1);
            _keyTexture.draw(key2);
            _keyTexture.draw(key3);
            break;
		case 4:
            _keyTexture.draw(key1);
            _keyTexture.draw(key2);
            _keyTexture.draw(key3);
            _keyTexture.draw(key4);
            break;
	}

	// dessiner les éléments de la fenêtre de vie
	_keyTexture.display();
	_keySprite.setTexture(_keyTexture.getTexture());
}



const sf::View& KeyWindow::getKeyView() const {
    return _keyView;
}