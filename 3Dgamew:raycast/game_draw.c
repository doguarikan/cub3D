
#include "cubthreed.h"

void	init_screen(t_map *cub)
{
	cub->img_ptr = mlx_new_image(cub->mlx, SCREENWIDTH, SCREENHEIGHT);
	if (!cub->img_ptr)
	{
		ft_free_parse(cub);
		ft_error("img_ptr error!");
		exit(1);
	}
	cub->mlx_data = (int *)mlx_get_data_addr(cub->img_ptr,
			&cub->pixel_bits, &cub->line_bytes, &cub->endian);
	if (!cub->mlx_data)
	{
		ft_free_parse(cub);
		ft_error("mlx_data error!");
		exit(1);
	}
	set_texture(cub);
}

void	set_texture(t_map *cub)
{
	cub->ceiling_texture = cub->col_sky[0] \
		* 65536 + cub->col_sky[1] * 256 + cub->col_sky[2];
	cub->floor_texture = cub->col_floor[0] \
		* 65536 + cub->col_floor[1] * 256 + cub->col_floor[2];
}

void	draw_fc(t_map *cub)
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

void	id_set(t_map *cub)
{
	cub->index_ea = -1;
	cub->index_so = -1;
	cub->index_no = -1;
	cub->index_we = -1;
	cub->index_floor = -1;
	cub->index_sky = -1;
	cub->playercount = 0;
}

void	ft_dupper(t_map *cub, int j, int i)
{
	cub->map_game[j] = ft_strdup(cub->tmp_map[i]);
	cub->map_line[j] = ft_strdup(cub->tmp_map[i]);
	cub->is_dup[j] = ft_strdup(cub->tmp_map[i]);
}
