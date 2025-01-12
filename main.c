#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
        Rail precedent;
        Joueur joueur1preced, joueur2preced;
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
        while (!joueurSansLettre(&joueur[0]) || !joueurSansLettre(&joueur[1])) {
            for (int i =0; i < MAX_JOUEUR; i++) {
                char motPreced[MAX_LETTRES_MOTS];
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
                    if (i==0) {
                        rejouer = piocherLettre(&joueur[i], &talon, &expose, &joueur1preced, &precedent, &r);
                    }
                    else {
                        rejouer = piocherLettre(&joueur[i], &talon, &expose, &joueur2preced, &precedent, &r);
                    }
                }
                if (commande == 'R') {
                    if (i==0) {
                        rejouer = demanderMotRV(&joueur[i], &r, motPreced, &joueur1preced,  &precedent);
                    }
                    else {
                        rejouer = demanderMotRV(&joueur[i], &r, motPreced, &joueur2preced,  &precedent);

                    }
                }
                if (commande == 'V') {
                    retournerRail(&r);
                    if (i==0) {
                        rejouer = demanderMotRV(&joueur[i], &r, motPreced, &joueur1preced,  &precedent);
                    }
                    else {
                        rejouer = demanderMotRV(&joueur[i], &r, motPreced, &joueur2preced,  &precedent);

                    }
                    retournerRail(&r);
                }
                if (commande == 'r') {
                    if (i==0) {
                        rejouer = demanderMotPetitRV(&joueur1preced, &joueur[0], &precedent, motPreced);
                    }
                    else {
                        rejouer = demanderMotPetitRV(&joueur2preced, &joueur[1], &precedent, motPreced);
                    }
                }
                if (commande == 'v') {
                    retournerRail(&r);
                    if (i==0) {
                        rejouer = demanderMotPetitRV(&joueur1preced, &joueur[0], &precedent, motPreced);
                    }
                    else {
                        rejouer = demanderMotPetitRV(&joueur2preced, &joueur[1], &precedent, motPreced);
                    }
                    retournerRail(&r);
                }
            }

        }
    }
