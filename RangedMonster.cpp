#include "RangedMonster.hpp"

void RangedMonster::attack(Character* target) {
	//crySound->setVolume(50);
      //  crySound->stop();
        //crySound->play();
    Fireball* nfb = new Fireball("fireball.png", this->getPosition(), target);
}

void RangedMonster::updateSprite(){
	          if(anim->x*OBJECT_SIZE >= OBJECT_SIZE*9){anim->x=9;}
	             _sprite->setTextureRect(sf::IntRect(anim->x*OBJECT_SIZE, anim->y*OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE));
}
// bool RangedMonster::fireball(Character* target) {
//     sf::Vector2f targetPos = target->getPosition();

//     float distX = targetPos.x - this->getPosition().x;
//     float distY = targetPos.y - this->getPosition().y;

//     float dirVecX = distX / PROJECTILE_SPEED;
//     float dirVecY = distY / PROJECTILE_SPEED;

//     Fireball* nfb = new Fireball(nameObject, initPos, player)
// }