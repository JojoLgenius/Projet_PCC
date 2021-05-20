#ifndef DAT_MATRICE_H_
#define DAT_MATRICE_H_


#include"global.h"

//Fonctions

/*Renvoi un element aleatoire entre 0 et max*/
int aleatoire(int max);

//Initialisation cout ville
    
/*Initialise des couts constant*/
//(Wikipedia)
void init_ville_test(mat_cout * mc);
/*Initialise les cout aleatoirement*/
void init_ville_alea(mat_cout * mc, int nb_ville, int max);
/*Initalise une matrice symettrique*/
void init_ville_alea_sym(mat_cout * mc, int nb_ville, int max);


/*Tableau de points*/
void chargement_fichier(tabpoints * t, char *nomfichier);


#endif