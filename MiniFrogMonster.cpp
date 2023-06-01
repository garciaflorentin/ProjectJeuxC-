#include "MiniFrogMonster.hpp"


void MiniFrogMonster::updateSprite(){
    if(_anim.x*_object_size >= _object_size*15) _anim.x=15;
    _sprite.setTextureRect(sf::IntRect(_anim.x*_object_size+4, _anim.y*_object_size+20, _object_size, _object_size));
}


void MiniFrogMonster::update(Player& pl) {
    if(pl.isAlive()){
    this->_player = pl;

    if (playerSeen() && !playerInRange())   goToPlayer();
    if (_upd.getElapsedTime().asMilliseconds()%40 == 0)
        if (playerInRange())    attack(pl);
    }
}


void MiniFrogMonster::goToPlayer()
{
    // cout << "Player seen" << endl;
    if(_player.isAlive()){

        sf::Vector2f player_pos = _player.getPosition();
        sf::Vector2f this_pos = this->getPosition();

        // cout << "current position : " << this_pos.x << ", " << this_pos.y << endl;

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
                }
                else {
                    np.y++;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 34.375;
                        _anim.x++;
                    }
                }
            }
            else if ((dist_x < 0) && (dist_y < 0)) {
                if (dist_x < dist_y) {
                    np.x--;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 35.375;
                        _anim.x++;
                    }
                }
                else {
                    np.y--;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 37.375;
                        _anim.x++;
                    }
                }
            }
            else if ((dist_x > 0) && (dist_y < 0)) {
                if (abs(dist_x) > abs(dist_y)) {
                    np.x++;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 36.375;
                        _anim.x++;
                    }
                }
                else {
                    np.y--;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 37.375;
                        _anim.x++;
                    }
                }
            }
            else if ((dist_x < 0) && (dist_y > 0)) {
                if (abs(dist_x) > abs(dist_y)) {
                    np.x--;

                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 35.375;
                        _anim.x++;
                    }
                }
                else {
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