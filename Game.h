#ifndef GAME_H
#define GAME_H

#include <stdbool.h> /*active le type bool */
#include <time.h> /*permet de gérer le temps */

#define ROWS 25
#define COLS 45

/Items permet de définir chaque type d'objet representer sur le plateu*/
#define IT_S 'S'
#define IT_F 'F'
#define IT_P 'p'
#define IT_O 'O'
#define IT_M 'M'
#define IT_EMPTY ' '

/*Index pour tableau */

enum { IDX_S=0, IDX_F, IDX_P, IDX_O, IDX_M, ITEM_COUNT }; /IDX c'est ce que l'on calcule (compteur), IT ce sont les ITEMS la répresentatin des rows et cols(ce qu'on dessine)/
/Joueur/
typedef struct Player{
char name [64];
int lives;  /* demarre à 5 à chaque partie*/
int highest_level;
int total_score;
}
Player;

/Etat de jeu/
typedef struct Game{
char board [ROWS][COLS];
/* contrat du niveau*/
int targets [ITEM_COUNT]; /* objectif de manger*/ /* ITEM_cOUNT permet d'avoir le nombre total d’items calculé automatiquement par le compilateur.*/
int progress [ITEM_COUNT]; /* objectif à recolter*/
int level;
int moves_left; /* coups restant*/
int time_limit_sec;/temps autorisé/
time_t level_start;/compte à rebours/

/Crseur + selection/
int score;
int cursor_row, cursor_col;
bool item_selected;
int sel_row, sel_col;
}
Game;

/*jeu */

void game_play_sequence(Player *player);
void game_play_level (Game g, Player *player, int level); / jouer le 1 niveau*/

/* sauvegarde la progression du joeuur*/
int load_progress(const char *player_name);
void save_progress(const char *player_name, int next_level);

bool game_is_adjacent(int r1, int c1, int r2, int c2); /est ce que les deux cases sont adjacentes ?/

#endif
