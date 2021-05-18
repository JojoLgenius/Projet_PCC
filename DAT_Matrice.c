#include "DAT_Matrice.h"

/*
Fonction initialiser_ville
Permet d'intialiser le tableau des villes 
Utiise les valeurs connue de wikipeda
*/

int ** init_ville_test(){

    //Nb villes
    int n=4;
    //Matrice
    int ** c;
    //Iterateurs
    int i;

    //Allocation memoire
    c=(int **)malloc(sizeof(int *) * (n+1));
    for(i=1;i<=n;i++){
        c[i]=(int *)malloc(sizeof(int) * (n+1));
    }

    /*Attribution des valeurs couts */
    c[1][1]=0;
    c[1][2]=30;
    c[1][3]=10;
    c[1][4]=20;
    c[2][1]=40;
    c[2][2]=0;
    c[2][3]=30;
    c[2][4]=5;
    c[3][1]=50;
    c[3][2]=10;
    c[3][3]=0;
    c[3][4]=10;
    c[4][1]=10;
    c[4][2]=20;
    c[4][3]=20;
    c[4][4]=0;

    return c;
}