
#ifndef CHEST_HPP
#define CHEST_HPP


#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Player.hpp"

class Chest {

private:
    bool isOpen;
public:

    Chest();
    ~Chest();
    bool isOpen();
    int open(Player* player);

};

#endif