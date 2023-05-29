#include "Fireball.hpp"


Fireball::Fireball(const char* nameObject, sf::Vector2f initPos, Character* player, float angle, int dmg) : 
    Projectile(nameObject, initPos, nullptr) {
        cout << "Creating new Fireball with initPos = " << initPos.x << " " << initPos.y << endl;
        _target = player;
        _isShot = false;
        distance = 0;

        this->setPosition(initPos);

        // _initPos = initPos;
        // setPosition(_initPos);

        _dmg = dmg;

        if (player!=nullptr) {

            cout << "computing trajectory" << endl;
            this->computeTrajectory(angle);

            initProjectile();
        }

        // while (!_isShot) {
        //     goTo;
        // }
}

void Fireball::computeTrajectory(float angle) {
    sf::Vector2f targetPos = _target->getPosition();
    cout << "got target position : " << targetPos.x << ", " << targetPos.y << endl;
    cout << "initial position : " << this->getPosition().x << ", " << this->getPosition().y << endl;

    float distX = targetPos.x - this->getPosition().x;
    float distY = targetPos.y - this->getPosition().y;

    distX += distX * (1-cos(angle));
    distY += distY * (sin(angle));

    // _dirVect.x = distX / PROJECTILE_SPEED;
    // _dirVect.y = distY / PROJECTILE_SPEED;

    _dirVect.x = -distX / (distX+distY) * PROJECTILE_SPEED;
    _dirVect.y = -distY / (distX+distY) * PROJECTILE_SPEED;

    cout << "direction vector : " << _dirVect.x << " " << _dirVect.y << endl;
}

void Fireball::initProjectile(){
    std::cout<<"init fireball"<<std::endl;
    //_sprite->setTextureRect(sf::IntRect(0,0,256,256));
    if (_dirVect.x != 0)    _sprite->rotate(-atan(_dirVect.y/_dirVect.x));
    else                    _sprite->rotate(90);

    //_sprite->setPosition(_initPos.x,_initPos.y);
}

void Fireball::goTo(){
    //cout << "Moving fireball" << endl;
    this->getSprite()->move(_dirVect);
}

void Fireball::collide(Object* o){
    std::cout<<"Fireball CollideObject"<<std::endl;
    //Character* p=dynamic_cast<Character*>(o);
   if(o->getName()=="player1.png" || o->getName()=="player2.png"){
        std::cout<<"Fireball collide Player"<<std::endl;
        Player* target=dynamic_cast<Player*>(o);
        target->takeDamage(2);
    }

    distance=0;
    _isShot=false;
 }
