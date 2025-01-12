#ifndef SAE__OCTO_DICTIONNAIRE_H
#define SAE__OCTO_DICTIONNAIRE_H
enum {TAMPON=256};



/**
* @brief vérifie si le mot est dans le dictionnaire  .
* @param [in] le mot mot qui doit etre vérifié .
* @pre le mot est compris dans le fichier ods4.txt.
*/
int estDansDictionnaire(const char* mot);
#endif //SAE__OCTO_DICTIONNAIRE_H
