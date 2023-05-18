#include "Chest.hpp"

void Chest::collide(Object* o){
        cout << "Chest collistion" << endl;
        Character* p=dynamic_cast<Character*>(o);
        if (p->canOpenChest()) {
                cout << "Can open chest" << endl;
                p->openChest(this);
                _gain->collide(o);   
        }
}

int Chest::open(){
        std::cout<<"chestOpen"<<std::endl;
	chestAnim->x = 1;
        _sprite->setTextureRect(sf::IntRect(chestAnim->x * 48 , chestAnim->y * CHEST_SIZE, CHEST_SIZE, CHEST_SIZE));
        _isOpen=true;
	return _gain->getGain();
}