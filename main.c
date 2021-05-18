#include "global.h"
#include "DAT_Matrice.h"
#include "TSP_Naive.h"
#include "Fourmi.h"
#include "Affichage.h"

int main(){

    /* Definitions variables */
    //Iterateur
    int i,j;
    //Matrice des couts
    int ** cv = NULL;
    //Nombre de ville
    int nb_ville=4;
    //Solution
    solution meilleure; 
    solution partielle;


    /*Initialisation*/
    cv=init_ville_test();
    
    for(i=1;i<=4;i++){
        for(j=1;j<=4;j++){
            printf("%3d | ",cv[i][j]);  
        }
        printf("\n");
    }

    /*Test sur terminal*/
    printf("\nDebut\n");
    
    initialiser_partielle(&partielle, nb_ville);
    initialiser_meilleure(&meilleure,nb_ville, cv);

    tsp_elag_naive(partielle,&meilleure, nb_ville, cv);

    printf("\n\nRésultat :\n");
    info_solution(meilleure, nb_ville);

    /*Debut MLV*/

    /*Liberation memoire*/
    free(cv);

    return EXIT_SUCCESS;
}