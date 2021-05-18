#include "DAT_Matrice.h"

/*
Fonction initialiser_ville
Permet d'intialiser le tableau des villes 
Utiise les valeurs connue de wikipeda
*/

void init_ville_test(mat_cout * mc){
    
    //Iterateurs
    int i;

    //Nombre de ville
    mc->nb_ville=4;
    mc->cv=NULL;

    //Allocation memoire
    mc->cv=(int **)malloc(sizeof(int *) * (mc->nb_ville+1));
    for(i=1; i <= mc->nb_ville; i++){
        mc->cv[i]=(int *)malloc(sizeof(int) * (mc->nb_ville+1));
    }

    /*Attribution des valeurs couts */
    mc->cv[1][1]=0;
    mc->cv[1][2]=30;
    mc->cv[1][3]=10;
    mc->cv[1][4]=20;
    mc->cv[2][1]=40;
    mc->cv[2][2]=0;
    mc->cv[2][3]=30;
    mc->cv[2][4]=5;
    mc->cv[3][1]=50;
    mc->cv[3][2]=10;
    mc->cv[3][3]=0;
    mc->cv[3][4]=10;
    mc->cv[4][1]=10;
    mc->cv[4][2]=20;
    mc->cv[4][3]=20;
    mc->cv[4][4]=0;
}