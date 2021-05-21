#include "DAT_Matrice.h"

/*Fonction aleatoire
permet de tirer un nombre aléatoire entre 0 et RAND_MAX*/

int aleatoire(int max){
  int alea;

  alea=rand()%(max-1)+1;

  return alea;
}


/*
Fonction initialiser_ville
Permet d'intialiser le tableau des villes 
Utiise les valeurs connue de wikipeda
*/

void init_ville_wikipedia(mat_cout * mc){
    
    //Iterateurs
    int i;

    //Nombre de ville
    mc->nb_ville=4;


    if(mc->cv != NULL){
        mc->cv = NULL;
    }

    //Allocation memoire
    mc->cv=(int **)malloc(sizeof(int *) * (mc->nb_ville+1));
    for(i=1; i <= mc->nb_ville; i++){
        mc->cv[i]=(int *)malloc(sizeof(int) * (mc->nb_ville+1));
    }

    /*Attribution des valeurs couts */
    mc->cv[1][1]=0;
    mc->cv[1][2]=4;
    mc->cv[1][3]=3;
    mc->cv[1][4]=1;
    mc->cv[2][1]=4;
    mc->cv[2][2]=0;
    mc->cv[2][3]=1;
    mc->cv[2][4]=2;
    mc->cv[3][1]=3;
    mc->cv[3][2]=1;
    mc->cv[3][3]=0;
    mc->cv[3][4]=5;
    mc->cv[4][1]=1;
    mc->cv[4][2]=2;
    mc->cv[4][3]=5;
    mc->cv[4][4]=0;
}



/*
Fonction initialiser_ville_
Permet d'intialiser le tableau des villes*/

void init_ville_alea(mat_cout * mc, int nb_ville, int max){

    int i,j;

    srand(time(NULL));

    mc->nb_ville = nb_ville;

    if(mc->cv != NULL){
        mc->cv = NULL;
    }

    
    //Allocation memoire
    mc->cv=(int **)malloc(sizeof(int *) * (mc->nb_ville+1));
    for(i=1; i <= mc->nb_ville; i++){
        mc->cv[i]=(int *)malloc(sizeof(int) * (mc->nb_ville+1));
    }
  
    for(i=1;i <= nb_ville; i++){
        for(j=1;j <= nb_ville; j++){
            if(i == j){
                mc->cv[i][j]=0;
            }
            else{
                mc->cv[i][j]=aleatoire(max);
            }
        }
    }
}

/*
  Fonction initialiser_ville_
  Permet d'intialiser le tableau des villes en forme matrice carre*/

void init_ville_alea_sym(mat_cout * mc, int nb_ville, int max){
    int i,j;

    srand(time(NULL));

    mc->nb_ville = nb_ville;

    if(mc->cv != NULL){
        mc->cv = NULL;
    }

    
    //Allocation memoire
    mc->cv=(int **)malloc(sizeof(int *) * (mc->nb_ville+1));
    for(i=1; i <= mc->nb_ville; i++){
        mc->cv[i]=(int *)malloc(sizeof(int) * (mc->nb_ville+1));
    }
  
    for(i=1;i <= nb_ville; i++){
        for(j=1;j <= nb_ville; j++){
            if(i == j){
                mc->cv[i][j]=0;
            }
            else if(j > i){
                mc->cv[i][j]=aleatoire(max);
            }
            else{
                mc->cv[i][j]= mc->cv[j][i];  
            }
        }
    }
}

/*
  Fonction initialiser_ville_test
  Permet d'intialiser le tableau de cout villes en fonction de tabpoints
Utilise les distances euclidiennes
*/
void init_ville_test(mat_cout * mc, tabpoints t){
      //Iterateurs
    int i,j;
    printf("t = %d", t.nb_point);
    //Nombre de ville
    mc->nb_ville = t.nb_point;


    if(mc->cv != NULL){
        mc->cv = NULL;
    }

    //Allocation memoire
    mc->cv=(int **)malloc(sizeof(int *) * (mc->nb_ville+1));
    for(i=1; i <= mc->nb_ville; i++){
        mc->cv[i]=(int *)malloc(sizeof(int) * (mc->nb_ville+1));
    }
    for(i=1;i <= mc->nb_ville; i++){
        for(j=1;j <= mc->nb_ville; j++){
            //Calcul distance euclidienne
            //racine(carre(x2-x1)+carre(y2-y1))
            
            mc->cv[i][j] = (int) ((sqrt(pow((t.tabp[j].x-t.tabp[i].x), 2.) + pow((t.tabp[j].y - t.tabp[i].y), 2.))) * 100);
            //(*100 permet de convertir le float < 1 en entier)
        }
    }

    
}



/*Tableau de point pour charger fichier*/


/*chargement de fichier
  Stocke dans un tableau les valeurs d'un fichier
*/
void chargement_fichier(tabpoints * t, char *nomfichier){
    int i;
    int nb_elem;
    
    FILE* fichier = NULL;

    fichier = fopen(nomfichier,"r");
    if (fichier == NULL) {
        printf("impossible d'ouvrir le fichier\n");
    }
    else{
        if(fscanf(fichier,"%d",&nb_elem));
        else{printf("erreur fscanf\n");};

        t->nb_point = nb_elem;

        //On realloue la taille du tableau de point
        free(t->tabp);
        t->tabp=NULL;
        t->tabp = (struct point *)malloc(sizeof(struct point) * (nb_elem+1));
        if(t->tabp == NULL){
            printf("Erreur alloc t->tabp (DAT_MAtrice.c)\n");
            exit(0);
        }
            
        //Affichage de chaques points
        for (i=1; i <= nb_elem; i++) { 
            if(fscanf(fichier,"%lf %lf",&(t->tabp[i].x), &(t->tabp[i].y)));
            else{printf("erreur fscanf\n");};
        }

        fclose(fichier);
    }
}