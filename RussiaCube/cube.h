/* Define the global parameters */
#ifndef CUBE
#define CUBE

#include <gtk/gtk.h>
#include <time.h>
#include <sys/time.h>

#define RED 1
#define BLUE 2
#define VIOLET 4

#define BRICKXSIZE 13
#define BRICKYSIZE 19
#define BRICKWIDTH 20
#define BRICKHEIGHT 20

#define _N(str) g_locale_to_utf8(str, -1, NULL,NULL,NULL)

typedef struct _brickposition
{
		gint g_x;    // based on 0
		gint g_y;    // based on 0
} BrickPosition;

typedef struct _brickblock
{
		BrickPosition brick_pos[4];
		BrickPosition area_start_pos;
		BrickPosition area_end_pos;
} BrickBlock;

typedef struct _candidateblock
{
		BrickBlock brick_block[4];
		gint index;
} CandidateBlock;

struct itimerval new_timeval,old_timeval;
void initialize(void);
gint update_brick_position(gint,gint,gint,gint);
gint key_press(GtkWidget*, GdkEventKey*, gpointer);

#endif
