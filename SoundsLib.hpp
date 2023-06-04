#ifndef SOUNDSLIB_HPP
#define SOUNDSLIB_HPP


#include <SFML/Audio.hpp>
#include <map>
#include <iostream>


using namespace std;


/**
 * @brief La classe SoundsLib gère la bibliothèque de sons utilisées dans le jeu.
 */
class SoundsLib {

    private:
        static map<string, sf::Music*> _sounds; ///< La collection de sons

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
         * @brief Récupère la collection de sons.
         * @return La collection de sons.
         */
        static map<string, sf::Music*>& getSounds() {
            return _sounds;
        }

        /**
         * @brief Assigner un son du nom de fichier spécifié.
         * @param filename Le nom du fichier du son.
         * @param sound Le son à assigner.
         * @return 0 si la texture est assignée avec succès, -1 sinon.
         */
        static int assignSound(string filename, sf::Music* sound);

        /**
         * @brief Assigner un son du nom de fichier spécifié.
         * @param filename Le nom du fichier du son.
         * @return Un pointeur vers le son assigné, ou nullptr si la texture n'a pas pu être chargée.
         */
        static sf::Music* assignSound(string filename);
};


#endif