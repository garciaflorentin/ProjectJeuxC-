#ifndef FIREBALL_HPP
#define FIREBALL_HPP


#include "Object.hpp"

#define FIREBALL_RANGE  15
#define SPR_SIZE        48


class Fireball : public Object {
    private:
        sf::Vector2f _targetPos;
        sf::Vector2f _step;

        int _range_count = SPR_SIZE*FIREBALL_RANGE;

        sf::Clock _upd;

    public:
        Fireball() : Object() {};
        Fireball(const char* nameObject, sf::Vector2f initPos, sf::Vector2f targetPos);
        
        ~Fireball() {};

        void computeTrajectory();

        void launch();
};


#endif