
#include "cubthreed.h"

int	exit_game(t_map *cub)
{
	ft_free_img(cub, 3);
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_image(cub->mlx, cub->img_ptr);
	if (cub->mlx)
	{
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
	ft_free_parse(cub);
	exit(0);
}

int	key_pressed(int keycode, t_map *cub)
{
	if (keycode == 65307)
		exit_game(cub);
	if (keycode == 119)
		cub->key->w = 1;
	if (keycode == 97)
		cub->key->a = 1;
	if (keycode == 115)
		cub->key->s = 1;
	if (keycode == 100)
		cub->key->d = 1;
	if (keycode == 65361)
		cub->key->left = 1;
	if (keycode == 65363)
		cub->key->right = 1;
	return (0);
}

int	key_released(int keycode, t_map *cub)
{
	if (keycode == 119)
		cub->key->w = 0;
	if (keycode == 97)
		cub->key->a = 0;
	if (keycode == 115)
		cub->key->s = 0;
	if (keycode == 100)
		cub->key->d = 0;
	if (keycode == 65361)
		cub->key->left = 0;
	if (keycode == 65363)
		cub->key->right = 0;
	return (0);
}

void	player_game(t_map *cub)
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
	draw_fc(cub);
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
