#ifndef LETTRE_H
#define LETTRE_H

enum {TAILLE_LETTRES=88};

// Structure pour stocker une lettre et sa quantité
typedef struct {
    char lettre;
    int quantite;
} Lettre;

/**
 * @brief Initialise le sac de lettres avec des lettres spécifiques et leurs quantités.
 *
 * Cette fonction initialise un tableau de `Lettre` en attribuant à chaque lettre une quantité définie.
 * Le tableau résultant contient les lettres et leurs occurrences, et la taille du sac est mise à jour dans `taille_sac`.
 *
 * @param [out] lettres Le tableau qui contiendra les lettres du sac.
 * @param [out] taille_sac La taille du sac de lettres, mise à jour après initialisation.
 *
 * @pre Le tableau `lettres` doit être initialisé et suffisamment grand pour contenir toutes les lettres et leurs occurrences.
 * @post Le tableau `lettres` est rempli avec les lettres et leurs quantités, et `taille_sac` est mis à jour.
 */
void initialiser_lettres(Lettre lettres[], int* taille_sac);

#endif //LETTRE_H




