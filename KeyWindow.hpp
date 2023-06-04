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
        const float _windowWidth = 1024.0, _windowHeight = 55;  ///< Dimensions de l'affichage
        sf::View _keyView;  ///< Vue sur les cles
        sf::RenderTexture _keyTexture;  ///< Texture des cles a realiser
        sf::Sprite _keySprite;  ///< Sprite des cles a afficher
        sf::Texture& _texture;  ///< Texture des cles
        Player& _player;    ///< Joueur a qui appartiennent les cles

    public:
        /**
         * @brief Constructeur par defaut
         * 
         */
        KeyWindow() : _player(*(new Player())), _texture(*(new sf::Texture())) {};

        /**
         * @brief Constructeur de la classe `KeyWindow`.
         *
         * @param p Joueur
         */
        KeyWindow(Player& p);

        /**
         * @brief Operateur d'assignement
         * 
         * @param other Les cles a assigner
         * @return KeyWindow& - Cles assignees
         */
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