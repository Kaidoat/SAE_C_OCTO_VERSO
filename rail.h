#ifndef RAIL_H
#define RAIL_H


enum{MAX_RAIL=8};

typedef struct {
    char lettres[MAX_RAIL]; // Le rail contient jusqu'� 8 lettres
    int recto;       // 1 si recto, 0 si verso
} Rail;

// Prototypes
//void initRail(Rail* rail, Pioche* pioche);
void afficherRail(const Rail* rail);
int ajouterLettres(Rail* rail, const char* mot, char extremite);
int retournerRail(Rail* rail);

#endif
