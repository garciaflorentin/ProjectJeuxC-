#include "FinalBoss.hpp"


FinalBoss::FinalBoss() : 
Monster("MonsterTextures/dragon_boss.png", {205,190}, /*(*(new Player())), (*(new Player())),*/ "serious meat", 1, 8, 100, 6), _fireballs(*(new vector<Projectile*>())) {
    for (int i = 0; i < FIREBALL_NUMBER; i++)
        _fireballs.push_back(new Fireball());

    _sprite.setTextureRect({0,64*2,64,64});
    _sprite.setScale(2.0,2.0);

    // sf::Vector2f pos = {10000,10000};
    // this->setPosition(pos);
}


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
        if ((dist1 < dist2 && !playerInRange(pl1, _attack_radius) && pl1.isAlive()) || (!pl2.isAlive() && !playerInRange(pl1, _attack_radius)))
            goToPlayer(pl1);
        else if ((dist1 > dist2 && !playerInRange(pl2, _attack_radius) && pl2.isAlive()) || (!pl1.isAlive() && !playerInRange(pl2, _attack_radius)))
            goToPlayer(pl2);
    }

    if (_upd.getElapsedTime().asMilliseconds()%50 == 0) {
        if (playerInRange(pl1, _meleeRange))   attack(pl1, 'm');
        if (playerInRange(pl2, _meleeRange))   attack(pl2, 'm');
    }

    if (_upd.getElapsedTime().asMilliseconds()%100 == 0) {
        if (playerInRange(pl1, _attack_radius))    attack(pl1, 'r');
        if (playerInRange(pl2, _attack_radius))    attack(pl2, 'r');
    }
}


void FinalBoss::attack(Character& target, char type) {
    switch (type) {
        case 'm':

            cout << "Boss melee attack" << endl;

            target.takeDamage(_damageAttack);
            break;

        case 'r':

            cout << "Boss ranged attack" << endl;

            _fireballs.clear();

            for (int i = 0; i < FIREBALL_NUMBER; i++) {
                _fireballs.push_back(new Fireball("OtherTextures/fireball.png", this->getPosition(), target, 2*PI/FIREBALL_NUMBER*i));
                _fireballs[i]->initProjectile();
                _fireballs[i]->setIsShot(true);
            }
            break;
    }
}

void FinalBoss::updateSprite() {
    if (_upd.getElapsedTime().asMilliseconds() % 5 == 0) {
        int anim = (_anim.x+_anim.y)%3;
        _sprite.setTextureRect({64*anim,64*2,64,64});
    }
}

void FinalBoss::collide(Object& o) {

    //cout << "Monster collide" << endl;

    if (typeid(o) == typeid(Projectile) || typeid(o) == typeid(Arrow)) {

        cout << "Monster collide with projectile" << endl;

        takeDamage(1);
    }
}