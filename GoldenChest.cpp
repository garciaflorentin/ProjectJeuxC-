#include "GoldenChest.hpp"


void GoldenChest::collide(Object& o){
    if(!isOpen()){
        if(typeid(o) == typeid(Projectile)){
                _sprite.scale(0,0);     
                return;  
        }
        
        Character& p=dynamic_cast<Character&>(o);
        if (p.getName() == "player1.png" || p.getName() == "player2.png") {
            bool canOpen=false;

            if(p.getPosition().x>=0 && p.getPosition().x<9540/2 && p.getPosition().y>-4896 &&  p.getPosition().y<=0 )
                canOpen=p.getKilledallMobs()[0];
            else if(p.getPosition().x>=0 && p.getPosition().x<9540/2 && p.getPosition().y<4992 && p.getPosition().y>=0)
                canOpen=p.getKilledallMobs()[1];
            else if(p.getPosition().x>=9540/2 && p.getPosition().x<=9540  && p.getPosition().y<4992 && p.getPosition().y>=0)
                canOpen=p.getKilledallMobs()[2];
            else if((p.getPosition().x>=9540/2  && p.getPosition().x<=9540 && p.getPosition().y<0 && p.getPosition().y>=-4896))
                canOpen=p.getKilledallMobs()[3];
            
            if (canOpen) {
                open();
                p.addKey();
            }
        }
    }
}


void GoldenChest::open(){
	_chestAnim.x = 1;
    _sprite.setTextureRect(sf::IntRect(49 , 233, 32, 24));
    _isOpen=true;
}