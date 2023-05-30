#ifndef FINALBOSS_HPP
#define FINALBOSS_HPP

#include "Monster.hpp"
#include "Fireball.hpp"

#define RANGED_RANGE    10
#define MELEE_RANGE     1
#define FIREBALL_NUMBER 8


class FinalBoss : public Monster {
    private :
        int _meleeRange = 1;
        std::vector<Projectile*>* _fireballs;

        bool playerInRange(int range);

    public :
        FinalBoss();

        void update(Player* pl);
        void attack(Character* target, char type);

        std::vector<Projectile*>* getProjectiles() { return _fireballs; };
};


#endif