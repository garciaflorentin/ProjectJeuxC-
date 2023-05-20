#include "MeleeMonster.hpp"

void MeleeMonster::attack(Character* target) {
    target->takeDamage(_damage);
    cout << "attack !" << endl;
}