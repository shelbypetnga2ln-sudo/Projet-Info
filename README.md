#include <stdio.h>
#include <string.h>
#include <time.h>
#include "display.h"
#include "game.h"
#include "Utils.h"

/* couleur par item*/
static int color_for_item(char it){
   switch(it){
       case IT_S: return C_YELLOW;  /*soleil*/
       case IT_F: return C_RED;    /*fraise*/
       case IT_P: return C_GREEN;  /*pomme*/
       case IT_O: return C_CYAN;   /*oignon*/
       case IT_M: return C_MAGNETA; /*mandarine*/
       default:  return C_WHITE; 
       }
  }
  static void print_contract(Game*g){
  printf("Contrat: ");
  const char 
keys[ ITEM_COUNT ]={IT_S, IT_F, IT_P, IT_O, IT_M};
  for(int i= 0; i<ITEM_COUNT; i++){
      if(g->targets[i]>0) {
           int col = color_for_item(keys[i]);
           set_color(col, -1);
           printf("%c", keys[i]);
           reset_color();
           printf("%d/%d", g->progress[i], g->targets[i]);
           }
      }
      printf("\n");
}

void display_board(Game*g, Player *p){
   clear_screen();
   time_t now = time(NULL);
   int remaining = g->time_limit_sec- (int)difftime(now, g->level_start);
     if (remaining < 0) remaining = 0;
     printf("================================ PLANTAMIZ 2025=========================================\n");
     printf("Niveau: %d| vies: %d | Coups restants: %d | score niv.: %d| Total: %d\n", g->level, p-> lives, g-> moves_left, remaining, g-> score, p->total_score);
     printf("==================================================================================================================================================\n");

          for(int r=0; r<ROWS; r++){
            for (int c= 0; c<COLS; c++){
                 char ch = g->board[r][c];
                 int col = color_for_item(ch);
                 int bg = -1;

                 if (g-> item_selected && r==g->sel_row && c==g->sel_col) bg = C_GRAY;
                 if (r==g-> cursor_row && c==g->cursor_col) bg = C_BLUE;
                                                            set_color(col,bg);
                                                            putchar(ch==IT_EMPTY? '.' : ch);
                                                            reset_color();
                                                       }
                                                       putchar('\n');
                                                    }
                                                    printf("\ncommandes: z q s d = déplacer | Espace = sélectionner/échanger | x= quitter niveau\n");
                                                    }
                                                    void display_main_menu(void){
                                                       clear_screen();
                                                       printf("=====================================================PLANTAMITZ 2025================================================\n");
                                                       printf("1.Nouvelle partie/ Continuer\n");
                                                       printf("2. Instructions\n");
                                                       printf("3. Quitter\n");
                                                       printf("===========================================================================================================================\n");
                                                       }

                                                       int get_menu_choice(void){
                                                         int c;
                                                         printf("vptre choix :");
                                                         if ( scanf("%d", &c)!=1) { while(getchar()!= '\'n); return 0;}
                                                           while(getchar()!='\n'); /* flush */
                                                           return c;
                                                        }
                                                        void display_instructions(void){
                                                          clear_screen();
                                                          printf("But: remplir le contrat (lettres S/F/P/O/M) en un nombre de coups et un temps limites.\n");
                                                          printf("Grille 25x45. Déplacements du Curseur : z q s d. Sélection avec Espace , puis z/q/s/d pour échanger.\n");
                                                          printf(" Groupes de 3+ disparaissent, gravité + remplissage aléatoire, cascades automatiques.\n");
                                                          printf("Groupe de 6+: disparition de TOUTES les lettres identiques du tableau.\n");
                                                          printf("\nAppuyer sur Entrée pour revenir au menu...");
                                                          getchar();
                                                      }
                                                      void display_highscores(void){
                                                        clear_screen();
                                                        printf("Meilleurs scores / progression : (optionnel)\n");
                                                        printf("Appuyer sur Entrée pour revenir au menu...");
                                                        getchar();
                                                      }
                                                        
    
