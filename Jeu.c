#include "Jeu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void trie_chaine(char* chaine) {
    int echange = 0;
    do {
        echange = 0;
        for (int i = 0; i < sizeof(chaine) - 1; i++) {
            if (chaine[i] > chaine[i+1]) {
                //echange
                char tmp = chaine[i];
                chaine[i] = chaine[i + 1];
                chaine[i + 1] = tmp;
                echange = 1;
            }
        }
    }
    while (echange != 0);
}

void initJoueur(Joueur* joueur) {
    joueur->nbLettres = MAX_CHEVALET; // Initialisation avec 12 lettres
    for (int i = 0; i < MAX_CHEVALET; i++) {
        joueur->chevalets[i] = 'A' + (rand() % 26); // G�n�re une lettre al�atoire
    }
    joueur->chevalets[MAX_CHEVALET] = '\0'; // Ajoute le caract�re de fin
}

// Fonction pour afficher les lettres du chevalet d'un joueur
void afficherJoueur(const Joueur* joueur, int numero) {
    printf("Joueur %d : ", numero);
    for (int i = 0; i < joueur->nbLettres; i++) {
        printf("%c", joueur->chevalets[i]);
    }
    printf("\n");
}

int jouerTour(Joueur* joueur, Rail* rail, Pioche* pioche) {
    printf("Saisissez votre mot : ");
    char mot[MAX_MOT];
    scanf("%s", mot);

    if (strcmp(mot, ".quit") == 0) {
        exit(-1);
    }

    printf("A quelle extremite (D/G) ? ");
    char extremite;
    scanf(" %c", &extremite);

    if (!ajouterLettres(rail, mot, extremite)) {
        printf("Invalide.\n");
        return 0;
    }

    // Supprimer les lettres utilis�es du chevalet
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

char piocher(Pioche* pioche) {
    // G�n�re une lettre al�atoire entre 'A' et 'Z'
    return 'A' + (rand() % 26);
}

