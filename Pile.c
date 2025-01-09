#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Pile.h"
#include <assert.h>

/**
 * @brief Initialiser une pile vide
 * @param[out] p : la pile à initialiser
 * @param[in] c : capacité de la pile (nb maximum de cartes stockées)
 * @pre c > 0
 */
void initialiser(Pile* p, unsigned int c) {
    assert(c > 0);
    p->capacite = c;
    p->tab = (Lettre*)malloc(c * sizeof(Lettre));
    p->sommet = -1;
}

/**
 * @brief Désallouer une pile
 * @param[in,out] p : la pile à désallouer
 */
void detruire(Pile* p) {
    free(p->tab);
    p->tab = NULL;
    p->capacite = 0;
    p->sommet = -1;
}

/**
 * @brief Test de pile pleine
 * @param[in] p : la pile testée
 * @return 1 si p est pleine, 0 sinon
 */
bool estPleine(const Pile* p) {
    return (p->sommet == (p->capacite - 1));
}

/**
 * @brief Test de pile vide
 * @param[in] p : la pile testée
 * @return 1 si p est vide, 0 sinon
 */
bool estVide(const Pile* p) {
    return (p->sommet == -1);
}

/**
 * @brief Lire la carte au sommet de la pile
 * @param[in] p : la pile
 * @return la carte au sommet de la pile
 * @pre la pile n’est pas vide
 */
Lettre sommet(const Pile *p) {
    assert(!estVide(p));
    return p->tab[p->sommet];
}

/**
 * @brief Empiler une carte sur une pile
 * @param[in,out] p : la pile
 * @param[in] it : la carte à empiler
 * @pre la pile n’est pas pleine
 */
void empiler(Pile* p, const Lettre it) {
    assert(!estPleine(p));
    p->sommet++;
    p->tab[p->sommet] = it;
}

/**
 * @brief Dépiler la carte au sommet de la pile
 * @param[in,out] p : la pile
 * @pre la pile n’est pas vide
 */
void depiler(Pile* p) {
    assert(!estVide(p));
    p->sommet--;
}

/**
 * @brief Initialise la pile talon
 * @param[in,out] p : la pile talon
 * @pre la pile est vide
 * @pre la pile a une capacité suffisante pour contenir toutes les cartes
 */
void initTalon(Pile* p, const Lettre* tableau) {
    assert(estVide(p));
    assert(p->capacite == TAILLE_LETTRES);

    for (int i = 0; i < TAILLE_LETTRES; i++) {
        empiler(p, tableau[i]);
    }
}

/**
 * @brief Mélanger une pile
 * @param[in] p : la pile
 * @pre la pile n'est pas vide
 */
void melanger(Pile* p) {
    assert(!estVide(p));

    srand(time(NULL));
    for (int i = p->sommet + 1; i >= 2; i--) {
        int a = rand() % i; // a pour aléatoire
        Lettre tmp = p->tab[i - 1];
        p->tab[i - 1] = p->tab[a];
        p->tab[a] = tmp;
    }
}

/**
 * @brief Quand le talon est vide, la pile de cartes exposées est mélangée et mise dans le talon
 * @param[in,out] talon : la pile talon
 * @param[in,out] expose : la pile exposée
 * @pre la pile talon est vide
 */
void talonVide(Pile* talon, Pile* expose) {
    assert(estVide(talon));

    melanger(expose);
    while (!estVide(expose)) {
        empiler(talon, sommet(expose));
        depiler(expose);
    }

    empiler(expose, sommet(talon));
    depiler(talon);
}