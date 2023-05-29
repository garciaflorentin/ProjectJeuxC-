#include "FinalBoss.hpp"


FinalBoss::FinalBoss() : Monster("angry_cat.png", {5,5}, "serious meat", 1, 10, 100, 1.5) {
    cout << "final boss constructor" << endl;
    for (int i = 0; i < FIREBALL_NUMBER; i++) _fireballs.push_back(nullptr);
}


bool FinalBoss::playerInRange(int range) {
    sf::Vector2f player_pos = _player->getPosition();
    sf::Vector2f this_pos = this->getPosition();

    float dist = sqrt((player_pos.x-this_pos.x)*(player_pos.x-this_pos.x) + 
        (player_pos.y-this_pos.y)*(player_pos.y-this_pos.y));
    
    if (dist < range)  return true;
    
    return false;
}

void FinalBoss::update(Player* pl) {
    this->_player = pl;

    if (playerSeen() && !playerInRange(_attack_radius)) goToPlayer();

    if (_upd.getElapsedTime().asMilliseconds()%100 == 0) {
        //cout << "Attack cooldown" << endl;
        if (playerInRange(_meleeRange)) attack(pl, 'm');
    }

    if (_upd.getElapsedTime().asMilliseconds()%150 == 0) {
        if (playerInRange(_attack_radius)) attack(pl, 'r');
    }
}

void FinalBoss::attack(Character* target, char type) {
    switch (type) {
        case 'm':
            target->takeDamage(_damage);
            break;
        case 'r':
            for (int i = 0; i < _fireballs.size(); i++) {
                _fireballs[i] = new Fireball("fireball.png", this->getPosition(), target, 360/FIREBALL_NUMBER*i);
                _fireballs[i]->initProjectile();
                _fireballs[i]->setIsShot(true);
            }
            break;
    }
}