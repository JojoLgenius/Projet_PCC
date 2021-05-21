#include "Affichage.h"

/*----------------------*/
/*  Affichage terminal  */
/*----------------------*/

/*Affiche_matrice()
Permet d'afficher une matrice passée en parametre
Soit de type float soit de type int
Une seule matrice possible
Remplir par NULL la matrice non utilise
*/
void affiche_matrice(int ** matint, float ** matfloat, int max){
    int i,j;
    if(matint!=NULL){
        printf("Affichage matrice int (cout des villes)\n");
    }
    else{
        printf("Affichage matrice float (pheromones)\n");
    }
    printf("\n     |");
    for(i=1;i<max+1;i++){
        printf("%4d ",i);
    }
    printf("\n-----+");
    for(i=1;i<max+1;i++){
        printf("-----");
    }
    printf("+\n");
    for(i=1;i<max+1;i++){
        printf("%4d |",i);
        for(j=1;j<max+1;j++){
            if(matint!=NULL){
                printf("%4d ",matint[i][j]);
            }
            else{
                printf("%.2f ",matfloat[i][j]); 
            }
        }
        printf("|\n");
    }
    printf("-----+");
    for(i=1;i<max+1;i++){
        printf("-----");
    }
    printf("+\n"); 
}

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





/*-----------------*/
/*  Affichage MLV  */
/*-----------------*/

void check(int x, int y,char * titre){
    //taille = 2.5% de la hauteur
    MLV_Font * police2 = MLV_load_font(
        "Police/Ubuntu-B.ttf",
        (int)(height * (2.5/100.)));

    
    MLV_draw_rectangle(
        x,
        y,
        (int)width * (2.5/100.),
        (int)height * (4.5/100),
        MLV_COLOR_WHITE
        );
    MLV_draw_text_with_font(
        x + (int)width * (4./100.),
        y + (int)height * (1./100),
        titre,police2,
        MLV_COLOR_WHITE
        );

    MLV_free_font(police2);
}

void menu(){

    //taille = 4% de la hauteur
    MLV_Font * police = MLV_load_font(
        "Police/Ubuntu-B.ttf",
        (int)(height * (4./100.)));

    //Contient villes
    MLV_draw_rectangle(
        (int)width * (5./100.),
        (int)height * (36./100.),
        (int)width * (30./100.),
        (int)height * (54./100),
        MLV_COLOR_WHITE
        );

    //Checkbox disposition villes
    MLV_draw_rectangle(
        (int)width * (50./100.),
        (int)height * (9./100.),
        (int)width * (40./100.),
        (int)height * (36./100),
        MLV_COLOR_WHITE
        );
    MLV_draw_text_box_with_font(
        (int)width * (50./100.),
        (int)height * (9./100.),
        (int)width * (40./100.),
        (int)height * (9./100),
        "Dispositions des villes",police,1,
        MLV_COLOR_WHITE,MLV_COLOR_BLACK,MLV_COLOR_WHITE,
        MLV_TEXT_CENTER,
        MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);

   check(
        (int)width * (51./100.),
        (int)height * (19./100.),
        "Mode Wikipedia"
        );
    check(
        (int)width * (51./100.),
        (int)height * (25/100.),
        "Mode aleatoire carré"
        );
    check(
        (int)width * (51./100.),
        (int)height * (31./100.),
        "Mode aleatoire carré symetrique"
        );
    check(
        (int)width * (51./100.),
        (int)height * (37./100.),
        "Mode Test (.txt)"
        );
    


        //Checkbox choix Algo
    MLV_draw_rectangle(
        (int)width * (50./100.),
        (int)height * (54./100.),
        (int)width * (40./100.),
        (int)height * (36./100),
        MLV_COLOR_WHITE
        );
    MLV_draw_text_box_with_font(
        (int)width * (50./100.),
        (int)height * (54./100.),
        (int)width * (40./100.),
        (int)height * (9./100),
        "Choix de l'algorithme",police,1,
        MLV_COLOR_WHITE,MLV_COLOR_BLACK,MLV_COLOR_WHITE,
        MLV_TEXT_CENTER,
        MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER
        );

    check(
        (int)width * (51./100.),
        (int)height * (64./100.),
        "Fourmi"
        );
    
    check(
        (int)width * (51./100.),
        (int)height * (70./100.),
        "TSP Elag Naive"
        );
    check(
        (int)width * (51./100.),
        (int)height * (76./100.),
        "Comparaison des TSP"
        );
    check(
        (int)width * (51./100.),
        (int)height * (82./100.),
        "Comparaison de Fourmi et TSP"
        );


    MLV_actualise_window();

    /*On libere la police utilise*/
    MLV_free_font(police);
    
}

/*Affiche le bouton suivant d epuis le menu*/
void bouton_suivant_menu(int choix_ville, int choix_algo){

        //taille = 4% de la hauteur
    MLV_Font * police = MLV_load_font(
        "Police/Ubuntu-B.ttf",
        (int)(height * (4./100.)));
    
    if(choix_ville > 0 && choix_algo > 0){
        /*Bouton suivant*/
        MLV_draw_text_box_with_font(
            (int)width * (5./100.),
            (int)height * (9./100.),
            (int)width * (15./100.),
            (int)height * (9./100),
            "Suivant",police,1,
            MLV_COLOR_GREY,MLV_COLOR_BLACK,MLV_COLOR_WHITE,
            MLV_TEXT_CENTER,
            MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER
            );
    }

    /*Libere police*/
    MLV_free_font(police);
}

/*Permet de remplir les coches*/
void remplir_coche(int choix_ville, int choix_algo){
    switch(choix_ville){
    case 1:
        MLV_draw_filled_rectangle(
            (int)width * (51.2/100.),
            (int)height * (19.5/100.),
            (int)width * (2./100.),
            (int)height * (3.6/100),
            MLV_COLOR_WHITE
            );
        break;
    case 2:
        MLV_draw_filled_rectangle(
            (int)width * (51.2/100.),
            (int)height * (25.5/100.),
            (int)width * (2./100.),
            (int)height * (3.6/100),
            MLV_COLOR_WHITE
            );
        break;
    case 3:
        MLV_draw_filled_rectangle(
            (int)width * (51.2/100.),
            (int)height * (31.4/100.),
            (int)width * (2./100.),
            (int)height * (3.6/100),
            MLV_COLOR_WHITE
            );
        break;
    case TEST:
        MLV_draw_filled_rectangle(
            (int)width * (51.2/100.),
            (int)height * (37.4/100.),
            (int)width * (2./100.),
            (int)height * (3.6/100),
            MLV_COLOR_WHITE
            );
        break;
    default:
        printf("Choix_ville n'est pas valide \n");
        break;
    }

    switch(choix_algo){
    case FOURMI:
        MLV_draw_filled_rectangle(
            (int)width * (51.2/100.),
            (int)height * (64.5/100.),
            (int)width * (2./100.),
            (int)height * (3.6/100),
            MLV_COLOR_WHITE
            );
        break;
    case TSP_ELAG:
        MLV_draw_filled_rectangle(
            (int)width * (51.2/100.),
            (int)height * (70.5/100.),
            (int)width * (2./100.),
            (int)height * (3.6/100),
            MLV_COLOR_WHITE
            );
        break;
    case COMP_TSP:
        MLV_draw_filled_rectangle(
            (int)width * (51.2/100.),
            (int)height * (76.4/100.),
            (int)width * (2./100.),
            (int)height * (3.6/100),
            MLV_COLOR_WHITE
            );
        break;
    case COMP_TSP_FOURMI:
        MLV_draw_filled_rectangle(
            (int)width * (51.2/100.),
            (int)height * (82.4/100.),
            (int)width * (2./100.),
            (int)height * (3.6/100),
            MLV_COLOR_WHITE
            );
        break;
    default:
        printf("Choix_algo n'est pas valide \n");
        break;
    
    }
    
}

/*Affiche la valeur n*/


void affiche_n(int n){
    /*Charge la police Ubuntu-B*/
    //taille = 4% de la hauteur
    MLV_Font * police = MLV_load_font(
        "Police/Ubuntu-B.ttf",
        (int)(height * (4./100.)));
        
    int taille = snprintf(NULL,0,"%d",n);
    char * strn = malloc(taille+1);

    snprintf(strn, taille+1, "%d", n);

    //texte
    MLV_draw_text_box_with_font(
        (int)width * (30./100.),
        (int)height * (9./100.),
        (int)width * (5./100.),
        (int)height * (9./100),
        strn,police,1,
        MLV_COLOR_BLACK,MLV_COLOR_BLACK,MLV_COLOR_WHITE,
        MLV_TEXT_CENTER,
        MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER
        );

    /*On libere strn*/
    free(strn);
    /*On libere la police utilise*/
    MLV_free_font(police);
    

}

/*affiche_inc_dec()
Affiche un bouton plus et un bouton moins
Agit sur le nombre de ville dans cas aleatoire
*/

void affiche_inc_dec(){
    /*Bouton Supprime*/
    MLV_draw_text_box(
        (int)(width * (27.5/100.)),
        (int)(height * (11./100.)),
        (int)(width * (2.5/100.)),
        (int)(height * (4.5/100.)),
        "-", 1,
        MLV_COLOR_BLACK, MLV_COLOR_BLACK,MLV_COLOR_WHITE,
        MLV_TEXT_CENTER,MLV_TEXT_CENTER,MLV_TEXT_CENTER);
    /*Bouton Ajoute*/
    MLV_draw_text_box(
        (int)(width * (35./100.)),
        (int)(height * (11./100.)),
        (int)(width * (2.5/100.)),
        (int)(height * (4.5/100.)),
        "+", 1,
        MLV_COLOR_BLACK, MLV_COLOR_BLACK,MLV_COLOR_WHITE,
        MLV_TEXT_CENTER,MLV_TEXT_CENTER,MLV_TEXT_CENTER);


}

/*Affiche un bouton pour charger un fichier de point ainsi qu'un bouton pour vider */
void affiche_charger(){

    //taille = 4% de la hauteur
    MLV_Font * police = MLV_load_font(
        "Police/Ubuntu-B.ttf",
        (int)(height * (4./100.)));

        //texte
    MLV_draw_text_box_with_font(
        (int)width * (27./100.),
        (int)height * (21./100.),
        (int)width * (10./100.),
        (int)height * (5./100),
        "Charger",police,1,
        MLV_COLOR_BLACK,MLV_COLOR_BLACK,MLV_COLOR_WHITE,
        MLV_TEXT_CENTER,
        MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER
        );
    

    
    /*On libere la police utilise*/
    MLV_free_font(police);
}

/*affiche_chemin
Affiche le dernier chemin entre par l'utilisateur
*/
void affiche_chemin(char * chemin){

    /*Charge la police Ubuntu-B*/
    //taille = 2.5% de la hauteur
    MLV_Font* police = MLV_load_font("Police/Ubuntu-B.ttf",(int)(height * (3./100.)));

    //texte
    MLV_draw_text_with_font(
        (int)(width * (5./100.)), (int)(height * (29./100.)),
        chemin,
        police,MLV_COLOR_WHITE);
    
    /*On libere la police utilise*/
    MLV_free_font(police);
 
}


//Affichage cout ville

/*Affichage pour mode wikipedia*/
void affiche_pt_wikipedia(){

    //Points
    MLV_draw_filled_circle(
        (int)width * (10./100.),
        (int)height * (45./100.),
        (int)width * (1./100.),
        MLV_COLOR_RED
        );
    MLV_draw_text(
        (int)(width * (9.7/100.)),
        (int)(height * (44./100.)),
        "1",
        MLV_COLOR_WHITE
        );
    
    MLV_draw_filled_circle(
        (int)width * (30./100.),
        (int)height * (45./100.),
        (int)width * (1./100.),
        MLV_COLOR_RED
        );
    MLV_draw_text(
        (int)(width * (29.7/100.)),
        (int)(height * (44./100.)),
        "2",
        MLV_COLOR_WHITE
        );
    
    MLV_draw_filled_circle(
        (int)width * (10./100.),
        (int)height * (82./100.),
        (int)width * (1./100.),
        MLV_COLOR_RED
        );
    MLV_draw_text(
        (int)(width * (9.7/100.)),
        (int)(height * (81./100.)),
        "3",
        MLV_COLOR_WHITE
        );
    
    MLV_draw_filled_circle(
        (int)width * (30./100.),
        (int)height * (82./100.),
        (int)width * (1./100.),
        MLV_COLOR_RED
        );
    MLV_draw_text(
        (int)(width * (29.7/100.)),
        (int)(height * (81./100.)),
        "4",
        MLV_COLOR_WHITE
        );
    
    //Liaisons possible

    //[1,2]
    MLV_draw_line(
        (int)width * (11.1/100.),
        (int)height * (45./100.),
        (int)width * (28.9/100.),
        (int)height * (45./100.),
        MLV_COLOR_CYAN
        );
    MLV_draw_text(
        (int)(width * (20./100.)),
        (int)(height * (42./100.)),
        "4",
        MLV_COLOR_YELLOW
        );

        //[1,3]
    MLV_draw_line(
        (int)width * (10./100.),
        (int)height * (47.1/100.),
        (int)width * (10./100.),
        (int)height * (79.9/100.),
        MLV_COLOR_CYAN
        );
    MLV_draw_text(
        (int)(width * (9./100.)),
        (int)(height * (63./100.)),
        "3",
        MLV_COLOR_YELLOW
        );

    //[1,4]
    MLV_draw_line(
        (int)width * (10.9/100.),
        (int)height * (47.1/100.),
        (int)width * (28.9/100.),
        (int)height * (79.9/100.),
        MLV_COLOR_CYAN
        );
    MLV_draw_text(
        (int)(width * (26./100.)),
        (int)(height * (70./100.)),
        "1",
        MLV_COLOR_YELLOW
        );
    
    //[2,3]
    MLV_draw_line(
        (int)width * (29.1/100.),
        (int)height * (47.1/100.),
        (int)width * (11./100.),
        (int)height * (80./100.),
        MLV_COLOR_CYAN
        );
    MLV_draw_text(
        (int)(width * (14./100.)),
        (int)(height * (70./100.)),
        "1",
        MLV_COLOR_YELLOW
        );
    
    //[2,4]
    MLV_draw_line(
        (int)width * (30./100.),
        (int)height * (47.1/100.),
        (int)width * (30./100.),
        (int)height * (79.9/100.),
        MLV_COLOR_CYAN
        );
    MLV_draw_text(
        (int)(width * (31./100.)),
        (int)(height * (63./100.)),
        "2",
        MLV_COLOR_YELLOW
        );
    
    //[3,4]
    MLV_draw_line(
        (int)width * (11.1/100.),
        (int)height * (82/100.),
        (int)width * (28.9/100.),
        (int)height * (82/100.),
        MLV_COLOR_CYAN
        );
    MLV_draw_text(
        (int)(width * (20./100.)),
        (int)(height * (83./100.)),
        "5",
        MLV_COLOR_YELLOW
        );  
    
}

/*affichage_pt_test
Affiche chaque point de tabpoints dans le graphe
*/

void affiche_pt_test(tabpoints t){

    int nb_elem = t.nb_point;
    int i,x,y;

    int mil_graphe_x = (int)width * (5./100.);
    int mil_graphe_y = (int)height * (36./100.) + (int)height * (54./100.);
    int taille_graphe = (int)width * (30./100.);
    //Verif
    //MLV_draw_filled_circle(mil_graphe_x,mil_graphe_y-2,1,MLV_COLOR_RED);

    //printf("Affichage\n");
    for(i=1; i <= nb_elem; i++) {
        x=(int)(mil_graphe_x + (t.tabp[i].x * taille_graphe));
        y=(int)(mil_graphe_y - (t.tabp[i].y * taille_graphe));
       MLV_draw_filled_circle(x,y,1,MLV_COLOR_RED);
    }

}

