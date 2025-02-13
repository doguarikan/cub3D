
#include "cubthreed.h"

void	calc_side(t_map *cub)
{
	if (cub->raycast->raydir_x < 0)
	{
		cub->raycast->step_x = -1;
		cub->raycast->next_hit_dist_x = (cub->player->loc_x \
		- cub->loc_px_index) * cub->raycast->dist_x_pstep;
	}
	else
	{
		cub->raycast->step_x = 1;
		cub->raycast->next_hit_dist_x = (cub->loc_px_index + 1.0 \
			- cub->player->loc_x) * cub->raycast->dist_x_pstep;
	}
	if (cub->raycast->raydir_y < 0)
	{
		cub->raycast->step_y = -1;
		cub->raycast->next_hit_dist_y = (cub->player->loc_y \
			- cub->loc_py_index) * cub->raycast->dist_y_pstep;
	}
	else
	{
		cub->raycast->step_y = 1;
		cub->raycast->next_hit_dist_y = (cub->loc_py_index + 1.0 \
			- cub->player->loc_y) * cub->raycast->dist_y_pstep;
	}
}

void	calc_ray(t_map *cub, int x)
{
	init_raycast(cub, x);
	calc_side(cub);
}

void	dda(t_map *cub)
{
	while (cub->raycast->wall_hit == 0)
	{
		if (cub->raycast->next_hit_dist_x < cub->raycast->next_hit_dist_y)
		{
			cub->raycast->next_hit_dist_x += cub->raycast->dist_x_pstep;
			cub->loc_px_index += cub->raycast->step_x;
			if (cub->raycast->step_x == 1)
				cub->raycast->wall_hit_dir = 1;
			else
				cub->raycast->wall_hit_dir = 0;
		}
		else
		{
			cub->raycast->next_hit_dist_y += cub->raycast->dist_y_pstep;
			cub->loc_py_index += cub->raycast->step_y;
			if (cub->raycast->step_y == 1)
				cub->raycast->wall_hit_dir = 2;
			else
				cub->raycast->wall_hit_dir = 3;
		}
		if (cub->map_game[cub->loc_py_index][cub->loc_px_index] == '1')
			cub->raycast->wall_hit = 1;
	}
}
