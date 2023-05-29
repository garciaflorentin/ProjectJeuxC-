#include "GoldenChest.hpp"

void GoldenChest::collide(Object* o){
  cout << "Chest collistion" << endl;
        //if(typeid(*o) == typeid(Character)){
        //cout << "Character collistion" << endl;

if(!isOpen()){
        if(typeid(*o)==typeid(Character)){
        Character* p=dynamic_cast<Character*>(o);
        bool canOpen=false;

        	if(p->getPosition().x>=0 && p->getPosition().x<9540/2 && p->getPosition().y>-4896 &&  p->getPosition().y<=0 ){
				canOpen=p->getKilledallMobs()[0];
			}else if(p->getPosition().x>=0 && p->getPosition().x<9540/2 && p->getPosition().y<4992 && p->getPosition().y>=0){
				canOpen=p->getKilledallMobs()[1];
			}else if(p->getPosition().x>=9540/2 && p->getPosition().x<=9540  && p->getPosition().y<4992 && p->getPosition().y>=0){
				canOpen=p->getKilledallMobs()[2];
			}else if((p->getPosition().x>=9540/2  && p->getPosition().x<=9540 && p->getPosition().y<0 && p->getPosition().y>=-4896)){
				canOpen=p->getKilledallMobs()[3];
			}
    std::cout<<"canOpen="<<canOpen<<std::endl;
        if (canOpen) {
                cout << "Can open GoldenChest" << endl;
                open();
                p->addKey();
        }
}
}
}


void GoldenChest::open(){
	chestAnim->x = 1;
        _sprite->setTextureRect(sf::IntRect(49 , 233, 32, 24));
        _sprite->scale(1.5,1.5);
        _isOpen=true;
}