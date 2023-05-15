#include "Object.hpp"

// d�finition de l'attribut de classe texturesLib, commun � tout les objects.
TexturesLib Object::_texturesLib;

bool Object::loadTexture(const char* spriteName) {// inutile surrement
    

    if (!_texture->loadFromFile(spriteName)) {

        std::cout << "error image " << spriteName << std::endl;
        return false;

    }
    return true;
}

// constructeurs

Object::Object(){
    _isUse = false;
    _texture = new sf::Texture();
    _sprite = new sf::Sprite();
    name = nullptr;
    //_texturesLib = TexturesLib();
}

Object::Object(const char* nameObject, sf::Vector2f initPos) : _isUse(false){
    _texture = new sf::Texture();
    _sprite = new sf::Sprite();

    std::cout << "Object Constructeur" << std::endl;
    //nom
    name = nameObject;
    //_texturesLib = TexturesLib();
    //on charge la textures sur le sprite
    switch(loadSprite(nameObject, initPos)) {

    case 1: cout << "une erreur c'est produit lors du chargement l'initialisation de l'object " << name << endl; break;
    case 2:
        cout << "Nouvelle texture charge et "<<name<<" sprite cree " << endl; break;
    
    case 3:

        cout << "Texture deja connu. Texture telecharg� et une copie de" << name <<" cree" << endl;
    }


}

Object::~Object() {
    delete[] _texture;
    delete[] _sprite;
}

const int Object::loadSprite(const char* nameSprite, sf::Vector2f initPos) { // return false si la texture � deja etait charg� , recupere la texture et l'assigne au sprite de l'object et return true sinon charge la textures et assigne la texture au sprite de l'object.
    std::cout << "loadsprite()" << std::endl;
    switch (TexturesLib::assignTexture(nameSprite, _texture))
    {
    case 1: return 1; break;
    case 2:
        // si jamais charg�
        _texture->setSmooth(true);
        _sprite->setTexture(*_texture);
        setPositionInBox(initPos);
        std::cout << "loadsprite() : 2" << std::endl;
        return 2;
        break;
    
    case 3:
        //si deja charg� ( il est dans _textures )
        //sf::Texture* texture = _texturesLib.getTextures()[nameSprite];
        _texture->setSmooth(true);
        _sprite->setTexture(*_texturesLib.getTexture(nameSprite));
        setPositionInBox(initPos);
        std::cout << "loadsprite() : 3" << std::endl;
        return 3;
        break;

    }
    
    return 0;
}



void Object::setPosition(sf::Vector2f& newPos){
    _sprite->setPosition(newPos);
}

void Object::setPositionInBox(sf::Vector2f& newPos){
    _sprite->setPosition({newPos.x*48,newPos.y*48});
}

// string Object::getName() const {
//     cout << "string conversion started" << endl;

//     if (name != 0) {
//         cout << "calling string constructor" << endl;
//         string* ret_name = new string(name);
//         cout << "string conversion ended" << endl;
//         return *ret_name;
//     }
     
//     else return "no_name";
// }