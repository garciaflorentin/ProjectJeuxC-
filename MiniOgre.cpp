#include "MiniOgre.hpp"

void MiniOgre::updateSprite(){
	    if(anim->x*OBJECT_SIZE >= OBJECT_SIZE*6){anim->x=3;}
	    _sprite->setTextureRect(sf::IntRect(anim->x*OBJECT_SIZE, anim->y*OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE));
 }

void MiniOgre::update(Player* pl) {
    //cout << "Updating monster" << endl;
    this->_player = pl;

    if (playerSeen() && !playerInRange()) {  goToPlayer();}
    if (_upd.getElapsedTime().asMilliseconds()%40 == 0) {
        //cout << "Attack cooldown" << endl;
        if (playerInRange()){    attack(pl);}
    }
}