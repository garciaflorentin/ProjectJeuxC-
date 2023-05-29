#ifndef TEXTURESLIB_HPP
#define TEXTURESLIB_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

using namespace std;

/**
 * @brief La classe TexturesLib gère la bibliothèque de textures utilisées dans le jeu.
 */
class TexturesLib {

private:
    static map<string, sf::Texture*>* _textures; ///< La collection de textures.

public:

 /**
     * @brief Constructeur de la classe TexturesLib.
     */
    TexturesLib() {}

    /**
     * @brief Destructeur de la classe TexturesLib.
     */
    ~TexturesLib() {
        while (!_textures->empty()) {
            auto it = _textures->begin();
            delete it->second;
            _textures->erase(it);
        }
    }
    /**
     * @brief Récupère la collection de textures.
     * @return La collection de textures.
     */
    static map<string, sf::Texture*>* getTextures() {
        return _textures;
    }

    /**
     * @brief Assigner une texture à un fichier spécifié.
     * @param filename Le nom du fichier de la texture.
     * @param _texture La texture à assigner.
     * @return 0 si la texture est assignée avec succès, -1 sinon.
     */
    static int assignTexture(string filename, sf::Texture* _texture);

    /**
     * @brief Assigner une texture à un fichier spécifié.
     * @param filename Le nom du fichier de la texture.
     * @return Un pointeur vers la texture assignée, ou nullptr si la texture n'a pas pu être chargée.
     */
    static sf::Texture* assignTexture(string filename);

    /**
     * @brief Rechercher une texture dans la collection en fonction de l'indice et du type d'énumération.
     * @param i L'indice de la texture.
     * @param typeEnum Le type d'énumération.
     * @return Un pointeur vers la texture correspondante, ou nullptr si la texture n'a pas été trouvée.
     */
    static sf::Texture* findTexture(int i, int typeEnum);

    /**
     * @brief Récupère une texture à partir du nom de fichier spécifié.
     * @param filename Le nom de fichier de la texture.
     * @return Un pointeur vers la texture correspondante, ou nullptr si la texture n'a pas été trouvée.
     */
    sf::Texture* getTexture(const char* filename);
};

#endif
