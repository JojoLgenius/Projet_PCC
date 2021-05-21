#ifndef EVENEMENT_H_
#define EVENEMENT_H_


#include "global.h"

/*Renvoi 1 si le click est sur suivant*/
int Click_suivant(int x, int y);
/*Renvoi 1 si le click est dans choix_ville*/
int Click_choix_ville(int x, int y);
/*Renvoi 1 si le click est dans choix_algo*/
int Click_choix_algo(int x, int y);
/*Renvoi 1 si le click est sur inc*/
int Click_inc(int x, int y);
/*Renvoi 1 si le click est sur dec*/
int Click_dec(int x, int y);
/*Renvoi 1 si le click est sur charger*/
int Click_charger(int x, int y);
/*Renvoi 1 si le click est sur retour_menu*/
int Click_retour_menu(int x, int y);
/*Renvoi 1 si le click est sur executer*/
int Click_executer(int x, int y);

/*
Click dans FOURMI
*/
//Nb_fourmi
int Click_inc_nb_fourmis(int x, int y);
int Click_dec_nb_fourmis(int x, int y);
//Pondere_a
int Click_inc_pondere_a(int x, int y);
int Click_dec_pondere_a(int x, int y);
//Pondere_b
int Click_inc_pondere_b(int x, int y);
int Click_dec_pondere_b(int x, int y);
//p
int Click_inc_p(int x, int y);
int Click_dec_p(int x, int y);

/*Gere les mise a jour en fonction des clicks*/
int MAJ_choix_ville(int choix_ville,int x,int y);
int MAJ_choix_algo(int choix_algo,int x,int y);


#endif