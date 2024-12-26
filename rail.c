#include "rail.h"
#include <stdio.h>
#include <string.h>

void initRail(Rail* rail, Pioche* pioche) {
    for (int i = 0; i < 8; i++) {
        rail->lettres[i] = '\0'; // Rail vide au d�part
    }
    rail->recto = 1;
    // Remplir le rail avec des lettres pioch�es
    for (int i = 0; i < 8; i++) {
        rail->lettres[i] = piocher(pioche);
    }
}

void afficherRail(const Rail* rail) {
    printf("Rail (%s): ", rail->recto ? "recto" : "verso");
    for (int i = 0; i < 8; i++) {
        if (rail->lettres[i] != '\0') {
            printf("%c ", rail->lettres[i]);
        }
    }
    printf("\n");
}

int ajouterLettres(Rail* rail, const char* mot, char extremite) {
    int motLen = strlen(mot);
    if (motLen > 8) return 0; // Mot trop long pour tenir sur le rail

    if (extremite == 'D') {
        // Ajouter � droite
        memmove(rail->lettres + motLen, rail->lettres, 8 - motLen);
        memcpy(rail->lettres, mot, motLen);
    }
    else if (extremite == 'G') {
        // Ajouter � gauche
        memmove(rail->lettres, rail->lettres + motLen, 8 - motLen);
        memcpy(rail->lettres + 8 - motLen, mot, motLen);
    }
    else {
        return 0; // Extr�mit� invalide
    }
    return 1;
}

int retournerRail(Rail* rail) {
    rail->recto = !rail->recto;
    int i = 0, j = 7;
    while (i < j) {
        char temp = rail->lettres[i];
        rail->lettres[i] = rail->lettres[j];
        rail->lettres[j] = temp;
        i++;
        j--;
    }
    return 1;
}
