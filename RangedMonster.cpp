#include "RangedMonster.hpp"

RangedMonster::RangedMonster(const char* nameObject, sf::Vector2f initPos, string name, int dmg, int ar, int vf) : Monster(nameObject, initPos, name, dmg, ar, vf) {
    _fireball = nullptr;
}

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
