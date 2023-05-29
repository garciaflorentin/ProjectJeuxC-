#ifndef DOOR_HPP
#define DOOR_HPP

#include "Wall.hpp"
#include "Player.hpp"

class Door : public Wall {

protected:
    sf::Vector2f anim; /**< Vecteur d'animation de la porte */
    bool isOpen; /**< Indique si la porte est ouverte */
    bool isOpening; /**< Indique si la porte est en train de s'ouvrir */
    int DOOR_SIZE = 240; /**< Taille de la porte */
    int cpt = 0; /**< Compteur pour l'animation de la porte */
    sf::Sprite* backDoorSprite; /**< Sprite du fond de la porte */
    sf::Texture backDoorTexture; /**< Texture du fond de la porte */

public:
    /**
     * @brief Constructeur de la classe `Door`.
     *
     * @param nameObject Nom de l'objet
     * @param initPos Position initiale
     * @param _typeWall Type de mur de la porte
     */
    Door(const char* nameObject, sf::Vector2f initPos, TypeWall _typeWall);

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
        isOpen = state;
    }

    /**
     * @brief Définit l'état d'ouverture de la porte en cours.
     *
     * @param state État d'ouverture de la porte en cours (en train de s'ouvrir ou non)
     */
    void setIsOpening(bool state) {
        isOpening = state;
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
    virtual void collide(Object* o);

    /**
     * @brief Indique si la porte peut être animée.
     *
     * @return `true` si la porte peut être animée, sinon `false`.
     */
    bool canBeAnimated() {
        return true;
    }
};

#endif
