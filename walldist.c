#include "cubthreed.h"

double	calc_dis(t_map *cub)
{
	if (cub->raycast->side1 == 0 || cub->raycast->side1 == 1)
	{
		cub->raycast->perp_dist = (cub->loc_px - cub->player->x \
		+ (1 - cub->raycast->step_x) / 2) / cub->raycast->raydir_x;
		if (cub->raycast->perp_dist <= 0.000001)
			cub->raycast->perp_dist = 0.00001;
		return (cub->player->y + cub->raycast->perp_dist \
				* cub->raycast->raydir_y);
	}
	cub->raycast->perp_dist = (cub->loc_py - cub->player->y \
		+ (1 - cub->raycast->step_y) / 2) / cub->raycast->raydir_y;
	if (cub->raycast->perp_dist <= 0.000001)
		cub->raycast->perp_dist = 0.00001;
	return (cub->player->x + cub->raycast->perp_dist \
			* cub->raycast->raydir_x);
}

void	calc_wall(t_map *cub)
{
	double	wall_x;
	wall_x = calc_dis(cub);
	wall_x -= floor(wall_x);
	cub->raycast->height = (SCREENHEIGHT / cub->raycast->perp_dist);
	cub->raycast->tex_x = (int)(wall_x * (double)TILE);
	if (cub->raycast->side1 == 0 || cub->raycast->side1 == 1)
		cub->raycast->tex_x = TILE - cub->raycast->tex_x - 1;
	else if (cub->raycast->side1 == 2 || cub->raycast->side1 == 3)
		cub->raycast->tex_x = TILE - cub->raycast->tex_x - 1;
	cub->raycast->start_y = -cub->raycast->height / 2 + SCREENHEIGHT / 2;
	if (cub->raycast->start_y < 0)
		cub->raycast->start_y = 0;
	cub->raycast->end_y = cub->raycast->height / 2 + SCREENHEIGHT / 2;
	if (cub->raycast->end_y >= SCREENHEIGHT)
		cub->raycast->end_y = SCREENHEIGHT - 1;
}

void	map_liner(t_map *cub, int x)
{
	double	step;
	double	tex_pos;
	int		i;
	int		tex_y;
	int		color;

	step = 1.0 * TILE / cub->raycast->height;
	tex_pos = (cub->raycast->start_y - SCREENHEIGHT \
				/ 2 + cub->raycast->height / 2) * step;
	i = cub->raycast->start_y;
	while (i <= cub->raycast->end_y)
	{
		tex_y = (int)tex_pos & 63;
		tex_pos += step;
		color = cub->walls[cub->raycast->side1]->addr[(TILE * tex_y) \
			+ cub->raycast->tex_x];
		cub->mlx_data[i * SCREENWIDTH + x] = color;
		i++;
	}
}
