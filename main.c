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

    /* Definitions variables */
    //Iterateur
    int i,j;
    //Matrice des couts
    mat_cout mcv;    


    
    /*
    int ** cv = NULL;
    //Nombre de ville
    int nb_ville=4;
    */

    
    //Solution
    solution  * meilleure = NULL;
    solution * partielle = NULL;

    //Allocation

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
    init_ville_alea(&mcv, 4, 10);
    
    for(i=1;i<= mcv.nb_ville; i++){
        for(j=1; j<= mcv.nb_ville; j++){
            printf("%3d | ",mcv.cv[i][j]);  
        }
        printf("\n");
    }

    /*Test sur terminal*/
    
    printf("\nDebut\n");

    
    initialiser_meilleure(meilleure,mcv);
    fourmi(meilleure,mcv, 1500, 1, 1, 0.5);

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















    

    /*Debut MLV*/

    //Valeur de la fenetre
    width = MLV_get_desktop_width()-100;
    height = width * 55/100;

    //Creation fenetre
    MLV_create_window("Plus Court Chemin",
                      "PCC",
                      width,
                      height);

    do{

        while(fenetre == MENU){
            menu();
            bouton_suivant_menu(choix_ville,choix_algo);
            remplir_coche(choix_ville,choix_algo);

            event = MLV_get_event(
                NULL,NULL,NULL,
                NULL,NULL,
                &mouse_x,&mouse_y, &mouse_button,
                &button_state         
                );
            
            if(event == MLV_MOUSE_BUTTON && mouse_button == MLV_BUTTON_LEFT && button_state == MLV_PRESSED){
                
                if(Click_suivant(mouse_x,mouse_y)){
                    fenetre = choix_algo;
                }
                if(Click_choix_ville(mouse_x,mouse_y)){
                    choix_ville = MAJ_choix_ville(
                        choix_ville,
                        mouse_x,mouse_y);
                }
                if(Click_choix_algo(mouse_x,mouse_y)){
                    choix_algo = MAJ_choix_algo(
                        choix_algo,
                        mouse_x,mouse_y);
                }

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