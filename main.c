#include "global.h"
#include "DAT_Matrice.h"
#include "TSP_Naive.h"
#include "Fourmi.h"
#include "Affichage.h"
#include "Evenement.h"


int main(){

    int etat = EN_COURS;
    int fenetre = MENU;

    //Selctions
    int choix_ville = WIKIPEDIA;
    int choix_algo = FOURMI;

    //MLV
    //Position souris
    int mouse_x,mouse_y;
    //Evenement de la souris
    MLV_Mouse_button mouse_button;
    MLV_Button_state button_state;
    //Type evenement (permet de savoir l'action réalisée)
    MLV_Event event;
    //Boite de saisie
    MLV_Input_box *input_box, *input_chemin;

    /* Definitions variables */
    //Permet de stocker un tableau de point (charger)
    tabpoints t;
    //Chemin du fichier (input)
    char *texte, *chemin;   
    //Iterateur
    int i,j;
    //Matrice des couts
    mat_cout mcv;
    //Cout maximum
    int cmax = 10;

    
    /*
    int ** cv = NULL;
    //Nombre de ville
    int nb_ville=4;
    */

    
    //Solution
    solution  * meilleure = NULL;
    solution * partielle = NULL;

    //Allocation

    t.tabp = (struct point *)malloc(sizeof(struct point)*1);
    if(t.tabp == NULL){
        printf("Erreur alloc t->tabp (main.c)\n");
        exit(0);
    }

    meilleure = (solution *)malloc(sizeof(solution)*1);
    if(meilleure == NULL){
        printf("Erreur alloc meilleure (main.c)\n");
        exit(0);
    }
    partielle = (solution *)malloc(sizeof(solution)*1);
    if(partielle == NULL){
        printf("Erreur alloc meilleure (main.c)\n");
        exit(0);
    }

    /*Initialisation*/
    //init_ville_test(&mcv);
    //init_ville_alea(&mcv, 4, 10);
    init_ville_alea_sym(&mcv, 12, 10);
    
    for(i=1;i<= mcv.nb_ville; i++){
        for(j=1; j<= mcv.nb_ville; j++){
            printf("%3d | ",mcv.cv[i][j]);  
        }
        printf("\n");
    }

    /*Test sur terminal*/
    
    printf("\nDebut\n");

    
    initialiser_meilleure(meilleure,mcv);
    fourmi(meilleure,mcv, 500, 1, 4, 0.5);

    printf("\n\nRésultat :\n");
    info_solution(*meilleure, mcv.nb_ville);

    free(meilleure);

    meilleure = NULL;
    meilleure = (solution *)malloc(sizeof(solution)*1);
    if(meilleure == NULL){
        printf("Erreur alloc meilleure (main.c)\n");
        exit(0);
    }
    partielle = NULL;
    partielle = (solution *)malloc(sizeof(solution)*1);
    if(partielle == NULL){
        printf("Erreur alloc meilleure (main.c)\n");
        exit(0);
    }
    
    initialiser_partielle(partielle, mcv.nb_ville);
    initialiser_meilleure(meilleure,mcv);
    nb_iteration=0;
    tsp_elag_naive(*partielle,meilleure,mcv);

    printf("\n\nRésultat :\n %d itérations \n",nb_iteration);
    info_solution(*meilleure, mcv.nb_ville);

    free(meilleure);
    free(partielle);
    

    printf("\nWait\n");

    /*
    meilleure = NULL;
    meilleure = (solution *)malloc(sizeof(solution)*1);
    if(meilleure == NULL){
        printf("Erreur alloc meilleure (main.c)\n");
        exit(0);
    }
    partielle = NULL;
    partielle = (solution *)malloc(sizeof(solution)*1);
    if(partielle == NULL){
        printf("Erreur alloc meilleure (main.c)\n");
        exit(0);
    }
    
    initialiser_partielle(partielle, mcv.nb_ville);
    initialiser_meilleure(meilleure,mcv);
    nb_iteration=0;
    tsp_naive(*partielle, meilleure, mcv);
    
    printf("\n\nRésultat :\n %d itérations \n",nb_iteration);
    info_solution(*meilleure, mcv.nb_ville);
   
    free(meilleure);
    free(partielle);

    */
    free(mcv.cv);
    mcv.cv = NULL;
    mcv.nb_ville = 0;












    

    /*Debut MLV*/

    //Valeur de la fenetre
    width = MLV_get_desktop_width()-100;
    height = width * 55/100;

    //Creation fenetre
    MLV_create_window("Plus Court Chemin",
                      "PCC",
                      width,
                      height);

    //Creation boite de saisie pour charger un fichier
    input_chemin = MLV_create_input_box(
        (int)(width * (5./100.)), (int)(height * (21./100.)),
        (int)(width * (20./100.)), (int)(height * (7./100.)),
        MLV_COLOR_WHITE, MLV_COLOR_BLACK,
        MLV_COLOR_WHITE, "->"
        );
    chemin = (char*) malloc( 1*sizeof(char) );
    *chemin = '\0';

    //Initialise mcv
    init_ville_test(&mcv);

    do{

        while(fenetre == MENU){

            
            //Affichage de la fenetre
            menu();
            bouton_suivant_menu(choix_ville,choix_algo);
            remplir_coche(choix_ville,choix_algo);
            affiche_n(mcv.nb_ville);


            if(choix_ville == WIKIPEDIA){
                affiche_pt_wikipedia();
            }
            //Si aleatoire est en selection
            //Possible de choisir le nb de ville
            if(choix_ville == ALEA_CARRE ||
               choix_ville == ALEA_CARRE_SYM){
                affiche_inc_dec();
            }
            if(choix_ville == TEST){
                /*On affiche la boite pour "chemin"*/
                MLV_draw_input_box(input_chemin);
                /*Affiche le bouton charger*/
                affiche_charger();
                /*On affiche le chemin actuel*/
                affiche_chemin(chemin);
            }
            
            
            //Recupere les clicks souris
            event = MLV_get_event(
                NULL,NULL,NULL,
                &texte, &input_box,
                &mouse_x,&mouse_y, &mouse_button,
                &button_state         
                );
            /*Si l'evenement est une boite*/
            if(event == MLV_INPUT_BOX){
                /*Si la boite est celle renseignant le chemin*/
                if( input_box == input_chemin ){
                    free( chemin );
                    chemin = texte;
                }
            }
            
            //Si le click souris est click gauche et appuye
            if(event == MLV_MOUSE_BUTTON && mouse_button == MLV_BUTTON_LEFT && button_state == MLV_PRESSED){
                //Si click est sur suivant
                if(Click_suivant(mouse_x,mouse_y)){
                    fenetre = choix_algo;
                }
                //Si click ets dans zone choix_ville
                if(Click_choix_ville(mouse_x,mouse_y)){
                    choix_ville = MAJ_choix_ville(
                        choix_ville,
                        mouse_x,mouse_y);
                    //On recharge une valeur pour mcv
                    free(mcv.cv);
                    mcv.cv = NULL;
                    switch(choix_ville){
                    case WIKIPEDIA :
                        init_ville_test(&mcv);
                        break;
                    case ALEA_CARRE :
                        //mcv.nb_ville = 45;
                        init_ville_alea(&mcv,mcv.nb_ville,cmax);
                        affiche_matrice(mcv.cv,NULL,mcv.nb_ville);
                        break;
                    case ALEA_CARRE_SYM:
                        init_ville_alea_sym(&mcv,mcv.nb_ville,cmax);
                        affiche_matrice(mcv.cv,NULL,mcv.nb_ville);
                        break;
                    case TEST :
                        init_ville_alea(&mcv,250,cmax);
                        break;
                    default :
                        init_ville_test(&mcv);
                        break;

                    }
                }
                //Si click est dans zone choix_algo
                if(Click_choix_algo(mouse_x,mouse_y)){
                    choix_algo = MAJ_choix_algo(
                        choix_algo,
                        mouse_x,mouse_y);
                }

                //Si click est couple a choix_ville = ALEA
                if(choix_ville == ALEA_CARRE ||
                   choix_ville == ALEA_CARRE_SYM
                    ){
                    //Si click inc (++)
                    if(Click_inc(mouse_x,mouse_y)){
                        free(mcv.cv);
                        mcv.nb_ville++;
                        //Si matrice non carre
                        if(choix_ville == ALEA_CARRE){
                            init_ville_alea(&mcv,mcv.nb_ville,cmax);
                            affiche_matrice(mcv.cv,NULL,mcv.nb_ville);
                        }
                        //Si matrice carre
                        else{
                            init_ville_alea_sym(&mcv,mcv.nb_ville,cmax);
                            affiche_matrice(mcv.cv,NULL,mcv.nb_ville);
                        }
                    }
                    //Si click dec (--)
                    if(Click_dec(mouse_x,mouse_y) &&
                       mcv.nb_ville>0){
                        free(mcv.cv);
                        mcv.nb_ville--;
                        //Si matrice non carre
                        if(choix_ville == ALEA_CARRE){
                            init_ville_alea(&mcv,mcv.nb_ville,cmax);
                        }
                        //Si matrice carre
                        else{
                            init_ville_alea_sym(&mcv,mcv.nb_ville,cmax);
                        }
                    }
                    
                }

                //Efface la coche precedente
                 MLV_clear_window(MLV_COLOR_BLACK);
                
            }
           
        }

        MLV_clear_window(MLV_COLOR_BLACK);
        MLV_actualise_window();

    }while(etat != FIN);




    
    MLV_free_window();
    
    /*Liberation memoire*/

    free(mcv.cv);

    return EXIT_SUCCESS;
}