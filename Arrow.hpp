#ifndef ARROW_HPP
#define ARROW_HPP

#include "Projectile.hpp"
#include "Character.hpp"


class Arrow : public Projectile {
    private:
        Character& _player;
        int _direction; ///< La direction dans laquelle le projectile se déplace.

    public:
        Arrow(string nameObject, sf::Vector2f initPos, Character& player);
        Arrow(const Arrow& other);

        Arrow& operator=(const Arrow& other);

        ~Arrow() {};

        void goTo();

        void initProjectile();

        const int getDirection() const { return _direction; };
        void setDirection(int direction) { _direction = direction; };

};


#endif