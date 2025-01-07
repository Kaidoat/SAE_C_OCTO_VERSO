#include <stdio.h>
#include <string.h>
#include <time.h>
#include "dictionnaire.h"


int estDansDictionnaire(const char* mot) {
    FILE* fichier = fopen("osd4.txt", "r"); // Ouvre le fichier en mode lecture
    if (fichier == NULL) {
        perror("Erreur d'ouverture du fichier");
        return 0;
    }

    char ligne[TAMPON]; // Tampon pour lire chaque ligne du fichier
    while (fgets(ligne, sizeof(ligne), fichier)) {
        // Supprime le caractère de fin de ligne, s'il existe
        ligne[strcspn(ligne, "\n")] = '\0';

        // Compare le mot avec la ligne actuelle
        if (strcmp(ligne, mot) == 0) {
            fclose(fichier); // Ferme le fichier
            return 1;     // Mot trouvé
        }
    }

    fclose(fichier); // Ferme le fichier
    return 0;    // Mot non trouvé
}
