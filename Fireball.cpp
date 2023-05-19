#include "Fireball.hpp"


Fireball::Fireball(const char* nameObject, sf::Vector2f initPos, sf::Vector2f targetPos) : Object(nameObject, initPos), _targetPos(targetPos) {
    this->computeTrajectory();
}

void Fireball::computeTrajectory() {
    sf::Vector2f curr_pos = this->getPosition();

    float distX = _targetPos.x - curr_pos.x;
    float distY = _targetPos.y - curr_pos.y;

    //fireball has a range of 15 blocks --> divide both distances by number of pixels
    float stepX = distX / float(FIREBALL_RANGE*SPR_SIZE);
    float stepY = distY / float(FIREBALL_RANGE*SPR_SIZE);

    _step = {stepX, stepY};
}

void Fireball::launch() {
    if (_range_count >= 0) {
        if (_upd.getElapsedTime().asMilliseconds()%50 == 0) {
            _sprite->move(_step);
            _range_count++;
        }
    }
}