#include "Jeu.h"
#include <stdio.h>
#include <string.h>

void trie_chaine(char* chaine) {
    int echange = 0;
    int max_iteration = strlen(chaine) - 1;
    do {
        echange = 0;
        for (int i = 0; i < max_iteration ; i++) {
            if (chaine[i] > chaine[i+1]) {
                //echange
                char tmp = chaine[i];
                chaine[i] = chaine[i + 1];
                chaine[i + 1] = tmp;
                // signale un echange effectue
                echange = 1;
            }
        }
        max_iteration--;
    }
    while (echange != 0 && max_iteration != 0);
}

void initJoueur(Joueur* joueur, int numero) {
    joueur->nbLettres = 12;
    for (int i = 0; i < joueur->nbLettres; i++) {
        joueur->chevalets[i] = piocher();
    }
    joueur->chevalets[joueur->nbLettres] = 0;
    trie_chaine(joueur->chevalets);
    joueur->numero = numero;
}

void afficherJoueur(const Joueur* joueur) {
    printf("%d : ", joueur->numero);
    for (int i = 0; i < joueur->nbLettres; i++) {
        printf("%c", joueur->chevalets[i]);
    }
    printf("\n");
}

// Fonction de vérification si un mot est valide pour un joueur (0 si mot invalide)
int motValide(const char* mot, const Joueur* joueur, int motInitial) {
    if (motInitial!=0 && strlen(mot) != 4) return 0; // Le mot doit contenir exactement 4 lettres

    // Vérifie que chaque lettre du mot est présente dans le chevalet
    int lettresUtilisees[12] = { 0 }; // Pour suivre les lettres utilisées
    for (int i = 0; i < strlen(mot); i++) {
        int trouve = 0;
        for (int j = 0; j < joueur->nbLettres; j++) {
            if (toupper(mot[i]) == joueur->chevalets[j] && !lettresUtilisees[j]) {
                lettresUtilisees[j] = 1; // Marquer la lettre comme utilisée
                trouve = 1;
                break;
            }
        }
        if (!trouve) return 0; // Une lettre n'est pas disponible
    }
    return 1; // Le mot est valide
}

// Fonction unique pour remplir le rail
void remplirRail(Rail* rail, Joueur* joueur) {
    char mot[50] = { 0 }; // Mot temporaire pour la saisie
    printf("--- Debut du jeu : Remplissage du rail ---\n");

        while (1) {
            afficherJoueur(joueur);
            printf("Joueur %d, entre un mot de 4 lettres : ", joueur->numero);
            (void)scanf("%s", mot);

            if (motValide(mot, joueur, 1)) break; // Mot valide, on sort de la boucle
            printf("Mot invalide, essaye a nouveau.\n");
        }

        // Retirer les lettres utilisées du chevalet
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < joueur->nbLettres; k++) {
                if (toupper(mot[j]) == joueur->chevalets[k]) {
                    joueur->chevalets[k] = joueur->chevalets[k + 1];
                    joueur->nbLettres--;
                    break;
                }
            }
        }

    strcat(rail->recto, mot); // Le second mot est ajouté au rail
}


int jouerTour(Joueur* joueur, Rail* rail, Pioche* pioche) {
    printf("Saisissez votre mot : ");
    char mot[50] = { 0 };
    (void)scanf("%s", mot);

    if (strcmp(mot, ".quit") == 0) {
        exit(-1);
    }

    printf("A quelle extremite (D/G) ? ");
    char extremite;
    (void)scanf(" %c", &extremite);

    if (!ajouterLettres(rail, mot, extremite)) {
        printf("Invalide.\n");
        return 0;
    }

    // Supprimer les lettres utilisées du chevalet
    for (int i = 0; mot[i] != '\0'; i++) {
        for (int j = 0; j < joueur->nbLettres; j++) {
            if (joueur->chevalets[j] == mot[i]) {
                joueur->chevalets[j] = joueur->chevalets[j + 1];
                joueur->nbLettres--;
                break;
            }
        }
    }
    return 1;
}

int verifierVictoire(const Joueur* joueur) {
    return joueur->nbLettres == 0;
}
