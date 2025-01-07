#ifndef SAE__OCTO_JOUEUR_H
#define SAE__OCTO_JOUEUR_H

#ifndef JEU_H
#define JEU_H

#include <stdio.h>

enum { MAX_CHEVALET = 12, MAX_MOT = 4, TAILLE_CHEVALET = 12 , MAX_TAILLE_CHEVALETS=20};

// Structure pour représenter un joueur
typedef struct {
    char chevalets[MAX_TAILLE_CHEVALETS]; // 12 lettres au départ et possibilité d'ajouter en cas de pénalité
    int nbLettres;      // Nombre actuel de lettres dans le chevalet
    int numero;         // Numéro du joueur
} Joueur;

// Structure pour stocker une lettre et sa quantité
typedef struct {
    char lettre;
    int quantite;
} Lettre;

// Prototypes des fonctions
void initialiser_lettres(Lettre lettres[], int* taille_sac);
void melanger_lettres(Lettre lettres[], int taille);
void initJoueur(Joueur* joueur, int numero, Lettre* sac, int* taille_sac);
void afficherJoueur(const Joueur* joueur);


#endif

#endif //SAE__OCTO_JOUEUR_H
