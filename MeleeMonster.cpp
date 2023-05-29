#include "MeleeMonster.hpp"

void MeleeMonster::attack(Character* target) {

   // crySound->setVolume(75);
     //   crySound->stop();
       // crySound->play();
    target->takeDamage(_damage);
    
    cout << "attack !" << endl;
}

 void MeleeMonster::updateSprite(){
	    if(anim->x*OBJECT_SIZE >= OBJECT_SIZE*3){anim->x=0;}
	    _sprite->setTextureRect(sf::IntRect(anim->x*OBJECT_SIZE, anim->y*OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE));
 }

    void MeleeMonster::update(Player* pl) {
    //cout << "Updating monster" << endl;
    this->_player = pl;

    if (playerSeen() && !playerInRange()) {  goToPlayer();}
    if (_upd.getElapsedTime().asMilliseconds()%20 == 0) {
        //cout << "Attack cooldown" << endl;
        if (playerInRange()){    attack(pl);}
    }
}