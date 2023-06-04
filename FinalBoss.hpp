#ifndef FINALBOSS_HPP
#define FINALBOSS_HPP


#include <cmath>

#include "Monster.hpp"
#include "Fireball.hpp"

#define PI 3.14159

#define FIREBALL_NUMBER 3


class FinalBoss : public Monster {
    private :
        int _meleeRange = 1;
        vector<Projectile*>& _fireballs;

        const bool playerInRange(Player& target, int range) const;

    public:
        FinalBoss();

        void attack(Character& target, char type);
        void update(Player& pl1, Player& pl2);

        virtual std::vector<Projectile*>* getProjectiles() { 
            //cout << "There are " << _fireballs.size() << " fireballs launched" << endl;
            return &_fireballs; 
        };

        void updateSprite();

        void collide(Object& o);
};


#endif