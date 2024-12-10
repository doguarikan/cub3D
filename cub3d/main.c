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

int	main()
{
	t_map	*cub;
	cub = (t_map *)malloc(sizeof(t_map));
	if (!cub)
		return (1);
	//map read and control

	//init map
	init_map(cub);

	//free and exit
	return (0);
}
