#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dictionnaire.h"
#include "jeu.h"
#include "rail.h"
#include "joueur.h"



    int main() {
        srand(time(NULL)); // Initialiser le générateur de nombres aléatoires

        // Initialisation des lettres dans le sac
        Lettre lettres[TAILLE_LETTRES];
        int taille_sac;
        Rail r;
        Jeu j;
        bool premierTour = true;

        Joueur joueur1, joueur2;
        char mot1[MAX_RAIL],mot2[MAX_RAIL];

        initialiser_lettres(lettres, &taille_sac);
        melanger_lettres(lettres, taille_sac);
        initJoueur(&joueur1, 1, lettres, &taille_sac);
        initJoueur(&joueur2, 2, lettres, &taille_sac);
        afficherJoueur(&joueur1);
        afficherJoueur(&joueur2);
        demanderMot(&joueur1, mot1,premierTour);
        demanderMot(&joueur2, mot2,premierTour);
        initRail(&r, mot1, mot2);
        afficherRail(&r);

        // faire une fonction qui verifie qu'un joueur n'a plus de lettre dans son chevalet
        // compter le nombre de '0' dans le chevalet
    }
