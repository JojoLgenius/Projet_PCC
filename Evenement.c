#include "Evenement.h"


/*Click_suivant
Si le click est sur le bouton suivant
Renvoi 1, sinon 0
*/
int Click_suivant(int x, int y){
    if(
        x > (int)width * (5./100.) &&
        y > (int)height * (9./100.) &&
        x < (int)width * (5./100.) +(int)width * (15./100.) &&
        y < (int)height * (9./100.) +(int)height * (9./100) 
        ){return 1;}
    return 0;        
}

/*Click_choix_ville
Si le click est sur le bouton suivant
Renvoi 1, sinon 0
*/
int Click_choix_ville(int x, int y){

    if(
        x > (int)width * (50./100.) &&
        y > (int)height * (9./100.) &&
        x < (int)width * (50./100.) + (int)width * (40./100.) &&
        y < (int)height * (9./100.) + (int)height * (36./100) 
        ){return 1;}
    return 0;
}

/*Click_choix_algo
Si le click est sur le bouton suivant
Renvoi 1, sinon 0
*/
int Click_choix_algo(int x, int y){

    if(
        x > (int)width * (50./100.) &&
        y > (int)height * (54./100.) &&
        x < (int)width * (50./100.) +  (int)width * (40./100.) &&
        y < (int)height * (54./100.) + (int)height * (36./100) 
        ){return 1;}
    return 0;
}

/*Click_inc
Si le click est sur le bouton inc
Renvoi 1, sinon 0
*/
int Click_inc(int x, int y){

    if(
        x > (int)width * (35./100.) &&
        y > (int)height * (11./100.) &&
        x < (int)width * (35./100.) +  (int)width * (2.5/100.) &&
        y < (int)height * (11./100.) + (int)height * (4.5/100.) 
        ){return 1;}
    return 0;
}

/*Click_dec
Si le click est sur le bouton dec
Renvoi 1, sinon 0
*/
int Click_dec(int x, int y){

    if(
        x > (int)width * (27.5/100.) &&
        y > (int)height * (11./100.) &&
        x < (int)width * (27.5/100.) +  (int)width * (2.5/100.) &&
        y < (int)height * (11./100.) + (int)height * (4.5/100.) 
        ){return 1;}
    return 0;
}

/*Click_charger
Si le click est sur le bouton charger
renvoi 1, sinon 0
*/
int Click_charger(int x, int y){

    if(
        x > (int)width * (27./100.) &&
        y > (int)height * (21./100.) &&
        x < (int)width * (27./100.) +  (int)width * (10./100.) &&
        y < (int)height * (21./100.) + (int)height * (5./100.) 
        ){return 1;}
    return 0;
}


/*MAJ_choix_ville
Renvoie la nouvelle valeur de choix
*/
int MAJ_choix_ville(int choix_ville,int x,int y){

    if(
        x > (int)width * (51./100.) &&
        y > (int)height * (19./100.) &&
        x < (int)width * (51./100.) + (int)width * (2.5/100.) &&
        y < (int)height * (19./100.) + (int)height * (4.5/100)
        ){return WIKIPEDIA;}
    if(
        x > (int)width * (51./100.) &&
        y > (int)height * (25./100.) &&
        x < (int)width * (51./100.) + (int)width * (2.5/100.) &&
        y < (int)height * (25./100.) + (int)height * (4.5/100)
        ){return ALEA_CARRE;}
    if(
        x > (int)width * (51./100.) &&
        y > (int)height * (31./100.) &&
        x < (int)width * (51./100.) + (int)width * (2.5/100.) &&
        y < (int)height * (31./100.) + (int)height * (4.5/100)
        ){return ALEA_CARRE_SYM;}
    if(
        x > (int)width * (51./100.) &&
        y > (int)height * (37./100.) &&
        x < (int)width * (51./100.) + (int)width * (2.5/100.) &&
        y < (int)height * (37./100.) + (int)height * (4.5/100)
        ){return TEST;}
    return choix_ville;
}


/*MAJ_choix_algo
Renvoie la nouvelle valeur de choix
*/
int MAJ_choix_algo(int choix_algo,int x,int y){

    if(
        x > (int)width * (51./100.) &&
        y > (int)height * (64./100.) &&
        x < (int)width * (51./100.) + (int)width * (2.5/100.) &&
        y < (int)height * (64./100.) + (int)height * (4.5/100)
        ){return FOURMI;}
    if(
        x > (int)width * (51./100.) &&
        y > (int)height * (70./100.) &&
        x < (int)width * (51./100.) + (int)width * (2.5/100.) &&
        y < (int)height * (70./100.) + (int)height * (4.5/100)
        ){return TSP_ELAG;}
    if(
        x > (int)width * (51./100.) &&
        y > (int)height * (76./100.) &&
        x < (int)width * (51./100.) + (int)width * (2.5/100.) &&
        y < (int)height * (76./100.) + (int)height * (4.5/100)
        ){return COMP_TSP;}
    
    if(
        x > (int)width * (51./100.) &&
        y > (int)height * (82./100.) &&
        x < (int)width * (51./100.) + (int)width * (2.5/100.) &&
        y < (int)height * (82./100.) + (int)height * (4.5/100)
        ){return COMP_TSP_FOURMI;}
    
    return choix_algo;
}