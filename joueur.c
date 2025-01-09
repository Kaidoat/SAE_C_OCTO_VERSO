#include <stdio.h>
#include <stdlib.h>

#include "joueur.h"
#include <stdbool.h>
#include <string.h>
#include "dictionnaire.h"
#include "Pile.h"


// Fonction pour initialiser un joueur avec des lettres du sac
void initJoueur(Joueur* joueur, int numero, Pile *talon) {
    joueur->nbLettres = MAX_CHEVALET; // Le joueur commence avec 12 lettres
    joueur->numero = numero;

    for (int i = 0; i < MAX_CHEVALET; i++) {
        Lettre lettre_actuelle = sommet(talon); // Appelle sommet sur le talon
        joueur->chevalets[i] = lettre_actuelle.lettre; // Ajoute la lettre au chevalet
        depiler(talon); // Retire la lettre du talon
    }

    joueur->chevalets[MAX_CHEVALET] = '\0'; // Terminer la chaîne
}




int comparerLettres(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

// Fonction pour afficher le chevalet d'un joueur
void afficherJoueur(const Joueur* joueur) {
    qsort(joueur->chevalets, joueur->nbLettres, sizeof(char), comparerLettres);
    printf("%d : ", joueur->numero);
    for (int i = 0; i < joueur->nbLettres; i++) {
        if(joueur->chevalets[i] != '0') {
            printf("%c", joueur->chevalets[i]);
        }
    }
    printf("\n");
}

bool verifLettre(Joueur* joueur, int nbLettres, const char* mot) {
    // On travaille directement sur le chevalet du joueur
    bool lettresValides = true; // Indicateur pour vérifier la validité du mot
    Joueur tmp = *joueur;

    // Vérification des lettres
    for (int i = 0; i < nbLettres; i++) {
        bool lettreTrouvee = false; // Indicateur si la lettre est trouvée dans le chevalet

        // Parcourir toutes les lettres du chevalet du joueur pour trouver une correspondance
        for (int j = 0; j < tmp.nbLettres; j++) {
            if (tmp.chevalets[j] == mot[i]) {
                // Lettre trouvée, on l'a juste trouvée, mais on ne la consomme pas encore
                lettreTrouvee = true;
                tmp.chevalets[j] = '0'; // Marquer la lettre comme utilisée
                break; // Sortir de la boucle interne (inutile de chercher plus loin)
            }
        }

        if (!lettreTrouvee) {
            // Si une lettre n'est pas trouvée dans le chevalet, le mot est invalide
            lettresValides = false;
            break; // Sortir de la boucle, inutile de continuer la vérification
        }
    }

    if(lettresValides) {
        for (int i = 0; i < tmp.nbLettres; i++) {
            joueur->chevalets[i] = tmp.chevalets[i];
        }
        joueur->nbLettres -= nbLettres;
    }

    return lettresValides; // Retourne vrai si toutes les lettres sont valides

}




void demanderMot(Joueur* joueur, char *mot, const bool premierTour) {

    do {
        printf("%d>", joueur->numero);
        scanf("%s", mot);

        // Vérifie les conditions du mot
        if (premierTour) {
            // Conditions spécifiques pour le premier tour
            if (strlen(mot) != 4) {


            } else if (estDansDictionnaire(mot) == 0) {

            } else if (!verifLettre(joueur, strlen(mot), mot)) {

            } else {
                break; // Toutes les conditions sont remplies, on sort de la boucle
            }
        } else {
            // Conditions pour les joueurs suivants
            if (estDansDictionnaire(mot) == 0) {


            } else if (!verifLettre(joueur, strlen(mot), mot)) {


            } else {
                break; // Toutes les conditions sont remplies, on sort de la boucle
            }
        }
    } while (1); // Continue de demander tant que les conditions ne sont pas respectées

}


// Fonction pour vérifier si un joueur n'a plus de lettres dans son chevalet
bool joueurSansLettre(const Joueur* joueur) {
    return joueur->nbLettres == 0;
}

int verifJoueur(Joueur* joueur){

    if (joueurSansLettre(joueur)) {
        return 1;
    } else {
        return 0;
    }


}

