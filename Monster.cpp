#include "Monster.hpp"
#include <math.h>

Player* Monster::_player = nullptr;
int Monster::_serial = 0;

Monster::Monster(const char* nameObject, sf::Vector2f initPos, string name, int dmg, int ar, int vf, float speed) :
            Character(nameObject, initPos),  _damage(dmg), _attack_radius(ar*SPR_SIZE), _vision_field(vf*SPR_SIZE), _canOpenChest(false) {
               isAttacking=false;
                this->speed=speed;
                _this_serial = _serial;
                _serial++;
            }

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
    //cout << "Player seen" << endl;

    sf::Vector2f player_pos = _player->getPosition();
    sf::Vector2f this_pos = this->getPosition();

    //cout << "current position : " << this_pos.x << ", " << this_pos.y << endl;

    float dist_x = player_pos.x - this_pos.x;
    float dist_y = player_pos.y - this_pos.y;

    sf::Vector2f np;
    np.x = 0;
    np.y = 0;

    if ((abs(dist_y) > _attack_radius-SPR_SIZE)||(abs(dist_x) > _attack_radius-SPR_SIZE)) {
        if ((dist_x > 0)&&(dist_y > 0)) {
            if (dist_x > dist_y) {   
            np.x++;
            if(_upd.getElapsedTime().asMilliseconds()%1 == 0){
            anim->y=2;
            anim->x++;
            }
            }
            else {   
            np.y++;
            if(_upd.getElapsedTime().asMilliseconds()%1 == 0){
            anim->y=0;anim->x++;}
            }
        } else if ((dist_x < 0)&&(dist_y < 0)) {
            if (dist_x < dist_y) {
                 np.x--;
                 if(_upd.getElapsedTime().asMilliseconds()%1 == 0){
                 anim->y=1;anim->x++;}
            }
            else{
                 np.y--;
                 if(_upd.getElapsedTime().asMilliseconds()%1 == 0){
                 anim->y=3;anim->x++;}
            }
        } else if ((dist_x > 0)&&(dist_y < 0)) {
            if (abs(dist_x) > abs(dist_y)){
                np.x++;
                if(_upd.getElapsedTime().asMilliseconds()%1 == 0){
                anim->y=2;anim->x++;}
            }
            else {np.y--;
            if(_upd.getElapsedTime().asMilliseconds()%1 == 0){
            anim->y=3;anim->x++;}
            }
        } else if ((dist_x < 0)&&(dist_y > 0)) {
            if (abs(dist_x) > abs(dist_y)) {
                 np.x--;
                 if(_upd.getElapsedTime().asMilliseconds()%1 == 0){
                 anim->y=1;anim->x++;}
            }
            else {
                np.y++;
                if(_upd.getElapsedTime().asMilliseconds()%1 == 0){
                anim->y=0;anim->x++;}
            }
        }

        //cout << "moving by " << np.x << " " << np.y << endl;
        updateSprite();
        move({np.x*speed,np.y*speed});
    }
}

void Monster::attack(Character* target) {
    target->takeDamage(_damage);
    cout << "attack !" << endl;
}

void Monster::update(Player* pl) {
    //cout << "Updating monster" << endl;
    this->_player = pl;

    if (playerSeen() && !playerInRange()) {  goToPlayer();}
    if (_upd.getElapsedTime().asMilliseconds()%100 == 0) {
        //cout << "Attack cooldown" << endl;
        if (playerInRange()){    attack(pl);}
    }
}
    

void Monster::move(sf::Vector2f deplacement){
	_sprite->move(deplacement.x,deplacement.y);

}

// bool Monster::fireball() {
//     /* Lance une boule de feu en direction du joueur */
// }

 void Monster::collide(Object* o) {
      
        //Projectile* p=dynamic_cast<Projectile*>(o);
       if(typeid(*o) == typeid(Projectile)){
                getSprite()->scale(0,0); 
                takeDamage(12);
        }
}