#ifndef DOOR_HPP
#define DOOR_HPP

#include "Wall.hpp"
#include "Player.hpp"


class Door : public Wall {

    protected:
        sf::Vector2f _anim; /**< Vecteur d'animation de la porte */
        bool _isOpen; /**< Indique si la porte est ouverte */
        bool _isOpening; /**< Indique si la porte est en train de s'ouvrir */
        int _door_size = 240; /**< Taille de la porte */
        int _cpt = 0; /**< Compteur pour l'animation de la porte */
        sf::Sprite& _backDoorSprite; /**< Sprite du fond de la porte */
        sf::Texture& _backDoorTexture; /**< Texture du fond de la porte */

    public:
        Door() : _backDoorTexture(*(new sf::Texture)), _backDoorSprite(*(new sf::Sprite)) {};

        /**
         * @brief Constructeur de la classe `Door`.
         *
         * @param nameObject Nom de l'objet
         * @param initPos Position initiale
         * @param _typeWall Type de mur de la porte
         */
        Door(string nameObject, sf::Vector2f initPos, TypeWall _typeWall);

        virtual Door& operator=(const Door& other) {
            Wall::operator=(other);

            _anim = other._anim;
            _isOpen = other._isOpen;
            _isOpening = other._isOpening;
            _door_size = other._door_size;
            _cpt = other._cpt;
            _backDoorSprite = other._backDoorSprite;
            _backDoorTexture = other._backDoorTexture;

            return *this;
        };

        /**
         * @brief Destructeur de la classe `Door`.
         */
        ~Door();

        /**
         * @brief Définit l'état d'ouverture de la porte.
         *
         * @param state État d'ouverture de la porte (ouvert ou fermé)
         */
        void setIsOpen(bool state) {
            _isOpen = state;
        }

        /**
         * @brief Définit l'état d'ouverture de la porte en cours.
         *
         * @param state État d'ouverture de la porte en cours (en train de s'ouvrir ou non)
         */
        void setIsOpening(bool state) {
            _isOpening = state;
        }

        /**
         * @brief Anime la porte.
         */
        virtual void animDoor();

        /**
         * @brief Gère la collision avec un objet.
         *
         * @param o Objet avec lequel il y a collision.
         */
        virtual void collide(Object& o);

        /**
         * @brief Indique si la porte peut être animée.
         *
         * @return `true` si la porte peut être animée, sinon `false`.
         */
        const bool canBeAnimated() const {
            return true;
        }
};


#endif