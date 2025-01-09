#ifndef _PILE_
#define _PILE_

/**
 * @file Pile.h
 * Projet SAE_Lexicon
 * @brief Composant de pile ? capacit? param?tr?e
 */

#include"Lettre.h"
#include <stdbool.h>

typedef struct  {
    unsigned int capacite;  // capacit? de la pile (c>0)
    Lettre* tab;          // tableau des éléments de pile en mémoire dynamique
    int sommet;          // indice de sommet de pile dans tab
} Pile;

/**
* @brief Initialiser une pile vide
* la pile est allouée en mémoire dynamique
* @see detruire, pour une d?sallocation en fin d?utilisation
* @param[out] p : la pile à initialiser
* @param[in] c : capacité de la pile (nb maximum de Lettre stockés)
* @pre c>0
*/
void initialiser(Pile* p, unsigned int c);


/**
 * @brief D?sallouer une pile
 * @see initialiser, la pile a d?j? ?t? initialis?e
 * @param[in,out] p : la pile ? d?sallouer
 */
void detruire(Pile* p);

/**
 * @brief Test de pile pleine
 * @param[in] p : la pile test?e
 * @return true si p est pleine, false sinon
 */
bool estPleine(const Pile* p);

/**
 * @brief Test de pile vide
 * @param[in] p : la pile test?e
 * @return true si p est vide, false sinon
 */
bool estVide(const Pile* p);

/**
 * @brief Lire la carte au sommet de pile
 * @param[in] p : la pile
 * @return la carte au sommet de pile
 * @pre la pile n?est pas vide
 */
Lettre sommet(const Pile *p);

/**
 * @brief Empiler une carte sur une pile
 * @param[in,out] p : la pile
 * @param[in] it : la carte ? empiler
 * @pre la pile n?est pas pleine
 */
void empiler(Pile* p, const Lettre it);

/**
 * @brief D?piler la carte au sommet de pile
 * @param[in,out] p : la pile
 * @pre la pile n?est pas vide
 */
void depiler(Pile* p);

/**
* @brief Initialise la pile talon
* @param[in,out] p : la pile talon
* @pre la pile est vide
* @pre la pile a une capacite suffisante pour avoir toutes les cartes
*/
void initTalon(Pile* p, const Lettre* tableau);

/**
* @brief M?lange une pile
* @param[in] p : la pile
* @pre la pile n'est pas vide
*/
void melanger(Pile* p);

/**
* @brief Quand le talon est vide, la pile de carte exposer est mélangé et mise dans le talon.
* @param[in,out] : p : la pile talon, la pile expose
* @pre la pile est vide
*/

void talonVide(Pile* talon, Pile* expose);
#endif
