#include "cubthreed.h"

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
		free(cub->tmp_map); // !?! fd -1 ise zaten tmp_map freelendi
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
	if (arg_checker(argc, argv) || map_read_check(cub, argv[1]))
	{
		free(cub);
		return (1);
	}
	cub->key = ft_calloc(sizeof(t_keycode), 1);
	cub->player = ft_calloc(sizeof(t_player), 1);
	cub->raycast = ft_calloc(sizeof(t_raycast), 1);
	if (!cub->key || !cub->player || !cub->raycast) //!?! birisi acılıp diğerleri acılmazsa leak verir mi 
	{
		ft_free_array(cub->tmp_map);
		free(cub);
		return (1);
	}
	if(!split_map(cub))
	{
		ft_free_array(cub->tmp_map);
		ft_free_struct(cub);
		free(cub);
		return (1);
	}
	if(map_check(cub))
	{
		cub_free(cub);
		return (1);
	}
	map_control(cub);  // haritanın çevresi 1 ile kaplı mı? floodfillde bunun içinde exitle çıkıyor bunlar
	if(!handle_color(cub))
	{
		ft_error("Color error");
		cub_free(cub);
		return (1);
	}
	handle_texture(cub);
	
	cub->mlx = mlx_init();
	if (!cub->mlx)
	{
		ft_free_parse(cub);
		ft_error("Mlx doesn't work!");
		return (1);
	}
	cub->win = mlx_new_window(cub->mlx, SCREENWIDTH, SCREENHEIGHT, "cub3D");
	init_screen(cub);
	init_player(cub);
	set_walls(cub);

	mlx_hook(cub->win, 2, (1L << 0), key_pressed, cub);
	mlx_hook(cub->win, 3, (1L << 1), key_released, cub);
	mlx_hook(cub->win, 17, 0, exit_game, cub);
	mlx_loop_hook(cub->mlx, game_hook, cub);
	mlx_loop(cub->mlx);

	free(cub->walls);
	ft_free_parse(cub); // destroylar exit_gameye eklenecek buraya da lazım mı???
	return (0);
}
