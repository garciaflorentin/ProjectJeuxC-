#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>

#include "TexturesLib.hpp"
#include "SoundsLib.hpp"


using namespace std;


/**
 * @class Object
 * @brief Classe de base pour les objets du jeu.
 */
class Object {
    protected:
        //bool _isOpen = true;

        sf::Texture& _texture; /**< Pointeur vers la texture de l'objet */
        sf::Sprite& _sprite; /**< Pointeur vers le sprite de l'objet */
        string _name; /**< Nom de l'objet */

    public:
        Object() : _texture(*(new sf::Texture)), _sprite(*(new sf::Sprite)) {};

        /**
         * @brief Constructeur de la classe Object avec un nom et une position initiale.
         * @param nameObject Nom de l'objet.
         * @param initPos Position initiale de l'objet.
         */
        Object(string nameObject, sf::Vector2f initPos);

        Object& operator=(const Object& other);

        /**
         * @brief Destructeur de la classe Object.
         */
        virtual ~Object() {};

        /**
         * @brief Charge la texture sur le sprite de l'objet.
         * @param nameSprite Nom de la texture.
         * @param initPos Position initiale du sprite.
         */
        void loadSprite(string nameSprite, sf::Vector2f initPos);

        /**
         * @brief Renvoie la taille du bloc de l'objet (méthode virtuelle pure à implémenter dans les classes dérivées).
         * @return Taille du bloc de l'objet.
         */
        virtual const int getBlockSize() const { return 0; };

        /**
         * @brief Gère la collision entre l'objet et un autre objet (méthode virtuelle pure à implémenter dans les classes dérivées).
         * @param o Pointeur vers l'objet avec lequel la collision est détectée.
         */
        virtual void collide(Object& o) {};

        /**
         * @brief Renvoie le numéro de série de l'objet.
         * @return Numéro de série de l'objet.
         */
        virtual const int getSerial() const;

        /**
         * @brief Définit la position de l'objet.
         * @param newPos Nouvelle position de l'objet.
         */
        void setPosition(sf::Vector2f& newPos);

        /**
         * @brief Définit la position de l'objet dans une boîte.
         * @param newPos Nouvelle position de l'objet.
         */
        void setPositionInBox(sf::Vector2f& newPos);

        /**
         * @brief Renvoie le sprite de l'objet.
         * @return Pointeur vers le sprite de l'objet.
         */
        sf::Sprite& getSprite();

        /**
         * @brief Renvoie la position de l'objet.
         * @return Position de l'objet.
         */
        const sf::Vector2f getPosition() const;

        /**
         * @brief Définit le sprite de l'objet.
         * @param sprite Sprite à définir.
         */
        void setSprite(sf::Sprite& sprite);

        /**
         * @brief Renvoie le nom de l'objet.
         * @return Nom de l'objet.
         */
        const string getName() const;

        /**
         * @brief Met à jour l'objet.
         * @param player Référence vers l'objet joueur.
         */
        virtual void update(Object& player){};

        //virtual bool isOpen() const { return true; };
};


#endif