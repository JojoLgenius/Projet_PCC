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
    mat_cout mcv;

    /*
    int ** cv = NULL;
    //Nombre de ville
    int nb_ville=4;
    */

    
    //Solution
    solution meilleure; 
    solution partielle;


    /*Initialisation*/
    init_ville_test(&mcv);
    
    for(i=1;i<=4;i++){
        for(j=1;j<=4;j++){
            printf("%3d | ",mcv.cv[i][j]);  
        }
        printf("\n");
    }

    /*Test sur terminal*/
    printf("\nDebut\n");
    
    initialiser_partielle(&partielle, mcv.nb_ville);
    initialiser_meilleure(&meilleure,mcv);

    tsp_elag_naive(partielle,&meilleure, mcv);

    printf("\n\nRésultat :\n");
    info_solution(meilleure, mcv.nb_ville);

    /*Debut MLV*/

    /*Liberation memoire*/
    free(mcv.cv);

    return EXIT_SUCCESS;
}