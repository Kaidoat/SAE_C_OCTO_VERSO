#ifndef LETTRE_H
#define LETTRE_H

enum {TAILLE_LETTRES=88};

// Structure pour stocker une lettre et sa quantité
typedef struct {
    char lettre;
    int quantite;
} Lettre;

void initialiser_lettres(Lettre lettres[], int* taille_sac);

#endif //LETTRE_H




