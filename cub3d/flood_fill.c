#include "cubthreed.h"

int control_wall(t_map *cub)
{
	return (is_valid(cub, cub->p_x, cub->p_y));
}

int is_valid(t_map *cub, int x, int y)
{
    if (!check_surround(cub, x, y))
	{
		cub_free(cub);
        ft_error("Invalid map!");
		exit(1);
	}
	if (cub->map_line[y][x + 1] == '0')
	{
		cub->map_line[y][x + 1] = cub->p_direction;
		is_valid(cub, x + 1, y);
	}
	if (cub->map_line[y][x - 1] == '0')
	{
		cub->map_line[y][x - 1] = cub->p_direction;
		is_valid(cub, x - 1, y);
	}
	if (cub->map_line[y + 1][x] == '0')
	{
		cub->map_line[y + 1][x] = cub->p_direction;
		is_valid(cub, x, y + 1);
	}
	if (cub->map_line[y - 1][x] == '0')
	{
		cub->map_line[y - 1][x] = cub->p_direction;
		is_valid(cub, x, y - 1);
	}
	return (1);
}

int	check_surround(t_map *cub, int x, int y)
{
	if (cub->map_line[y][x + 1] != '0' && cub->map_line[y][x + 1] != '1' &&
		cub->map_line[y][x + 1] != cub->p_direction)
	{
		return (0);
	}
	if (cub->map_line[y][x - 1] != '0' && cub->map_line[y][x - 1] != '1' &&
		cub->map_line[y][x - 1] != cub->p_direction)
	{
		return (0);
	}
	if (cub->map_line[y + 1][x] != '0' && cub->map_line[y + 1][x] != '1' &&
		cub->map_line[y + 1][x] != cub->p_direction)
	{
		return (0);
	}
	if (cub->map_line[y - 1][x] != '0' && cub->map_line[y - 1][x] != '1' &&
		cub->map_line[y - 1][x] != cub->p_direction)
	{
		return (0);
	}
	return (1);
}

void	cub_free(t_map *cub)
{
	int	i;

	i = 0;
	while (i < cub->first_len)
	{
		free(cub->tmp_map[i]);
		i++;
	}
	i = 0;
	while (i < cub->first_len - 6)
	{
		free(cub->map_line[i]);
		i++;
	}
	free(cub);
}
