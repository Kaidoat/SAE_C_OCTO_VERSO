#include "rail.h"
#include <stdio.h>
#include <string.h>

void initRail(Rail *rail, const char *mot1, const char *mot2) {
    // Comparer les mots et les ajouter dans l'ordre alphab�tique
    if (strcmp(mot1, mot2) < 0) {
        snprintf(rail->lettres, sizeof(rail->lettres), "%s%s", mot1, mot2);
    } else {
        snprintf(rail->lettres, sizeof(rail->lettres), "%s%s", mot2, mot1);
    }

    // Initialiser les autres champs de la structure
    rail->recto = 1; // Par d�faut, on initialise � recto
    rail->longueur = strlen(rail->lettres);
}


void afficherRail(const Rail *rail) {
    // V�rifier si la cha�ne 'lettres' contient bien des caract�res
    if (rail != NULL && rail->lettres[0] != '\0') {
        printf("Rail : %s\n", rail->lettres);
        printf("R : %d\n", rail->recto);
        printf("Longueur : %d\n", rail->longueur);
    } else {
        printf("Le rail est vide ou invalide.\n");
    }
}

