#include "pioche.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialisation de la pioche
void initPioche(Pioche* p) {
    p->tete = NULL;
    p->taille = 0;
    remplirPioche(p);
    melangerPioche(p);
}

// Remplir la pioche avec les lettres et leurs quantités
void remplirPioche(Pioche* p) {
    char lettres[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                      'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' };
    int capacite[] = { 9, 1, 2, 3, 14, 1, 1, 1, 7, 1,
                      5, 3, 6, 5, 2, 1, 6, 7, 6, 5, 2 };

    for (int i = 0; i < sizeof(lettres) / sizeof(lettres[0]); i++) {
        for (int j = 0; j < capacite[i]; j++) {
            Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
            if (!nouveau) {
                perror("Erreur d'allocation mémoire");
                exit(EXIT_FAILURE);
            }
            nouveau->lettre = lettres[i];
            nouveau->suivant = p->tete;
            p->tete = nouveau; // Ajouter en tête de la liste
            p->taille++;
        }
    }
}

void melangerPioche(Pioche* p) {
    if (p->taille < 2) return;

    // Utiliser un tableau statique de taille maximale
    Noeud* tableau[TAILLE_MAX_PIOCHE];

    Noeud* courant = p->tete;
    for (int i = 0; i < p->taille; i++) {
        tableau[i] = courant;
        courant = courant->suivant;
    }

    srand(time(NULL));
    for (int i = p->taille - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Noeud* temp = tableau[i];
        tableau[i] = tableau[j];
        tableau[j] = temp;
    }

    for (int i = 0; i < p->taille - 1; i++) {
        tableau[i]->suivant = tableau[i + 1];
    }
    tableau[p->taille - 1]->suivant = NULL;
    p->tete = tableau[0];
}

// Piocher une lettre
char piocher(Pioche* p) {
    if (!p->tete) {
        printf("Pioche vide.\n");
        return '\0';
    }

    Noeud* tete = p->tete;
    char lettre = tete->lettre;

    p->tete = tete->suivant;
    free(tete);
    p->taille--;

    return lettre;
}

// Libérer la mémoire allouée pour la pioche
void libererPioche(Pioche* p) {
    Noeud* courant = p->tete;
    while (courant) {
        Noeud* temp = courant;
        courant = courant->suivant;
        free(temp);
    }
    p->tete = NULL;
    p->taille = 0;
}
