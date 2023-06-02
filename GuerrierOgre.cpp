#include "GuerrierOgre.hpp"


void GuerrierOgre::updateSprite(){
    if(_anim.x*_object_size >= _object_size*6)  _anim.x=3;
    _sprite.setTextureRect(sf::IntRect(_anim.x*_object_size, _anim.y*_object_size, _object_size, _object_size));
}


void GuerrierOgre::update(Player& target1, Player& target2) {
    float dist1, dist2;
    
    if (target1.isAlive() || target2.isAlive()) {
        if (playerSeen(target1, target2, &dist1, &dist2)) {
            if (dist1 < dist2 && !playerInRange(target1))
                goToPlayer(target1);
            else if (dist1 > dist2 && !playerInRange(target2))
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


void GuerrierOgre::goToPlayer(Player& target) {
    if(target.isAlive()) {
        sf::Vector2f player_pos = target.getPosition();
        sf::Vector2f this_pos = this->getPosition();

        float dist_x = player_pos.x - this_pos.x;
        float dist_y = player_pos.y - this_pos.y;

        sf::Vector2f np;
        np.x = 0;
        np.y = 0;

        if ((abs(dist_y) > _attack_radius - SPR_SIZE) || (abs(dist_x) > _attack_radius - SPR_SIZE)){
            if ((dist_x > 0) && (dist_y > 0)) {
                if (dist_x > dist_y) {
                    np.x++;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 6;
                        _anim.x++;
                    }
                }
                else {
                    np.y++;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0){
                        _anim.y = 4;
                        _anim.x++;
                    }
                }
            }
            else if ((dist_x < 0) && (dist_y < 0)) {
                if (dist_x < dist_y) {
                    np.x--;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 5;
                        _anim.x++;
                    }
                }
                else {
                    np.y--;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 7;
                        _anim.x++;
                    }
                }
            }
            else if ((dist_x > 0) && (dist_y < 0)) {
                if (abs(dist_x) > abs(dist_y)) {
                    np.x++;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 6;
                        _anim.x++;
                    }
                }
                else {
                    np.y--;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 7;
                        _anim.x++;
                    }
                }
            }
            else if ((dist_x < 0) && (dist_y > 0)) {
                if (abs(dist_x) > abs(dist_y)) {
                    np.x--;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 5;
                        _anim.x++;
                    }
                }
                else {
                    np.y++;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 4;
                        _anim.x++;
                    }
                }
            }

            updateSprite();
            move({np.x * _speed, np.y * _speed});
        }
    }
}