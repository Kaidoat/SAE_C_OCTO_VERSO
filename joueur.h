#ifndef SAE__OCTO_JOUEUR_H
#define SAE__OCTO_JOUEUR_H

#ifndef JEU_H
#define JEU_H

#include <stdio.h>
#include <stdbool.h>
#include "Lettre.h"
#include "Pile.h"
#include "rail.h"

enum { MAX_CHEVALET = 12, MAX_MOT = 4, TAILLE_CHEVALET = 12 , MAX_TAILLE_CHEVALETS=20};

// Structure pour représenter un joueur
typedef struct {
    char chevalets[MAX_TAILLE_CHEVALETS]; // 12 lettres au départ et possibilité d'ajouter en cas de pénalité
    int nbLettres;      // Nombre actuel de lettres dans le chevalet
    int numero;         // Numéro du joueur
} Joueur;



/**
 * @brief Initialise un joueur avec son numéro et sa pile de talons.
 * @param[out] joueur Le joueur à initialiser.
 * @param[in] numero Le numéro attribué au joueur.
 * @param[in] talon La pile de talons associée au joueur.
 * @pre <code>joueur</code> doit pointer vers une structure valide.
 * @pre <code>numero</code> doit être un entier positif.
 * @pre <code>talon</code> doit pointer vers une pile initialisée.
 */
void initJoueur(Joueur* joueur, int numero, Pile *talon);



/**
 * @brief Affiche les informations d'un joueur.
 * @param[in] joueur Le joueur dont les informations doivent être affichées.
 * @pre <code>joueur</code> doit pointer vers une structure valide et initialisée.
 */
void afficherJoueur(const Joueur* joueur);



/**
 * @brief Demande à un joueur de saisir un mot avec des vérifications de validité.
 *
 * Cette fonction permet de demander à un joueur de saisir un mot et vérifie si ce mot
 * respecte certaines conditions, comme sa longueur, sa présence dans un dictionnaire,
 * et si il est jouer au premier tour.
 *
 * @param [in] joueur Le joueur qui effectue la saisie.
 * @param [out] mot Le mot saisi par le joueur.
 * @param [in] premierTour Indique si c'est le premier tour ou non, pour appliquer des règles spécifiques.
 *
 * @pre La fonction vérifie plusieurs conditions pour le mot saisi :
 *  - Si c'est le premier tour, le mot doit avoir une longueur de 4 caractères.
 *  - Le mot doit être présent dans un dictionnaire.
 *  - Le mot doit respecter certaines règles de lettres définies par la fonction `verifLettre`.
 *
 * @post Le mot saisi est validé et stocké dans la variable `mot` si toutes les conditions sont remplies.
 */
void demanderMot(Joueur* joueur, char *mot, const bool premierTour);

/**
 * @brief Vérifie si un joueur n'a plus de lettres dans son chevalet.
 *
 * Cette fonction permet de vérifier si un joueur a épuisé toutes ses lettres
 * en comparant la valeur de `nbLettres` à zéro.
 *
 * @param [in] joueur Le joueur dont on souhaite vérifier le nombre de lettres.
 *
 * @return `true` si le joueur n'a plus de lettres dans son chevalet, `false` sinon.
 *
 * @pre Le joueur doit être initialisé avec une valeur pour l'attribut `nbLettres`.
 */
bool joueurSansLettre(const Joueur* joueur);


/**
 * @brief Demande à un joueur de proposer un mot et vérifie sa validité selon plusieurs critères.
 *
 * Cette fonction demande à un joueur de proposer un mot, le vérifie en appliquant les conditions suivantes :
 * - Le mot doit être valide (enlevez les parenthèses et vérifier si sa longueur ne dépasse pas 8).
 * - Le mot sans parenthèses doit exister dans le dictionnaire.
 * - Les lettres à l'intérieur des parenthèses doivent correspondre au début ou à la fin de la chaîne de lettres du rail.
 * - Le joueur doit posséder les lettres nécessaires pour jouer le mot.
 * Si une des conditions échoue, la fonction renvoie `true`, sinon elle renvoie `false`.
 *
 * @param [in] joueur Le joueur qui propose le mot.
 * @param [in] rail Le rail qui contient les lettres et qui impose certaines restrictions pour le mot.
 *
 * @return `true` si une des conditions échoue (mot invalide, lettres manquantes, etc.), `false` si toutes les conditions sont remplies.
 *
 * @pre Le rail doit être initialisé avec des lettres et le joueur doit avoir un chevalet avec des lettres.
 * @post Si le mot est valide, la fonction renvoie `false`, sinon `true`.
 */
bool demanderMotRV(Joueur *joueur, Rail *rail);


/**
 * @brief Permet à un joueur de piocher une lettre du talon.
 *
 * Cette fonction permet à un joueur de choisir une lettre parmi celles qu'il possède
 * et de la mettre dans la pile `expose`, puis de piocher une nouvelle lettre du talon
 * pour remplacer celle qu'il a choisie. Si la lettre choisie n'est pas présente dans le chevalet
 * du joueur, la fonction retourne `true`, sinon elle retourne `false` après avoir effectué l'échange.
 *
 * @param [in] joueur Le joueur qui effectue l'action de piocher une lettre.
 * @param [in, out] talon La pile de lettres disponibles, dont le sommet est utilisé pour piocher une nouvelle lettre.
 * @param [in, out] expose La pile qui contient les lettres exposées, où la lettre choisie par le joueur est empilée.
 *
 * @return `true` si la lettre choisie par le joueur n'est pas présente dans son chevalet, `false` sinon.
 *
 * @pre La pile `talon` doit contenir des lettres, et le joueur doit avoir un chevalet avec des lettres.
 */
bool piocherLettre(Joueur* joueur, Pile* talon, Pile* expose);


#endif

#endif //SAE__OCTO_JOUEUR_H
