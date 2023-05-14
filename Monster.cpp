#include "Monster.hpp"

#include <math.h>

Player* Monster::_player = nullptr;

bool Monster::playerSeen() const {
    sf::Vector2f player_pos = _player->getPosition();
    sf::Vector2f this_pos = this->getPosition();

    float dist = sqrt((player_pos.x-this_pos.x)*(player_pos.x-this_pos.x) + 
        (player_pos.y-this_pos.y)*(player_pos.y-this_pos.y));
    
    if (dist < _vision_field)   return true;
    
    return false;
}

bool Monster::playerInRange() const {
    sf::Vector2f player_pos = _player->getPosition();
    sf::Vector2f this_pos = this->getPosition();

    float dist = sqrt((player_pos.x-this_pos.x)*(player_pos.x-this_pos.x) + 
        (player_pos.y-this_pos.y)*(player_pos.y-this_pos.y));
    
    if (dist < _attack_radius)  return true;
    
    return false;
}

void Monster::goToPlayer() {
    sf::Vector2f player_pos = _player->getPosition();
    sf::Vector2f this_pos = this->getPosition();

    float dist_x = player_pos.x - this_pos.x;
    float dist_y = player_pos.y - this_pos.y;

    sf::Vector2i np;
    np.x = this_pos.x;
    np.y = this_pos.y;

    if ((dist_y > _attack_radius)||(dist_x > _attack_radius)) {
        if (dist_x < dist_y)    np.y++;
        else                    np.x++;

        move(np);
    }
}

void Monster::attack(Character* target) {
    target->takeDamage(_damage);
}

void Monster::update(Player& pl) {
    this->_player = &pl;

    if (playerSeen())       goToPlayer();
    if (playerInRange())    attack(&pl);
}

void Monster::move(sf::Vector2i deplacement){
	_sprite->move(deplacement.x,deplacement.y);

}