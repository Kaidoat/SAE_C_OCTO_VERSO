#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    printf("Joueur %d : ", joueur->numero);
    for (int i = 0; i < joueur->nbLettres; i++) {
        printf("%c", joueur->chevalets[i]);
    }
    printf("\n");
}

bool verifLettre(const Joueur* joueur, int nbLettres, const char* mot) {
    Joueur tmp = *joueur; // Copie du joueur
    int cpt = nbLettres;  // Compteur de lettres à trouver

    for (int i = 0; i < nbLettres; i++) {
        bool lettreTrouvee = false; // Indique si la lettre est trouvée dans le chevalet

        for (int j = 0; j < tmp.nbLettres; j++) {
            if (tmp.chevalets[j] == mot[i]) {
                // Lettre trouvée, on la "consomme" en la remplaçant
                tmp.chevalets[j] = '0'; // Marquer la lettre comme utilisée
                lettreTrouvee = true;
                cpt--; // Réduire le compteur
                break; // Sortir de la boucle interne (inutile de chercher davantage)
            }
        }

        if (!lettreTrouvee) {
            // Si la lettre n'est pas trouvée, on peut immédiatement retourner false
            return false;
        }
    }

    // Si toutes les lettres ont été trouvées, le compteur doit être à 0
    return (cpt == 0);
}

void demanderMot(const Joueur* joueur, char *mot, const bool premierTour) {
    printf("%d>", joueur->numero);
    scanf("%s", mot); // Correction ici, pas besoin de &mot

    if (premierTour) {
        while (strlen(mot) != 4 || estDansDictionnaire(mot) == 0 || !verifLettre(joueur, strlen(mot), mot)) { // Prblm : reste dans la boucle
            printf("%d>", joueur->numero);                                                                     // résoudre : teste 1 par 1 chaque condition
            scanf("%s", mot); // Toujours scanf sans &mot
        }
    }

}


