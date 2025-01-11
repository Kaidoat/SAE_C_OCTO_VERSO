#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dictionnaire.h"
#include "jeu.h"
#include "rail.h"
#include "joueur.h"
#include "Lettre.h"
#include "Pile.h"
#pragma warning(disable:4996)

enum {MAX_JOUEUR=2};

    int main() {
        srand(time(NULL)); // Initialiser le générateur de nombres aléatoires

        // Initialisation des lettres dans le sac
        Lettre lettres[TAILLE_LETTRES];
        Pile talon;
        Pile expose;
        int taille_sac;
        Rail r;
        bool premierTour = true;
        bool rejouer = false;

        Joueur joueur1, joueur2;
        Joueur joueur[MAX_JOUEUR] = {joueur1, joueur2};
        char mot1[MAX_LETTRES_MOTS],mot2[MAX_LETTRES_MOTS];
        char commande;

        initialiser_lettres(lettres, &taille_sac);
        initialiser(&talon, TAILLE_LETTRES);
        initialiser(&expose, TAILLE_LETTRES);
        initTalon(&talon, lettres);
        melanger(&talon);
        initJoueur(&joueur[0], 1, &talon);
        initJoueur(&joueur[1], 2, &talon);
        afficherJoueur(&joueur[0]);
        afficherJoueur(&joueur[1]);
        demanderMot(&joueur[0], mot1,premierTour);
        demanderMot(&joueur[1], mot2,premierTour);
        initRail(&r, mot1, mot2);

        premierTour = false;
        while (!verifJoueur(&joueur[1]) || !verifJoueur(&joueur[2])) {
            for (int i =0; i < MAX_JOUEUR; i++) {
                if (rejouer) {
                    rejouer = false;
                    continue;
                }
                afficherJoueur(&joueur[0]);
                afficherJoueur(&joueur[1]);
                afficherRailRecto(&r);
                retournerRail(&r);
                afficherRailVerso(&r);
                retournerRail(&r);
                printf("%d>    ", i+1);
                scanf(" %c",&commande);
                getchar();
                if (commande == '-') {
                    //appel fonction pioche
                    rejouer = piocherLettre(&joueur[i], &talon, &expose);
                }
                if (commande == 'R') {
                    //appel fonction PoserMotRecto
                    rejouer = demanderMotRV(&joueur[i], &r);
                }
                if (commande == 'V') {
                    //appel fonction PoserMotVerso
                    retournerRail(&r);
                    rejouer = demanderMotRV(&joueur[i], &r);
                    retournerRail(&r);
                }
                if (commande == 'r') {
                    //appel fonction petitR
                    printf("r");
                }
                if (commande == 'v') {
                    //appel fonction petitV
                    printf("v");
                }
            }

        }
    }
