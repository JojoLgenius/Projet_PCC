#ifndef EVENEMENT_H_
#define EVENEMENT_H_


#include "global.h"

/*Renvoi 1 si le click est sur suivant*/
int Click_suivant(int x, int y);
/*Renvoi 1 si le click est dans choix_ville*/
int Click_choix_ville(int x, int y);
/*Renvoi 1 si le click est dans choix_algo*/
int Click_choix_algo(int x, int y);


/*Gere les mise a jour en fonction des clicks*/
int MAJ_choix_ville(int choix_ville,int x,int y);
int MAJ_choix_algo(int choix_algo,int x,int y);


#endif