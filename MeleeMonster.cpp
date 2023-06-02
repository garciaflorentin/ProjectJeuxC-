#include "MeleeMonster.hpp"


void MeleeMonster::attack(Character& target) {
    cout << "MeleeMonster attack" << endl;
    
    _crySound->setVolume(75);
    _crySound->stop();
    _crySound->play();

    target.takeDamage(_damageAttack);
}

void MeleeMonster::updateSprite(){
    if(_anim.x*_object_size >= _object_size*3)   _anim.x=0;
    _sprite.setTextureRect(sf::IntRect(_anim.x*_object_size, _anim.y*_object_size, _object_size, _object_size));
}


// void MeleeMonster::update(Player& pl) {
//     this->_player = pl;

//     if (playerSeen() && !playerInRange())   goToPlayer();
//     if (_upd.getElapsedTime().asMilliseconds()%1000 == 0)
//         if (playerInRange())    attack(pl);
    
// }