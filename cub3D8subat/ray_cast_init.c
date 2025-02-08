#include "cubthreed.h"

void	init_player_pos(t_map *cub)
{
	if (cub->playertype == 'W')
	{
		cub->player->dir_x = -1;
		cub->player->dir_y = 0;
		cub->player->plane_x = 0;
		cub->player->plane_y = -0.66; // 66derece
	}
	else if (cub->playertype == 'E')
	{
		cub->player->dir_x = 1;
		cub->player->dir_y = 0;
		cub->player->plane_x = 0;
		cub->player->plane_y = 0.66;
	}
}

void	init_player(t_map *cub)
{
	cub->player->x = (double)cub->loc_px;
	cub->player->y = (double)cub->loc_py;
	if (cub->playertype == 'N')
	{
		cub->player->dir_x = 0;
		cub->player->dir_y = -1;
		cub->player->plane_x = 0.66;
		cub->player->plane_y = 0;
	}
	else if (cub->playertype == 'S')
	{
		cub->player->dir_x = 0;
		cub->player->dir_y = 1;
		cub->player->plane_x = -0.66;
		cub->player->plane_y = 0;
	}
	init_player_pos(cub);
}

void	init_raycast(t_map *cub, int x)
{
	cub->raycast->camera_x = 2 * x / (double)SCREENWIDTH - 1;
	cub->raycast->raydir_x = cub->player->dir_x
		+ cub->player->plane_x * cub->raycast->camera_x;
	cub->raycast->raydir_y = cub->player->dir_y
		+ cub->player->plane_y * cub->raycast->camera_x;
	cub->loc_px = (int)cub->player->x;
	cub->loc_py = (int)cub->player->y;
	cub->raycast->deltadist_x = fabs(1 / cub->raycast->raydir_x);
	cub->raycast->deltadist_y = fabs(1 / cub->raycast->raydir_y);
	cub->raycast->hit = 0;
}
