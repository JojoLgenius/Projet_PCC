#ifndef AFFICHAGE_H_
#define AFFICHAGE_H_


#include "global.h"

/*----------------------*/
/*  Affichage Terminal  */
/*----------------------*/

/*Affiche la liste*/
void affiche_liste(int *liste, int nb_ville);
/*Affiche les informations de la solution*/
void info_solution(solution s, int nb_ville);



/*-----------------*/
/*  Affichage MLV  */
/*-----------------*/

/*Affiche une coche*/
void check(int x, int y,char * titre);
/*Affiche le menu*/
void menu();
/*Bouton suivant ssi les options sont selectionnée*/
void bouton_suivant_menu(int choix_ville, int choix_algo);
/*Permet de remplir les coches*/
void remplir_coche(int choix_ville, int choix_algo);


#endif