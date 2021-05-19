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

//Variable globale

int nb_iteration;

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