#include"global_cube.h"

void initialize()
{
		/* init the global brick candidate*/
		candidate_block[0].index=0;
		candidate_block[0].brick_block[0].brick_pos[0].g_x=0;
		candidate_block[0].brick_block[0].brick_pos[0].g_y=1;
		candidate_block[0].brick_block[0].brick_pos[1].g_x=1;
		candidate_block[0].brick_block[0].brick_pos[1].g_y=1;
		candidate_block[0].brick_block[0].brick_pos[2].g_x=2;
		candidate_block[0].brick_block[0].brick_pos[2].g_y=1;
		candidate_block[0].brick_block[0].brick_pos[3].g_x=1;
		candidate_block[0].brick_block[0].brick_pos[3].g_y=0;
		candidate_block[0].brick_block[0].area_start_pos.g_x=0;
		candidate_block[0].brick_block[0].area_start_pos.g_y=0;
		candidate_block[0].brick_block[0].area_end_pos.g_x=2;
		candidate_block[0].brick_block[0].area_end_pos.g_y=1;
		
		candidate_block[0].brick_block[1].brick_pos[0].g_x=0;
		candidate_block[0].brick_block[1].brick_pos[0].g_y=0;
		candidate_block[0].brick_block[1].brick_pos[1].g_x=0;
		candidate_block[0].brick_block[1].brick_pos[1].g_y=1;
		candidate_block[0].brick_block[1].brick_pos[2].g_x=0;
		candidate_block[0].brick_block[1].brick_pos[2].g_y=2;
		candidate_block[0].brick_block[1].brick_pos[3].g_x=1;
		candidate_block[0].brick_block[1].brick_pos[3].g_y=1;
		candidate_block[0].brick_block[1].area_start_pos.g_x=0;
		candidate_block[0].brick_block[1].area_start_pos.g_y=0;
		candidate_block[0].brick_block[1].area_end_pos.g_x=1;
		candidate_block[0].brick_block[1].area_end_pos.g_y=2;
		
		candidate_block[0].brick_block[2].brick_pos[0].g_x=0;
		candidate_block[0].brick_block[2].brick_pos[0].g_y=0;
		candidate_block[0].brick_block[2].brick_pos[1].g_x=1;
		candidate_block[0].brick_block[2].brick_pos[1].g_y=0;
		candidate_block[0].brick_block[2].brick_pos[2].g_x=2;
		candidate_block[0].brick_block[2].brick_pos[2].g_y=0;
		candidate_block[0].brick_block[2].brick_pos[3].g_x=1;
		candidate_block[0].brick_block[2].brick_pos[3].g_y=1;
		candidate_block[0].brick_block[2].area_start_pos.g_x=0;
		candidate_block[0].brick_block[2].area_start_pos.g_y=0;
		candidate_block[0].brick_block[2].area_end_pos.g_x=2;
		candidate_block[0].brick_block[2].area_end_pos.g_y=1;
		
		candidate_block[0].brick_block[3].brick_pos[0].g_x=1;
		candidate_block[0].brick_block[3].brick_pos[0].g_y=0;
		candidate_block[0].brick_block[3].brick_pos[1].g_x=1;
		candidate_block[0].brick_block[3].brick_pos[1].g_y=1;
		candidate_block[0].brick_block[3].brick_pos[2].g_x=1;
		candidate_block[0].brick_block[3].brick_pos[2].g_y=2;
		candidate_block[0].brick_block[3].brick_pos[3].g_x=0;
		candidate_block[0].brick_block[3].brick_pos[3].g_y=1;
		candidate_block[0].brick_block[3].area_start_pos.g_x=0;
		candidate_block[0].brick_block[3].area_start_pos.g_y=0;
		candidate_block[0].brick_block[3].area_end_pos.g_x=1;
		candidate_block[0].brick_block[3].area_end_pos.g_y=2;
		
		/* brick block 2 */
		candidate_block[1].index=0;
		candidate_block[1].brick_block[0].brick_pos[0].g_x=0;
		candidate_block[1].brick_block[0].brick_pos[0].g_y=0;
		candidate_block[1].brick_block[0].brick_pos[1].g_x=1;
		candidate_block[1].brick_block[0].brick_pos[1].g_y=0;
		candidate_block[1].brick_block[0].brick_pos[2].g_x=2;
		candidate_block[1].brick_block[0].brick_pos[2].g_y=0;
		candidate_block[1].brick_block[0].brick_pos[3].g_x=3;
		candidate_block[1].brick_block[0].brick_pos[3].g_y=0;
		candidate_block[1].brick_block[0].area_start_pos.g_x=0;
		candidate_block[1].brick_block[0].area_start_pos.g_y=0;
		candidate_block[1].brick_block[0].area_end_pos.g_x=3;
		candidate_block[1].brick_block[0].area_end_pos.g_y=0;
		
		candidate_block[1].brick_block[1].brick_pos[0].g_x=0;
		candidate_block[1].brick_block[1].brick_pos[0].g_y=0;
		candidate_block[1].brick_block[1].brick_pos[1].g_x=0;
		candidate_block[1].brick_block[1].brick_pos[1].g_y=1;
		candidate_block[1].brick_block[1].brick_pos[2].g_x=0;
		candidate_block[1].brick_block[1].brick_pos[2].g_y=2;
		candidate_block[1].brick_block[1].brick_pos[3].g_x=0;
		candidate_block[1].brick_block[1].brick_pos[3].g_y=3;
		candidate_block[1].brick_block[1].area_start_pos.g_x=0;
		candidate_block[1].brick_block[1].area_start_pos.g_y=0;
		candidate_block[1].brick_block[1].area_end_pos.g_x=0;
		candidate_block[1].brick_block[1].area_end_pos.g_y=3;
		
		candidate_block[1].brick_block[2].brick_pos[0].g_x=0;
		candidate_block[1].brick_block[2].brick_pos[0].g_y=0;
		candidate_block[1].brick_block[2].brick_pos[1].g_x=1;
		candidate_block[1].brick_block[2].brick_pos[1].g_y=0;
		candidate_block[1].brick_block[2].brick_pos[2].g_x=2;
		candidate_block[1].brick_block[2].brick_pos[2].g_y=0;
		candidate_block[1].brick_block[2].brick_pos[3].g_x=3;
		candidate_block[1].brick_block[2].brick_pos[3].g_y=0;
		candidate_block[1].brick_block[2].area_start_pos.g_x=0;
		candidate_block[1].brick_block[2].area_start_pos.g_y=0;
		candidate_block[1].brick_block[2].area_end_pos.g_x=3;
		candidate_block[1].brick_block[2].area_end_pos.g_y=0;
		
		candidate_block[1].brick_block[3].brick_pos[0].g_x=0;
		candidate_block[1].brick_block[3].brick_pos[0].g_y=0;
		candidate_block[1].brick_block[3].brick_pos[1].g_x=0;
		candidate_block[1].brick_block[3].brick_pos[1].g_y=1;
		candidate_block[1].brick_block[3].brick_pos[2].g_x=0;
		candidate_block[1].brick_block[3].brick_pos[2].g_y=2;
		candidate_block[1].brick_block[3].brick_pos[3].g_x=0;
		candidate_block[1].brick_block[3].brick_pos[3].g_y=3;
		candidate_block[1].brick_block[3].area_start_pos.g_x=0;
		candidate_block[1].brick_block[3].area_start_pos.g_y=0;
		candidate_block[1].brick_block[3].area_end_pos.g_x=0;
		candidate_block[1].brick_block[3].area_end_pos.g_y=3;
		
		/* brick block 3 */
		candidate_block[2].index=0;
		candidate_block[2].brick_block[0].brick_pos[0].g_x=0;
		candidate_block[2].brick_block[0].brick_pos[0].g_y=1;
		candidate_block[2].brick_block[0].brick_pos[1].g_x=1;
		candidate_block[2].brick_block[0].brick_pos[1].g_y=1;
		candidate_block[2].brick_block[0].brick_pos[2].g_x=2;
		candidate_block[2].brick_block[0].brick_pos[2].g_y=1;
		candidate_block[2].brick_block[0].brick_pos[3].g_x=2;
		candidate_block[2].brick_block[0].brick_pos[3].g_y=0;
		candidate_block[2].brick_block[0].area_start_pos.g_x=0;
		candidate_block[2].brick_block[0].area_start_pos.g_y=0;
		candidate_block[2].brick_block[0].area_end_pos.g_x=2;
		candidate_block[2].brick_block[0].area_end_pos.g_y=1;
		
		candidate_block[2].brick_block[1].brick_pos[0].g_x=0;
		candidate_block[2].brick_block[1].brick_pos[0].g_y=0;
		candidate_block[2].brick_block[1].brick_pos[1].g_x=0;
		candidate_block[2].brick_block[1].brick_pos[1].g_y=1;
		candidate_block[2].brick_block[1].brick_pos[2].g_x=0;
		candidate_block[2].brick_block[1].brick_pos[2].g_y=2;
		candidate_block[2].brick_block[1].brick_pos[3].g_x=1;
		candidate_block[2].brick_block[1].brick_pos[3].g_y=2;
		candidate_block[2].brick_block[1].area_start_pos.g_x=0;
		candidate_block[2].brick_block[1].area_start_pos.g_y=0;
		candidate_block[2].brick_block[1].area_end_pos.g_x=1;
		candidate_block[2].brick_block[1].area_end_pos.g_y=2;
		
		candidate_block[2].brick_block[2].brick_pos[0].g_x=0;
		candidate_block[2].brick_block[2].brick_pos[0].g_y=0;
		candidate_block[2].brick_block[2].brick_pos[1].g_x=1;
		candidate_block[2].brick_block[2].brick_pos[1].g_y=0;
		candidate_block[2].brick_block[2].brick_pos[2].g_x=2;
		candidate_block[2].brick_block[2].brick_pos[2].g_y=0;
		candidate_block[2].brick_block[2].brick_pos[3].g_x=0;
		candidate_block[2].brick_block[2].brick_pos[3].g_y=1;
		candidate_block[2].brick_block[2].area_start_pos.g_x=0;
		candidate_block[2].brick_block[2].area_start_pos.g_y=0;
		candidate_block[2].brick_block[2].area_end_pos.g_x=2;
		candidate_block[2].brick_block[2].area_end_pos.g_y=1;
		
		candidate_block[2].brick_block[3].brick_pos[0].g_x=0;
		candidate_block[2].brick_block[3].brick_pos[0].g_y=0;
		candidate_block[2].brick_block[3].brick_pos[1].g_x=1;
		candidate_block[2].brick_block[3].brick_pos[1].g_y=0;
		candidate_block[2].brick_block[3].brick_pos[2].g_x=1;
		candidate_block[2].brick_block[3].brick_pos[2].g_y=1;
		candidate_block[2].brick_block[3].brick_pos[3].g_x=1;
		candidate_block[2].brick_block[3].brick_pos[3].g_y=2;
		candidate_block[2].brick_block[3].area_start_pos.g_x=0;
		candidate_block[2].brick_block[3].area_start_pos.g_y=0;
		candidate_block[2].brick_block[3].area_end_pos.g_x=1;
		candidate_block[2].brick_block[3].area_end_pos.g_y=2;
		
		/* brick 4 */
		candidate_block[3].index=0;
		candidate_block[3].brick_block[0].brick_pos[0].g_x=0;
		candidate_block[3].brick_block[0].brick_pos[0].g_y=0;
		candidate_block[3].brick_block[0].brick_pos[1].g_x=1;
		candidate_block[3].brick_block[0].brick_pos[1].g_y=0;
		candidate_block[3].brick_block[0].brick_pos[2].g_x=0;
		candidate_block[3].brick_block[0].brick_pos[2].g_y=1;
		candidate_block[3].brick_block[0].brick_pos[3].g_x=1;
		candidate_block[3].brick_block[0].brick_pos[3].g_y=1;
		candidate_block[3].brick_block[0].area_start_pos.g_x=0;
		candidate_block[3].brick_block[0].area_start_pos.g_y=0;
		candidate_block[3].brick_block[0].area_end_pos.g_x=1;
		candidate_block[3].brick_block[0].area_end_pos.g_y=1;
		
		candidate_block[3].brick_block[1].brick_pos[0].g_x=0;
		candidate_block[3].brick_block[1].brick_pos[0].g_y=0;
		candidate_block[3].brick_block[1].brick_pos[1].g_x=0;
		candidate_block[3].brick_block[1].brick_pos[1].g_y=1;
		candidate_block[3].brick_block[1].brick_pos[2].g_x=1;
		candidate_block[3].brick_block[1].brick_pos[2].g_y=0;
		candidate_block[3].brick_block[1].brick_pos[3].g_x=1;
		candidate_block[3].brick_block[1].brick_pos[3].g_y=1;
		candidate_block[3].brick_block[1].area_start_pos.g_x=0;
		candidate_block[3].brick_block[1].area_start_pos.g_y=0;
		candidate_block[3].brick_block[1].area_end_pos.g_x=1;
		candidate_block[3].brick_block[1].area_end_pos.g_y=1;
		
		candidate_block[3].brick_block[2].brick_pos[0].g_x=0;
		candidate_block[3].brick_block[2].brick_pos[0].g_y=0;
		candidate_block[3].brick_block[2].brick_pos[1].g_x=1;
		candidate_block[3].brick_block[2].brick_pos[1].g_y=0;
		candidate_block[3].brick_block[2].brick_pos[2].g_x=0;
		candidate_block[3].brick_block[2].brick_pos[2].g_y=1;
		candidate_block[3].brick_block[2].brick_pos[3].g_x=1;
		candidate_block[3].brick_block[2].brick_pos[3].g_y=1;
		candidate_block[3].brick_block[2].area_start_pos.g_x=0;
		candidate_block[3].brick_block[2].area_start_pos.g_y=0;
		candidate_block[3].brick_block[2].area_end_pos.g_x=1;
		candidate_block[3].brick_block[2].area_end_pos.g_y=1;
		
		candidate_block[3].brick_block[3].brick_pos[0].g_x=0;
		candidate_block[3].brick_block[3].brick_pos[0].g_y=0;
		candidate_block[3].brick_block[3].brick_pos[1].g_x=0;
		candidate_block[3].brick_block[3].brick_pos[1].g_y=1;
		candidate_block[3].brick_block[3].brick_pos[2].g_x=1;
		candidate_block[3].brick_block[3].brick_pos[2].g_y=0;
		candidate_block[3].brick_block[3].brick_pos[3].g_x=1;
		candidate_block[3].brick_block[3].brick_pos[3].g_y=1;
		candidate_block[3].brick_block[3].area_start_pos.g_x=0;
		candidate_block[3].brick_block[3].area_start_pos.g_y=0;
		candidate_block[3].brick_block[3].area_end_pos.g_x=1;
		candidate_block[3].brick_block[3].area_end_pos.g_y=1;
		
		/* brick 5 */
		candidate_block[4].index=0;
		candidate_block[4].brick_block[0].brick_pos[0].g_x=0;
		candidate_block[4].brick_block[0].brick_pos[0].g_y=0;
		candidate_block[4].brick_block[0].brick_pos[1].g_x=0;
		candidate_block[4].brick_block[0].brick_pos[1].g_y=1;
		candidate_block[4].brick_block[0].brick_pos[2].g_x=1;
		candidate_block[4].brick_block[0].brick_pos[2].g_y=1;
		candidate_block[4].brick_block[0].brick_pos[3].g_x=2;
		candidate_block[4].brick_block[0].brick_pos[3].g_y=1;
		candidate_block[4].brick_block[0].area_start_pos.g_x=0;
		candidate_block[4].brick_block[0].area_start_pos.g_y=0;
		candidate_block[4].brick_block[0].area_end_pos.g_x=2;
		candidate_block[4].brick_block[0].area_end_pos.g_y=1;
		
		candidate_block[4].brick_block[1].brick_pos[0].g_x=0;
		candidate_block[4].brick_block[1].brick_pos[0].g_y=0;
		candidate_block[4].brick_block[1].brick_pos[1].g_x=0;
		candidate_block[4].brick_block[1].brick_pos[1].g_y=1;
		candidate_block[4].brick_block[1].brick_pos[2].g_x=0;
		candidate_block[4].brick_block[1].brick_pos[2].g_y=2;
		candidate_block[4].brick_block[1].brick_pos[3].g_x=1;
		candidate_block[4].brick_block[1].brick_pos[3].g_y=0;
		candidate_block[4].brick_block[1].area_start_pos.g_x=0;
		candidate_block[4].brick_block[1].area_start_pos.g_y=0;
		candidate_block[4].brick_block[1].area_end_pos.g_x=1;
		candidate_block[4].brick_block[1].area_end_pos.g_y=2;
		
		candidate_block[4].brick_block[2].brick_pos[0].g_x=0;
		candidate_block[4].brick_block[2].brick_pos[0].g_y=0;
		candidate_block[4].brick_block[2].brick_pos[1].g_x=1;
		candidate_block[4].brick_block[2].brick_pos[1].g_y=0;
		candidate_block[4].brick_block[2].brick_pos[2].g_x=2;
		candidate_block[4].brick_block[2].brick_pos[2].g_y=0;
		candidate_block[4].brick_block[2].brick_pos[3].g_x=2;
		candidate_block[4].brick_block[2].brick_pos[3].g_y=1;
		candidate_block[4].brick_block[2].area_start_pos.g_x=0;
		candidate_block[4].brick_block[2].area_start_pos.g_y=0;
		candidate_block[4].brick_block[2].area_end_pos.g_x=2;
		candidate_block[4].brick_block[2].area_end_pos.g_y=1;
		
		candidate_block[4].brick_block[3].brick_pos[0].g_x=1;
		candidate_block[4].brick_block[3].brick_pos[0].g_y=0;
		candidate_block[4].brick_block[3].brick_pos[1].g_x=1;
		candidate_block[4].brick_block[3].brick_pos[1].g_y=1;
		candidate_block[4].brick_block[3].brick_pos[2].g_x=1;
		candidate_block[4].brick_block[3].brick_pos[2].g_y=2;
		candidate_block[4].brick_block[3].brick_pos[3].g_x=0;
		candidate_block[4].brick_block[3].brick_pos[3].g_y=2;
		candidate_block[4].brick_block[3].area_start_pos.g_x=0;
		candidate_block[4].brick_block[3].area_start_pos.g_y=0;
		candidate_block[4].brick_block[3].area_end_pos.g_x=1;
		candidate_block[4].brick_block[3].area_end_pos.g_y=2;
		
		/* brick 6 */
		candidate_block[5].index=0;
		candidate_block[5].brick_block[0].brick_pos[0].g_x=0;
		candidate_block[5].brick_block[0].brick_pos[0].g_y=0;
		candidate_block[5].brick_block[0].brick_pos[1].g_x=0;
		candidate_block[5].brick_block[0].brick_pos[1].g_y=1;
		candidate_block[5].brick_block[0].brick_pos[2].g_x=1;
		candidate_block[5].brick_block[0].brick_pos[2].g_y=1;
		candidate_block[5].brick_block[0].brick_pos[3].g_x=1;
		candidate_block[5].brick_block[0].brick_pos[3].g_y=2;
		candidate_block[5].brick_block[0].area_start_pos.g_x=0;
		candidate_block[5].brick_block[0].area_start_pos.g_y=0;
		candidate_block[5].brick_block[0].area_end_pos.g_x=1;
		candidate_block[5].brick_block[0].area_end_pos.g_y=2;
		
		candidate_block[5].brick_block[1].brick_pos[0].g_x=0;
		candidate_block[5].brick_block[1].brick_pos[0].g_y=1;
		candidate_block[5].brick_block[1].brick_pos[1].g_x=1;
		candidate_block[5].brick_block[1].brick_pos[1].g_y=0;
		candidate_block[5].brick_block[1].brick_pos[2].g_x=1;
		candidate_block[5].brick_block[1].brick_pos[2].g_y=1;
		candidate_block[5].brick_block[1].brick_pos[3].g_x=2;
		candidate_block[5].brick_block[1].brick_pos[3].g_y=0;
		candidate_block[5].brick_block[1].area_start_pos.g_x=0;
		candidate_block[5].brick_block[1].area_start_pos.g_y=0;
		candidate_block[5].brick_block[1].area_end_pos.g_x=2;
		candidate_block[5].brick_block[1].area_end_pos.g_y=1;
		
		candidate_block[5].brick_block[2].brick_pos[0].g_x=0;
		candidate_block[5].brick_block[2].brick_pos[0].g_y=0;
		candidate_block[5].brick_block[2].brick_pos[1].g_x=0;
		candidate_block[5].brick_block[2].brick_pos[1].g_y=1;
		candidate_block[5].brick_block[2].brick_pos[2].g_x=1;
		candidate_block[5].brick_block[2].brick_pos[2].g_y=1;
		candidate_block[5].brick_block[2].brick_pos[3].g_x=1;
		candidate_block[5].brick_block[2].brick_pos[3].g_y=2;
		candidate_block[5].brick_block[2].area_start_pos.g_x=0;
		candidate_block[5].brick_block[2].area_start_pos.g_y=0;
		candidate_block[5].brick_block[2].area_end_pos.g_x=1;
		candidate_block[5].brick_block[2].area_end_pos.g_y=2;
		
		candidate_block[5].brick_block[3].brick_pos[0].g_x=0;
		candidate_block[5].brick_block[3].brick_pos[0].g_y=1;
		candidate_block[5].brick_block[3].brick_pos[1].g_x=1;
		candidate_block[5].brick_block[3].brick_pos[1].g_y=0;
		candidate_block[5].brick_block[3].brick_pos[2].g_x=1;
		candidate_block[5].brick_block[3].brick_pos[2].g_y=1;
		candidate_block[5].brick_block[3].brick_pos[3].g_x=2;
		candidate_block[5].brick_block[3].brick_pos[3].g_y=0;
		candidate_block[5].brick_block[3].area_start_pos.g_x=0;
		candidate_block[5].brick_block[3].area_start_pos.g_y=0;
		candidate_block[5].brick_block[3].area_end_pos.g_x=2;
		candidate_block[5].brick_block[3].area_end_pos.g_y=1;
		
		/* brick 7 */
		candidate_block[6].index=0;
		candidate_block[6].brick_block[0].brick_pos[0].g_x=1;
		candidate_block[6].brick_block[0].brick_pos[0].g_y=0;
		candidate_block[6].brick_block[0].brick_pos[1].g_x=0;
		candidate_block[6].brick_block[0].brick_pos[1].g_y=1;
		candidate_block[6].brick_block[0].brick_pos[2].g_x=1;
		candidate_block[6].brick_block[0].brick_pos[2].g_y=1;
		candidate_block[6].brick_block[0].brick_pos[3].g_x=0;
		candidate_block[6].brick_block[0].brick_pos[3].g_y=2;
		candidate_block[6].brick_block[0].area_start_pos.g_x=0;
		candidate_block[6].brick_block[0].area_start_pos.g_y=0;
		candidate_block[6].brick_block[0].area_end_pos.g_x=1;
		candidate_block[6].brick_block[0].area_end_pos.g_y=2;
		
		candidate_block[6].brick_block[1].brick_pos[0].g_x=0;
		candidate_block[6].brick_block[1].brick_pos[0].g_y=0;
		candidate_block[6].brick_block[1].brick_pos[1].g_x=1;
		candidate_block[6].brick_block[1].brick_pos[1].g_y=0;
		candidate_block[6].brick_block[1].brick_pos[2].g_x=1;
		candidate_block[6].brick_block[1].brick_pos[2].g_y=1;
		candidate_block[6].brick_block[1].brick_pos[3].g_x=2;
		candidate_block[6].brick_block[1].brick_pos[3].g_y=1;
		candidate_block[6].brick_block[1].area_start_pos.g_x=0;
		candidate_block[6].brick_block[1].area_start_pos.g_y=0;
		candidate_block[6].brick_block[1].area_end_pos.g_x=2;
		candidate_block[6].brick_block[1].area_end_pos.g_y=1;
		
		candidate_block[6].brick_block[2].brick_pos[0].g_x=1;
		candidate_block[6].brick_block[2].brick_pos[0].g_y=0;
		candidate_block[6].brick_block[2].brick_pos[1].g_x=0;
		candidate_block[6].brick_block[2].brick_pos[1].g_y=1;
		candidate_block[6].brick_block[2].brick_pos[2].g_x=1;
		candidate_block[6].brick_block[2].brick_pos[2].g_y=1;
		candidate_block[6].brick_block[2].brick_pos[3].g_x=0;
		candidate_block[6].brick_block[2].brick_pos[3].g_y=2;
		candidate_block[6].brick_block[2].area_start_pos.g_x=0;
		candidate_block[6].brick_block[2].area_start_pos.g_y=0;
		candidate_block[6].brick_block[2].area_end_pos.g_x=1;
		candidate_block[6].brick_block[2].area_end_pos.g_y=2;
		
		candidate_block[6].brick_block[3].brick_pos[0].g_x=0;
		candidate_block[6].brick_block[3].brick_pos[0].g_y=0;
		candidate_block[6].brick_block[3].brick_pos[1].g_x=1;
		candidate_block[6].brick_block[3].brick_pos[1].g_y=0;
		candidate_block[6].brick_block[3].brick_pos[2].g_x=1;
		candidate_block[6].brick_block[3].brick_pos[2].g_y=1;
		candidate_block[6].brick_block[3].brick_pos[3].g_x=2;
		candidate_block[6].brick_block[3].brick_pos[3].g_y=1;
		candidate_block[6].brick_block[3].area_start_pos.g_x=0;
		candidate_block[6].brick_block[3].area_start_pos.g_y=0;
		candidate_block[6].brick_block[3].area_end_pos.g_x=2;
		candidate_block[6].brick_block[3].area_end_pos.g_y=1;

		/* end of init brick */
}

