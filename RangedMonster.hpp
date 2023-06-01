#ifndef RANGED_MONSTER_HPP
#define RANGED_MONSTER_HPP

#include "Monster.hpp"
#include "Fireball.hpp"


class RangedMonster : public Monster {
    private:
        Fireball& _fireball;

    public:
        RangedMonster(string nameObject, sf::Vector2f initPos, Player& player, string name="meat", int dmg=1, int ar=5, int vf=50,float speed=1) : 
        Monster(nameObject, initPos, player, name, dmg, ar, vf,speed), _fireball(*(new Fireball())) {
            _anim.x = 9;
	        _anim.y = 0;

            updateSprite();

            _footStepSound = SoundsLib::assignSound("Sounds/footStep.wav");
        };

        ~RangedMonster(){};

        void attack(Character& target);

        Projectile* getProjectile() { return &_fireball; };

        void updateSprite();
};


#endif