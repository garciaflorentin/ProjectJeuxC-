#ifndef MONSTER_HPP
#define MONSTER_HPP

//#include "Character.hpp"
#include "Player.hpp"

#define SPR_SIZE 48

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

        void setDamage(Character* target) {};

        sf::Clock _upd;

        bool _canOpenChest = false;

    public :
        Monster(const char* nameObject, sf::Vector2f initPos, string name="meat", int dmg=1, int ar=3, int vf=6);
        ~Monster();
        
        void attack(Character* target);
        void move(sf::Vector2f deplacement);
        
        void update(Player* pl);      

        void collide(Object* o) {};  

        void openChest(Chest* chest) {};
        
        bool fireball();
};

#endif