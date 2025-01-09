#include "rail.h"
#include <stdio.h>
#include <string.h>

void initRail(Rail *rail, const char *mot1, const char *mot2) {
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


void afficherRailRecto(const Rail *rail) {
    // Vérifier si la chaîne 'lettres' contient bien des caractères
    if (rail != NULL && rail->lettres[0] != '\0') {
        printf("R : %s\n", rail->lettres);

    } else {
        printf("Le rail est vide ou invalide.\n");
    }
}



void afficherRailVerso(const Rail *rail) {
    // Vérifier si la chaîne 'lettres' contient bien des caractères
    if (rail != NULL && rail->lettres[0] != '\0') {
        printf("V : %s\n", rail->lettres);

    } else {
        printf("Le rail est vide ou invalide.\n");
    }
}


int retournerRail(Rail *rail) {
        if (rail == NULL || rail->longueur == 0) {
            return 0; // Échec si le rail est invalide
        }

        // Inverser l'ordre des lettres dans le rail
        int i, j;
        char temp;
        for (i = 0, j = rail->longueur - 1; i < j; i++, j--) {
            temp = rail->lettres[i];
            rail->lettres[i] = rail->lettres[j];
            rail->lettres[j] = temp;
        }

        // Basculer entre recto (1) et verso (0)
        rail->recto = !rail->recto;

        return 1; // Succès
    }




