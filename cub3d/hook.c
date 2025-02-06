#include "cubthreed.h"

int	exit_game(t_map *cub)
{
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	exit(0);
}

void	player_game(t_map *cub) // hareketten sonra player yön ve yerini hesaplama
{
	if (cub->key->w)
		move_ws(cub, 1);
	if (cub->key->s)
		move_ws(cub, -1);
	if (cub->key->a)
		move_ad(cub, -1);
	if (cub->key->d)
		move_ad(cub, 1);
	if (cub->key->right)
		rotate_player(cub, 1);
	if (cub->key->left)
		rotate_player(cub, -1);
}

int	game_hook(void *param)
{
	int		x;
	t_map	*cub;

	cub = (t_map *)param;
	x = 0;
	draw_floor_ceiling(cub);
	player_game(cub);
	while (x < SCREENWIDTH)
	{
		calc_ray(cub, x);
		dda(cub);
		calc_wall(cub);
		map_liner(cub, x);
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img_ptr, 0, 0);
	return (0);
}
