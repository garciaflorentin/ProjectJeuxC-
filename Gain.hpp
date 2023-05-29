#ifndef GAIN_HPP
#define GAIN_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

//class
#include "TexturesLib.hpp"
#include "Chest.hpp"
#include "Object.hpp"

class Chest;

class Gain : public Object {

private:
    sf::Music* musicGain; /**< Musique jouée lorsqu'un gain est obtenu */
    sf::Music* musicNoGain; /**< Musique jouée lorsqu'aucun gain n'est obtenu */

    int GAIN_SIZE = 16; /**< Taille d'un bloc de gain */
    int _gain; /**< Valeur du gain obtenu */
    bool gainReaped = false; /**< Indique si le gain a été récolté */

public:
    /**
     * @brief Constructeur de la classe `Gain`.
     *
     * @param nameObject Nom de l'objet
     * @param initPos Position initiale
     */
    Gain(const char* nameObject, sf::Vector2f initPos) : Object(nameObject, initPos) {
        _gain = rand() % 5;
        _sprite->setScale(0.f, 0.f);
        musicGain = new sf::Music;
        if (!musicGain->openFromFile("musicGain.wav")) {
            std::cout << "erreur de chargement de musicGain" << std::endl;
        }
        musicNoGain = new sf::Music;
        if (!musicNoGain->openFromFile("01_chest_open_1.wav")) {
            std::cout << "erreur de chargement de musicNoGainOk" << std::endl;
        }
        musicGain->setVolume(50);
    }

    /**
     * @brief Destructeur de la classe `Gain`.
     */
    ~Gain() {
        delete _sprite;
        delete musicGain;
        delete musicNoGain;
    }

    /**
     * @brief Récupère la valeur du gain.
     *
     * @return La valeur du gain.
     */
    int getGain() const {
        return _gain;
    }

    /**
     * @brief Gère la collision avec un objet.
     *
     * @param o Objet avec lequel il y a collision.
     */
    void collide(Object* o) {
        _sprite->setScale(48.f, 48.f);
        if (!gainReaped) {
            gainReaped = true;
            if (_gain > 0) {
                musicGain->play();
            } else {
                musicNoGain->play();
            }
        }
    }

    /**
     * @brief Récupère la taille d'un bloc de gain.
     *
     * @return La taille d'un bloc de gain.
     */
    const int getBlockSize() {
        return GAIN_SIZE;
    }

};

#endif
