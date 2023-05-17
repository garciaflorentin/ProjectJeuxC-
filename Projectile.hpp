#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>
#include "Object.hpp"
#include "Player.hpp"
#include "TexturesLib.hpp"
class Player;


class Projectile: public Object{

    private:

    Player* player;
    bool _isShooted;
    int direction;

    public:

    Projectile(const char* nameObject, sf::Vector2f initPos,Player* player);
    ~Projectile(){
    }

    void goTo(int dir);

    void initProjectile();

    void collide(Object* o);
    const int getBlockSize(){return 32;}

    bool isShooted(){
        return _isShooted;
    }

    void setIsShooted(bool state){
        _isShooted=state;
    }

    int getDirection(){
        return direction;
    }

    void setDirection(int _direction){
        direction=_direction;
    }

    void updateProjectile(){
        this->goTo(getDirection());
    }


    

};

#endif