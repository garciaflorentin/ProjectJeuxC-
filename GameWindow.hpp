#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include <SFML/Graphics.hpp>

#include "GameGestion.hpp"
#include "LifeWindow.hpp"
#include "KeyWindow.hpp"
#include "UserInterface.hpp"


using namespace std;


/**
 * @class GameWindow
 * @brief Represente l'affichage de la fenetre
 */
class GameWindow {
    private :
        float _windowWidth = 1024.0, _windowHeight = 768.0; ///< Dimensions de la fenetre
        sf::RenderWindow* _window; /**< The SFML render window */
        sf::Event _event; /**< The SFML event object */
        sf::VideoMode _videoMode; /**< The SFML video mode */
        sf::View _view; /**< The SFML view */
        vector<sf::Vector2f> _currentWindowPos; /**< The current window position */
        sf::Vector2f _positionCentre; /**< The center position of the window */

        // Class instances
        GameGestion& _game; /**< The game management instance */
        LifeWindow& _lifeWindow; /**< The life window instance */
        LifeWindow& _lifeWindowP2; /**< The second player's life window instance */
        KeyWindow& _keyWindow; /**< The key window instance */
        UserInterface& _ui; /**< The user interface instance */

        // Private member functions
        /**
         * @brief Polls the SFML event to handle user input.
         */
        void pollEvent();

        /**
         * @brief Sets the current window position.
         */
        void setCurrentWindowPos();

    public:
        // Constructors and Destructor
        /**
         * @brief Default constructor for GameWindow.
         */
        GameWindow();

        /**
         * @brief Destructor for GameWindow.
         */
        ~GameWindow();

        // Getters
        /**
         * @brief Gets the GameGestion instance.
         * @return A pointer to the GameGestion instance.
         */
        GameGestion& getGame();

        /**
         * @brief Gets the position of the window center.
         * @return A reference to the position of the window center.
         */
        const sf::Vector2f& getPositionCentre() const;

        /**
         * @brief Gets the SFML render window.
         * @return A pointer to the SFML render window.
         */
        sf::RenderWindow& getWindow() const;

        /**
         * @brief Gets the UserInterface instance.
         * @return A pointer to the UserInterface instance.
         */
        const UserInterface& getUi() const;

        /**
         * @brief Gets the dimensions of the window.
         * @return The dimensions of the window as a sf::Vector2f.
         */
        const sf::Vector2f getWindowDim() const;

        /**
         * @brief Gets the current window position.
         * @return A pointer to the current window position vector.
         */
        std::vector<sf::Vector2f>& getCurrentWindowPos();

        /**
         * @brief Gets the SFML view of the window.
         * @return A pointer to the SFML view.
         */
        const sf::View& getViewWindow() const ;

        // Setters
        /**
         * @brief Sets the life view for player 1.
         */
        void setLifeViewPlayer1();

        /**
         * @brief Sets the life view for player 2.
         */
        void setLifeViewPlayer2();

        /**
         * @brief Sets the key view.
         */
        void setKeyView();

        // Control
        /**
         * @brief Checks if the game window is running.
         * @return True if the window is open, false otherwise.
         */
        const bool isRunning() const;

        /**
         * @brief Controls the game window, handling user input and updating the game state.
         * @return An integer representing the game state.
         */
        int controlWindow();

        /**
         * @brief Limits the frame rate of the game window.
         * @param frame The desired frame rate.
         */
        void limitFrameRate(int frame);

        // Display
        /**
         * @brief Clears the window.
         */
        void clearWindow() const;

        /**
         * @brief Draws all sprites to the window.
         */
        void draw();

        /**
         * @brief Displays the window.
         */
        void display();

        /**
         * @brief Sets the scrolling view for the game.
         */
        void setScrollingView();

        /**
         * @brief Sets the view for the boss fight.
         */
        void setViewBoss();

        // Private display functions
        /**
         * @brief Displays the life window.
         */
        void displayLifeWindow();

        /**
         * @brief Displays the second player's life window.
         */
        void displayLifeWindowP2();

        /**
         * @brief Displays the key window.
         */
        void displayKeyWindow();
};


#endif


