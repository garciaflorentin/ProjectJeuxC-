#ifndef KEYWINDOW_HPP
#define KEYWINDOW_HPP

#include <SFML/Graphics.hpp>

#include "Player.hpp"


/**
 * @class KeyWindow
 * @brief Classe représentant la fenêtre des clés du joueur.
 *
 * La classe `KeyWindow` gère l'affichage des clés collectées par le joueur.
 */
class KeyWindow {
    private:
        const float _windowWidth = 1024.0, _windowHeight = 55;
        sf::View _keyView;
        sf::RenderTexture _keyTexture;
        sf::Sprite _keySprite;
        sf::Texture _texture;
        Player& _player;

    public:
        KeyWindow() : _player(*(new Player())) {};

        /**
         * @brief Constructeur de la classe `KeyWindow`.
         *
         * @param p Joueur
         */
        KeyWindow(Player& p);


        KeyWindow& operator=(const KeyWindow& other);

        /**
         * @brief Destructeur de la classe `KeyWindow`.
         */
        ~KeyWindow() {};

        /**
         * @brief Dessine la fenêtre des clés sur la cible spécifiée.
         *
         * @param target Fenêtre de rendu cible
         */
        void drawTo(sf::RenderWindow& target);

        /**
         * @brief Met à jour la fenêtre des clés.
         */
        void updateWindow();

        /**
         * @brief Obtient la vue de la fenêtre des clés.
         *
         * @return Vue de la fenêtre des clés
         */
        const sf::View& getKeyView() const;
};


#endif