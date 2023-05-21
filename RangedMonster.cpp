#include "RangedMonster.hpp"

void RangedMonster::attack(Character* target) {
    Fireball* nfb = new Fireball("fireball.png", this->getPosition(), target);
}

// bool RangedMonster::fireball(Character* target) {
//     sf::Vector2f targetPos = target->getPosition();

//     float distX = targetPos.x - this->getPosition().x;
//     float distY = targetPos.y - this->getPosition().y;

//     float dirVecX = distX / PROJECTILE_SPEED;
//     float dirVecY = distY / PROJECTILE_SPEED;

//     Fireball* nfb = new Fireball(nameObject, initPos, player)
// }