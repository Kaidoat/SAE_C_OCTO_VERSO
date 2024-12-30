#include "pioche.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define FAUX_RANDOM

                                       // A  B  C  D   E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  };
static const int occurences_lettres[] = { 9, 1, 2, 3, 14, 1, 1, 1, 7, 1, 0, 5, 3, 6, 5, 2, 1, 6, 7, 6, 5, 2 };

static int pioche[sizeof(occurences_lettres)];

// Initialisation de la pioche
void initPioche(Pioche* p) {
    memcpy(pioche, occurences_lettres, sizeof(occurences_lettres));
}

// Remplir la pioche avec les lettres et leurs quantités
void remplirPioche(Pioche* p) {
 /*
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
    }*/
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

int getRandom() {
#ifdef FAUX_RANDOM
    static int rand_index = 0;
    static const int faux_rand[] = { 'V','C','E','E','N','K','L','M','E','R','S','U','A', // premier joueur avec test sur le K qui doit donner un autre tirage
                                     'A','B','D','E','I','L','N','O','R','R','T','U'// 2eme joueur
    };
    
    if (rand_index >= sizeof(faux_rand)/sizeof(int)) {
        // on a depassé le jeu de test, renvoie du vrai random
        return rand() % sizeof(occurences_lettres);
    }
    else {
        return faux_rand[rand_index++]-'A';
    }
#else
    return rand() % sizeof(occurences_lettres);
#endif
}

// Piocher une lettre
char piocher() {
    while (1) {
        int lettre_index = getRandom();
        if (pioche[lettre_index] > 0) {
            pioche[lettre_index]--;
            return 'A'+ lettre_index;
        }
    }
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
