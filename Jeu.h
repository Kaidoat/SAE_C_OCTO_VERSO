#ifndef JEU_H
#define JEU_H

#include "rail.h"

typedef struct {
    char chevalets[20]; // 12 lettres au depart par joueur et plus si penalités.
    int nbLettres;
    int numero;
} Joueur;

// Prototypes
void initJoueur(Joueur* joueur, int numero);
void afficherJoueur(const Joueur* joueur);
int jouerTour(Joueur* joueur, Rail* rail, Pioche* pioche);
int verifierVictoire(const Joueur* joueur);
void remplirRail(Rail* rail, Joueur* joueur);
int motValide(const char* mot, const Joueur* joueur, int motInitial);

#endif
