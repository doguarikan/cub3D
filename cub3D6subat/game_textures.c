#include "cubthreed.h"

void	xpm_to_img(t_map *cub, char *path, int index)
{
	cub->walls[index] = malloc(sizeof(t_textures));
	if (!cub->walls[index])
	{
		ft_free_parse(cub); // !?! buraya ilk girisinden sonra malloc calısmaz ise onceki walls indexlerini freelemek gerekir mi
		ft_error("Malloc doesn't work!"); // !?! gerekirse bunu nasıl yaparız???!!!
		exit(1);
	}
	cub->walls[index]->img = mlx_xpm_file_to_image(cub->mlx, path,
			&cub->walls[index]->w, &cub->walls[index]->h);
	if (!cub->walls[index]->img)
	{
		ft_free_parse(cub); // !?! o index freelenmeli mi???
		ft_error("Texture doesn't work!");
		exit(1);
	}
	cub->walls[index]->addr = \
	(int *)mlx_get_data_addr(cub->walls[index]->img, \
	&cub->walls[index]->bpp, &cub->walls[index]->line_len, \
	&cub->walls[index]->endian);
	if (!cub->walls[index]->addr)
	{
		ft_free_parse(cub); // !?! o index freelenmeli mi???
		ft_error("Texture doesn't work!");
		exit(1);
	}
	if (!cub->walls[index]->addr) // !?! aynı kontolden neden iki tane var ???
	{
		ft_free_parse(cub); // !?! o index freelenmeli mi???
		ft_error("Texture doesn't work!");
		exit(1);
	}
}

void	set_walls(t_map *cub)
{
	xpm_to_img(cub, cub->tex_we, 1);
	xpm_to_img(cub, cub->tex_ea, 0);
	xpm_to_img(cub, cub->tex_so, 3);
	xpm_to_img(cub, cub->tex_no, 2);
}
