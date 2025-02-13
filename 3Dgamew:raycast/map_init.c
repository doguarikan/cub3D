
#include "cubthreed.h"

int	set_color(t_map	*cub)
{
	if (coma_count(cub))
		return (1);
	cub->floor_char = ft_split(cub->tmp_map[cub->index_floor], ',');
	if (!cub->floor_char)
		return (1);
	cub->sky_char = ft_split(cub->tmp_map[cub->index_sky], ',');
	if (!cub->sky_char)
	{
		ft_free_array(cub->floor_char);
		return (1);
	}
	if (process_color_array(cub->floor_char)
		|| process_color_array(cub->sky_char))
	{
		return (1);
	}
	color_atoi(cub);
	return (0);
}

int	*allocate_color_array(t_map *cub, int is_floor)
{
	int	*array;

	array = (int *)malloc(3 * sizeof(int));
	if (!array)
	{
		if (is_floor)
		{
			ft_free_color(cub);
		}
		else
		{
			free(cub->col_floor);
			ft_free_color(cub);
			ft_free_cub(cub);
		}
		ft_error("Memory allocation failed!");
		exit(1);
	}
	return (array);
}

void	convert_colors_to_int(t_map *cub)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		cub->col_sky[i] = ft_atoi(cub->sky_char[i]);
		cub->col_floor[i] = ft_atoi(cub->floor_char[i]);
		i++;
	}
}

void	color_atoi(t_map *cub)
{
	int	i;

	i = 0;
	while (cub->sky_char[i])
	{
		rgb_check(cub->sky_char[i], cub);
		i++;
	}
	i = 0;
	while (cub->floor_char[i])
	{
		rgb_check(cub->floor_char[i], cub);
		i++;
	}
	cub->col_floor = allocate_color_array(cub, 1);
	cub->col_sky = allocate_color_array(cub, 0);
	convert_colors_to_int(cub);
	if (color_range(cub))
	{
		free(cub->col_floor);
		free(cub->col_sky);
		ft_free_color(cub);
		ft_error("Color range!");
		exit(1);
	}
}

int	color_range(t_map *cub)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (cub->col_sky[i] > 255 || cub->col_sky[i] < 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (cub->col_floor[i] > 255 || cub->col_floor[i] < 0)
			return (1);
		i++;
	}
	return (0);
}
