
#include "cubthreed.h"

int	ft_allocater(t_map *cub)
{
	int	size;

	size = cub->map_y_line - 6 + 1;
	if (size <= 0)
		return (1);
	cub->map_line = malloc(sizeof(char *) * size);
	if (!cub->map_line)
		return (1);
	cub->map_game = malloc(sizeof(char *) * size);
	if (!cub->map_game)
		return (1);
	cub->is_dup = malloc(sizeof(char *) * size);
	if (!cub->is_dup)
		return (1);
	return (0);
}

void	ft_null(t_map *cub, int j)
{
	cub->map_line[j] = NULL;
	cub->map_game[j] = NULL;
	cub->is_dup[j] = NULL;
}

int	map_line_fill(t_map *cub)
{
	int	i;
	int	j;

	if (ft_allocater(cub))
		return (1);
	i = 0;
	j = 0;
	while (j <= cub->first_len - 5 && cub->tmp_map[i])
	{
		if (i != cub->index_no && i != cub->index_so && i != cub->index_ea
			&& i != cub->index_we && i != cub->index_sky
			&& i != cub->index_floor)
		{
			if (cub->tmp_map[i] && cub->map_game && cub->map_line
				&& cub->is_dup)
				ft_dupper(cub, j, i);
			else
				return (1);
			j++;
		}
		i++;
	}
	ft_null(cub, j);
	return (0);
}

int	chr_find(const char *str, t_map *cub)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'S' || str[i] == 'W'
			|| str[i] == 'N' || str[i] == 'E')
		{
			cub->playertype = str[i];
			return (i);
		}
		i++;
	}
	return (-1);
}

int	locate_p(t_map *cub)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (cub->map_line[i])
	{
		if (chr_find(cub->map_line[i], cub) >= 0)
		{
			count++;
			cub->player->loc_y = (double)i;
			cub->player->loc_x = (double)chr_find(cub->map_line[i], cub);
			cub->loc_py_index = i;
			cub->loc_px_index = chr_find(cub->map_line[i], cub);
		}
		i++;
	}
	cub->map_game[cub->loc_py_index][cub->loc_px_index] = '0';
	if (count != 1)
		return (1);
	return (0);
}
