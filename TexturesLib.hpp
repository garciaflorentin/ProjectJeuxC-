#ifndef TEXTURESLIB_HPP
#define TEXTURESLIB_HPP

#include <SFML/Graphics.hpp>

using namespace std;

class TexturesLib {
public:
    //j'ai rendu _textures public afin d'y acceder directement, plus facile
    //bibliotheque des textures classee par nom du fichier
    static map<string, sf::Texture*> _textures;


    /* Accesseurs */
    const bool addTexture(string filename, sf::Texture* texture);// fonction inutile.

    //focntions assignTexture , sur-chargé mais faisant la meme chose avec differents attributs

    bool assignTexture(string filename, sf::Texture* _texture);

    sf::Texture* assignTexture(string filename);

    map<string, sf::Texture*>& getTexturesMap() const{
        return _textures;
    }

   
};

  

#endif