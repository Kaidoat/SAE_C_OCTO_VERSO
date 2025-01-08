#include <stdio.h>
#include <stdlib.h>

#include "joueur.h"
#include <stdbool.h>
#include <string.h>
#include "dictionnaire.h"

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
    printf("%d : ", joueur->numero);
    for (int i = 0; i < joueur->nbLettres; i++) {
        printf("%c", joueur->chevalets[i]);
    }
    printf("\n");
}

bool verifLettre(Joueur* joueur, int nbLettres, const char* mot) {
    // On travaille directement sur le chevalet du joueur
    bool lettresValides = true; // Indicateur pour vérifier la validité du mot

    // Vérification des lettres
    for (int i = 0; i < nbLettres; i++) {
        bool lettreTrouvee = false; // Indicateur si la lettre est trouvée dans le chevalet

        // Parcourir toutes les lettres du chevalet du joueur pour trouver une correspondance
        for (int j = 0; j < joueur->nbLettres; j++) {
            if (joueur->chevalets[j] == mot[i]) {
                // Lettre trouvée, on l'a juste trouvée, mais on ne la consomme pas encore
                lettreTrouvee = true;
                joueur->chevalets[j] = '0'; // Marquer la lettre comme utilisée
                break; // Sortir de la boucle interne (inutile de chercher plus loin)
            }
        }

        if (!lettreTrouvee) {
            // Si une lettre n'est pas trouvée dans le chevalet, le mot est invalide
            lettresValides = false;
            break; // Sortir de la boucle, inutile de continuer la vérification
        }
    }

    return lettresValides; // Retourne vrai si toutes les lettres sont valides
}




void demanderMot(const Joueur* joueur, char *mot, const bool premierTour) {

    do {
        printf("%d>", joueur->numero);
        scanf("%s", mot);

        // Vérifie les conditions du mot
        if (premierTour) {
            // Conditions spécifiques pour le premier tour
            if (strlen(mot) != 4) {
                printf("caca1\n");

            } else if (estDansDictionnaire(mot) == 0) {
                printf("caca2\n");
            } else if (!verifLettre(joueur, strlen(mot), mot)) {
                printf("caca3\n");
            } else {
                break; // Toutes les conditions sont remplies, on sort de la boucle
            }
        } else {
            // Conditions pour les joueurs suivants
            if (estDansDictionnaire(mot) == 0) {
                printf("caca4\n");

            } else if (!verifLettre(joueur, strlen(mot), mot)) {
                printf("caca5\n");

            } else {
                break; // Toutes les conditions sont remplies, on sort de la boucle
            }
        }
    } while (1); // Continue de demander tant que les conditions ne sont pas respectées
}



