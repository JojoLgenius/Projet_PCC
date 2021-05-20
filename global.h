#ifndef GLOBAL_H_
#define GLOBAL_H_

//Include

#include<stdio.h>
#include<stdlib.h>
#include<MLV/MLV_all.h>
#include<time.h>
#include<math.h>

//Define
#define Q 1 //(Fourmi.h :-> maj_phero)
#define Y 2 //(Fourmi.h :-> fourmi)
#define PREM_VILLE 1 //(Fourmi.h :-> fourmi)

//Etat du programme
#define EN_COURS 1
#define FIN 0

//Choix_ville
#define WIKIPEDIA 1
#define ALEA_N_CARRE 2
#define ALEA_CARRE 3

//Fenetre
#define MENU 1
#define FOURMI 2
#define TSP_ELAG 3
#define COMP_TSP 4
#define COMP_TSP_FOURMI 5

//Variable globale

int nb_iteration;

//MLV
int width;
int height;

//Structures



//Solution pour TSP
typedef struct{
  int t;
  int * ordre;
  int cout;    
}solution;

//Stock un nombre de ville et une matrice
typedef struct{
    int nb_ville;
    int ** cv;
}mat_cout;


#endif