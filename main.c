#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dictionnaire.h"
#include "jeu.h"
#include "rail.h"
#include "joueur.h"
#include "Lettre.h"
#include "Pile.h"



    int main() {
        srand(time(NULL)); // Initialiser le générateur de nombres aléatoires

        // Initialisation des lettres dans le sac
        Lettre lettres[TAILLE_LETTRES];
        Pile talon;
        Pile expose;
        int taille_sac;
        Rail r;
        Jeu j;
        bool premierTour = true;

        Joueur joueur1, joueur2;
        char mot1[MAX_RAIL],mot2[MAX_RAIL];

        initialiser_lettres(lettres, &taille_sac);
        initialiser(&talon, TAILLE_LETTRES);
        initialiser(&expose, TAILLE_LETTRES);
        initTalon(&talon, lettres);
        melanger(&talon);
        initJoueur(&joueur1, 1, &talon);
        initJoueur(&joueur2, 2, &talon);
        afficherJoueur(&joueur1);
        afficherJoueur(&joueur2);
        demanderMot(&joueur1, mot1,premierTour);
        demanderMot(&joueur2, mot2,premierTour);
        initRail(&r, mot1, mot2);
        afficherRailRecto(&r);
        retournerRail(&r);
        afficherRailVerso(&r);

        premierTour = false;
        while (!verifJoueur(&joueur1) || !verifJoueur(&joueur2)) {
            // faire un scanf pour savoir quel commande le joueur joue
        }
    }
