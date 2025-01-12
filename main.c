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
        precedent = r;
        joueur1preced = joueur[0];
        joueur2preced = joueur[1];

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
                    rejouer = piocherLettre(&joueur[i], &talon, &expose);
                }
                if (commande == 'R') {
                    rejouer = demanderMotRV(&joueur[i], &r, motPreced);
                }
                if (commande == 'V') {
                    retournerRail(&r);
                    rejouer = demanderMotRV(&joueur[i], &r, motPreced);
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
                precedent = r;
                joueur1preced = joueur[0];
                joueur2preced = joueur[1];
            }

        }
    }
