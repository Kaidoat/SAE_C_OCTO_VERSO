#ifndef JEU_H
#define JEU_H

#include "rail.h"
enum{MAX_CHEVALET=12, MAX_MOT= 4};

typedef struct {
    char chevalets[20]; // 12 lettres au depart par joueur et plus si penalit�s.
    int nbLettres;
    int numero;
} Joueur;

// Prototypes
void initJoueur(Joueur* joueur);
void afficherJoueur(const Joueur* joueur,int numero);
int jouerTour(Joueur* joueur, Rail* rail, Pioche* pioche);
int verifierVictoire(const Joueur* joueur);
void remplirRail(Rail* rail, Joueur* joueur);
int motValide(const char* mot, const Joueur* joueur, int motInitial);
void genererLettresAleatoires(char* lettres, int taille);
char piocher(Pioche* pioche);
#endif
