#include <stdio.h>
#include <stdlib.h>

#include "joueur.h"
#include <stdbool.h>
#include <string.h>
#include "dictionnaire.h"
#include "Pile.h"
#include "rail.h"

// Fonction pour initialiser un joueur avec des lettres du sac
void initJoueur(Joueur* joueur, int numero, Pile *talon) {
    joueur->nbLettres = MAX_CHEVALET; // Le joueur commence avec 12 lettres
    joueur->numero = numero;

    for (int i = 0; i < MAX_CHEVALET; i++) {
        Lettre lettre_actuelle = sommet(talon); // Appelle sommet sur le talon
        joueur->chevalets[i] = lettre_actuelle.lettre; // Ajoute la lettre au chevalet
        depiler(talon); // Retire la lettre du talon
    }

    joueur->chevalets[MAX_CHEVALET] = '\0'; // Terminer la chaîne
}




int comparerLettres(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

// Fonction pour afficher le chevalet d'un joueur
void afficherJoueur(const Joueur* joueur) {
    qsort(joueur->chevalets, joueur->nbLettres, sizeof(char), comparerLettres);
    printf("%d : ", joueur->numero);
    for (int i = 0; i < MAX_CHEVALET; i++) {
        if(joueur->chevalets[i] != '0') {
            printf("%c", joueur->chevalets[i]);
        }
    }
    printf("\n");
}


/**
 * @brief Vérifie si un joueur peut former un mot en utilisant un nombre donné de lettres.
 *
 * @param[in] joueur Le joueur dont les lettres doivent être vérifiées.
 * @param[in] nbLettres Le nombre de lettres du mot à vérifier.
 * @param[in] mot Le mot que le joueur souhaite former.
 * @return <code>true</code> si le joueur peut former le mot avec les lettres disponibles, <code>false</code> sinon.
 * @pre <code>joueur</code> doit pointer vers une structure valide et initialisée.
 * @pre <code>mot</code> doit être une chaîne de caractères terminée par '\0'.
 * @pre <code>nbLettres</code> doit correspondre à la longueur du mot <code>mot</code>.
 */

bool verifLettre(Joueur* joueur, int nbLettres, const char* mot) {
    // On travaille directement sur le chevalet du joueur
    bool lettresValides = true; // Indicateur pour vérifier la validité du mot
    Joueur tmp = *joueur;

    // Vérification des lettres
    for (int i = 0; i < nbLettres; i++) {
        bool lettreTrouvee = false; // Indicateur si la lettre est trouvée dans le chevalet

        // Parcourir toutes les lettres du chevalet du joueur pour trouver une correspondance
        for (int j = 0; j < MAX_CHEVALET; j++) {
            if (tmp.chevalets[j] == mot[i]) {
                // Lettre trouvée, on l'a juste trouvée, mais on ne la consomme pas encore
                lettreTrouvee = true;
                tmp.chevalets[j] = '0'; // Marquer la lettre comme utilisée
                break; // Sortir de la boucle interne (inutile de chercher plus loin)
            }
        }

        if (!lettreTrouvee) {
            // Si une lettre n'est pas trouvée dans le chevalet, le mot est invalide
            lettresValides = false;
            break; // Sortir de la boucle, inutile de continuer la vérification
        }
    }

    if(lettresValides) {
        for (int i = 0; i < MAX_CHEVALET; i++) {
            joueur->chevalets[i] = tmp.chevalets[i];
        }
        joueur->nbLettres -= nbLettres;
    }

    return lettresValides; // Retourne vrai si toutes les lettres sont valides

}




void demanderMot(Joueur* joueur, char *mot, const bool premierTour) {

    do {
        printf("%d>", joueur->numero);
        scanf("%s", mot);

        // Vérifie les conditions du mot
        if (premierTour) {
            // Conditions spécifiques pour le premier tour
            if (strlen(mot) != 4) {


            } else if (estDansDictionnaire(mot) == 0) {

            } else if (!verifLettre(joueur, strlen(mot), mot)) {

            } else {
                break; // Toutes les conditions sont remplies, on sort de la boucle
            }
        }
    } while (1); // Continue de demander tant que les conditions ne sont pas respectées

}


// Fonction pour vérifier si un joueur n'a plus de lettres dans son chevalet
bool joueurSansLettre(const Joueur* joueur) {
    return joueur->nbLettres == 0;
}


/**
 * @brief Vérifie si un joueur possède une lettre spécifique dans son chevalet.
 *
 * Cette fonction parcourt le chevalet du joueur et vérifie si la lettre donnée
 * y est présente. Si la lettre est trouvée, elle renvoie l'indice de la lettre dans le chevalet.
 * Si la lettre n'est pas présente, elle renvoie `-1`.
 *
 * @param [in] joueur Le joueur dont on souhaite vérifier le chevalet.
 * @param [in] lettre La lettre à rechercher dans le chevalet du joueur.
 *
 * @return L'indice de la lettre dans le chevalet si elle est trouvée, `-1` sinon.
 *
 * @pre Le joueur doit être initialisé avec un chevalet contenant des lettres.
 */
int verifUneLettre(Joueur* joueur, char lettre) {
    for (int i = 0; i < MAX_CHEVALET; i++) {
        if (joueur->chevalets[i] == lettre) {
            return i;
        }
    }
    return -1;
}

bool piocherLettre(Joueur* joueur, Pile* talon, Pile* expose) {
    char lettre;
    scanf("%c", &lettre);
    getchar();


    int verifLettre = verifUneLettre(joueur, lettre);
    if (verifLettre == -1) {
        return true;
    }

    Lettre lettreExpose = {joueur->chevalets[verifLettre], 0};
    empiler(expose, lettreExpose);
    joueur->chevalets[verifLettre] = sommet(talon).lettre;
    depiler(talon);
    return false;
}


/**
 * @brief Remet en forme une chaîne de caractères en supprimant toutes les occurrences d'un caractère spécifié.
 *
 * Cette fonction prend une chaîne d'entrée `value`, et retire toutes les occurrences du caractère `compo`.
 * Le résultat est stocké dans la chaîne `result`, qui doit être suffisamment grande pour contenir la chaîne résultante.
 *
 * @param [in] value La chaîne d'entrée qui contient les caractères à traiter.
 * @param [in] compo Le caractère à supprimer de la chaîne d'entrée.
 * @param [out] result La chaîne résultante, qui contiendra la chaîne `value` sans le caractère `compo`.
 *
 * @pre La chaîne `result` doit être initialisée et être suffisamment grande pour contenir la chaîne résultante.
 *
 * @post La chaîne `result` contient la même chaîne que `value`, mais sans les occurrences du caractère `compo`.
 */
void remise_forme(const char *value, char compo, char *result) {
    int longueur = strlen(value); // Longueur de la chaîne d'entrée
    int index_result = 0;         // Index pour construire la chaîne résultante

    // Parcours de chaque caractère de la chaîne d'entrée
    for (int ind = 0; ind < longueur; ind++) {
        char c = value[ind];

        // Si le caractère courant n'est pas égal au caractère "compo"
        if (c != compo) {
            result[index_result] = c; // Ajout du caractère à la chaîne résultante
            index_result++;
        }
    }

    // Terminer la chaîne résultante avec un '\0'
    result[index_result] = '\0';
}


/**
 * @brief Sépare les lettres d'un mot entre celles qui sont avant et après les parenthèses.
 *
 * Cette fonction prend un mot en entrée et le sépare en deux parties :
 * - Les lettres avant les parenthèses sont ajoutées à `lettreJoueur`.
 * - Les lettres à l'intérieur des parenthèses sont ajoutées à `lettreRail`.
 * De plus, la fonction modifie le flag `lettreDebut` à `true` si le mot commence par une parenthèse.
 *
 * @param [out] lettreJoueur La chaîne qui contiendra les lettres avant les parenthèses.
 * @param [out] lettreRail La chaîne qui contiendra les lettres à l'intérieur des parenthèses.
 * @param [in] mot La chaîne de caractères représentant le mot à traiter.
 * @param [out] lettreDebut Un indicateur qui sera mis à `true` si le mot commence par une parenthèse, sinon il reste inchangé.
 *
 * @pre Les chaînes `lettreJoueur` et `lettreRail` doivent être initialisées et être suffisamment grandes pour contenir les lettres extraites.
 */
void recupererLettre(char *lettreJoueur, char *lettreRail, const char *mot, bool *lettreDebut) {
    int longueur = strlen(mot);
    int joueurIndex = 0; // Index pour remplir lettreJoueur
    int railIndex = 0;   // Index pour remplir lettreRail
    int insideParentheses = 0; // Indicateur pour savoir si on est entre parenthèses

    for (int ind = 0; ind < longueur; ind++) {
        char c = mot[ind];

        if (c == '(') {
            // On entre dans une zone entre parenthèses
            insideParentheses = 1;
            if (ind == 0) {
                *lettreDebut = true; // Mettre lettreDebut à true
            }
        } else if (c == ')') {
            // On sort de la zone entre parenthèses
            insideParentheses = 0;
        } else if (insideParentheses) {
            // Si on est entre parenthèses, ajouter à lettreRail
            lettreRail[railIndex] = c;
            railIndex++;
        } else if (c != ' ') {
            // Si on est hors parenthèses et ce n'est pas un espace, ajouter à lettreJoueur
            lettreJoueur[joueurIndex] = c;
            joueurIndex++;
        }
    }

    // Terminer les chaînes avec un '\0'
    lettreJoueur[joueurIndex] = '\0';
    lettreRail[railIndex] = '\0';
}

void mettreAJourRail(Rail *rail, char *lettreJoueur, bool lettreRailDebut) {
    int longueur = strlen(lettreJoueur); // Longueur des lettres à ajouter
    int railLength = strlen(rail->lettres); // Longueur actuelle des lettres dans le rail

    if (longueur > 8) {
        printf("Erreur : les lettres à ajouter dépassent la taille maximale du rail.\n");
        return;
    }

    if (!lettreRailDebut) {
        // Ajouter les lettres au début du rail
        if (railLength + longueur > 8) {
            // Calculer combien de lettres doivent être supprimées à la fin
            int excess = railLength + longueur - 8;

            // Décaler les lettres existantes vers la droite
            for (int i = railLength - 1; i >= 0; i--) {
                rail->lettres[i + longueur] = rail->lettres[i];
            }

            // Tronquer les lettres excédentaires à la fin
            railLength = 8 - longueur;
        } else {
            // Décaler tout le rail à droite si l'ajout ne dépasse pas 8 caractères
            for (int i = railLength - 1; i >= 0; i--) {
                rail->lettres[i + longueur] = rail->lettres[i];
            }
        }

        // Ajouter lettreJoueur au début
        for (int i = 0; i < longueur; i++) {
            rail->lettres[i] = lettreJoueur[i];
        }

    } else {
        // Ajouter les lettres à la fin du rail
        if (railLength + longueur > 8) {
            // Calculer combien de lettres au début doivent être supprimées
            int excess = railLength + longueur - 8;

            // Décaler les lettres restantes pour supprimer celles du début
            for (int i = excess; i < railLength; i++) {
                rail->lettres[i - excess] = rail->lettres[i];
            }

            // Tronquer les lettres au début si nécessaire
            railLength = 8 - longueur;
        }

        // Ajouter lettreJoueur à la fin
        for (int i = 0; i < longueur; i++) {
            rail->lettres[railLength + i] = lettreJoueur[i];
        }
    }

    // Terminer la chaîne avec '\0'
    rail->lettres[8] = '\0'; // S'assurer que le rail ne dépasse jamais 8 caractères
}






bool demanderMotRV(Joueur *joueur, Rail *rail, char *motPreced) {
    char mot[MAX_LETTRES_MOTS];
    char motSansParantheses[MAX_LETTRES_MOTS];
    scanf("%s", mot);

    // Supprimer les parenthèses du mot
    remise_forme(mot, '(', motSansParantheses);
    remise_forme(motSansParantheses, ')', motSansParantheses);

    if (strlen(motSansParantheses) > 8) {
        return true;
    }

    char lettreJoueur[MAX_LETTRES_MOTS];
    char lettreRail[MAX_LETTRES_MOTS];
    bool lettreRailDebut = false;

    // Récupérer les lettres
    recupererLettre(lettreJoueur, lettreRail, mot, &lettreRailDebut);

    // Vérifier si le mot sans parenthèses est dans le dictionnaire
    if (estDansDictionnaire(motSansParantheses) == 0) {
        return true;
    }

    // Vérifier que les lettres de lettreRail sont dans rail->lettres
    int railLength = strlen(rail->lettres);
    int lettreRailLength = strlen(lettreRail);

    if (!lettreRailDebut) {
        // Vérifier si les lettres de lettreRail correspondent au début de rail->lettres
        for (int i = 0; i < lettreRailLength; i++) {
            if (lettreRail[i] != rail->lettres[i]) {
                return true;
            }
        }
    } else {
        // Vérifier si les lettres de lettreRail correspondent à la fin de rail->lettres
        for (int i = 0; i < lettreRailLength; i++) {
            if (lettreRail[i] != rail->lettres[railLength - lettreRailLength + i]) {
                return true;
            }
        }
    }

    if(!verifLettre(joueur, strlen(lettreJoueur), lettreJoueur)) {
        return true;
    }

    mettreAJourRail(rail, lettreJoueur, lettreRailDebut);

    if(strlen(motSansParantheses) == 8) {
        printf("-%d>", joueur->numero);
        char lettre;

        do {
            scanf("%c", &lettre);
            getchar();
            verifLettre(joueur, 1, &lettre);
        }while (verifUneLettre(joueur, lettre) == -1);
    }

    // Toutes les conditions sont satisfaites
    *motPreced = motSansParantheses;
    return false;
}

bool demanderMotPetitRV(Joueur *joueurPrecedent, Joueur* joueurActuel, Rail *rail, char *motPreced) {
    char mot[MAX_LETTRES_MOTS];
    char motSansParantheses[MAX_LETTRES_MOTS];
    scanf("%s", mot);

    // Supprimer les parenthèses du mot
    remise_forme(mot, '(', motSansParantheses);
    remise_forme(motSansParantheses, ')', motSansParantheses);

    if (strlen(motSansParantheses) != 8 && strlen(motPreced) == 8) {
        return true;
    }

    char lettreJoueur[MAX_LETTRES_MOTS];
    char lettreRail[MAX_LETTRES_MOTS];
    bool lettreRailDebut = false;

    // Récupérer les lettres
    recupererLettre(lettreJoueur, lettreRail, mot, &lettreRailDebut);

    // Vérifier si le mot sans parenthèses est dans le dictionnaire
    if (estDansDictionnaire(motSansParantheses) == 0) {
        return true;
    }

    // Vérifier que les lettres de lettreRail sont dans rail->lettres
    int railLength = strlen(rail->lettres);
    int lettreRailLength = strlen(lettreRail);

    if (!lettreRailDebut) {
        // Vérifier si les lettres de lettreRail correspondent au début de rail->lettres
        for (int i = 0; i < lettreRailLength; i++) {
            if (lettreRail[i] != rail->lettres[i]) {
                return true;
            }
        }
    } else {
        // Vérifier si les lettres de lettreRail correspondent à la fin de rail->lettres
        for (int i = 0; i < lettreRailLength; i++) {
            if (lettreRail[i] != rail->lettres[railLength - lettreRailLength + i]) {
                return true;
            }
        }
    }

    if(!verifLettre(joueurPrecedent, strlen(lettreJoueur), lettreJoueur)) {
        return true;
    }

    mettreAJourRail(rail, lettreJoueur, lettreRailDebut);

    if(strlen(motSansParantheses) == 8) {
        printf("-%d>", joueurActuel->numero);
        char lettre;

        do {
            scanf("%c", &lettre);
            getchar();
            verifLettre(joueurActuel, 1, &lettre);
        }while (verifUneLettre(joueurActuel, lettre) == -1);
    }

    // Toutes les conditions sont satisfaites
    *motPreced = motSansParantheses;
    return false;
}