#ifndef WALL_ZONE_HPP
#define WALL_ZONE_HPP

#include "Wall.hpp"


class WallZone : public Wall{

public:
    WallZone(const char* nameObject, sf::Vector2f initPos, TypeWall _typeWall) : Wall(nameObject,initPos,_typeWall) {
    resistance=1000000;
    }

    ~WallZone(){};

};
#endif