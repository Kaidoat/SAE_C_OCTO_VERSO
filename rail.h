#ifndef RAIL_H
#define RAIL_H

#include "pioche.h"

typedef struct {
    char lettres[8]; // Le rail contient jusqu'à 8 lettres
    int recto;       // 1 si recto, 0 si verso
} Rail;

// Prototypes
void initRail(Rail* rail, Pioche* pioche);
void afficherRail(const Rail* rail);
int ajouterLettres(Rail* rail, const char* mot, char extremite);
int retournerRail(Rail* rail);

#endif
