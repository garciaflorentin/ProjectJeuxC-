#include "TexturesLib.hpp"

// Initialisation de l'attribut statique 
map<string, sf::Texture*>* TexturesLib::_textures = new map<string, sf::Texture*>();

/* Charge une texture dans la map si elle est pas deja dedans et renvoie la texture
demandee*/
int TexturesLib::assignTexture(string filename,sf::Texture* _texture) {
    std::cout << " assignTexture() " << std::endl;

    if (_textures->count(filename) == 0) {
        _textures->insert({ filename, new sf::Texture });
        if (!((*_textures)[filename]->loadFromFile(filename) && _texture->loadFromFile(filename))) { //charger le fichier
            std::cout << "erreur dans le chargement de l'image [methode TexturesLib::assignTexture]" << std::endl;
            return EXIT_FAILURE;
        }
        std::cout << " assignTexture() : 2" << std::endl;
        return 2;
    }
    _texture = (*_textures)[filename];
    std::cout << " assignTexture()  : 3 " << std::endl;
    return 3;
}

sf::Texture* TexturesLib::assignTexture(string filename) {
    if (_textures->count(filename) == 0) {
        _textures->insert({ filename, new sf::Texture });
        if (!(*_textures)[filename]->loadFromFile(filename))    //charger le fichier
            throw runtime_error("Couldn't load texture from file " + filename);
    }

    return (*_textures)[filename];
}

sf::Texture* TexturesLib::findTexture(int i, int typeEnum) {
    if (typeEnum == 1) {//tile

        switch (i) {

        case 1:

            return (*_textures)["Grass.png"];
            break;
        case 2:
            return (*_textures)["Rock.png"];
            break;
        case 3:
            return (*_textures)["Tree.png"];
            break;

        }
    }
    else if (typeEnum == 2) {//monster

    }
    else if (typeEnum == 3) {//chest

        switch (i) {

        case 1: return (*_textures)["Chest.png"];
            break;

        }
    }

    return nullptr;
}