#include <SFML/Graphics.hpp>

#include "GameWindow.hpp"
#include "GameGestion.hpp"


int main(void)
{
    std::srand(std::time(nullptr));

    GameWindow _window; // cree la fenetre
    GameGestion& g = _window.getGame();
    //Player& p = *g.getPlayerVector()[0];
    //sf::Sprite& sp = p.getSprite();
    g.setPlayer(); // decoupe le sprite en ses differentes orientation , l'ajoute au vecteur de sprite de GameGestion et initialise le vecteur de mouvement.

    _window.limitFrameRate(60);

    while (_window.isRunning()) {
        g.updateMobs();

        int fin = _window.controlWindow();
        
        if ((!_window.getUi().isPaused()) && _window.getUi().isLaunched())
            _window.display();
    }

    return EXIT_SUCCESS;
};