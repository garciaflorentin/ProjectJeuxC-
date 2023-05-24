#ifndef DEMONDOG_MONSTER_HPP
#define DEMONDOG_MONSTER_HPP

#include "MeleeMonster.hpp"


class DemonDogMonster : public MeleeMonster {
        

    public:
    DemonDogMonster(const char* nameObject, sf::Vector2f initPos, string name="meat", int dmg=3, int ar=1, int vf=4, float speed=1) : MeleeMonster(nameObject, initPos, name, dmg, ar, vf,speed) {
            anim->x = 0;
	        anim->y = 0;
            _sprite->scale(1,1);
            //_attack_radius=ar*96;
            updateSprite();
}

    ~DemonDogMonster(){};


 void updateSprite(){
	    if(anim->x*96 >= 96*3){anim->x=0;}
	    _sprite->setTextureRect(sf::IntRect(anim->x*96, anim->y*48, 96, 48));
 }

};


#endif