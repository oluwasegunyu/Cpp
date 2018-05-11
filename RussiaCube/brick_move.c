#include"global_cube.h"

/* Whether the brick block conflict or not 
   return 1, OK
   return 0, not OK
 */
gint update_brick_position(gint m_currentblock,gint m_blockstatus,gint m_startx, gint m_starty)
{
		gint t_loopi,t_tempint,t_indexx,t_indexy,t_brickblockindex,t_tempx,t_tempy;

		t_tempint=0;
		t_brickblockindex=m_blockstatus;

		/* Clear the current exist brick block */
		for(t_loopi=0;t_loopi<4;t_loopi++)
		{
			gint tt_tempindex;
			tt_tempindex=candidate_block[current_brickblock_index].index;
			t_tempx=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_x+current_brick_x;
			t_tempy=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_y+current_brick_y;
			g_brick[t_tempx][t_tempy]=0;
		}

		/* using the input parameter, judge whether it is possible */
		for(t_loopi=0;t_loopi<4;t_loopi++)
		{// for each brick in the brick block
			t_indexx=candidate_block[m_currentblock].brick_block[t_brickblockindex].brick_pos[t_loopi].g_x;
			t_indexy=candidate_block[m_currentblock].brick_block[t_brickblockindex].brick_pos[t_loopi].g_y;
			t_indexx=t_indexx+m_startx;
			t_indexy=t_indexy+m_starty;
			/* Get the value from matrix */
			if(t_indexx<0||t_indexx>=BRICKXSIZE||t_indexy<0||t_indexy>=BRICKYSIZE)
				t_tempint++;
			else
				t_tempint=t_tempint+g_brick[t_indexx][t_indexy];
		}// for each brick in the brick block

		/* Recover the current brick  */
		for(t_loopi=0;t_loopi<4;t_loopi++)
		{
			gint tt_tempindex;
			tt_tempindex=candidate_block[current_brickblock_index].index;
			t_tempx=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_x+current_brick_x;
			t_tempy=candidate_block[current_brickblock_index].brick_block[tt_tempindex].brick_pos[t_loopi].g_y+current_brick_y;
			g_brick[t_tempx][t_tempy]=1;
		}

		/* return the judgement */
		if(t_tempint>=1)
			return 0;
		else
			return 1;
}

