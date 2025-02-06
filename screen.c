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
		ft_error("mlx_data error!"); // !?! img pointer falan freelenmeli mi?
		exit(1);
	}
	set_cf_texture(cub);
}
