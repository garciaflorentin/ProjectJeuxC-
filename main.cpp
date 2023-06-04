#include <SFML/Graphics.hpp>

#include "GameWindow.hpp"
#include "GameGestion.hpp"


int main(void)
{
    std::srand(std::time(nullptr));

    GameWindow _window; // cree la fenetre
    GameGestion& g = _window.getGame();

    _window.limitFrameRate(60);

    while (_window.isRunning()) {
        g.updateMobs();

        int fin = _window.controlWindow();
        
        if ((!_window.getUi().isPaused()) && _window.getUi().isLaunched())
            _window.display();
    }

    return EXIT_SUCCESS;
};