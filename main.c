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
    //init_ville_alea(&mcv, 11, 10);
    
    for(i=1;i<= mcv.nb_ville; i++){
        for(j=1; j<= mcv.nb_ville; j++){
            printf("%3d | ",mcv.cv[i][j]);  
        }
        printf("\n");
    }

    /*Test sur terminal*/
    printf("\nDebut\n");

    initialiser_meilleure(&meilleure,mcv);
    nb_iteration=0;
    fourmi(&meilleure,mcv, 10, 1, 1, 0.5);

    printf("\n\nRésultat :\n %d itérations \n",nb_iteration);
    info_solution(meilleure, mcv.nb_ville);

    free(meilleure.ordre);
    
    initialiser_partielle(&partielle, mcv.nb_ville);
    initialiser_meilleure(&meilleure,mcv);
    nb_iteration=0;
    tsp_elag_naive(partielle,&meilleure,mcv);

    printf("\n\nRésultat :\n %d itérations \n",nb_iteration);
    info_solution(meilleure, mcv.nb_ville);

    free(meilleure.ordre);
    free(partielle.ordre);

    printf("\nWait\n");

    initialiser_partielle(&partielle, mcv.nb_ville);
    initialiser_meilleure(&meilleure,mcv);
    nb_iteration=0;
    tsp_naive(partielle, &meilleure, mcv);
    
    printf("\n\nRésultat :\n %d itérations \n",nb_iteration);
    info_solution(meilleure, mcv.nb_ville);

    /*Debut MLV*/

    /*Liberation memoire*/
    free(meilleure.ordre);
    free(partielle.ordre);
    free(mcv.cv);

    return EXIT_SUCCESS;
}