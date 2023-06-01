#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "Object.hpp"

#define PROJECTILE_SPEED 10.0


class Projectile: public Object {

    protected:
        bool _isShot; ///< Indique si le projectile a été tiré.
        int _distance; ///< La distance parcourue par le projectile.

    public:
        Projectile() : Object() {};

        /**
         * @brief Constructeur de la classe Projectile.
         * @param nameObject Le nom de l'objet projectile.
         * @param initPos La position initiale du projectile.
         * @param player Le joueur qui a tiré le projectile.
         */
        Projectile(string nameObject, sf::Vector2f initPos);

        /**
         * @brief Destructeur de la classe Projectile.
         */
        ~Projectile() {};

        /**
         * @brief Constructeur de copie de la classe Projectile.
         * @param other L'autre projectile à copier.
         */
        Projectile(const Projectile& other);

        /**
         * @brief Opérateur d'assignation de la classe Projectile.
         * @param other L'autre projectile à assigner.
         * @return Une référence sur le projectile assigné.
         */
        Projectile& operator=(const Projectile& other);

        /**
         * @brief Déplace le projectile vers sa nouvelle position en fonction de sa direction.
         */
        virtual void goTo() {};

        /**
         * @brief Initialise le projectile.
         */
        virtual void initProjectile() {};

        /**
         * @brief Gère la collision du projectile avec un autre objet.
         * @param o L'objet avec lequel le projectile entre en collision.
         */
        virtual void collide(Object& o);

        /**
         * @brief Récupère la taille du projectile.
         * @return La taille du projectile.
         */
        const int getBlockSize() { return 32; }

        /**
         * @brief Vérifie si le projectile a été tiré.
         * @return `true` si le projectile a été tiré, sinon `false`.
         */
        bool isShot() {
            return _isShot;
        }

        /**
         * @brief Définit l'état du projectile (tiré ou non).
         * @param state L'état du projectile.
         */
        void setIsShot(bool state) {
            _isShot = state;
        }

        /**
         * @brief Récupère la distance parcourue par le projectile.
         * @return La distance parcourue par le projectile.
         */
        int getDistance() {
            return _distance;
        }

        /**
         * @brief Incrémente la distance parcourue par le projectile.
         */
        void incrementeDistance() {
            _distance++;
        }

        /**
         * @brief Définit la distance parcourue par le projectile.
         * @param i La distance parcourue par le projectile.
         */
        void setDistance(int i) {
            _distance = i;
        }

        /**
         * @brief Gère le dépassement de limite du projectile (hors des limites de l'écran).
         */
        void arrowOutOfBounds();
};

#endif