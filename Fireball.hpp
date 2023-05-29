#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include <cmath>

#include "Projectile.hpp"

#define SPR_SIZE            48
#define PROJECTILE_SPEED    10.0


class Fireball : public Projectile {
    private:
        sf::Vector2f _initPos;
        sf::Vector2f _dirVect;

        int _dmg;

        Character* _target;

    public:
        Fireball() : Projectile() {};
        Fireball(const char* nameObject, sf::Vector2f initPos, Character* player, float angle = 0, int dmg = 2);
        ~Fireball() {};

        void computeTrajectory(float angle);

        void initProjectile();
        void goTo();
        void collide(Object* o);
};


#endif