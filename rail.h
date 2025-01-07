#ifndef RAIL_H
#define RAIL_H


enum{MAX_RAIL=8};

typedef struct {
    char lettres[MAX_RAIL]; // Le rail contient jusqu'à 8 lettres
    int recto;       // 1 si recto, 0 si verso
    int longueur;
} Rail;

// Prototypes
void initRail(Rail* rail, char mot1, char mot2);
void afficherRail(const Rail* rail);
int ajouterLettres(Rail* rail, const char* mot, char extremite);
int retournerRail(Rail* rail);

#endif
