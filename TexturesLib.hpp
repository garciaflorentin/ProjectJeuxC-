#ifndef TEXTURESLIB_HPP
#define TEXTURESLIB_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class TexturesLib {

private:
    static map<string, sf::Texture*>* _textures;

public:

    TexturesLib() {
        _textures = new map<string, sf::Texture*>;
    }

    ~TexturesLib() {
        while (!_textures->empty())
        {
            auto it = _textures->begin(); // Obtenir l'it�rateur du premier �l�ment
            delete it->second; // Supprimer la texture point�e par la valeur de la paire cl�-valeur
            _textures->erase(it); // Supprimer la paire cl�-valeur
        }

    }

    map<string, sf::Texture*>* getTextures() {
        return _textures;
    }

    //focntions assignTexture , sur-charg� mais faisant la meme chose avec differents attributs

    int assignTexture(string filename, sf::Texture* _texture);

    sf::Texture* assignTexture(string filename);



   
};

  

#endif