#include "GameWindow.hpp"
#include "Object.hpp"

int main(void) {
    __cplusplus;
    GameWindow _window;
    Object o("object.png");
    std::vector<sf::Sprite> sprites;
    sprites.push_back(o.getSprite());

    while (_window.isRunning()) {
        _window.controlWindow();
        _window.updateWindow();
        // Window.verificationWindow();
   
    }
    return EXIT_SUCCESS;
}