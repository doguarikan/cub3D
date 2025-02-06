#include "cubthreed.h"

void	set_cf_texture(t_map *cub)
{
	cub->ceiling_texture = cub->col_sky[0] * 65536 + cub->col_sky[1] * 256 + cub->col_sky[2];
	cub->floor_texture = cub->col_floor[0] * 65536 + cub->col_floor[1] * 256 + cub->col_floor[2];
}

void	draw_floor_ceiling(t_map *cub)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < SCREENHEIGHT / 2)
	{
		n = 0;
		while (n < SCREENWIDTH)
		{
			cub->mlx_data[i * SCREENWIDTH + n] = cub->ceiling_texture;
			n++;
		}
		i++;
	}
	while (i < SCREENHEIGHT)
	{
		n = 0;
		while (n < SCREENWIDTH)
		{
			cub->mlx_data[i * SCREENWIDTH + n] = cub->floor_texture;
			n++;
		}
		i++;
	}
}
