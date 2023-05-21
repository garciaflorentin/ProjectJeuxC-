#ifndef RANGED_MONSTER_HPP
#define RANGED_MONSTER_HPP

#include "Monster.hpp"
#include "Fireball.hpp"

#define PROJECTILE_SPEED 10.0


class RangedMonster : public Monster {
    private:
        

    public:
        RangedMonster(const char* nameObject, sf::Vector2f initPos, string name="meat", int dmg=1, int ar=5, int vf=10) : Monster(nameObject, initPos, name, dmg, ar, vf) {};
        ~RangedMonster();

        void attack(Character* target);

        bool fireball(Character* target);
};


#endif