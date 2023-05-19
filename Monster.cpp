#include "Monster.hpp"
#include <math.h>

Player* Monster::_player = nullptr;

Monster::Monster(const char* nameObject, sf::Vector2f initPos, string name, int dmg, int ar, int vf) :
            Character(nameObject, initPos),  _damage(dmg), _attack_radius(ar*SPR_SIZE), _vision_field(vf*SPR_SIZE), _canOpenChest(false) {}

Monster::~Monster() {}

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

    //cout << "current position : " << this_pos.x << ", " << this_pos.y << endl;

    float dist_x = player_pos.x - this_pos.x;
    float dist_y = player_pos.y - this_pos.y;

    sf::Vector2f np;
    np.x = 0;
    np.y = 0;

    if ((abs(dist_y) > _attack_radius-10)||(abs(dist_x) > _attack_radius-10)) {
        if ((dist_x > 0)&&(dist_y > 0)) {
            if (dist_x > dist_y)    np.x++;
            else                    np.y++;
        } else if ((dist_x < 0)&&(dist_y < 0)) {
            if (dist_x < dist_y)    np.x--;
            else                    np.y--;
        } else if ((dist_x > 0)&&(dist_y < 0)) {
            if (abs(dist_x) > abs(dist_y))  np.x++;
            else                            np.y--;
        } else if ((dist_x < 0)&&(dist_y > 0)) {
            if (abs(dist_x) > abs(dist_y))  np.x--;
            else                            np.y++;
        }

        move(np);
    }
}

void Monster::attack(Character* target) {
    target->takeDamage(_damage);
    cout << "attack !" << endl;
}

void Monster::update(Player* pl) {
    this->_player = pl;

    if (playerSeen())       goToPlayer();
    if (_upd.getElapsedTime().asMilliseconds()%1000 == 0) {
        if (playerInRange())    attack(pl);
    }
}
    

void Monster::move(sf::Vector2f deplacement){
	_sprite->move(deplacement.x,deplacement.y);

}

/*bool Monster::fireball() {
    /* Lance une boule de feu en direction du joueur */
//}