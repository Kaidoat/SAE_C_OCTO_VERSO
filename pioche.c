#include "pioche.h"

void initPioche(Pioche** p){
    *p = (Pioche*)malloc(sizeof(Pioche)); // Allouer dynamiquement la mémoire
    if (*p == NULL) {
        printf("Erreur d'allocation mémoire pour la pioche.\n");
        exit(EXIT_FAILURE);
    }
    remplirPioche(*p);
    melangerPioche(*p);
}
void melangerPioche(Pioche *p) {
    // Initialiser la graine pour la fonction rand()
    srand(time(NULL));

    // Mélanger avec l'algorithme de Fisher-Yates
    for (int i = p->nbPioche - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Choisir un index aléatoire
        // Échanger les éléments p->chevalet[i] et p->chevalet[j]
        char temp = p->chevalet[i];
        p->chevalet[i] = p->chevalet[j];
        p->chevalet[j] = temp;
    }
}
char piocher(Pioche *p){}
void remplirPioche (Pioche *p){
    p->nbPioche =0;
    char lettres[] = {'A','B', 'C',
                      'D', 'E', 'F', 'G', 'H',
                      'I', 'J', 'K', 'L', 'M', 'N',
                      'O' ,'P', 'Q', 'R', 'S', 'T',
                      'U', 'V' };
    int capacite[]={9, 1, 2, 3 ,14 ,
                    1, 1, 1, 7, 1, 0 ,5,
                    3, 6 ,5 ,2 ,1 ,6 ,7, 6, 5, 2 };

    for (int i = 0 ; i< sizeof(lettres)/ sizeof(lettres[0]); i++){
        for(int j = 0; j < capacite[i]; j ++){
            p->chevalet [p->nbPioche] = lettres[i];
        }
    }
}