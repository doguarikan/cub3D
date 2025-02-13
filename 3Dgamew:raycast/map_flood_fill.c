
#include "cubthreed.h"

void	ft_free_cut(t_map *cub)
{
	ft_free_cub(cub);
	ft_error("Invalid map!");
	exit(1);
}

int	control_wall(t_map *cub)
{
	return (is_valid(cub, cub->player->loc_x, cub->player->loc_y));
}

int	is_valid(t_map *cub, int x, int y)
{
	if (!check_surround(cub, x, y))
		ft_free_cut(cub);
	if (cub->map_line[y][x + 1] == '0')
	{
		cub->map_line[y][x + 1] = cub->playertype;
		is_valid(cub, x + 1, y);
	}
	if (cub->map_line[y][x - 1] == '0')
	{
		cub->map_line[y][x - 1] = cub->playertype;
		is_valid(cub, x - 1, y);
	}
	if (cub->map_line[y + 1][x] == '0')
	{
		cub->map_line[y + 1][x] = cub->playertype;
		is_valid(cub, x, y + 1);
	}
	if (cub->map_line[y - 1][x] == '0')
	{
		cub->map_line[y - 1][x] = cub->playertype;
		is_valid(cub, x, y - 1);
	}
	return (1);
}

int	check_surround(t_map *cub, int x, int y)
{
	if (cub->map_line[y][x + 1] != '0' && cub->map_line[y][x + 1] != '1' &&
		cub->map_line[y][x + 1] != cub->playertype)
	{
		return (0);
	}
	if (cub->map_line[y][x - 1] != '0' && cub->map_line[y][x - 1] != '1' &&
		cub->map_line[y][x - 1] != cub->playertype)
	{
		return (0);
	}
	if (cub->map_line[y + 1][x] != '0' && cub->map_line[y + 1][x] != '1' &&
		cub->map_line[y + 1][x] != cub->playertype)
	{
		return (0);
	}
	if (cub->map_line[y - 1][x] != '0' && cub->map_line[y - 1][x] != '1' &&
		cub->map_line[y - 1][x] != cub->playertype)
	{
		return (0);
	}
	return (1);
}

void	map_check(t_map *cub)
{
	if (map_line_fill(cub))
	{
		ft_free_array(cub->tmp_map);
		ft_free_struct(cub);
		free(cub);
		exit (0);
	}
	if (cub->index_p < cub->index_no || cub->index_p < cub->index_so
		|| cub->index_p < cub->index_ea || cub->index_p < cub->index_we
		|| cub->index_p < cub->index_floor || cub->index_p < cub->index_sky)
	{
		ft_free_cub(cub);
		ft_error("Invalid map, map location fail!");
		exit (1);
	}
	if (locate_p(cub))
	{
		ft_free_cub(cub);
		ft_error("Invalid map!");
		exit (1);
	}
}
