#include "Projectile.hpp"


Projectile::Projectile(const char* nameObject, sf::Vector2f initPos,Player* player) : Object(nameObject,initPos){
    this->player = player;
    _isShooted= false;
    //initProjectile();
}
/*
Projectile::Projectile(const Projectile& other) : Object(other)
{
    player = other.player;
    _isShooted = other._isShooted;
    initProjectile();
}

Projectile& Projectile::operator=(const Projectile& other)
{
    if (this != &other) {
        Object::operator=(other);
        player = other.player;
        _isShooted = other._isShooted;
        initProjectile();
    }
    return *this;
}

*/

void Projectile::goTo(int dir){
    switch(dir){
        case 0:
        getSprite()->move(0,10);
        break;
        case 1:
        getSprite()->move(-10,0);
        break;
        case 2:
        getSprite()->move(10,0);
        break;
        case 3:
        getSprite()->move(0,-10);
        break;

    }
}

void Projectile::initProjectile(){
    _sprite->setTextureRect(sf::IntRect(player->getOrientation()*256,0,256,256));
    _sprite->scale(0.125,0.125);
    std::cout<<"playerPos  "<<"_xPlayer="<<player->getPosition().x<<"_yPlayer="<<player->getPosition().y<<std::endl;
    switch(player->getOrientation()){
        case 0:
        std::cout<<" fleche initialisé vers le bas" << std::endl;
            _sprite->setPosition(player->getPosition().x,player->getPosition().y+32);
            break;
        case 1:
            std::cout<<" fleche initialisé vers le haut" << std::endl;

            _sprite->setPosition(player->getPosition().x,player->getPosition().y-32);
            break;          
         case 2:
                 std::cout<<" fleche initialisé vers le drotie" << std::endl;

            _sprite->setPosition(player->getPosition().x+32,player->getPosition().y);
            break;  
        case 3:
                std::cout<<" fleche initialisé vers le gauche" << std::endl;

            _sprite->setPosition(player->getPosition().x-32,player->getPosition().y);
            break;
    }
    std::cout<<"projPos  "<<"_xProj="<<this->getPosition().x<<"_yProj="<<this->getPosition().y<<std::endl;


}


 void Projectile::collide(Object* o){
    _isShooted=false;
    initProjectile();    
    std::cout<<"ProjectcollideAobject"<<std::endl;
 }
