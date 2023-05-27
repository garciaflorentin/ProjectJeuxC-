#include "RangedMonster.hpp"

// RangedMonster::RangedMonster(const char* nameObject, sf::Vector2f initPos, string name, int dmg, int ar, int vf) : Monster(nameObject, initPos, name, dmg, ar, vf) {
//     _fireball = nullptr;
// }

void RangedMonster::attack(Character* target) {
    cout << "entering attack" << endl;
    //delete[] _fireball;
    cout << "previous fireball deleted" << endl;
    cout << "current position x = " << this->getPosition().x << " y = " << this->getPosition().y << endl;
    cout << "target position x = " << target->getPosition().x << " y = " << target->getPosition().y << endl;
    _fireball = new Fireball("fireball.png", this->getPosition(), target);
    cout << "new fireball created" << endl;
    _fireball->initProjectile();
    cout << "exiting initProjectile" << endl;
    _fireball->setIsShot(true);
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
