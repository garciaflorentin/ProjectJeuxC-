#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include <cmath>

#include "Projectile.hpp"
#include "Character.hpp"
#include "Player.hpp"


class Fireball : public Projectile {
    private:
        sf::Vector2f _initPos;
        sf::Vector2f _dirVect;

        int _dmg;

        Character& _target;

    public:
        Fireball() : Projectile(), _target(*(new Character())) {};
        Fireball(string nameObject, sf::Vector2f initPos, Character& player, float angle = 0, int dmg = 2);
        Fireball& operator=(const Fireball& other);
        ~Fireball() {};

        void computeTrajectory(float angle);

        void initProjectile();
        void goTo();
        void collide(Object& o);
};


#endif