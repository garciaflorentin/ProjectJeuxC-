#ifndef GOLDENCHEST_HPP
#define GOLDENCHEST_HPP

#include "Chest.hpp"


class GoldenChest : public Chest{

    private:

    int key = 1;

    public:

    GoldenChest(const char* nameObject, sf::Vector2f initPos) : Chest(nameObject,initPos){
        chestAnim->x = 0;
	    chestAnim->y = 6;
	    _sprite->setTextureRect(sf::IntRect(chestAnim->x * CHEST_SIZE , 233 ,32, 24));
    }
    ~GoldenChest(){}

    void collide(Object* o);
    void open();

};
#endif