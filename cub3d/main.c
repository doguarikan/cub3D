#include "cubthreed.h"

int	init_map(t_map *cub)
{
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, 1280, 720, "cub3D");
	create_xpm(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->wall_ea, 64, 64);
    mlx_loop(cub->mlx);
	return(0);
}

int ft_error(char *line)// int mi voidmi
{
	printf("Error\n%s\n", line);
	return (1); // 1 mi 0 mı?
}

int	arg_checker(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		ft_error("Invalid argument count!");
		return (1);
	}
	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 'b' && argv[1][len - 2] != 'u' &&  // dosya uzantısı .cub ile mi bitiyor kontolü
			argv[1][len - 3] != 'c' && argv[1][len - 4] != '.')
	{
		ft_error("File extension must be .cub!\n");
		return (1);
	}
	return (0);
}

int	map_read_check(t_map *cub, char *f_name)
{
	read_chars(cub, f_name);
	if (!(cub->tmp_map)) // map okuma işleminden sonra okunabilmiş mi kontrolü
	{
		free(cub->tmp_map);
		ft_error("Cannot read the map!");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*cub;
	//t_mlx	*minx;

	cub = (t_map *)malloc(sizeof(t_map));
	if (!cub)
		return (1);
	if (arg_checker(argc, argv) || map_read_check(cub, argv[1]))
	{
		free (cub);
		return (1);
	}
	if(!split_map(cub))
	{
		free(cub);
		return (1);
	}
	if(map_check(cub))
		return (1);
	control_wall(cub);
	if(!handle_color(cub))
	{
		ft_error("Color error");
		cub_free(cub);
		return (1);
	}
	
	handle_texture(cub);

	//minx = (t_map *)malloc(sizeof(t_map));
	//if (!minx)
	//	return (1);
	

	//init map
	init_map(cub);

	//free and exit
	return (0);
}
