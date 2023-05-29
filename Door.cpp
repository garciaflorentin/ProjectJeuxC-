#include "Door.hpp"



Door::Door(const char* nameObject, sf::Vector2f initPos, TypeWall _typeWall): Wall(nameObject,initPos,_typeWall){
        anim.x=0;
        anim.y=0;
        _sprite->setTextureRect(sf::IntRect(42,anim.y*DOOR_SIZE,156,175));
        isOpen=false;
        isOpening=false;
        resistance=1000000;
     /*   if (!(backDoorTexture.loadFromFile("!Demon Door.png"))){
			std::cout<<"probleme dans la creation de la porte"<<std::endl;
		}
        backDoorSprite->setTexture(backDoorTexture);
        backDoorSprite->setTextureRect(sf::IntRect(2159,496,240,240));
      backDoorSprite->setPosition(initPos);*/
    }

Door::~Door(){
        delete backDoorSprite;
    }

void Door::animDoor(){
        if(anim.y==3){
            isOpen=true;
            isOpening=false;
        }else if(isOpening){
            anim.y=anim.y+1;
            sf::sleep(sf::seconds(0.5));
            _sprite->setTextureRect(sf::IntRect(42,anim.y*DOOR_SIZE,156,175));
        }
    }

void Door::collide(Object* o){
		if(typeid(*o) == typeid(Player)){

		    Player* p=dynamic_cast<Player*>(o);
            if(p->getKey()==4){
                if(!isOpen){
                    isOpening=true;
                    //animDoor();
                }else{
                    sf::Vector2f newpos;
                    newpos={9984,9984};
                    p->isInTheCave(true);
                    p->setPosition(newpos);
                    
                }
            }
	    }
    }