#include "DAT_Matrice.h"

/*Fonction aleatoire
permet de tirer un nombre aléatoire entre 0 et RAND_MAX*/

int aleatoire(int max){
  int alea;

  alea=rand()%(max-1)+1;

  return alea;
}


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


    if(mc->cv != NULL){
        mc->cv = NULL;
    }

   

    //Allocation memoire
    mc->cv=(int **)malloc(sizeof(int *) * (mc->nb_ville+1));
    for(i=1; i <= mc->nb_ville; i++){
        mc->cv[i]=(int *)malloc(sizeof(int) * (mc->nb_ville+1));
    }

    /*Attribution des valeurs couts */
    mc->cv[1][1]=0;
    mc->cv[1][2]=4;
    mc->cv[1][3]=3;
    mc->cv[1][4]=1;
    mc->cv[2][1]=4;
    mc->cv[2][2]=0;
    mc->cv[2][3]=1;
    mc->cv[2][4]=2;
    mc->cv[3][1]=3;
    mc->cv[3][2]=1;
    mc->cv[3][3]=0;
    mc->cv[3][4]=5;
    mc->cv[4][1]=1;
    mc->cv[4][2]=2;
    mc->cv[4][3]=5;
    mc->cv[4][4]=0;
}



/*
Fonction initialiser_ville_
Permet d'intialiser le tableau des villes*/

void init_ville_alea(mat_cout * mc, int nb_ville, int max){

    int i,j;

    srand(time(NULL));

    mc->nb_ville = nb_ville;

    if(mc->cv != NULL){
        mc->cv = NULL;
    }

    
    //Allocation memoire
    mc->cv=(int **)malloc(sizeof(int *) * (mc->nb_ville+1));
    for(i=1; i <= mc->nb_ville; i++){
        mc->cv[i]=(int *)malloc(sizeof(int) * (mc->nb_ville+1));
    }
  
    for(i=1;i <= nb_ville; i++){
        for(j=1;j <= nb_ville; j++){
            if(i == j){
                mc->cv[i][j]=0;
            }
            else{
                mc->cv[i][j]=aleatoire(max);
            }
        }
    }
}