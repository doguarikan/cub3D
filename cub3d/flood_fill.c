#include "cubthreed.h"

int control_wall(t_map *cub)
{
	return (is_valid(cub, cub->player->x, cub->player->y));
}

int is_valid(t_map *cub, int x, int y)
{
    if (!check_surround(cub, x, y)) // anlık yerin sag sol ust altında 1 0 ve player yonu disinda bir şey var mı ona bakar
	{
		cub_free(cub);
        ft_error("Invalid map!");
		exit(1);
	}
	if (cub->map_line[y][x + 1] == '0') // floodfill ile sag sol alt ust gidere recursive ilerler
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

int	check_surround(t_map *cub, int x, int y) // sol sag ust alt kontolu yapar
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

void	cub_free(t_map *cub)
{
	ft_free_array(cub->tmp_map);
	ft_free_array(cub->map_line);
	ft_free_array(cub->map_game);
	ft_free_struct(cub);
	free(cub);
}
