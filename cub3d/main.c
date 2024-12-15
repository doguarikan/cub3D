#include "cubthreed.h"

int	init_map(t_map *cub)
{
	create_xpm(cub);
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, 1280, 720, "cub3D");
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->floor, 32, 32);
    mlx_loop(cub->mlx_win);
	return(0);
}

int	arg_checker(int argc, char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (argc != 2)
	{
		//ft_printf("Error : Invalid number of arguments!\n");
		return (1);
	}
	if (argv[len - 1] != 'b' && argv[len - 2] != 'u' && \
			argv[len - 3] != 'c' && argv[len - 4] != '.')
	{
		//ft_printf("Error : File extension must be .cub!\n");
		return (1);
	}
	return (0);
}

int	map_read_check(t_map *cub, char *f_name)
{
	read_chars(cub, f_name);
	if (!(cub->tmp_map))
	{
		//ft_printf("Error : Cannot read the map!\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*cub;

	cub = (t_map *)malloc(sizeof(t_map));
	if (!cub)
		return (1);
	if (arg_checker(argc, argv[1]) || map_read_check(cub, argv[1]))
		return (1);
	if(!split_map(cub))
		return (1);
	//if (map_checker(cub))
	//	return (1);
	//map read and control

	//init map
	//init_map(cub);

	//free and exit
	return (0);
}
