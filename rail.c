#include "rail.h"
#include <stdio.h>
#include <string.h>

void initRail(Rail *rail, char *mot1,  char *mot2) {
    // Validation des entrées : s'assurer que les mots ont exactement 4 lettres
    if (strlen(mot1) != 4 || strlen(mot2) != 4) {
        printf("Erreur : Les mots doivent contenir exactement 4 lettres chacun.\n");
        return;
    }

    // Comparer les mots et les ajouter dans l'ordre alphabétique
    if (strcmp(mot1, mot2) < 0) {
        snprintf(rail->lettres, sizeof(rail->lettres), "%s%s", mot1, mot2);
    } else {
        snprintf(rail->lettres, sizeof(rail->lettres), "%s%s", mot2, mot1);
    }

    // Initialiser les autres champs de la structure
    rail->recto = 1; // Par défaut, on initialise à recto
    rail->longueur = strlen(rail->lettres);
}

void afficherRail(const Rail *rail) {
    printf("Rail : %s\n", rail->lettres);
    printf("Recto : %d\n", rail->recto);
    printf("Longueur : %d\n", rail->longueur);

}
