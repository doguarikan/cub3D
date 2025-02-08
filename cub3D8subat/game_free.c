#include "cubthreed.h"

void ft_free_struct(t_map *cub)
{
	free(cub->key);
	free(cub->player);
	free(cub->raycast);
}

void	cub_free(t_map *cub)
{
	ft_free_array(cub->tmp_map);
	ft_free_array(cub->map_line);
	ft_free_array(cub->map_game);
	ft_free_array(cub->is_dup);
	ft_free_struct(cub);
	free(cub);
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

void ft_free_color(t_map *cub)
{
	ft_free_array(cub->floor_char);
	ft_free_array(cub->sky_char);
	cub_free(cub);
}

void ft_free_parse(t_map *cub)
{
	ft_free_array(cub->tmp_map);
	ft_free_array(cub->map_line);
	ft_free_array(cub->map_game);
	ft_free_array(cub->floor_char);
	ft_free_array(cub->sky_char); // !?! int arrayleri freelemek lazım
	ft_free_struct(cub);
	free(cub);
}