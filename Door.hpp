#ifndef DOOR_HPP
#define DOOR_HPP

#include "Wall.hpp"
#include "Player.hpp"

class Door: public Wall {

    private:

    sf::Vector2f anim;
    bool isOpen;
    bool isOpening;
    int DOOR_SIZE=240;
    int cpt=0;
    sf::Sprite* backDoorSprite;
    sf::Texture backDoorTexture;

    public:

    Door(const char* nameObject, sf::Vector2f initPos, TypeWall _typeWall);
    ~Door();

    void setIsOpen(bool state){
        isOpen=state;
    }

    void setIsOpening(bool state){
        isOpening=state;
    }

    void animDoor();

    void collide(Object* o);

    bool canBeAnimated(){
		return true;
	}
};
#endif