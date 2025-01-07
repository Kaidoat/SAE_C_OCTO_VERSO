
#include "joueur.h" // Déclaration du type Joueur
#include "rail.h"   // Déclaration du type Rail

enum{NB_JOUEURS =2};

typedef struct{
    Joueur joueur[NB_JOUEURS];
    Rail r;
    int joueurActuelle;
}Jeu;

void demanderMot(Jeu* j, char mot[MAX_MOT]);
void joueurSuivant(Jeu* j);

