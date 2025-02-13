
#include "cubthreed.h"

void	ft_free_texture(t_map *cub)
{
	ft_free_parse(cub);
	ft_error("Malloc doesn't work!");
	exit(1);
}

void	ft_free_img(t_map *cub, int index)
{
	if (!cub || !cub->walls)
		return ;
	while (index >= 0)
	{
		if (cub->walls[index])
		{
			if (cub->walls[index]->img)
				mlx_destroy_image(cub->mlx, cub->walls[index]->img);
			free(cub->walls[index]);
		}
		index--;
	}
}

void	xpm_to_img(t_map *cub, char *path, int index)
{
	cub->walls[index] = malloc(sizeof(t_textures));
	if (!cub->walls[index])
	{
		ft_error("Malloc doesn't work!");
		exit(1);
	}
	cub->walls[index]->img = mlx_xpm_file_to_image(cub->mlx, path,
			&cub->walls[index]->w, &cub->walls[index]->h);
	if (!cub->walls[index]->img)
	{
		img_exit(cub, index);
		exit(1);
	}
	cub->walls[index]->addr = \
	(int *)mlx_get_data_addr(cub->walls[index]->img, \
	&cub->walls[index]->bpp, &cub->walls[index]->line_len, \
	&cub->walls[index]->endian);
	if (!cub->walls[index]->addr)
	{
		img_exit(cub, index);
		exit(1);
	}
}

void	set_walls(t_map *cub)
{
	xpm_to_img(cub, cub->tex_ea, 0);
	xpm_to_img(cub, cub->tex_we, 1);
	xpm_to_img(cub, cub->tex_no, 2);
	xpm_to_img(cub, cub->tex_so, 3);
}

void	img_exit(t_map *cub, int index)
{
	ft_free_img(cub, index);
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_image(cub->mlx, cub->img_ptr);
	if (cub->mlx)
	{
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
	ft_free_parse(cub);
	ft_error("Image doesn't work!");
}
