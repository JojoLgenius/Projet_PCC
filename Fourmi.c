#include "Fourmi.h"


/*Fonction aleatoire
  permet de tirer un nombre aléatoire entre 0 et RAND_MAX
*/

float float_aleatoire(){
    int alea;
    float res;

    alea=rand()%(9999+1);

    res = alea/(float)10000;

    return res;
}


/* Fonction initialiser_phero
   Permet d'intialiser le tableau des pheromones
*/
void init_phero(float ** phero, int nb_ville){

    int i,j;
  
    for(i=1; i <= nb_ville; i++){
        for(j=1; j<= nb_ville; j++){
            phero[i][j]=(float)0;
        }
    }
}

/* Init_visite
   Permet d'initialiser a 0 le tableau visite
*/
void init_visite(float * visite, int nb_ville){
    int i;

    for(i=1; i <= nb_ville; i++){
        visite[i]= (float)0;
    }
}




/*----------------------------------*/

/*Fonction calc_chance
Recupere :
> * visite;  -> tableau des ville à visiter de puis en_cours
> en_cours;  -> ville dans laquelle on se situe
>constante y;-> LA valeur Y du calcul
>pondere_a;  -> Importance de taux de pheromone
>pondere_b;  -> Importance de distance
>nb_villes;  -> Nombre d eville pour boucle for
*/

void calc_chance(mat_cout mc, float * visite, float ** phero, int en_cours, int pondere_a, int pondere_b){

    //Iterateur
    int i;
    //Resultat
    float total = (float)0;

    
    //Boucle pour calculer le total (denominateur)
    for(i=1; i <= mc.nb_ville; i++){
        if(visite[i]>=0){
            visite[i]=((float)Y + powf(phero[en_cours][i], (float)pondere_a)) * powf((float)1 / (float)(mc.cv[en_cours][i]), (float)pondere_b);
            total += visite[i];           
        }
    }

    
    //Boucle pour calculer chaque valeur de visite[i] (numerateur)
    for(i=1; i<= mc.nb_ville; i++){
        if(visite[i] >= 0){
            if(total == (float)0){
                printf("Erreur total = 0 \n");
                exit(0);
            }
            visite[i] = visite[i]/total;
            //Verif
            //printf("Calc_chance : visite[%d]=%f\n",i,visite[i]);
        }
    }
    
}


/*choix_ville
Permet de choisir la prochaine ville (utilise une variable aleatoire)
parametre:
----------
> * visite;
> nb_ville;
*/
int choix_ville(float * visite, int nb_ville){

    int i;
    float falea;

    falea=float_aleatoire();
    //Si alea = 1.0000 probleme lors de la comparaison 0.0 == 0.0
    //Alea appartient a [0.0 - 0.9999];
    for(i=1;i<=nb_ville;i++){
        if(visite[i] >= (float)0){
            falea -= visite[i];
            printf("\n i=%d -- alea=%f\n",i,falea);
            if(falea < (float)0){
                return i;
            }
        }
    }
    //Si un probleme survient
    printf("Erreur lors du choix de la ville\n");
    exit(0);
    //return 0;
}



/*maj_phero
Permet de mettre à jour la matrice des pheromones
paramertre : 
-----------
>fourmi; -> Contient la longueur (cout totale) du trajet final
         -> l'ordre de trajet
>nb_ville-> permet de connaitre le nombre de ville (boucle)

constante:
----------
> Q; -> ciontenu dans define (global.h)
*/
void maj_phero(solution fourmi, float ** phero ,int nb_ville){
    int i;
    //printf("Chemin : [");
    
    //Boucle sur l'odre de la solution & parcours matrice phero
    for(i=1;i<nb_ville;i++){
        //printf("%d,",fourmi.ordre[i]);
        phero[fourmi.ordre[i]][fourmi.ordre[i+1]] += ((float)Q/(float)fourmi.cout);
    }
    //printf("%d]\n",fourmi.ordre[i]);
    //Chemin entre arrivee et depart
    phero[fourmi.ordre[i]][fourmi.ordre[1]] += ((float)Q/(float)fourmi.cout);
}

/*red_phero
Permet de reduire le taux de pheromone d'un certain pourcentage
chaque iteration
parametre:
----------
>p;        -> proportionn de pheronomone qui s'evaporent
>nb_ville; -> permet de naviguer dans la matrice (boucles)
*/
void red_phero(float ** phero, float p, int nb_ville){
    int i,j;
    
    for(i=1;i<=nb_ville;i++){
        for(j=1;j<=nb_ville;j++){
            phero[i][j]-=(phero[i][j]*p);
        }
    }   
}


/*
Fourmi
Calcule le PCC avec l'algorithme des fourmi
 Parametre :
------------
> mat_cout mc   -> Matrice de cout des villes + Nombre de ville
> int nb_fourmi -> Nombre de fourmi (nb d'iterations)
> int nb_ville  -> Nombre de ville (Pour les parcours)
> int pondere_a -> Importance des pheromones dans le calcul
> int pondere_b -> Importance de la distance dans le calcul
> float p       -> Proportion de pheromone qui s'evaporent
*/
void fourmi(solution * meilleure, mat_cout mc, int nb_fourmi, int pondere_a, int pondere_b, float p){

    /*Variables*/
    float ** phero = NULL;
    float * visite = NULL; //Contient proba + si < 0.0 deja visite

    int en_cours = PREM_VILLE; //Ville a la position actuelle
    int i,j; //Iterateurs

    solution fourmi; //Ordre et cout final de chaque iterations

    //Allocation
    phero = (float **)malloc(sizeof(float *) * (mc.nb_ville+1));
    if(phero == NULL){
        printf("Erreur malloc phero (Fourmi.h/fourmi)\n");
        exit(0);
    }
    for(i=1; i <= mc.nb_ville; i++){
        phero[i]=(float *)malloc(sizeof(float ) * (mc.nb_ville+1));
        if(phero[i] == NULL){
            printf("Erreur malloc phero[%d](Fourmi.h/fourmi)\n",i);
            exit(0);
        }
    }

    
    /*Initialisation des matrices*/
    init_phero(phero, mc.nb_ville);

    //Iteration pour le nombre de fourmi demande
    for(i=1; i <= nb_fourmi; i++){

        printf("Fourmi n°%d\n",i);
        //Allocations memoire
        visite=(float *)malloc(sizeof(float) * (mc.nb_ville+1));
        if(visite == NULL){
            printf("Erreur malloc visite (Fourmi.h/fourmi)\n");
            exit(0);
        }

        fourmi.ordre = NULL;
        fourmi.ordre = (int *)malloc(sizeof(int) * (mc.nb_ville+1));
        if(fourmi.ordre == NULL){
            printf("Erreur malloc fourmi.ordre (Fourmi.h/fourmi)\n");
            exit(0);
        }
 
        //initialise visite
        init_visite(visite, mc.nb_ville);
        
        red_phero(phero, p, mc.nb_ville);//Les pheromones s'evapore (mettre en fin)
                    
        visite[PREM_VILLE] = (float)-1;//La premiere ville est considéré comme visitée
       
        en_cours=PREM_VILLE;//On commence par la premiere ville
        //Verif
        //printf("Fourmi n°%d(itérations)\n\n",i);
        fourmi.ordre[1]=en_cours;//Ordre commence par PREM_VILLE
        
        //On explore les villes suivantes
        for(j=PREM_VILLE+1; j <= mc.nb_ville; j++){
            //Calcule des chances
            calc_chance(mc,visite,phero,en_cours,pondere_a,pondere_b);
            //Modif ville actuel pour choix
            en_cours=choix_ville(visite,mc.nb_ville);
            
            //Add ordre + cout de (solution)fourmi
            fourmi.ordre[j]=en_cours;
            fourmi.cout=mc.cv[fourmi.ordre[j-1]][fourmi.ordre[j]];

            //LA ville actuelle ne peut plus etre visitee
            visite[en_cours]=(float)(-1);
            //Verif
            //printf("ville n°%d -> choix_ville= %d\n",j,en_cours);
        }
        //Cout du retour a PREM_VILLE
        fourmi.cout = mc.cv[fourmi.ordre[j-1]][fourmi.ordre[1]];
        //Ajout des pheromones
        maj_phero(fourmi, phero, mc.nb_ville);

        //Libere la visite
        free(visite);
        free(fourmi.ordre);
    }


    //Libere la matrice de phero
    
    free(phero);
}
