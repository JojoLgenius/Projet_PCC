#ifndef TSP_NAIVE_H_
#define TSP_NAIVE_H_


#include"global.h"

/*Initialise la meilleure solution*/
void initialiser_meilleure(solution * meilleure, mat_cout mc);
/*Initialise la solution partielle*/
void initialiser_partielle(solution * partielle, int nb_ville);


/*Renvoi 1 si x appartient a liste*/
int appartient(int x, int * liste, int nb_ville);


/*TSP_elag_naive*/
void tsp_elag_naive(solution partielle, solution * meilleure, mat_cout mc);


#endif