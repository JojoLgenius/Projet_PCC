#ifndef AFFICHAGE_H_
#define AFFICHAGE_H_


#include "global.h"

/*----------------------*/
/*  Affichage Terminal  */
/*----------------------*/

/*Affiche une matrice (int/float)*/
void affiche_matrice(int ** matint, float ** matfloat, int max);
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
/*Affiche le nombre de ville*/
void affiche_n(int n);
/*Afficher bouton plus/moins pour regler ville*/
void affiche_inc_dec();
/*Affiche un bouton pour charger*/
void affiche_charger();
/*Affiche un chemin (charger)*/
void affiche_chemin(char * chemin);


//Affichage cout ville

/*Affichage pour mode wikipedia*/
void affiche_pt_wikipedia();
/*Affichage pour mode TEST*/
void affiche_pt_test(tabpoints t);


#endif