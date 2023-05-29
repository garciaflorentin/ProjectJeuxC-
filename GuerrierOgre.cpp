#include "GuerrierOgre.hpp"

void GuerrierOgre::updateSprite(){
	    if(anim->x*OBJECT_SIZE >= OBJECT_SIZE*6){anim->x=3;}
	    _sprite->setTextureRect(sf::IntRect(anim->x*OBJECT_SIZE, anim->y*OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE));
 }

void GuerrierOgre::update(Player* pl) {
    //cout << "Updating monster" << endl;
    if(pl->isAlive()){
    this->_player = pl;

    if (playerSeen() && !playerInRange()) {  goToPlayer();}
    if (_upd.getElapsedTime().asMilliseconds()%40 == 0) {
        //cout << "Attack cooldown" << endl;
        if (playerInRange()){    attack(pl);}
    }
    }
}

void GuerrierOgre::goToPlayer()
{
    // cout << "Player seen" << endl;
    if(_player->isAlive()){

    sf::Vector2f player_pos = _player->getPosition();
    sf::Vector2f this_pos = this->getPosition();

    // cout << "current position : " << this_pos.x << ", " << this_pos.y << endl;

    float dist_x = player_pos.x - this_pos.x;
    float dist_y = player_pos.y - this_pos.y;

    sf::Vector2f np;
    np.x = 0;
    np.y = 0;

    if ((abs(dist_y) > _attack_radius - SPR_SIZE) || (abs(dist_x) > _attack_radius - SPR_SIZE))
    {
        if ((dist_x > 0) && (dist_y > 0))
        {
            if (dist_x > dist_y)
            {
                np.x++;
                if (_upd.getElapsedTime().asMilliseconds() % 1 == 0)
                {
                    anim->y = 6;
                    anim->x++;
                }
            }
            else
            {
                np.y++;
                if (_upd.getElapsedTime().asMilliseconds() % 1 == 0)
                {
                    anim->y = 4;
                    anim->x++;
                }
            }
        }
        else if ((dist_x < 0) && (dist_y < 0))
        {
            if (dist_x < dist_y)
            {
                np.x--;
                if (_upd.getElapsedTime().asMilliseconds() % 1 == 0)
                {
                    anim->y = 5;
                    anim->x++;
                }
            }
            else
            {
                np.y--;
                if (_upd.getElapsedTime().asMilliseconds() % 1 == 0)
                {
                    anim->y = 7;
                    anim->x++;
                }
            }
        }
        else if ((dist_x > 0) && (dist_y < 0))
        {
            if (abs(dist_x) > abs(dist_y))
            {
                np.x++;
                if (_upd.getElapsedTime().asMilliseconds() % 1 == 0)
                {
                    anim->y = 6;
                    anim->x++;
                }
            }
            else
            {
                np.y--;
                if (_upd.getElapsedTime().asMilliseconds() % 1 == 0)
                {
                    anim->y = 7;
                    anim->x++;
                }
            }
        }
        else if ((dist_x < 0) && (dist_y > 0))
        {
            if (abs(dist_x) > abs(dist_y))
            {
                np.x--;
                if (_upd.getElapsedTime().asMilliseconds() % 1 == 0)
                {
                    anim->y = 5;
                    anim->x++;
                }
            }
            else
            {
                np.y++;
                if (_upd.getElapsedTime().asMilliseconds() % 1 == 0)
                {
                    anim->y = 4;
                    anim->x++;
                }
            }
        }

        // cout << "moving by " << np.x << " " << np.y << endl;
        updateSprite();
        move({np.x * speed, np.y * speed});
    }
    }
}