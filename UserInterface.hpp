#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "TexturesLib.hpp"
#include "SoundsLib.hpp"


using namespace std;


/**
 * @brief Cette interface representa la GUI du jeu
 * 
 */
class UserInterface{
    private:
        const float _windowWidth = 1024.f, _windowHeight = 768.f;   ///< Les dimensions de la GUI

        sf::View _UiView;   ///< La vue sur la GUI

        sf::RenderWindow* _window;  ///< Fenetre a afficher

        sf::Event _event;           ///< Evenement a prendre en compte
        sf::VideoMode _videoMode;   ///< Le mode video
        sf::Texture& _UiTexture, _UiTexture1, _UiTexture2;  ///< Les textures de la GUI

        sf::Font _police;   ///< La police 

        sf::Music* _StartMusic; ///< Musique du debut de jeu

        sf::Sprite& _Background, _button1, _button2, _button3, _cadre;  ///< Sprites de la GUI

        bool _isPaused, _isLaunched, _isDead, _win; ///< Control d'affichage

    public:

        /**
         * @brief Constructeur de la classe `UserInterface`.
         */
        UserInterface();

        /**
         * @brief Operateur d'assignement
         * 
         * @param other GUI a assigner
         * @return UserInterface& - GUI assignee
         */
        UserInterface& operator=(const UserInterface& other);

        /**
         * @brief Destructeur de la classe `UserInterface`.
         */
        ~UserInterface();

        /**
         * @brief Dessine l'interface sur la fenêtre donnée.
         *
         * @param target Fenêtre de rendu
         */
        void drawTo(sf::RenderWindow& target);

        /**
         * @brief Met à jour l'interface.
         */
        void updateUi();

        /**
         * @brief Récupère la vue de l'interface.
         *
         * @return Vue de l'interface
         */
        const sf::View& getUiView() const {
            return _UiView;
        }

        /**
         * @brief Vérifie si le jeu est en pause.
         *
         * @return Vrai si le jeu est en pause, sinon faux
         */
        const bool isPaused() const {
            return _isPaused;
        }

        /**
         * @brief Vérifie si le jeu est en cours.
         *
         * @return Vrai si le jeu est en cours, sinon faux
         */
        const bool isLaunched() const {
            return _isLaunched;
        }

        /**
         * @brief Vérifie si le joueur est mort.
         *
         * @return Vrai si le joueur est mort, sinon faux
         */
        const bool isDead() const {
            return _isDead;
        }

        /**
         * @brief Vérifie si le joueur a gagné.
         *
         * @return Vrai si le joueur a gagné, sinon faux
         */
        const bool getWin() const {
            return _win;
        }

        /**
         * @brief Définit l'état de pause du jeu.
         *
         * @param state État de pause (vrai ou faux)
         */
        void setIsPaused(bool state){
            _isPaused=state;
        }

        /**
         * @brief Définit l'état du jeu en cours.
         *
         * @param state État du jeu en cours (vrai ou faux)
         */
        void setIsLaunched(bool state){
            _isLaunched=state;
        }

        /**
         * @brief Définit l'état de mort du joueur.
         *
         * @param state État de mort du joueur (vrai ou faux)
         */
        void setIsDead(bool state){
            _isDead=state;
        }

        /**
         * @brief Définit l'état de victoire du joueur.
         *
         * @param state État de victoire du joueur (vrai ou faux)
         */
        void setWin(bool state){
            _win=state;
        }

        /**
         * @brief Affiche l'écran de démarrage.
         */
        void setStartScreen();

        /**
         * @brief Exécute la fenêtre de pause.
         */
        void runPausedWindow();

        /**
         * @brief Exécute la fenêtre de jeu en cours.
         */
        void runLaunchedWindow();

        /**
         * @brief Exécute la fenêtre de fin de partie en cas de mort du joueur.
         */
        void runDeathWindow();

        /**
         * @brief Exécute la fenêtre de victoire.
         */
        void runVictoryWindow();

        /**
         * @brief Effectue un fondu sur la musique donnée.
         *
         * @param music Musique à fondu
         */
        void fade(sf::Music& music);

        /**
         * @brief Récupère la fenêtre de rendu.
         *
         * @return Fenêtre de rendu
         */
        sf::RenderWindow& getWindow(){
            return *_window;
        }
};


#endif