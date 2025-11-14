#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "display.h"
#include "game.h"
#include "Utils.h"

int main(void){
    srand(time(NULL));

    Player player = {0};
    player.lives = 5;
    player.total_score = 0;

    display_main_menu();
    printf("\nEntrez votre nom : ");
    fgets(player.name, sizeof(player.name), stdin);
    /* enlever le \n */
    for(char *p=player.name; *p; ++p){ if (*p=='\n'||*p=='\r'){ *p='\0'; break; } }
    if (player.name[0]=='\0') snprintf(player.name, sizeof(player.name), "Joueur");

    player.highest_level = load_progress(player.name);

    int running = 1;
    while (running){
        display_main_menu();
        printf("Bonjour %s (prochaine reprise: niveau %d)\n", player.name, player.highest_level);
        int choice = get_menu_choice();
        switch(choice){
            case 1: {
                player.lives = 5;
                game_play_sequence(&player);
            } break;
            case 2:
                display_instructions();
                break;
            case 3:
                running = 0;
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
     }
