#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstring>

class UserInterface{

private:

    const float windowWidth = 1024.f, windowHeight = 768.f;
    sf::View* UiView;
    sf::RenderWindow* window;
    sf::Event* event;
    sf::VideoMode videoMode;
    sf::Texture* UiTexture;
    sf::Texture* UiTexture1;
    sf::Texture* UiTexture2;
    sf::Font* police;
    sf::Music StartMusic;

    sf::Sprite* Background;
    sf::Sprite* button1;
    sf::Sprite *button2;
    sf::Sprite *button3;
    sf::Sprite *cadre;

    bool _isPaused, _isLaunched, _isDead, _win;

public:

    /**
     * @brief Constructeur de la classe `UserInterface`.
     */
    UserInterface();

    /**
     * @brief Destructeur de la classe `UserInterface`.
     */
    ~UserInterface();

    /**
     * @brief Dessine l'interface sur la fenêtre donnée.
     *
     * @param target Fenêtre de rendu
     */
    void drawTo(sf::RenderWindow* target);

    /**
     * @brief Met à jour l'interface.
     */
    void updateUi();

    /**
     * @brief Récupère la vue de l'interface.
     *
     * @return Vue de l'interface
     */
    sf::View* getUiView() {
        return UiView;
    }

    /**
     * @brief Vérifie si le jeu est en pause.
     *
     * @return Vrai si le jeu est en pause, sinon faux
     */
    bool isPaused(){
        return _isPaused;
    }

    /**
     * @brief Vérifie si le jeu est en cours.
     *
     * @return Vrai si le jeu est en cours, sinon faux
     */
    bool isLaunched(){
        return _isLaunched;
    }

    /**
     * @brief Vérifie si le joueur est mort.
     *
     * @return Vrai si le joueur est mort, sinon faux
     */
    bool isDead(){
        return _isDead;
    }

    /**
     * @brief Vérifie si le joueur a gagné.
     *
     * @return Vrai si le joueur a gagné, sinon faux
     */
    bool getWin(){
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
    sf::RenderWindow* getWindow(){
        return window;
    }

};

#endif
