#include "Monster.hpp"


int Monster::_serial = 0;


Monster::Monster(string nameObject, sf::Vector2f initPos, /*Player& player1, Player& player2,*/ string name, int dmg, int ar, int vf, float speed) : 
Character(nameObject, initPos), /*_player1(player1), _player2(player2),*/ _attack_radius(ar * SPR_SIZE), _vision_field(vf * SPR_SIZE), _canOpenChest(false) {
    //_player = player;

    _damageAttack = dmg;
    _isAttacking = false;
    _speed = speed;
    _this_serial = _serial;
    _serial++;

    _takeDamageMusic = SoundsLib::assignSound("Sounds/Retro Roar Krushed 01.wav");

    sf::Vector2f pos = {initPos.x*SPR_SIZE, initPos.y*SPR_SIZE};

    _upd = sf::Clock();
}


Monster::~Monster() {
    //_crySound.stop();
}


bool Monster::playerSeen(Player& p1, Player& p2, float* dist1, float* dist2) const {
    bool seen = false;

    if(p1.isAlive()){
        sf::Vector2f player_pos = p1.getPosition();
        sf::Vector2f this_pos = this->getPosition();

        float dist = sqrt((player_pos.x - this_pos.x) * (player_pos.x - this_pos.x) +
                        (player_pos.y - this_pos.y) * (player_pos.y - this_pos.y));

        *dist1 = dist;

        if (dist < _vision_field)
            seen = true;
    }

    if(p2.isAlive()){
        sf::Vector2f player_pos = p2.getPosition();
        sf::Vector2f this_pos = this->getPosition();

        float dist = sqrt((player_pos.x - this_pos.x) * (player_pos.x - this_pos.x) +
                        (player_pos.y - this_pos.y) * (player_pos.y - this_pos.y));

        *dist2 = dist;

        if (dist < _vision_field)
            seen = true;
    }

    return seen;
}


bool Monster::playerInRange(Player& target) const {
    if(target.isAlive()) {
        sf::Vector2f player_pos = target.getPosition();
        sf::Vector2f this_pos = this->getPosition();

        float dist = sqrt((player_pos.x - this_pos.x) * (player_pos.x - this_pos.x) +
                        (player_pos.y - this_pos.y) * (player_pos.y - this_pos.y));

        if (dist < _attack_radius) {
            //cout << "Player in range" << endl;
            return true;
        }
    }
    return false;
}


void Monster::goToPlayer(Player& target) {
    if(target.isAlive()){ 
        sf::Vector2f player_pos = target.getPosition();
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


void Monster::attack(Player& target) {
    if (target.isAlive()) {
        target.takeDamage(_damageAttack);
    }
}

void Monster::update(Player& target1, Player& target2) {
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


void Monster::collide(Object& o) {

    //cout << "Monster collide" << endl;

    if (typeid(o) == typeid(Projectile) || typeid(o) == typeid(Arrow)) {

        cout << "Monster collide with projectile" << endl;

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