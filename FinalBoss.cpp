#include "FinalBoss.hpp"

#define FIREBALL_NUMBER 3


FinalBoss::FinalBoss() : 
Monster("MonsterTextures/angry_cat.png", {5,5}, (*(new Player())), "serious meat", 1, 10, 100, 1.5) {}


const bool FinalBoss::playerInRange(int range) const {
    sf::Vector2f player_pos = _player.getPosition();
    sf::Vector2f this_pos = this->getPosition();

    float dist = sqrt((player_pos.x-this_pos.x)*(player_pos.x-this_pos.x) + 
        (player_pos.y-this_pos.y)*(player_pos.y-this_pos.y));
    
    if (dist < range)  return true;
    
    return false;
}


void FinalBoss::update(Player& pl) {
    this->_player = pl;

    if (playerSeen() && !playerInRange(_attack_radius)) goToPlayer();

    if (_upd.getElapsedTime().asMilliseconds()%100 == 0) 
        if (playerInRange(_meleeRange)) attack(pl, 'm');

    if (_upd.getElapsedTime().asMilliseconds()%150 == 0) 
        if (playerInRange(_attack_radius)) attack(pl, 'r');
}


void FinalBoss::attack(Character& target, char type) {
    switch (type) {
        case 'm':
            target.takeDamage(_damageAttack);
            break;

        case 'r':
            _fireballs.clear();

            for (int i = 0; i < FIREBALL_NUMBER; i++) {
                _fireballs.push_back(new Fireball("fireball.png", this->getPosition(), target, 360/FIREBALL_NUMBER*i));
                _fireballs[i]->initProjectile();
                _fireballs[i]->setIsShot(true);
            }
            break;
    }
}