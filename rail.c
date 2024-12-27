#include "rail.h"
#include <stdio.h>
#include <string.h>

void initRail(Rail* rail) {
    rail->recto[0] = 0;
}

void afficherRail(const Rail* rail) {
    printf("R : %s\n", rail->recto);
}

int ajouterLettres(Rail* rail, const char* mot, char extremite) {
    int motLen = strlen(mot);
    if (motLen > 8) return 0; // Mot trop long pour tenir sur le rail

    if (extremite == 'D') {
        // Ajouter à droite
        memmove(rail->recto + motLen, rail->recto, 8 - motLen);
        memcpy(rail->recto, mot, motLen);
    }
    else if (extremite == 'G') {
        // Ajouter à gauche
        memmove(rail->recto, rail->recto + motLen, 8 - motLen);
        memcpy(rail->recto + 8 - motLen, mot, motLen);
    }
    else {
        return 0; // Extrémité invalide
    }
    return 1;
}

int retournerRail(Rail* rail) {
    int i = 0, j = 7;
    while (i < j) {
        char temp = rail->recto[i];
        rail->recto[i] = rail->recto[j];
        rail->recto[j] = temp;
        i++;
        j--;
    }
    return 1;
}
