#ifndef JEU_H
#define JEU_H

#include "rail.h"

enum{MAX_CHEVALET=12,  MAX_MOT=9};

typedef struct {
    char chevalets[MAX_CHEVALET]; // 12 lettres par joueur max
    int nbLettres;
} Joueur;

// Prototypes
void initJoueur(Joueur* joueur, Pioche* pioche);
void afficherJoueur(const Joueur* joueur, int numero);
int jouerTour(Joueur* joueur, Rail* rail, Pioche* pioche);
int verifierVictoire(const Joueur* joueur);



#endif
