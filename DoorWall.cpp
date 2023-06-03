#include "DoorWall.hpp"


void DoorWall::animDoor(){
    if(_anim.y==3){
        _isOpen = true;
        _isOpening = false;
    } else if (_isOpening) {
        _anim.y = _anim.y+1;
        sf::sleep(sf::seconds(0.5));
        _sprite.setTextureRect(sf::IntRect(_anim.x,_anim.y*64,96,64));
    }
}


void DoorWall::collide(Object& o){

    cout << "Collision with the big door" << endl;
    
    if(typeid(o) == typeid(Player)){
        
        cout << "Player collision with a big door" << endl;

        Player& p=dynamic_cast<Player&>(o);

        if(p.getKey() >= _nbKey){

            cout << "Opening the door" << endl;

            if(!_isOpen) { 
                _isOpening=true;
                _sprite.scale(0,0);
            }
        }
    }
}