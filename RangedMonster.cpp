#include "RangedMonster.hpp"


void RangedMonster::attack(Character& target) {
    cout << "Ranged monster attack" << endl;

    _crySound->setVolume(50);
    _crySound->stop();
    _crySound->play();

    cout << "Firing fireball" << endl;
    _fireball = Fireball("OtherTextures/fireball.png", this->getPosition(), target);
    _fireball.initProjectile();
    _fireball.setIsShot(true);
}


void RangedMonster::updateSprite(){
    if(_anim.x*_object_size >= _object_size*9)  _anim.x=9;
    _sprite.setTextureRect(sf::IntRect(_anim.x*_object_size, _anim.y*_object_size, _object_size, _object_size));
}

void RangedMonster::update(Player& target1, Player& target2) {
    float dist1, dist2;
    
    if (target1.isAlive() || target2.isAlive()) {
        if (playerSeen(target1, target2, &dist1, &dist2)) {
            if ((dist1 < dist2 && !playerInRange(target1) && target1.isAlive()) || (!target2.isAlive() && !playerInRange(target1)))
                goToPlayer(target1);
            else if ((dist1 > dist2 && !playerInRange(target2) && target2.isAlive()) || (!target1.isAlive() && !playerInRange(target2)))
                goToPlayer(target2);
        }
        
        if (_upd.getElapsedTime().asMilliseconds() % _attack_cooldown == 0) {
            if (playerInRange(target1))
                attack(target1);
            if (playerInRange(target2))
                attack(target2);
        }       
    }
}