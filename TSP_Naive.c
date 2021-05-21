#include "TSP_Naive.h"




/*
  Fonction initialiser_partielle
  Permet d'intialiser la solution partielle de départ*/

void initialiser_partielle(solution * partielle, int nb_ville){

    int i;
    
    partielle->ordre=NULL;
    
    partielle->ordre=(int *)malloc(sizeof(int) * (nb_ville+1));
    if(partielle->ordre == NULL){
        printf("Erreur allocation partielle.ordre dans TSP_naive.c\n");
        exit(0);
    }
  
    partielle->t = 1;
    partielle->ordre[1] = 1;
    for(i=2; i<= nb_ville; i++){
        partielle->ordre[i] = 0;
    }
    partielle->cout = 0;

}
/*
  Fonction initialiser_meilleur
  Permet d'intialiser la meilleure solution de départ*/

void initialiser_meilleure(solution * meilleure,  mat_cout mc){

    //Iterateur
    int i;

    
    meilleure->ordre=NULL;
    meilleure->ordre=(int *)malloc(sizeof(int) * (mc.nb_ville+2));
    if(meilleure->ordre == NULL){
        printf("Erreur allocation meilleure.ordre dans TSP_naive.c\n");
        exit(0);
    }
  
    meilleure->t = mc.nb_ville;
    meilleure->cout = 0;
  
    for(i=1;i<= mc.nb_ville;i++){
        meilleure->ordre[i] = i;
        if(i>1){
            meilleure->cout += mc.cv[i-1][i];
        }
    }
    meilleure->cout += mc.cv[mc.nb_ville][1];
  
}








/*Fonction appartient
Permet de verifier si un entier donné appartient à une liste donnée
retourne 1 si oui, 0 sinon.
*/

int appartient(int x, int * liste, int nb_ville){
  int i;

  for(i=1;i<=nb_ville;i++){
    if(x==liste[i]){
      return 1;
    }
  }
  return 0;
}




/*---------------------------------------------------------------*/
/*---------------------------------------------------------------*/


/*Fonction tsp_naive
  Traduction de l'algorithme donné en language c
*/

void tsp_naive(solution partielle, solution *meilleure, mat_cout mc){

    int cout_fin,i,j;
    int ordre;
    solution Ns;

    initialiser_partielle(&Ns, mc.nb_ville);
  
    /*Si toute les villes ont été visitées, on calcule le cout de la dernière ville jusqu'a la ville initiale*/
    if(partielle.t == meilleure->t){

        cout_fin = partielle.cout;
        ordre = partielle.ordre[mc.nb_ville];
        cout_fin += mc.cv[ordre][1];
        
        /*si le cout total < meilleure : meilleure = partielle*/
        if(cout_fin < meilleure->cout){
            for(i=1;i <= mc.nb_ville;i++){
                meilleure->ordre[i] = partielle.ordre[i];
            }
            meilleure->cout = cout_fin;
        }
    }

  
    /*Sinon on ajoute une ville à visiter qui n'est pas présente dans la solution partielle, puis on relance la fonction tsp_naive (réccursive) en utilisant une nouvelle solution (Ns) afin de ne pas avoir de problème de boucle infinie*/  
    else{
        for(i=1;i<=mc.nb_ville;i++){   
            if(appartient(i,partielle.ordre, mc.nb_ville) == 0){
                
	
                /*On copie la nouvelle solution depuis la solution partielle*/
                Ns.t = partielle.t;
                for(j=1;j<= mc.nb_ville;j++){
                    Ns.ordre[j] = partielle.ordre[j];
                }
                Ns.cout = partielle.cout;
                /*Fin de copie*/

                    
                Ns.t++;
                Ns.ordre[Ns.t] = i;
                Ns.cout += mc.cv[Ns.ordre[Ns.t-1]][i];
                tsp_naive(Ns,meilleure,mc);
                
            }     
        }
    }
    free(Ns.ordre);

    nb_iteration++;
}




















/*Fonction tsp_elag_naive
  Traduction de l'algorithme donné en language c
  
*/

void tsp_elag_naive(solution partielle, solution *meilleure, mat_cout mc){

    int cout_fin,i,j;
    int ordre;
    solution Ns;
    
    initialiser_partielle(&Ns, mc.nb_ville);
  
    /*Si toute les villes ont été visitées, on calcule le cout de la dernière ville jusqu'a la ville initiale*/
    if(partielle.t == meilleure->t){
        cout_fin = partielle.cout;
        ordre = partielle.ordre[mc.nb_ville];
        cout_fin += mc.cv[ordre][1];
        
        /*si le cout total < meilleure : meilleure = partielle*/
        if(cout_fin < meilleure->cout){
            for(i=1;i <= mc.nb_ville;i++){
                meilleure->ordre[i] = partielle.ordre[i];
            }
            meilleure->cout = cout_fin;
        }
    }

  
    /*Sinon on ajoute une ville à visiter qui n'est pas présente dans la solution partielle, puis on relance la fonction tsp_naive (réccursive) en utilisant une nouvelle solution (Ns) afin de ne pas avoir de problème de boucle infinie*/  
    else{
        for(i=1;i<=mc.nb_ville;i++){
            if(appartient(i,partielle.ordre, mc.nb_ville) == 0){
                
                cout_fin = partielle.cout;
                ordre = partielle.ordre[partielle.t];
                cout_fin += mc.cv[ordre][i];
	
                /*
                  /!\ Condition supplémentaire par rapport a la version 1/!\
                */
                if(cout_fin < meilleure->cout){
                    /*On copie la nouvelle solution depuis la solution partielle*/
                    Ns.t = partielle.t;
                    for(j=1;j<= mc.nb_ville;j++){
                        Ns.ordre[j] = partielle.ordre[j];
                    }
                    Ns.cout = partielle.cout;
                    /*Fin de copie*/

                    
                    Ns.t++;
                    Ns.ordre[Ns.t] = i;
                    Ns.cout += mc.cv[Ns.ordre[Ns.t-1]][i];
                    tsp_elag_naive(Ns,meilleure,mc);
                }
            }     
        }
    }
    free(Ns.ordre);

    nb_iteration++;
}
