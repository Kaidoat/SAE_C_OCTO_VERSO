void joueurSuivant(Jeu* j) {
    ++j->joueurActuelle;
    p->joueurActuelle%=2;
}
void demanderMot(Jeu* j, char mot[MAX_MOT]);