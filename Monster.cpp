#include "Monster.hpp"


int Monster::_serial = 0;


Monster::Monster(string nameObject, sf::Vector2f initPos, Player& player, string name, int dmg, int ar, int vf, float speed) : 
Character(nameObject, initPos), _player(player), _attack_radius(ar * SPR_SIZE), _vision_field(vf * SPR_SIZE), _canOpenChest(false) {
    //_player = player;

    _damageAttack = dmg;
    _isAttacking = false;
    _speed = speed;
    _this_serial = _serial;
    _serial++;

    sf::Vector2f pos = {initPos.x*SPR_SIZE, initPos.y*SPR_SIZE};

    _upd = sf::Clock();
}


Monster::~Monster() {
    //_crySound.stop();
}


bool Monster::playerSeen() const {
    if(_player.isAlive()){
    sf::Vector2f player_pos = _player.getPosition();
    sf::Vector2f this_pos = this->getPosition();

    float dist = sqrt((player_pos.x - this_pos.x) * (player_pos.x - this_pos.x) +
                      (player_pos.y - this_pos.y) * (player_pos.y - this_pos.y));

    if (dist < _vision_field)
        return true;
    }

    return false;
}


bool Monster::playerInRange() const {
    if(_player.isAlive()) {
    sf::Vector2f player_pos = _player.getPosition();
    sf::Vector2f this_pos = this->getPosition();

    float dist = sqrt((player_pos.x - this_pos.x) * (player_pos.x - this_pos.x) +
                      (player_pos.y - this_pos.y) * (player_pos.y - this_pos.y));

    if (dist < _attack_radius)
        return true;
    }
    return false;
}


void Monster::goToPlayer() {
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
                        _anim.y = 2;
                        _anim.x++;
                    }
                } else {
                    np.y++;
                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 0;
                        _anim.x++;
                    }
                }
            } else if ((dist_x < 0) && (dist_y < 0)) {
                if (dist_x < dist_y) {
                    np.x--;
                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 1;
                        _anim.x++;
                    }
                } else {
                    np.y--;
                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 3;
                        _anim.x++;
                    }
                }
            } else if ((dist_x > 0) && (dist_y < 0)) {
                if (abs(dist_x) > abs(dist_y)) {
                    np.x++;
                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 2;
                        _anim.x++;
                    }
                } else {
                    np.y--;
                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 3;
                        _anim.x++;
                    }
                }
            } else if ((dist_x < 0) && (dist_y > 0)) {
                if (abs(dist_x) > abs(dist_y)) {
                    np.x--;
                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 1;
                        _anim.x++;
                    }
                } else {
                    np.y++;
                    if (_upd.getElapsedTime().asMilliseconds() % 1 == 0) {
                        _anim.y = 0;
                        _anim.x++;
                    }
                }
            }

            updateSprite();
            move({np.x * _speed, np.y * _speed});
        }
    }
}


void Monster::attack(Character& target) {
    if (target.isAlive()) {
        target.takeDamage(_damageAttack);
    }
}

void Monster::update() {
    if (_player.isAlive()) {
        if (playerSeen() && !playerInRange())
            goToPlayer();
        
        if (_upd.getElapsedTime().asMilliseconds() % 100 == 0)
            if (playerInRange())
                attack(_player);
    }
}


void Monster::collide(Object& o) {
    if (typeid(o) == typeid(Projectile)) {
        getSprite().scale(0, 0);
        takeDamage(12);
    } else if (typeid(o) == typeid(Player)) {
        Player& p=dynamic_cast<Player&>(o);
        p.getAnim().x=19;

        if(p.getHitAnim()<=3) {
            p.getSprite().setTextureRect(sf::IntRect(p.getAnim().x*32,p.getAnim().y*32,32,32));
            p.setHitAnim(0);
        } else { p.incrHitAnim(); }
    }
}


void Monster::openChest(Chest& chest) {}
void Monster::updateSprite() {}

float Monster::lifetime_secs() { return _upd.getElapsedTime().asSeconds(); }
int Monster::getSerial() { return _this_serial; }