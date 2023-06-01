#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/Audio.hpp>

#include "Tile.hpp"
#include "TypeWall.hpp"
#include "Projectile.hpp"
#include "SoundsLib.hpp"


/**
 * @brief Classe représentant un mur.
 *
 * La classe `Wall` hérite de la classe `Tile` et représente un mur dans le jeu.
 */
class Wall: public Tile {

    protected:
        sf::Music* _collideMusic; // Musique de collision
        int _resistance;

    public:
        Wall() {};

        /**
         * @brief Constructeur de la classe `Wall`.
         *
         * @param nameObject Nom de l'objet.
         * @param initPos Position initiale du mur.
         * @param _typeWall Type de mur.
         */
        Wall(string nameObject, sf::Vector2f initPos, TypeWall _typeWall) : Tile(nameObject,initPos) {
            _collideMusic = SoundsLib::assignSound("Sounds/musicCollideWall.wav");
    
            _resistance = 4;
            _tile_size =48;
            int t = static_cast<int>(_typeWall);

            switch(t){
                case 0:
                    _sprite.setTextureRect(sf::IntRect(243, 1880, 48, 96));
                    break;
                case 1:
                    _sprite.setTextureRect(sf::IntRect(192, 1920, 48, 48));
                    break;
                case 2:
                    _sprite.setTextureRect(sf::IntRect(338, 1882, 48, 48));
                    break;
                case 3:
                    _sprite.setTextureRect(sf::IntRect(2, 50, 96, 96));
                    break;
                case 4:
                    _sprite.setTextureRect(sf::IntRect(386, 1594, 48, 96));
                    break;
                case 5:
                    _sprite.setTextureRect(sf::IntRect(338, 1930, 48, 48));
                    break;
                case 6:
                    _sprite.setTextureRect(sf::IntRect(626, 1498, 48, 96));
                    break;
                case 7:
                    _sprite.setTextureRect(sf::IntRect(772, 1498, 48, 48));
                    break;
                case 8:
                    _sprite.setTextureRect(sf::IntRect(772, 1450, 48, 48));
                    break;
                case 9:
                    _sprite.setTextureRect(sf::IntRect(2, 1434, 48, 48));
                    break;
                case 10:
                    _sprite.setTextureRect(sf::IntRect(578, 1354, 48, 48));
                    break;
                case 11:
                    _sprite.setTextureRect(sf::IntRect(576, 1594, 48, 96));
                    break;
                case 12:
                    _sprite.setTextureRect(sf::IntRect(2, 482, 96, 96));
                    break;
                case 13:
                    _sprite.setTextureRect(sf::IntRect(242, 1786, 48, 48));
                    break;
                case 14:
                    _sprite.setTextureRect(sf::IntRect(146, 1786, 48, 48));
                    break;
                case 15:
                    _sprite.setTextureRect(sf::IntRect(772, 1834, 48, 96));
                    break;
                case 16:
                    _sprite.setTextureRect(sf::IntRect(51, 1786, 48, 48));
                    break;
                case 17:
                    _sprite.setTextureRect(sf::IntRect(1029, 1254, 122, 96));
                    break;
                case 18:
                    _sprite.setTextureRect(sf::IntRect(1108, 1354, 48, 96));
                    break;
                case 19:
                    _sprite.setTextureRect(sf::IntRect(1108, 1450, 48, 48));
                    break;
                case 20:
                    _sprite.setTextureRect(sf::IntRect(1108, 1499, 48, 48));
                    break;
                case 21:
                    _sprite.setTextureRect(sf::IntRect(822, 1499, 48, 48));
                    break;
                case 22:
                    _sprite.setTextureRect(sf::IntRect(1060, 1546, 48, 96));
                    break;
                case 23:
                    _sprite.setTextureRect(sf::IntRect(1108, 1546, 48, 96));
                    break;
                case 24:
                    _sprite.setTextureRect(sf::IntRect(1012, 1834, 96, 96));
                    break;
                case 25:
                    _sprite.setTextureRect(sf::IntRect(1029, 1254, 122, 96));
                    _sprite.rotate(-90);
                    break;
                case 26:
                    _sprite.setTextureRect(sf::IntRect(1029, 1254, 122, 96));
                    _sprite.rotate(90);
                    break;
                case 27:
                    _sprite.setTextureRect(sf::IntRect(1029, 1254, 122, 96));
                    _sprite.rotate(-180);
                    break;
                case 28:
                    _sprite.setTextureRect(sf::IntRect(1033, 1740, 112, 96));
                    break;
                case 29:
                    _sprite.setTextureRect(sf::IntRect(892, 1644, 112, 96));
                    break;
                case 30:
                    _sprite.setTextureRect(sf::IntRect(1033, 1644, 112, 96));
                    break;
                case 31:
                    _sprite.setTextureRect(sf::IntRect(892, 1740, 112, 96));
                    break;
                case 32:
                    _sprite.setTextureRect(sf::IntRect(918, 1354, 48, 96));
                    break;
                case 33:
                    _sprite.setTextureRect(sf::IntRect(820, 1354, 48, 96));
                    break;
                case 34:
                    _sprite.setTextureRect(sf::IntRect(1014, 1354, 48, 96));
                    break;
                case 35:
                    _sprite.setTextureRect(sf::IntRect(966, 1354, 48, 96));
                    break;
                case 36:
                    _sprite.setTextureRect(sf::IntRect(434, 1110, 48, 48));
                    break;
                case 37:
                    _sprite.setTextureRect(sf::IntRect(506, 1110, 23, 48));
                    _sprite.scale(2.09,1);
                    break;
            }
        }

        Wall& operator= (const Wall& other);

        /**
         * @brief Destructeur de la classe `Wall`.
         */
        ~Wall(){
            _collideMusic->stop();
        }

        /**
         * @brief Vérifie si le mur peut être animé.
         *
         * @return `true` si le mur peut être animé, `false` sinon.
         */
        virtual const bool canBeAnimated() const { return false; }

        /**
         * @brief Récupère la taille d'un bloc du mur.
         *
         * @return La taille d'un bloc du mur.
         */
        const int getBlockSize(){
            return _tile_size;
        }

        /**
         * @brief Gère la collision avec un objet.
         *
         * @param o Objet en collision avec le mur.
         */
        void collide(Object& o){
            if(typeid(o) == typeid(Projectile)){
                if(_resistance==0){
                    _sprite.scale(0,0);     
                    return;  
                } else { _resistance--; }
            }
            _collideMusic->stop();
            _collideMusic->play();
        }
};


#endif