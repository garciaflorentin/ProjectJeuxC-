#include "MiniOgre.hpp"


void MiniOgre::updateSprite(){
    if(_anim.x*_object_size >= _object_size*6)  _anim.x=3;
    _sprite.setTextureRect(sf::IntRect(_anim.x*_object_size, _anim.y*_object_size, _object_size, _object_size));
}


void MiniOgre::update(Player& target1, Player& target2) {
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