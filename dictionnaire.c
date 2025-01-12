    #include <stdio.h>
    #include <string.h>

    #include "dictionnaire.h"


int estDansDictionnaire(const char* mot) {
    FILE *fichier = fopen("ods4.txt", "r"); // Ouvre le fichier dictionnaire en lecture
    if (fichier == NULL) {
        perror("Impossible d'ouvrir le fichier de dictionnaire");
        return 2; // Retourne une erreur spécifique
    }

    char ligne[TAMPON]; // Tampon pour lire chaque ligne
    while (fgets(ligne, sizeof(ligne), fichier)) {
        // Supprime le caractère de fin de ligne (\n), s'il existe
        ligne[strcspn(ligne, "\n")] = '\0';

        // Compare le mot avec la ligne actuelle
        if (strcmp(ligne, mot) == 0) {
            fclose(fichier); // Ferme le fichier
            return 1; // Mot trouvé
        }
    }

    fclose(fichier); // Ferme le fichier
    return 0; // Mot non trouvé

    /*FILE *fichier = fopen("C:/Users/Abdullah/CLionProjects/SAE_C_OCTO_VERSO/ods4.txt", "r"); // Ouvre le fichier en mode lecture
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 0;
    }

    char buffer[256]; // Tampon pour lire les mots du fichier
    while (fscanf(fichier, "%255s", buffer) != EOF) { // Lecture mot par mot
        if (strcmp(buffer, &mot) == 0) { // Comparaison avec le mot donné
            fclose(fichier); // Ferme le fichier
            return 1;     // Mot trouvé
        }
    }

    fclose(fichier); // Ferme le fichier
    return 0;*/
}
