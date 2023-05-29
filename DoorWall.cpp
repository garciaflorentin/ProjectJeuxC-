#include "DoorWall.hpp"

void DoorWall::animDoor(){

    
        if(anim.y==3){
            isOpen=true;
            isOpening=false;
        }else if(isOpening){
            anim.y=anim.y+1;
            sf::sleep(sf::seconds(0.5));
            _sprite->setTextureRect(sf::IntRect(anim.x,anim.y*64,96,64));
        }
    }

void DoorWall::collide(Object* o){
		if(typeid(*o) == typeid(Player)){
		    Player* p=dynamic_cast<Player*>(o);

            if(p->getKey()>=nbKey){
                if(!isOpen){
                    isOpening=true;

                }else{
                    _sprite->scale(0,0);
                   /* sf::Vector2f newpos;
                    switch(nbKey){
                        case 1:
                        newpos={50,-1500};
                        break;
                        case 2:
                        newpos={250,50};
                        break;
                        case 3:
                        newpos={150,-200};
                        break;
                    }
                    p->getSprite()->setPosition(newpos);*/
                    
                }
            }
	    }
    }