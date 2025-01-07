#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "joueur.h"

// Fonction pour initialiser les lettres du sac
void initialiser_lettres(Lettre lettres[], int* taille_sac) {
    Lettre temp[] = {
            {'A', 9}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 14},
            {'F', 1}, {'G', 1}, {'H', 1}, {'I', 7}, {'J', 1},
            {'K', 0}, {'L', 5}, {'M', 3}, {'N', 6}, {'O', 5},
            {'P', 2}, {'Q', 1}, {'R', 6}, {'S', 7}, {'T', 6},
            {'U', 5}, {'V', 2}
    };
    int n = sizeof(temp) / sizeof(temp[0]);
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < temp[i].quantite; j++) {
            lettres[index++] = temp[i];
        }
    }
    *taille_sac = index;
}

// Fonction pour mélanger les lettres du sac
void melanger_lettres(Lettre lettres[], int taille) {
    for (int i = taille - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Lettre temp = lettres[i];
        lettres[i] = lettres[j];
        lettres[j] = temp;
    }
}

// Fonction pour initialiser un joueur avec des lettres du sac
void initJoueur(Joueur* joueur, int numero, Lettre* sac, int* taille_sac) {
    joueur->nbLettres = MAX_CHEVALET; // Le joueur commence avec 12 lettres
    joueur->numero = numero;
    for (int i = 0; i < MAX_CHEVALET; i++) {
        joueur->chevalets[i] = sac[--(*taille_sac)].lettre; // Prend une lettre aléatoire du sac
    }
    joueur->chevalets[MAX_CHEVALET] = '\0'; // Terminer la chaîne
}

// Fonction pour afficher le chevalet d'un joueur
void afficherJoueur(const Joueur* joueur) {
    printf("Joueur %d : ", joueur->numero);
    for (int i = 0; i < joueur->nbLettres; i++) {
        printf("%c", joueur->chevalets[i]);
    }
    printf("\n");
}