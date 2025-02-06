#include "cubthreed.h"

void	calc_side(t_map *cub)
{
	if (cub->raycast->raydir_x < 0)
	{
		cub->raycast->step_x = -1;
		cub->raycast->sidedist_x = (cub->player->x - cub->loc_px) \
			* cub->raycast->deltadist_x;
	}
	else
	{
		cub->raycast->step_x = 1;
		cub->raycast->sidedist_x = (cub->loc_px + 1.0 - cub->player->x) \
			* cub->raycast->deltadist_x;
	}
	if (cub->raycast->raydir_y < 0)
	{
		cub->raycast->step_y = -1;
		cub->raycast->sidedist_y = (cub->player->y - cub->loc_py) \
			* cub->raycast->deltadist_y;
	}
	else
	{
		cub->raycast->step_y = 1;
		cub->raycast->sidedist_y = (cub->loc_py + 1.0 - cub->player->y) \
			* cub->raycast->deltadist_y;
	}
}

void	calc_ray(t_map *cub, int x)
{
	init_raycast(cub, x);
	calc_side(cub);
}

void	dda(t_map *cub)
{
	while (cub->raycast->hit == 0)
	{
		if (cub->raycast->sidedist_x < cub->raycast->sidedist_y)
		{
			cub->raycast->sidedist_x += cub->raycast->deltadist_x;
			cub->loc_px += cub->raycast->step_x;
			if (cub->raycast->step_x == 1)
				cub->raycast->side1 = 1;
			else
				cub->raycast->side1 = 0;
		}
		else
		{
			cub->raycast->sidedist_y += cub->raycast->deltadist_y;
			cub->loc_py += cub->raycast->step_y;
			if (cub->raycast->step_y == 1)
				cub->raycast->side1 = 2;
			else
				cub->raycast->side1 = 3;
		}
		if (cub->map_game[cub->loc_py][cub->loc_px] == '1')
			cub->raycast->hit = 1;
	}
}

void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
