#include "cubthreed.h"
/*
int	init_map(t_map *cub)
{
	//create_xpm(cub);
	//cub->mlx = mlx_init();
	//cub->mlx_win = mlx_new_window(cub->mlx, 1280, 720, "cub3D");
	//mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->floor, 32, 32);
    //mlx_loop(cub->mlx_win);
	return(0);
}
*/
int ft_error(char *line)
{
	printf("Error %s\n", line);
	return (1); // 1 mi 0 mı?
}

int	arg_checker(int argc, char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (argc != 2)
	{
		ft_error("Invalid argument count!");
		return (1);
	}
	if (argv[len - 1] != 'b' && argv[len - 2] != 'u' && \
			argv[len - 3] != 'c' && argv[len - 4] != '.')
	{
		ft_error("File extension must be .cub!\n");
		return (1);
	}
	return (0);
}

int	map_read_check(t_map *cub, char *f_name)
{
	read_chars(cub, f_name);
	if (!(cub->tmp_map))
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

	cub = (t_map *)malloc(sizeof(t_map));
	if (!cub)
		return (1);
	if (arg_checker(argc, argv[1]) || map_read_check(cub, argv[1]))
	{
		free (cub);
		return (1);
	}
	if(!split_map(cub))
		return (1);
	if(map_check(cub))
		return (1);
	control_wall(cub);
	

	//init map
	//init_map(cub);

	//free and exit
	return (0);
}
