#ifndef RANGED_MONSTER_HPP
#define RANGED_MONSTER_HPP

#include "Monster.hpp"
#include "Fireball.hpp"

//#define PROJECTILE_SPEED 10.0

using namespace std;


class RangedMonster : public Monster {
    private:
        Fireball* _fireball;

    public:
        RangedMonster(const char* nameObject, sf::Vector2f initPos, string name="meat", int dmg=1, int ar=5, int vf=10,float speed=1) : Monster(nameObject, initPos, name, dmg, ar, vf,speed) {
            anim->x = 9;
	        anim->y = 0;
            updateSprite();

            _fireball = nullptr;
        };
        ~RangedMonster();

        void attack(Character* target);

        Projectile* getProjectile() { return  _fireball; };
        //bool fireball(Character* target);

        void updateSprite();
};


#endif