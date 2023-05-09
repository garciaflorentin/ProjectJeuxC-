#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "Character.hpp"

class Monster : public Character {
    private :
        int _damage;
        int _attack_radius;
        int _vision_field;

        void hitPlayer(Character& target);
        void goToPlayer();
        bool playerInRange() const;

        //std::vector<Object*>* _map;

    public :
        Monster() : Character() {};
        Monster(const char* nameObject, sf::Vector2f initPos, string name="meat", int dmg=1, int ar=1, int vf=5) :
            Character(nameObject, initPos),  _damage(dmg), _attack_radius(ar), _vision_field(vf) {};
        
        void attackPlayer(Character& target);
        void moveTo(sf::Vector2i nextPos);
        void update();
};

#endif