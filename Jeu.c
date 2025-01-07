#include "joueur.h"
#include "Dictionnaire.h"
#include "rail.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

enum{NB_JOUEURS =2};

typedef struct{
    Joueur joueur[NB_JOUEURS];
    Rail rail;
    int joueurActuelle;
}Jeu;
void demanderMot(Jeu* j, char mot[MAX_MOT]);
void initRail(Rail* rail, const char mot1, const char mot2);
void joueurSuivant(Jeu* j);


