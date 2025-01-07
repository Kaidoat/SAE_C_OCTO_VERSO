#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

        Joueur joueur1, joueur2;
        const char mot1,mot2;

        initialiser_lettres(lettres, &taille_sac);
        melanger_lettres(lettres, taille_sac);
        initJoueur(&joueur1, 1, lettres, &taille_sac);
        initJoueur(&joueur2, 2, lettres, &taille_sac);
        afficherJoueur(&joueur1);
        afficherJoueur(&joueur2);

        initRail(&r, mot1, mot2);
        afficherRail(&r);



    }
