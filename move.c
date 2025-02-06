#include "cubthreed.h"

void	move_ws(t_map *cub, int direction)
{
	double	des_x;
	double	des_y;

	des_x = cub->player->x + cub->player->dir_x * (double)2 / 10 * direction; // neden 10?
	des_y = cub->player->y + cub->player->dir_y * (double)2 / 10 * direction;
	if (cub->map_game[(int)cub->player->y][(int)des_x] == '0')
		cub->player->x = des_x;
	if (cub->map_game[(int)des_y][(int)cub->player->x] == '0')
		cub->player->y = des_y;
}

void	move_ad(t_map *cub, int direction)
{
	double	des_x;
	double	des_y;

	des_x = cub->player->x + cub->player->plane_x
		* (double)2 / 10 * direction;
	des_y = cub->player->y + cub->player->plane_y
		* (double)2 / 10 * direction;
	if (cub->map_game[(int)cub->player->y][(int)des_x] == '0')
		cub->player->x = des_x;
	if (cub->map_game[(int)des_y][(int)cub->player->x] == '0')
		cub->player->y = des_y;
}

void	rotate_player(t_map *cub, int direction)
{
	double	old_dirx;
	double	old_planex;
	double	rotate_angle;

	rotate_angle = 0.05 * direction;
	old_dirx = cub->player->dir_x;
	cub->player->dir_x = cub->player->dir_x * cos(rotate_angle)
		- cub->player->dir_y * sin(rotate_angle);
	cub->player->dir_y = old_dirx * sin(rotate_angle)
		+ cub->player->dir_y * cos(rotate_angle);
	old_planex = cub->player->plane_x;
	cub->player->plane_x = cub->player->plane_x * cos(rotate_angle)
		- cub->player->plane_y * sin(rotate_angle);
	cub->player->plane_y = old_planex * sin(rotate_angle)
		+ cub->player->plane_y * cos(rotate_angle);
}
