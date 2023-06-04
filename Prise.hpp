#ifndef GAIN_HPP
#define GAIN_HPP

#include <SFML/Audio.hpp>

#include "Object.hpp"


/**
 * @brief Cette classe represente des coeurs contenus dans un coffre
 * 
 */
class Prise : public Object {

    private:
        sf::Music* _musicPrise; /**< Musique jouée lorsqu'un gain est obtenu */
        sf::Music* _musicNoPrise; /**< Musique jouée lorsqu'aucun gain n'est obtenu */

        int _prise_size = 16; /**< Taille d'un bloc de gain */
        int _value; /**< Valeur du gain obtenu */
        bool _valueReaped = false; /**< Indique si le gain a été récolté */

    public:
        /**
         * @brief Constructeur de la classe `Prise`.
         *
         * @param nameObject Nom de l'objet
         * @param initPos Position initiale
         */
        Prise(const char* nameObject, sf::Vector2f initPos) : 
        Object(nameObject, initPos) {
            _value = rand() % 5;
            _sprite.setScale(0.f, 0.f);

            _musicPrise = SoundsLib::assignSound("Sounds/musicGain.wav");
            _musicNoPrise = SoundsLib::assignSound("Sounds/01_chest_open_1.wav");
            
            _musicPrise->setVolume(50);
        };

        /**
         * @brief Destructeur de la classe `Prise`.
         */
        ~Prise() {
            _musicPrise->stop();
            _musicNoPrise->stop();
        };

        /**
         * @brief Récupère la valeur du gain.
         *
         * @return La valeur du gain.
         */
        int getPrise() const {
            return _value;
        }

        /**
         * @brief Gère la collision avec un objet.
         *
         * @param o Objet avec lequel il y a collision.
         */
        void collide(Object& o) {
            _sprite.setScale(48.f, 48.f);

            if (!_valueReaped) {
                _valueReaped = true;

                if (_value > 0) {
                    _musicPrise->play();
                } else {
                    _musicNoPrise->play();
                }
            }
        }

        /**
         * @brief Récupère la taille d'un bloc de gain.
         *
         * @return La taille d'un bloc de gain.
         */
        const int getBlockSize() {
            return _prise_size;
        }
};


#endif