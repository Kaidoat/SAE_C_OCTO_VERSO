#include "jeu.c"
#include "pioche.c"
#include "rail.c"

#include <stdio.h>
#include <stdlib.h>

int main() {
    Pioche* p;
    initPioche(&p);
    printf("Pioche initialisée et mélangée :\n");
    for (int i = 0; i < p->nbPioche; i++) {
        printf("%c ", p->chevalet[i]);
    }
    printf("\n");
    free(p);



    return 0;
}