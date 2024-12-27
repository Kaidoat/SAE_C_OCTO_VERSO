#ifndef RAIL_H
#define RAIL_H

#include "pioche.h"

typedef struct {
    char recto[20]; // Taille arbitraire qui devrait être suffisante
} Rail;

// Prototypes
void initRail(Rail* rail);
void afficherRail(const Rail* rail);
int ajouterLettres(Rail* rail, const char* mot, char extremite);
int retournerRail(Rail* rail);

#endif
