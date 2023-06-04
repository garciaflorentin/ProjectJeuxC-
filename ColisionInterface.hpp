#ifndef _COLISIONINTERFACE_H_
#define _COLISIONINTERFACE_H_

/// Special library
#include <SFML/Graphics.hpp>

/// STL
#include <iostream>
#include <vector>
#include <string>

#include "Object.hpp"


/**
 * @brief Cette interface permet de gerer les collisions
 * 
 */
class ColisionInterface {

    public:

        /// Check if two sprite are in contact
        /// \param sprite1 First sprite
        /// \param sprite2 Second sprite
        /// \return True if the two sprite are in contact
    // virtual bool collideTwoSprite64x64(sf::Vector2f sprite1, sf::Vector2f sprite2) = 0;

        /// Chec if the player's sword is in conctact with the target
        /// \param target the sprite in contact with the sword
        /// \return True if the sprite is in constact with the sword
    //  virtual bool collideSword(Character attacker, Character target) = 0;

        /// Check if the sprite is in contact with a list of sprite
        /// \param user The sprite Checked
        /// \param wall List of sprite
        /// \param info est  un vecteur indiquant le type de colide ([1]) et l'indice du mur concerné ([0])
        virtual void collideWall(Object& o, std::vector <Object*>& wallList,std::vector<int>& info) = 0;

        /// Check if the next move is possible
        /// \param user The sprite who will move
        /// \param move His deplacement
        /// \return True if he can't move
        //virtual bool previewCollide(sf::Vector2f user, sf::Vector2f move) = 0;

        /// Check if the sprite will go out the map
        /// \param user The sprite Check
        virtual void LimitMap() = 0;

        ///
        //virtual void collideMonster(Player& player, Monster& monster) = 0;

        /// Check where the sprite if in contact
        /// \param sprite1 The sprite who suffered the contact
        /// \param sprite2 The sprite who afflict the contact
        virtual int collidePosition(Object& object1, Object& object2) = 0;
};

#endif