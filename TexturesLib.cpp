#include "TexturesLib.hpp"


map<string, sf::Texture*> TexturesLib::_textures;


int TexturesLib::assignTexture(string filename, sf::Texture& _texture) {
    if (TexturesLib::_textures.count(filename) == 0) {
        _textures.insert({ filename, new sf::Texture });

        if (!(TexturesLib::_textures[filename]->loadFromFile(filename))) { //charger le fichier
            //cout << "erreur dans le chargement de l'image " << filename << endl;
            throw runtime_error("Error loading texture " + filename);
            return EXIT_FAILURE;
        }

        return 0;
    }

    _texture = *TexturesLib::_textures[filename];
    return 0;
}


sf::Texture& TexturesLib::assignTexture(string filename) {
    cout << "Looking for texture " << filename << endl;
    
    if (_textures.count(filename) == 0) {
        _textures.insert({ filename, new sf::Texture });

        if (!_textures[filename]->loadFromFile(filename)) {    //charger le fichier
            throw runtime_error("Error loading texture " + filename);
        }
    }

    return *_textures[filename];
}
