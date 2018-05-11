#ifndef global_cube
#define global_cube
#include<gtk/gtk.h>
#include "cube.h"

extern GtkWidget *window;
extern GtkWidget *game_area;
extern GtkWidget *time_label;
extern GtkWidget *grade_label;
extern GtkWidget *score_label;
extern GtkWidget *red_map, *blue_map, *violet_map;

extern unsigned char g_color;
extern unsigned int grade;
extern unsigned int score;

extern gint g_brick[BRICKXSIZE][BRICKYSIZE];

/* global parameters for the brick*/
extern CandidateBlock candidate_block[];  

extern gint current_brickblock_index;    
extern gint current_brick_x;             /* based on 0 */
extern gint current_brick_y;             /* based on 0 */

/* end of global parameters */

#endif
