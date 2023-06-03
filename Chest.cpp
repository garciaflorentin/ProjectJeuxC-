#include "Chest.hpp"


void Chest::collide(Object& o){
    if(typeid(o) == typeid(Projectile)){
            _sprite.scale(0,0);     
            return;  
    }
    
    //Character& p=dynamic_cast<Character&>(o);
    if (o.getName() == "PlayerTextures/player1.png" || o.getName() == "PlayerTextures/player2.png") {
        Character& p=dynamic_cast<Character&>(o);
        p.openChest(*this);
        _prise.collide(o);   
    }
}


const int Chest::open(){
	_chestAnim.x = 1;
    _sprite.setTextureRect(sf::IntRect(_chestAnim.x * 48 , _chestAnim.y * _chest_size, _chest_size, _chest_size));
    _isOpen=true;
	return _prise.getPrise();
}