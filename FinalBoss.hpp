#ifndef FINALBOSS_HPP
#define FINALBOSS_HPP

#include "Monster.hpp"
#include "Fireball.hpp"

#define RANGED_RANGE    10
#define MELEE_RANGE     1


class FinalBoss : public Monster {
    private :
        int _meleeRange = 1;
        std::vector<Fireball*> _fireballs;

        bool playerInRange(int range);

    public :
        FinalBoss();

        void update(Player* pl);
        void attack(Character* target);
};


#endif