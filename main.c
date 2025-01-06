#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Jeu.h"

int main() {


    srand(time(NULL));

    Pioche pioche;
    initPioche(&pioche);


    Joueur joueur1, joueur2;
    initJoueur(&joueur1);
    initJoueur(&joueur2);


    afficherJoueur(&joueur1,1);

    afficherJoueur(&joueur2,2);





}