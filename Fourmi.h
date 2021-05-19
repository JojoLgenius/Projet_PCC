#ifndef FOURMI_H_
#define FOURMI_H_


#include"global.h"


/*Permet de generer un nb*/
// [0.0000 - 0.9999]
float float_aleatoire();

/*Initialisations*/

/*Matrice des pheromones*/
// all = 0.0
void init_phero(float ** phero, int nb_ville);
/* Tableau des visites restantes */
// all = 0.0 (si < 0.0 : ne pas visiter)
void init_visite( float * visite, int nb_ville);

/*Fonctions*/

/*Calcul de probabilite des prochaines villes*/
//MAJ tableau visite
void calc_chance(mat_cout mc,float * visite, float ** phero ,int en_cours,int pondere_a, int pondere_b);
/*Choisi la prochaine ville*/
//(Utilise float_aleatoire())
int choix_ville(float * visite, int nb_ville);
/*MAJ matrice phero en fonction de la solution*/
void maj_phero(solution fourmi, float ** phero ,int nb_ville);
/*MAJ matrice phero en reduisant les elements*/
void red_phero(float ** phero, float p,int nb_ville);

/*Algorithme des fourmis*/
void fourmi(solution * meilleure, mat_cout mc, int nb_fourmi, int pondere_a, int pondere_b, float p);


#endif