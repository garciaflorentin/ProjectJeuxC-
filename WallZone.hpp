#ifndef WALL_ZONE_HPP
#define WALL_ZONE_HPP

#include "Wall.hpp"


/**
 * @brief Cette classe represente la zone des murs impermeable
 * 
 */
class WallZone : public Wall{
    public:
        WallZone(string nameObject, sf::Vector2f initPos, TypeWall _typeWall) : Wall(nameObject,initPos,_typeWall) {
            _resistance=1000000;
        }

        ~WallZone(){};
};


#endif