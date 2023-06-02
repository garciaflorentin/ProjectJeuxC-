#include "FinalBoss.hpp"

#define FIREBALL_NUMBER 3


FinalBoss::FinalBoss() : 
Monster("MonsterTextures/angry_cat.png", {5,5}, /*(*(new Player())), (*(new Player())),*/ "serious meat", 1, 10, 100, 1.5) {}


const bool FinalBoss::playerInRange(Player& target, int range) const {
    sf::Vector2f player_pos = target.getPosition();
    sf::Vector2f this_pos = this->getPosition();

    float dist = sqrt((player_pos.x-this_pos.x)*(player_pos.x-this_pos.x) + 
        (player_pos.y-this_pos.y)*(player_pos.y-this_pos.y));
    
    if (dist < range)  return true;
    
    return false;
}


void FinalBoss::update(Player& pl1, Player& pl2) {
    float dist1, dist2;

    if (playerSeen(pl1, pl2, &dist1, &dist2)) {
        if (dist1 < dist2 && !playerInRange(pl1, _attack_radius))
            goToPlayer(pl1);
        else if (dist1 > dist2 && !playerInRange(pl2, _attack_radius))
            goToPlayer(pl2);
    }

    if (_upd.getElapsedTime().asMilliseconds()%100 == 0) {
        if (playerInRange(pl1, _meleeRange))   attack(pl1, 'm');
        if (playerInRange(pl2, _meleeRange))   attack(pl2, 'm');
    }

    if (_upd.getElapsedTime().asMilliseconds()%150 == 0) {
        if (playerInRange(pl1, _attack_radius))    attack(pl1, 'r');
        if (playerInRange(pl2, _attack_radius))    attack(pl2, 'r');
    }
}


void FinalBoss::attack(Character& target, char type) {
    switch (type) {
        case 'm':
            target.takeDamage(_damageAttack);
            break;

        case 'r':
            _fireballs.clear();

            for (int i = 0; i < FIREBALL_NUMBER; i++) {
                _fireballs.push_back(new Fireball("OtherTextures/fireball.png", this->getPosition(), target, 360/FIREBALL_NUMBER*i));
                _fireballs[i]->initProjectile();
                _fireballs[i]->setIsShot(true);
            }
            break;
    }
}