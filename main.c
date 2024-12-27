#include "Jeu.h"

int main() {
    // Initialisation de la pioche
    Pioche pioche;
    initPioche(&pioche);

    // Initialisation des joueurs
    Joueur joueur1, joueur2;
    initJoueur(&joueur1, 1);
    initJoueur(&joueur2, 2);

    // Initialisation du rail
    Rail rail;
    initRail(&rail);

    // Remplissage initial du rail avec les mots des joueurs
    remplirRail(&rail, &joueur1);
    remplirRail(&rail, &joueur2);

    printf("\nLe rail est rempli avec les mots: \n");
    afficherRail(&rail);

    // Affichage initial des joueurs et du rail
    afficherJoueur(&joueur1);
    afficherJoueur(&joueur2);
    afficherRail(&rail);

    // Boucle principale du jeu
    while (1) {
        // Tour du joueur 1
        printf("\n--- Tour du Joueur 1 ---\n");
        if (jouerTour(&joueur1, &rail, &pioche)) {
            if (verifierVictoire(&joueur1)) {
                printf("Joueur 1 gagne !\n");
                break;
            }
        }

        // Tour du joueur 2
        printf("\n--- Tour du Joueur 2 ---\n");
        if (jouerTour(&joueur2, &rail, &pioche)) {
            if (verifierVictoire(&joueur2)) {
                printf("Joueur 2 gagne !\n");
                break;
            }
        }
    }

    // Libération des ressources
    libererPioche(&pioche);
    return 0;
}
