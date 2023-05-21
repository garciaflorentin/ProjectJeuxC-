#include "GoldenChest.hpp"

void GoldenChest::collide(Object* o){
  cout << "Chest collistion" << endl;
        //if(typeid(*o) == typeid(Character)){
        //cout << "Character collistion" << endl;
if(!isOpen()){
        Character* p=dynamic_cast<Character*>(o);
        bool canOpen=false;

        	if(p->getPosition().x>=0 && p->getPosition().x<4800 && p->getPosition().y>-5000 &&  p->getPosition().y<=0 ){
				canOpen=p->getKilledallMobs()[0];
			}else if(p->getPosition().x>=0 && p->getPosition().x<4800 && p->getPosition().y<5000 && p->getPosition().y>=0){
				canOpen=p->getKilledallMobs()[1];
			}else if(p->getPosition().x>=4800 && p->getPosition().x<=9600  && p->getPosition().y<-5000 && p->getPosition().y<=0){
				canOpen=p->getKilledallMobs()[2];
			}else if((p->getPosition().x>=4800 && p->getPosition().x<=9600 && p->getPosition().y<5000 && p->getPosition().y>=0)){
				canOpen=p->getKilledallMobs()[3];
			}
    std::cout<<"canOpen="<<canOpen<<std::endl;
        if (p->getName() == "player1.png" && canOpen) {
                cout << "Can open GoldenChest" << endl;
                open();
                p->addKey();
        }
}
}


void GoldenChest::open(){
    std::cout<<"a"<<std::endl;
	chestAnim->x = 1;
        _sprite->setTextureRect(sf::IntRect(49 , 233, 32, 24));
        _isOpen=true;
}