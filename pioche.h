#ifndef PIOCHE_H
#define TAILLE_MAX_PIOCHE 88

// Structure pour un n�ud dans la liste cha�n�e
typedef struct Noeud {
    char lettre;             // Lettre stock�e
    struct Noeud* suivant;   // Pointeur vers le prochain n�ud
} Noeud;

// Structure pour la pioche
typedef struct {
    Noeud* tete;             // Pointeur vers le premier n�ud de la liste
    int taille;              // Nombre de lettres dans la pioche
} Pioche;

// Prototypes des fonctions
void initPioche(Pioche* p);
void remplirPioche(Pioche* p);
void melangerPioche(Pioche* p);
char piocher(Pioche* p);
void libererPioche(Pioche* p);

#endif

