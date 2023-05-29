#ifndef LIFEWINDOW_HPP
#define LIFEWINDOW_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Heart.hpp"
#include "Object.hpp"

/**
 * @class LifeWindow
 * @brief Classe représentant la fenêtre de vie du joueur.
 *
 * La classe `LifeWindow` gère l'affichage de la barre de vie du joueur.
 */
class LifeWindow {
private:
    const float windowWidth = 1024.0, windowHeight = 55;
    sf::View* lifeView;
    sf::RenderTexture* lifeTexture;
    sf::Sprite* lifeSprite;
    Heart* lifePlayer;

public:
    /**
     * @brief Constructeur de la classe `LifeWindow`.
     *
     * @param HeartPlayer Coeur du joueur
     */
    LifeWindow(Heart* HeartPlayer);

    /**
     * @brief Destructeur de la classe `LifeWindow`.
     */
    ~LifeWindow();

    /**
     * @brief Dessine la fenêtre de vie sur la cible spécifiée.
     *
     * @param target Fenêtre de rendu cible
     */
    void drawTo(sf::RenderWindow* target);

    /**
     * @brief Met à jour la fenêtre de vie.
     */
    void updateWindow();

    /**
     * @brief Obtient la vue de la fenêtre de vie.
     *
     * @return Vue de la fenêtre de vie
     */
    sf::View* getLifeView();
};

#endif
