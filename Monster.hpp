#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "Character.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
class Player;


#define SPR_SIZE 48

class Monster : public Character {
    protected :
        static Player* _player;

        static int _serial;

        int _this_serial;
        
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
        Monster(const char* nameObject, sf::Vector2f initPos, string name="meat", int dmg=1, int ar=2, int vf=5);
        ~Monster();
        
        virtual void attack(Character* target);
        void move(sf::Vector2f deplacement);
        
        void update(Player* pl);      

        void collide(Object* o) {
            //std::cout<<"monsterCollide"<<std::endl;
        };  

        void openChest(Chest* chest) {};

        float lifetime_secs() { return _upd.getElapsedTime().asSeconds(); };

        int getSerial() { return _this_serial; };

        virtual Projectile* getProjectile() { return nullptr; }
};

#endif


