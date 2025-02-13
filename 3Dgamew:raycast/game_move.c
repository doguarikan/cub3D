
#include "cubthreed.h"

void	move_ws(t_map *cub, int direction)
{
	double	des_x;
	double	des_y;

	des_x = cub->player->loc_x + cub->player->dir_x * (double)1 / 50
		* direction;
	des_y = cub->player->loc_y + cub->player->dir_y * (double)1 / 50
		* direction;
	if (cub->map_game[(int)cub->player->loc_y][(int)des_x] == '0')
		cub->player->loc_x = des_x;
	if (cub->map_game[(int)des_y][(int)cub->player->loc_x] == '0')
		cub->player->loc_y = des_y;
}

void	move_ad(t_map *cub, int direction)
{
	double	des_x;
	double	des_y;

	des_x = cub->player->loc_x + cub->player->plane_x
		* (double)1 / 50 * direction;
	des_y = cub->player->loc_y + cub->player->plane_y
		* (double)1 / 50 * direction;
	if (cub->map_game[(int)cub->player->loc_y][(int)des_x] == '0')
		cub->player->loc_x = des_x;
	if (cub->map_game[(int)des_y][(int)cub->player->loc_x] == '0')
		cub->player->loc_y = des_y;
}

void	rotate_player(t_map *cub, int direction)
{
	double	old_dirx;
	double	old_planex;
	double	rotate_angle;

	rotate_angle = 0.007 * direction;
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

int	ft_sp(int input)
{
	if (input > 32 && input <= 126)
	{
		return (1);
	}
	return (0);
}

void	count_check(t_map *cub, int count)
{
	if (count != 1)
	{
		ft_free_cub(cub);
		ft_error("Invalid character count on the map file!");
		exit(1);
	}
}
