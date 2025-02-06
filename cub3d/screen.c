#include "cubthreed.h"

void	init_screen(t_map *cub)
{
	cub->img_ptr = mlx_new_image(cub->mlx, SCREENWIDTH, SCREENHEIGHT);
	if (!cub->img_ptr)
		ft_error("img_ptr error!");
	cub->mlx_data = (int *)mlx_get_data_addr(cub->img_ptr,
			&cub->pixel_bits, &cub->line_bytes, &cub->endian);
	if (!cub->mlx_data)
		ft_error("mlx_data error!");
	set_cf_texture(cub);
}
