#ifndef HEART_HPP
#define HEART_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/**
 * @class Heart
 * @brief Classe représentant les vies du joueur.
 *
 * La classe `Heart` gère les vies du joueur et leur affichage.
 */
class Heart {
private:
    std::vector<sf::Texture*>* _textures;
    std::vector<sf::Sprite*>* _sprites;
    std::vector<sf::Sprite>* life;
    int numberOfQuarter;
    string belongTo;

    /**
     * @brief Initialise les sprites de vie.
     */
    void initLife();

    /**
     * @brief Change le nombre de vies affichées.
     *
     * @param i Nombre de vies
     */
    void changeLife(int i);

public:
    /**
     * @brief Constructeur par défaut de la classe `Heart`.
     */
    Heart();

    /**
     * @brief Destructeur de la classe `Heart`.
     */
    ~Heart();

    /**
     * @brief Constructeur de copie de la classe `Heart`.
     *
     * @param other Autre instance de `Heart` à copier
     */
    Heart(const Heart& other);

    /**
     * @brief Opérateur d'assignation de la classe `Heart`.
     *
     * @param other Autre instance de `Heart` à assigner
     * @return Référence à l'instance assignée
     */
    Heart& operator=(const Heart& other);

    /**
     * @brief Retire une vie au joueur.
     */
    void removeLife();

    /**
     * @brief Ajoute une vie au joueur.
     */
    void addLife();

    /**
     * @brief Initialise les vies du joueur.
     */
    void initPlayerLife();

    /**
     * @brief Obtient le propriétaire des vies.
     *
     * @return Propriétaire des vies
     */
    string getBelongTo();

    /**
     * @brief Définit le propriétaire des vies.
     *
     * @param _belongTo Propriétaire des vies
     */
    void setBelongTo(string _belongTo);

    /**
     * @brief Obtient le nombre de quartiers de vie.
     *
     * @return Nombre de quartiers de vie
     */
    const int getNumberOfQuarter() const;

    /**
     * @brief Obtient le sprite du quartier de vie spécifié.
     *
     * @param NOQ Numéro du quartier de vie
     * @return Sprite du quartier de vie
     */
    sf::Sprite getHeart(int NOQ) const;

    /**
     * @brief Obtient les vies du joueur.
     *
     * @return Vecteur de sprites représentant les vies du joueur
     */
    std::vector<sf::Sprite>* getLife() const;
};

#endif
