#include "Jeu.h"

int main() {
    Pioche pioche;
    initPioche(&pioche);

    Rail rail;
    //initRail(&rail, &pioche);

    Joueur joueur1, joueur2;
    initJoueur(&joueur1, &pioche);
    initJoueur(&joueur2, &pioche);

    //afficherRail(&rail);
    afficherJoueur(&joueur1, 1);
    afficherJoueur(&joueur2, 2);

    while (1) {
        if (jouerTour(&joueur1, &rail, &pioche)) {
            if (verifierVictoire(&joueur1)) {
                printf("Joueur 1 gagne !\n");
                break;
            }
        }

        if (jouerTour(&joueur2, &rail, &pioche)) {
            if (verifierVictoire(&joueur2)) {
                printf("Joueur 2 gagne !\n");
                break;
            }
        }
    }

    libererPioche(&pioche);
    return 0;
}
