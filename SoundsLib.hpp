#ifndef SOUNDSLIB_HPP
#define SOUNDSLIB_HPP


#include <SFML/Audio.hpp>
#include <map>
#include <iostream>


using namespace std;


/**
 * @brief La classe SoundsLib gère la bibliothèque de Sounds utilisées dans le jeu.
 */
class SoundsLib {

    private:
        static map<string, sf::Music*> _sounds; ///< La collection de Sounds.

    public:

    /**
         * @brief Constructeur de la classe SoundsLib.
         */
        SoundsLib() {};

        /**
         * @brief Destructeur de la classe SoundsLib.
         */
        ~SoundsLib() {
            while (!_sounds.empty()) {
                auto it = _sounds.begin();
                delete it->second;
                _sounds.erase(it);
            }
        }

        /**
         * @brief Récupère la collection de Sounds.
         * @return La collection de Sounds.
         */
        static map<string, sf::Music*>& getSounds() {
            return _sounds;
        }

        /**
         * @brief Assigner une texture à un fichier spécifié.
         * @param filename Le nom du fichier de la texture.
         * @param _texture La texture à assigner.
         * @return 0 si la texture est assignée avec succès, -1 sinon.
         */
        static int assignSound(string filename, sf::Music* _texture);

        /**
         * @brief Assigner une texture à un fichier spécifié.
         * @param filename Le nom du fichier de la texture.
         * @return Un pointeur vers la texture assignée, ou nullptr si la texture n'a pas pu être chargée.
         */
        static sf::Music* assignSound(string filename);
};


#endif