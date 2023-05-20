#ifndef MELEE_MONSTER_HPP
#define MELEE_MONSTER_HPP

#include "Monster.hpp"


class MeleeMonster : public Monster {
    private:
        

    public:
        MeleeMonster(const char* nameObject, sf::Vector2f initPos, string name="meat", int dmg=1, int ar=2, int vf=6) : Monster(nameObject, initPos, name, dmg, ar, vf) {};
        ~MeleeMonster();

        void attack(Character* target);
};


#endif