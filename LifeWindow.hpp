#ifndef LIFEWINDOW_HPP
#define LIFEWINDOW_HPP

#include <SFML/Graphics.hpp>

#include "Heart.hpp"


/**
 * @class LifeWindow
 * @brief Classe représentant la fenêtre de vie du joueur.
 *
 * La classe `LifeWindow` gère l'affichage de la barre de vie du joueur.
 */
class LifeWindow {

    private:
        const float _windowWidth = 1024.0, _windowHeight = 55;  ///< Dimensions de l'affichage
        sf::View& _lifeView;                ///< Vue sur les coeurs
        sf::RenderTexture* _lifeTexture;    ///< Textures a realiser
        sf::Sprite _lifeSprite; ///< Sprite des coeurs
        Heart& _lifePlayer; ///< Les coeurs du joueurs

    public:
        /**
         * @brief Constructeur par defaut
         * 
         */
        LifeWindow() : _lifePlayer(*(new Heart())), _lifeView(*(new sf::View())) {};

        /**
         * @brief Constructeur de la classe `LifeWindow`.
         *
         * @param HeartPlayer Coeur du joueur
         */
        LifeWindow(Heart& HeartPlayer);

        /**
         * @brief Operateur d'assignement
         * 
         * @param other L'affichage a assigner
         * @return LifeWindow& - L'affichage assigne
         */
        LifeWindow& operator=(const LifeWindow& other);

        /**
         * @brief Destructeur de la classe `LifeWindow`.
         */
        ~LifeWindow() {};

        /**
         * @brief Dessine la fenêtre de vie sur la cible spécifiée.
         *
         * @param target Fenêtre de rendu cible
         */
        void drawTo(sf::RenderWindow& target);

        /**
         * @brief Met à jour la fenêtre de vie.
         */
        void updateWindow();

        /**
         * @brief Obtient la vue de la fenêtre de vie.
         *
         * @return Vue de la fenêtre de vie
         */
        const sf::View& getLifeView() const;
};



#endif