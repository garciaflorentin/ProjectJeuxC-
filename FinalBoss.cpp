#include "FinalBoss.hpp"


FinalBoss::FinalBoss() : Monster("angry_cat.png", {100,100}, "serious meat", 1, 10, 100, 1.5) {
    for (int i = 0; i < 5; i++) _fireballs.push_back(nullptr);
}


void FinalBoss::update(Player* pl) {
    
}

void FinalBoss::attack(Character* character) {
    
}