#ifndef RAIL_H
#define RAIL_H


enum{MAX_RAIL=9,MAX_TOUR1=4, MAX_LETTRES_MOTS = 11};

typedef struct {
    char lettres[MAX_RAIL]; // Le rail contient jusqu'� 8 lettres
    int recto;       // 1 si recto, 0 si verso
    int longueur;
} Rail;


/**
 * @brief Initialise un rail avec deux mots, tri�s par ordre alphab�tique.
 *
 * Cette fonction prend deux mots en entr�e et les concat�ne dans un rail apr�s les avoir tri�s par ordre alphab�tique.
 * Le rail est ensuite initialis� avec ces lettres, et des valeurs par d�faut sont attribu�es aux autres champs de la structure.
 *
 * @param [out] rail Le rail � initialiser.
 * @param [in] mot1 Le premier mot � ajouter au rail.
 * @param [in] mot2 Le deuxi�me mot � ajouter au rail.
 *
 * @pre Les mots doivent �tre des cha�nes de caract�res valides.
 * @post Le rail est initialis� avec les mots tri�s et concat�n�s, et les autres champs sont d�finis par d�faut.
 */
void initRail(Rail *rail, const char *mot1, const char *mot2);


/**
 * @brief Affiche le contenu du rail dans sa face recto.
 *
 * Cette fonction affiche le contenu du rail tel qu'il est stock� dans la structure, en utilisant la face recto (lettres dans l'ordre).
 * Si le rail est vide ou invalide, un message d'erreur est affich�.
 *
 * @param [in] rail Le rail dont le recto doit �tre affich�.
 *
 * @pre Le rail doit �tre une structure valide.
 * @post Le contenu du rail est affich�, ou un message d'erreur est affich� si le rail est invalide.
 */
void afficherRailRecto(const Rail* rail);


/**
 * @brief Affiche le contenu du rail dans sa face verso.
 *
 * Cette fonction affiche le contenu du rail tel qu'il est stock� dans la structure, en utilisant la face verso.
 * Si le rail est vide ou invalide, un message d'erreur est affich�.
 *
 * @param [in] rail Le rail dont le verso doit �tre affich�.
 *
 * @pre Le rail doit �tre une structure valide.
 * @post Le contenu du rail est affich�, ou un message d'erreur est affich� si le rail est invalide.
 */
void afficherRailVerso(const Rail* rail);

/**
 * @brief Retourne le rail (inverse l'ordre des lettres et bascule entre recto et verso).
 *
 * Cette fonction inverse l'ordre des lettres du rail et bascule l'�tat du rail entre la face recto (1) et verso (0).
 * Si le rail est invalide, la fonction retourne un �chec (0).
 *
 * @param [in, out] rail Le rail � retourner (modifier).
 *
 * @return Retourne 1 en cas de succ�s, 0 en cas d'�chec (rail invalide).
 *
 * @pre Le rail doit �tre une structure valide et non vide.
 * @post Le rail est retourn� et l'�tat recto/verso est mis � jour.
 */
int retournerRail(Rail* rail);

#endif
