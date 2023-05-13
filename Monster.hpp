#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "Character.hpp"
#include "Player.hpp"

#define SPRITE_SIZE 48

class Monster : public Character {
    private :
        static Player* _player;
        
        int _damage;
        float _attack_radius;
        float _vision_field;

        //void hitPlayer(Character& target);
        void goToPlayer();
        bool playerSeen() const;
        bool playerInRange() const;

        //std::vector<Object*>* _map;

        //virtual void setDamage(Character* target);

    public :
        Monster(const char* nameObject, sf::Vector2f initPos, string name="meat", int dmg=1, int ar=1, int vf=5) :
            Character(nameObject, initPos),  _damage(dmg), _attack_radius(ar*SPRITE_SIZE), _vision_field(vf*SPRITE_SIZE) {};
        
        void attack(Character* target);
        void move(sf::Vector2i deplacement);
        
        void update(Player& pl);
        
};

#endif