#include "MeleeMonster.hpp"

void MeleeMonster::attack(Character* target) {
    target->takeDamage(_damage);
    cout << "attack !" << endl;
}

 void MeleeMonster::updateSprite(){
	    if(anim->x*OBJECT_SIZE >= OBJECT_SIZE*3){anim->x=0;}
	    _sprite->setTextureRect(sf::IntRect(anim->x*OBJECT_SIZE, anim->y*OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE));
 }