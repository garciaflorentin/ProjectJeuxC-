#ifndef RANGED_MONSTER_HPP
#define RANGED_MONSTER_HPP

#include "Monster.hpp"
#include "Fireball.hpp"

//#define PROJECTILE_SPEED 10.0


class RangedMonster : public Monster {
    private:
        Fireball* _fireball;

    public:
        RangedMonster(const char* nameObject, sf::Vector2f initPos, string name="meat", int dmg=1, int ar=5, int vf=10);
        ~RangedMonster();

        void attack(Character* target);

        Projectile* getProjectile() { return  _fireball; };
};


#endif