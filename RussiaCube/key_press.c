#include "global_cube.h"
#include <gdk/gdkkeysyms.h>

/* handle for the user input action
 */
gint key_press(GtkWidget *widget, GdkEventKey *event, gpointer arg)
{
		gint t_tempindex,t_tempx,t_tempy,t_retv, t_loopi,tt_loopi;
		BrickPosition t_oldstart,t_oldend,t_newstart,t_newend;
		GdkEvent t_event;
		char score_text[10];

		t_oldstart.g_x=current_brick_x;
		t_oldstart.g_y=current_brick_y;
		t_tempindex=candidate_block[current_brickblock_index].index;
		t_oldend=candidate_block[current_brickblock_index].brick_block[t_tempindex].area_end_pos;
		t_oldend.g_x=t_oldend.g_x+current_brick_x;
		t_oldend.g_y=t_oldend.g_y+current_brick_y;

		t_retv=0;
		switch(event->keyval)
		{
			case GDK_Up:
			{
				t_tempindex=(candidate_block[current_brickblock_index].index+1)%4;
				t_retv=update_brick_position(current_brickblock_index,t_tempindex,current_brick_x, current_brick_y);
				if(t_retv==1)
				{
					/* Clear the old value */
					for(t_loopi=0;t_loopi<4;t_loopi++)
					{
						gint tt_tempindex;
						tt_tempindex=candidate_block[current_brickblock_index].index;
						t_tempx=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_x+current_brick_x;
						t_tempy=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_y+current_brick_y;
						g_brick[t_tempx][t_tempy]=0;
					}
					/* action */
					candidate_block[current_brickblock_index].index=t_tempindex;
					/* Set the new value */
					for(t_loopi=0;t_loopi<4;t_loopi++)
					{
						gint tt_tempindex;
						tt_tempindex=candidate_block[current_brickblock_index].index;
						t_tempx=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_x+current_brick_x;
						t_tempy=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_y+current_brick_y;
						g_brick[t_tempx][t_tempy]=1;
					}// end of set new value
				}// end of brick block changed.
			}
			break;
			case GDK_Down:
			{
				t_tempindex=candidate_block[current_brickblock_index].index;
				t_retv=update_brick_position(current_brickblock_index,t_tempindex,current_brick_x, current_brick_y+1);
				if(t_retv==1)
				{
					/* Clear the old value */
					for(t_loopi=0;t_loopi<4;t_loopi++)
					{
						gint tt_tempindex;
						tt_tempindex=candidate_block[current_brickblock_index].index;
						t_tempx=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_x+current_brick_x;
						t_tempy=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_y+current_brick_y;
						g_brick[t_tempx][t_tempy]=0;
					}
					/* action */
					current_brick_y++;
					/* Set the new value */
					for(t_loopi=0;t_loopi<4;t_loopi++)
					{
						gint tt_tempindex;
						tt_tempindex=candidate_block[current_brickblock_index].index;
						t_tempx=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_x+current_brick_x;
						t_tempy=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_y+current_brick_y;
						g_brick[t_tempx][t_tempy]=1;
					}// end of set new value
				}// end of brich changed
				else
				{// matrix bottom met. New brick created
					t_retv=1;
					/* Create a brick block randomly */
					current_brickblock_index=g_random_int_range(0,7);
					current_brick_x=5;
					current_brick_y=0;
					candidate_block[current_brickblock_index].index=g_random_int_range(0,4);
					/* Clear the all 1 rows */
					gint tt_src=BRICKYSIZE-1;
					gint tt_dst=BRICKYSIZE-1;
					for(t_loopi=BRICKYSIZE-1;t_loopi>=0;t_loopi--)
					{// adjust g_brick  
						if(tt_src!=tt_dst)
						{// should copy
							for( tt_loopi=0;tt_loopi<BRICKXSIZE;tt_loopi++)
							{// copy row
								g_brick[tt_loopi][tt_dst]=g_brick[tt_loopi][tt_src];
							}// end of copy row
						}// should copy
						/* move src upward */
						tt_src--;
						/* can dest move upward? depends on whether the row are all 1 */
						gint tt_sumrow=0;
						for( tt_loopi=0;tt_loopi<BRICKXSIZE;tt_loopi++)
						{// sum row
							tt_sumrow=tt_sumrow+g_brick[tt_loopi][tt_dst];
						}// end of sum row
						if(tt_sumrow<BRICKXSIZE) tt_dst--;// not all 1
					}// end of adjust g_brick matrix

					/* Clear the empty matrix */
					for(t_loopi=0;t_loopi<=tt_dst;t_loopi++)
					{// clear the upper row
						for(t_tempx=0;t_tempx<BRICKXSIZE;t_tempx++)
						{
							g_brick[t_tempx][t_loopi]=0;
						}
						score+=100;
						sprintf(score_text, "%s%d", "得分: ", score);
						gtk_label_set_text(GTK_LABEL(score_label),_N(score_text));	
					}// clear the upper row

					/* Set the matrix new value */
					for(t_loopi=0;t_loopi<4;t_loopi++)
					{
						gint tt_tempindex;
						tt_tempindex=candidate_block[current_brickblock_index].index;
						t_tempx=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_x+current_brick_x;
						t_tempy=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_y+current_brick_y;
						g_brick[t_tempx][t_tempy]=1;
					}// end of set new matrix value

					/* Reset the redraw area to all area */
					t_oldstart.g_x=0;t_oldstart.g_y=0;
					t_oldend.g_x=BRICKXSIZE-1;t_oldend.g_y=BRICKYSIZE-1;

				}// end of new brick
			}
			break;
			case GDK_Right:
			{
				t_tempindex=candidate_block[current_brickblock_index].index;
				t_retv=update_brick_position(current_brickblock_index,t_tempindex,current_brick_x+1, current_brick_y);
				if(t_retv==1)
				{
					/* Clear the old value */
					for(t_loopi=0;t_loopi<4;t_loopi++)
					{
					gint tt_tempindex;
					tt_tempindex=candidate_block[current_brickblock_index].index;
					t_tempx=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_x+current_brick_x;
					t_tempy=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_y+current_brick_y;
					g_brick[t_tempx][t_tempy]=0;
					}
					/* action */
					current_brick_x++;
					/* Set the new value */
					for(t_loopi=0;t_loopi<4;t_loopi++)
					{
						gint tt_tempindex;
						tt_tempindex=candidate_block[current_brickblock_index].index;
						t_tempx=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_x+current_brick_x;
						t_tempy=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_y+current_brick_y;
						g_brick[t_tempx][t_tempy]=1;
					}// end of set new value
				}// end of brick changed
			}
			break;
			case GDK_Left:
			{
				t_tempindex=candidate_block[current_brickblock_index].index;
				t_retv=update_brick_position(current_brickblock_index,t_tempindex,current_brick_x-1, current_brick_y);
				if(t_retv==1)
				{
					/* Clear the old value */
					for(t_loopi=0;t_loopi<4;t_loopi++)
					{
						gint tt_tempindex;
						tt_tempindex=candidate_block[current_brickblock_index].index;
						t_tempx=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_x+current_brick_x;
						t_tempy=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_y+current_brick_y;
						g_brick[t_tempx][t_tempy]=0;
					}
					/* action */
					current_brick_x--;
					/* Set the new value */
					for(t_loopi=0;t_loopi<4;t_loopi++)
					{
						gint tt_tempindex;
						tt_tempindex=candidate_block[current_brickblock_index].index;
						t_tempx=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_x+current_brick_x;
						t_tempy=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_y+current_brick_y;
						g_brick[t_tempx][t_tempy]=1;
					}// end of set new value
				}// end of brick changed
			}
			break;
		}
			
		if(t_retv==1)
		{// redraw the related area
			t_newstart.g_x=current_brick_x;
			t_newstart.g_y=current_brick_y;
			t_tempindex=candidate_block[current_brickblock_index].index;
			t_newend=candidate_block[current_brickblock_index].brick_block[t_tempindex].area_end_pos; 
			t_newend.g_x=t_newend.g_x+t_newstart.g_x;
			t_newend.g_y=t_newend.g_y+t_newstart.g_y;
			if(t_newstart.g_x>t_oldstart.g_x)
			t_newstart.g_x=t_oldstart.g_x;
			if(t_newstart.g_y>t_oldstart.g_y)
			t_newstart.g_y=t_oldstart.g_y;
			if(t_newend.g_x<t_oldend.g_x)
			t_newend.g_x=t_oldend.g_x;
			if(t_newend.g_y<t_oldend.g_y)
			t_newend.g_y=t_oldend.g_y;
				
			/* active the area redraw */
			t_event.type=GDK_EXPOSE;
			((GdkEventExpose*)&t_event)->window=((GtkWidget* )arg)->window;
			((GdkEventExpose*)&t_event)->send_event=TRUE;
			((GdkEventExpose*)&t_event)->area.x=t_newstart.g_x*BRICKWIDTH;
			((GdkEventExpose*)&t_event)->area.y=t_newstart.g_y*BRICKHEIGHT;
			((GdkEventExpose*)&t_event)->area.width=(t_newend.g_x-t_newstart.g_x+1)*BRICKWIDTH;
			((GdkEventExpose*)&t_event)->area.height=(t_newend.g_y-t_newstart.g_y+1)*BRICKHEIGHT;
			((GdkEventExpose*)&t_event)->region=gdk_region_rectangle(&((GdkEventExpose*)&t_event)->area);
			((GdkEventExpose*)&t_event)->count=0;
			gdk_event_put(&t_event);
		}
}

