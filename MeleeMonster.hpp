#ifndef MELEE_MONSTER_HPP
#define MELEE_MONSTER_HPP

#include "Monster.hpp"


class MeleeMonster : public Monster {
    private:
        

    public:
        MeleeMonster(const char* nameObject, sf::Vector2f initPos, string name="Zombie", int dmg=1, int ar=1, int vf=10, float speed=3) : Monster(nameObject, initPos, name, dmg, ar, vf,speed) {
            anim->x = 0;
	        anim->y = 0;
            updateSprite();
        };
        ~MeleeMonster(){};

        void attack(Character* target);

        void updateSprite();
};


#endif