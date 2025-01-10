#ifndef SAE__OCTO_JOUEUR_H
#define SAE__OCTO_JOUEUR_H

#ifndef JEU_H
#define JEU_H

#include <stdio.h>
#include <stdbool.h>
#include "Lettre.h"
#include "Pile.h"

enum { MAX_CHEVALET = 12, MAX_MOT = 4, TAILLE_CHEVALET = 12 , MAX_TAILLE_CHEVALETS=20};

// Structure pour représenter un joueur
typedef struct {
    char chevalets[MAX_TAILLE_CHEVALETS]; // 12 lettres au départ et possibilité d'ajouter en cas de pénalité
    int nbLettres;      // Nombre actuel de lettres dans le chevalet
    int numero;         // Numéro du joueur
} Joueur;


// Prototypes des fonctions
void initJoueur(Joueur* joueur, int numero, Pile *talon);
void afficherJoueur(const Joueur* joueur);
bool verifLettre(Joueur* joueur, int nbLettres, const char* mot);
void demanderMot(Joueur* joueur, char *mot, const bool premierTour);
bool joueurSansLettre(const Joueur* joueur);
int verifJoueur(Joueur* joueur);
bool piocherLettre(Joueur* joueur, Pile* talon, Pile* expose);



#endif

#endif //SAE__OCTO_JOUEUR_H
