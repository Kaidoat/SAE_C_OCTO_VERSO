#ifndef RAIL_H
#define RAIL_H


enum{MAX_RAIL=9,MAX_TOUR1=4, MAX_LETTRES_MOTS = 11};

typedef struct {
    char lettres[MAX_RAIL]; // Le rail contient jusqu'à 8 lettres
    int recto;       // 1 si recto, 0 si verso
    int longueur;
} Rail;


/**
 * @brief Initialise un rail avec deux mots, triés par ordre alphabétique.
 *
 * Cette fonction prend deux mots en entrée et les concatène dans un rail après les avoir triés par ordre alphabétique.
 * Le rail est ensuite initialisé avec ces lettres, et des valeurs par défaut sont attribuées aux autres champs de la structure.
 *
 * @param [out] rail Le rail à initialiser.
 * @param [in] mot1 Le premier mot à ajouter au rail.
 * @param [in] mot2 Le deuxième mot à ajouter au rail.
 *
 * @pre Les mots doivent être des chaînes de caractères valides.
 * @post Le rail est initialisé avec les mots triés et concaténés, et les autres champs sont définis par défaut.
 */
void initRail(Rail *rail, const char *mot1, const char *mot2);


/**
 * @brief Affiche le contenu du rail dans sa face recto.
 *
 * Cette fonction affiche le contenu du rail tel qu'il est stocké dans la structure, en utilisant la face recto (lettres dans l'ordre).
 * Si le rail est vide ou invalide, un message d'erreur est affiché.
 *
 * @param [in] rail Le rail dont le recto doit être affiché.
 *
 * @pre Le rail doit être une structure valide.
 * @post Le contenu du rail est affiché, ou un message d'erreur est affiché si le rail est invalide.
 */
void afficherRailRecto(const Rail* rail);


/**
 * @brief Affiche le contenu du rail dans sa face verso.
 *
 * Cette fonction affiche le contenu du rail tel qu'il est stocké dans la structure, en utilisant la face verso.
 * Si le rail est vide ou invalide, un message d'erreur est affiché.
 *
 * @param [in] rail Le rail dont le verso doit être affiché.
 *
 * @pre Le rail doit être une structure valide.
 * @post Le contenu du rail est affiché, ou un message d'erreur est affiché si le rail est invalide.
 */
void afficherRailVerso(const Rail* rail);

/**
 * @brief Retourne le rail (inverse l'ordre des lettres et bascule entre recto et verso).
 *
 * Cette fonction inverse l'ordre des lettres du rail et bascule l'état du rail entre la face recto (1) et verso (0).
 * Si le rail est invalide, la fonction retourne un échec (0).
 *
 * @param [in, out] rail Le rail à retourner (modifier).
 *
 * @return Retourne 1 en cas de succès, 0 en cas d'échec (rail invalide).
 *
 * @pre Le rail doit être une structure valide et non vide.
 * @post Le rail est retourné et l'état recto/verso est mis à jour.
 */
int retournerRail(Rail* rail);

#endif
