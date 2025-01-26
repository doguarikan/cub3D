#include "cubthreed.h"

int	create_xpm(t_map *cub)
{
	int	x;
	int	y;
	int		img_width;
	int		img_height;

	img_width = 32;
	img_height = 32;
	cub->wall_ea = mlx_xpm_file_to_image(cub->mlx, cub->tex_ea, &img_width, &img_height);
	cub->wall_no = mlx_xpm_file_to_image(cub->mlx, cub->tex_no, &img_width, &img_height);
	cub->wall_so = mlx_xpm_file_to_image(cub->mlx, cub->tex_so, &img_width, &img_height);
	cub->wall_we = mlx_xpm_file_to_image(cub->mlx, cub->tex_we, &img_width, &img_height);
	if (!cub->wall_no || !cub->wall_so || !cub->wall_we || !cub->wall_so)
	{
		ft_error("XPM error.");
		//safe_exit(cub); burda hata falan kotrolu lazın
	}
	return (0);
}

int	safe_exit(t_map *cub)//eksik
{
	mlx_destroy_image(cub->mlx, cub->wall_ea);
	mlx_destroy_image(cub->mlx, cub->wall_so);
	mlx_destroy_image(cub->mlx, cub->wall_we);
	mlx_destroy_image(cub->mlx, cub->wall_no);
	mlx_clear_window(cub->mlx, cub->mlx_win);
	return (0);
}

/*
int	ft_move(int key, t_map *cub)
{
	int		x;
	int		y;
	char	*move;

	x = cub->p_x;
	y = cub->p_y;
	if (key == 13)
		y--;
	else if (key == 1)
		y++;
	else if (key == 2)
		x++;
	else if (key == 0)
		x--;
	else if (key == 53)
		safe_exit(cub);
	else
		return (0);
	mlx_clear_window(cub->mlx, cub->mlx_win);
	map_move(cub, x, y);
	put_image(cub);
	move = ft_itoa(cub->playermove);
	mlx_string_put(cub->mlx, cub->mlx_win, 15, 15, 16777215, move);
	free(move);
	return (0);
}

void	put_image_extra(t_map *cub, void *img, int x, int y)
{
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, img, 64 * x, 64 * y);
}

int	put_image(t_map *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (cub->map_line[y][x])
	{
		if (cub->map_line[y] && cub->map_line[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		if (cub->map_line[y][x] == 'E')
			put_image_extra(cub, cub->wall_ea, x, y);
		if (cub->map_line[y][x] == 'C')
			put_image_extra(cub, cub->wall_no, x, y);
		if (cub->map_line[y][x] == 'P')
			put_image_extra(cub, cub->wall_we, cub->p_x, cub->p_y);
		if (cub->map_line[y][x] == '1')
			put_image_extra(cub, cub->wall_so, x, y);
		x++;
	}
	return (0);
}


int	map_init(t_map *cub, char *argv)
{
	int	x;

	cub->playermove = 0;
	cub->mlx = mlx_init();
	x = ft_strlen(cub->map_line[0]) - 1;
	cub->mlx_win = mlx_new_window(cub->mlx, \
		64 * x, 64 * cub->map_y_line, "cub3d");
	if (!cub->mlx || !cub->mlx_win || create_xpm(cub))
	{
		printf("Error : mlx or mlx_win is NULL!\n");
		return (1);
	}
	put_image(cub);
	mlx_string_put(cub->mlx, cub->mlx_win, 15, 15, 16777215, "0");
	//mlx_hook(cub->mlx_win, 2, 1L << 2, ft_move, cub);
	//mlx_hook(cub->mlx_win, 17, 1L << 2, safe_exit, cub);
	mlx_loop(cub->mlx);
	return (0);
}
int	main(int argc, char **argv)
{
	t_map	cub;

	if (arg_checker(argc, argv[1]) || map_read_check(&cub, argv[1]))
		return (1);
	if (map_checker(&cub))
		return (1);
	if ((&cub)->map_y_line > 20 || (&cub)->map_x_line > 40)
	{
		ft_printf("Error : extends out!\n");
		return (1);
	}

	if (map_init(&cub, argv[1]))
		return (1);
	return (0);
}
*/
