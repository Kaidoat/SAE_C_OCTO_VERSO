#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"
#include "rail.h"
#include "joueur.h"


#define TAILLE_LETTRES 88

    int main() {
        srand(time(NULL)); // Initialiser le générateur de nombres aléatoires

        // Initialisation des lettres dans le sac
        Lettre lettres[TAILLE_LETTRES];
        int taille_sac;
        Rail r;

        initialiser_lettres(lettres, &taille_sac);
        melanger_lettres(lettres, taille_sac);

        // Initialiser les joueurs
        Joueur joueur1, joueur2;
        initJoueur(&joueur1, 1, lettres, &taille_sac);
        initJoueur(&joueur2, 2, lettres, &taille_sac);

        // Afficher les chevalets des joueurs
        afficherJoueur(&joueur1);
        afficherJoueur(&joueur2);
        afficherRail(&r);

        return 0;
    }
