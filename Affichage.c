#include "Affichage.h"

/*----------------------*/
/*  Affichage terminal  */
/*----------------------*/

/*Fonction affiche_liste
  Permet d'afficher une liste d'entier donné en paramètre
*/

void affiche_liste(int *liste, int nb_ville){
    int i;

    printf("[");
    for(i=1;i<nb_ville;i++){
        printf("%d,",liste[i]);
    }
    printf("%d]\n",liste[i]);

}

/*Fonction info_solution
  Permet d'afficher les informations d'une solution donnée en paramètre
*/
void info_solution(solution s, int nb_ville){

    printf("--------------------\n");
    printf("Nombre de ville: %d\n",s.t);
    printf("Ordre de visite des villes : ");
    affiche_liste(s.ordre, nb_ville);
    printf("Cout finale: %d\n",s.cout);
    printf("--------------------\n");

}