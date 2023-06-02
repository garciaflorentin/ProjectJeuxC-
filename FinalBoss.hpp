#ifndef FINALBOSS_HPP
#define FINALBOSS_HPP


#include <cmath>

#include "Monster.hpp"
#include "Fireball.hpp"


class FinalBoss : public Monster {
    private :
        int _meleeRange = 1;
        vector<Projectile*> _fireballs;

        const bool playerInRange(Player& target, int range) const;

    public:
        FinalBoss();

        void attack(Character& target, char type);
        void update(Player& pl1, Player& pl2);

        const std::vector<Projectile*>* getProjectiles() const { return &_fireballs; };
};


#endif