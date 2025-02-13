
#include "cubthreed.h"

void	ft_free_struct(t_map *cub)
{
	free(cub->key);
	free(cub->player);
	free(cub->raycast);
}

int	ft_free_cub(t_map *cub)
{
	ft_free_array(cub->tmp_map);
	ft_free_array(cub->map_line);
	ft_free_array(cub->is_dup);
	ft_free_array(cub->map_game);
	ft_free_struct(cub);
	free(cub);
	return (1);
}

void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_color(t_map *cub)
{
	ft_free_array(cub->floor_char);
	ft_free_array(cub->sky_char);
	ft_free_cub(cub);
}

void	ft_free_parse(t_map *cub)
{
	ft_free_array(cub->tmp_map);
	ft_free_array(cub->map_line);
	ft_free_array(cub->map_game);
	ft_free_array(cub->is_dup);
	ft_free_array(cub->floor_char);
	ft_free_array(cub->sky_char);
	free(cub->tex_ea);
	free(cub->tex_so);
	free(cub->tex_no);
	free(cub->tex_we);
	free(cub->col_floor);
	free(cub->col_sky);
	ft_free_struct(cub);
	free(cub);
}
