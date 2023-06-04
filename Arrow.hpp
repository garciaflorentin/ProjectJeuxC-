#ifndef ARROW_HPP
#define ARROW_HPP

#include "Projectile.hpp"
#include "Character.hpp"


/**
 * @brief Cette classe represente une fleche qui ne peut etre lancee que par un joueur
 * 
 */
class Arrow : public Projectile {
    private:
        Character& _player; ///< le joueur qui a lance la fleche
        int _direction; ///< La direction dans laquelle le projectile se déplace.

    public:
        /**
         * @brief Constructeur
         * 
         * @param nameObject Nom du fichier texture
         * @param initPos Position initiale
         * @param player Joueur qui lance la fleche
         */
        Arrow(string nameObject, sf::Vector2f initPos, Character& player);

        /**
         * @brief Constreur par copie
         * 
         * @param other Fleche a copier
         */
        Arrow(const Arrow& other);

        /**
         * @brief Operateur d'assignement
         * 
         * @param other Fleche a assigner
         * @return Arrow& - Fleche assignee
         */
        Arrow& operator=(const Arrow& other);

        /**
         * @brief Destructeur
         * 
         */
        ~Arrow() {};

        /**
         * @brief Fait deplacer la fleche
         * 
         */
        void goTo();

        /**
         * @brief Lance le projectile et le dessine
         * 
         */
        void initProjectile();

        /**
         * @brief Getteur de _direction
         * 
         * @return const int - La direction dans laquelle se deplace la fleche
         */
        const int getDirection() const { return _direction; };

        /**
         * @brief Donner une nouvelle direction a la fleche
         * 
         * @param direction Nouvelle direction
         */
        void setDirection(int direction) { _direction = direction; };

};


#endif