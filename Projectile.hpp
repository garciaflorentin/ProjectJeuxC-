#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>
#include "Object.hpp"
#include "Player.hpp"
#include "TexturesLib.hpp"
#include "Monster.hpp"
class Player;
class Monster;

class Projectile: public Object{

    protected:

    Player* _player;
    bool _isShot;
    int direction;
    int distance;

    public:

    Projectile() : Object() {};
    Projectile(const char* nameObject, sf::Vector2f initPos,Player* player);
    ~Projectile(){}
    Projectile(const Projectile& other);
    Projectile& operator=(const Projectile& other);



    virtual void goTo();

    virtual void initProjectile();

    virtual void collide(Object* o);

    const int getBlockSize(){return 32;}

    bool isShot(){
        return _isShot;
    }

    void setIsShot(bool state){
        _isShot=state;
    }

    int getDirection(){
        return direction;
    }

    void setDirection(int _direction){
        direction=_direction;
    }

    int getDistance(){
        return distance;
    }

    void incrementeDistance(){
        distance++;
        
    }

    void setDistance(int i){
        distance=i;
    }

    void arrowOutOfBounds();
    

};

#endif