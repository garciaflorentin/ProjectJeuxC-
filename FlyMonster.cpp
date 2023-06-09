#include "FlyMonster.hpp"


void FlyMonster::updateSprite(){
    if(_anim.x*_object_size >= _object_size*12)
        _anim.x=12;
    _sprite.setTextureRect(sf::IntRect(_anim.x*_object_size+4, _anim.y*_object_size+20, _object_size, _object_size));
}


void FlyMonster::update(Player& target1, Player& target2) {

    //cout << "Updating monster" << endl;

    float dist1, dist2;
    
    if (target1.isAlive() || target2.isAlive()) {

        //cout << "At least one of the players is alive" << endl;

        if (playerSeen(target1, target2, &dist1, &dist2)) {

            //cout << "A player is seen" << endl;

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


void FlyMonster::goToPlayer(Player& target) {

    //cout << "Going towards the player : " << target.getName() << endl;

    if(target.isAlive()) {
        sf::Vector2f player_pos = target.getPosition();
        sf::Vector2f this_pos = this->getPosition();

        float dist_x = player_pos.x - this_pos.x;
        float dist_y = player_pos.y - this_pos.y;

        sf::Vector2f np;
        np.x = 0;
        np.y = 0;

        if ((abs(dist_y) > _attack_radius - SPR_SIZE) || (abs(dist_x) > _attack_radius - SPR_SIZE)) {
            if ((dist_x > 0) && (dist_y > 0)) {
                if (dist_x > dist_y) {
                    np.x++;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 36.375;
                        _anim.x++;
                    }
                } else {
                    np.y++;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 34.375;
                        _anim.x++;
                    }
                }
            } else if ((dist_x < 0) && (dist_y < 0)) {
                if (dist_x < dist_y) {
                    np.x--;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 35.375;
                        _anim.x++;
                    }
                } else {
                    np.y--;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 37.375;
                        _anim.x++;
                    }
                }
            } else if ((dist_x > 0) && (dist_y < 0)) {
                if (abs(dist_x) > abs(dist_y)) {
                    np.x++;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 36.375;
                        _anim.x++;
                    }
                } else {
                    np.y--;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 37.375;
                        _anim.x++;
                    }
                }
            } else if ((dist_x < 0) && (dist_y > 0)) {
                if (abs(dist_x) > abs(dist_y)) {
                    np.x--;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 35.375;
                        _anim.x++;
                    }
                } else {
                    np.y++;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 34.375;
                        _anim.x++;
                    }
                }
            }

            updateSprite();
            move({np.x * _speed, np.y * _speed});
        }
    }
}