#ifndef SAE__OCTO_PIOCHE_H
#define SAE__OCTO_PIOCHE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



enum{CARTEJOUEUR=12, CARTEPIOCHE=64, CARTETOTAL=88, NB_JOUEURS=2};

typedef struct{
    char chevalet[CARTETOTAL];
    int nbPioche;
}Pioche;


void initPioche(Pioche** p);
void melangerPioche(Pioche* p);
char piocher(Pioche *p);
void remplirPioche (Pioche *p);




#endif //SAE__OCTO_PIOCHE_H
