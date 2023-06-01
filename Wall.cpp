#include "Wall.hpp"


Wall& Wall::operator=(const Wall& other) {
    Tile::operator=(other);

    _collideMusic = SoundsLib::assignSound("Sounds/musicCollideWall.wav");
    
    _resistance = other._resistance;

    return *this;
}