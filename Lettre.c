#include "Lettre.h"



// Fonction pour initialiser les lettres du sac
void initialiser_lettres(Lettre lettres[], int* taille_sac) {
    Lettre temp[] = {
        {'A', 9}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 14},
        {'F', 1}, {'G', 1}, {'H', 1}, {'I', 7}, {'J', 1},
        {'K', 0}, {'L', 5}, {'M', 3}, {'N', 6}, {'O', 5},
        {'P', 2}, {'Q', 1}, {'R', 6}, {'S', 7}, {'T', 6},
        {'U', 5}, {'V', 2}
    };
    int n = sizeof(temp) / sizeof(temp[0]);
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < temp[i].quantite; j++) {
            lettres[index++] = temp[i];
        }
    }
    *taille_sac = index;
}

