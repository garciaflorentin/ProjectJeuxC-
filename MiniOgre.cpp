#include "MiniOgre.hpp"


void MiniOgre::updateSprite(){
    if(_anim.x*_object_size >= _object_size*6)  _anim.x=3;
    _sprite.setTextureRect(sf::IntRect(_anim.x*_object_size, _anim.y*_object_size, _object_size, _object_size));
}


// void MiniOgre::update(Player& pl) {
//     this->_player = pl;

//     if (playerSeen() && !playerInRange())   goToPlayer();
//     if (_upd.getElapsedTime().asMilliseconds()%40 == 0)
//         if (playerInRange())    attack(pl);
// }