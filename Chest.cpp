#include "Chest.hpp"

void Chest::collide(Object* o){
        Player* p=dynamic_cast<Player*>(o);
        p->openChest(this);
        _gain->collide(o);
}

int Chest::open(){
	chestAnim->x = 1;
        _sprite->setTextureRect(sf::IntRect(chestAnim->x * 48 , chestAnim->y * CHEST_SIZE, CHEST_SIZE, CHEST_SIZE));
        _isOpen=true;
	return _gain->getGain();
}