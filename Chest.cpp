#include "Chest.hpp"

Chest::Chest(): _isOpen(false) {
	_gain = new Gain();
}
Chest::Chest() {
	delete _gain;
}

int Chest::open(Player* player) {
	return _gain->getGain();
}