#include "cubthreed.h"

int control_sep(t_map *cub)
{
	if (!cub || !cub->player || !cub->is_dup)
		return (0);
	
	int player_y = (int)cub->player->y;
	int player_x = (int)cub->player->x;

	if (player_y < 0 || player_y >= (int)(cub->map_y_line - 3) ||
		player_x < 0 || player_x >= (int)ft_strlen(cub->is_dup[player_y]))
		return (0);

	return (is_dup(cub, player_x, player_y));
}

int check_dup(t_map *cub, int x, int y)
{
	if (!cub || !cub->is_dup)
		return (0);

	if (y < 0 || y >= (int)(cub->map_y_line - 3))
		return (0);

	if (!cub->is_dup[y])
		return (0);

	if (x < 0 || x >= (int)ft_strlen(cub->is_dup[y]))
		return (0);
	
	if (ft_whitespace(cub->is_dup[y][x]) || cub->is_dup[y][x] == '\n')
		return (0);
		
	return (1);
}

int is_dup(t_map *cub, int x, int y)
{
	if (!check_dup(cub, x, y))
		return (1);
	
	if (cub->is_dup[y][x] == 'X')
		return (1);

	cub->is_dup[y][x] = 'X';

	if (check_dup(cub, x + 1, y))
		is_dup(cub, x + 1, y);
	
	if (check_dup(cub, x - 1, y))
		is_dup(cub, x - 1, y);
	
	if (check_dup(cub, x, y + 1))
		is_dup(cub, x, y + 1);
	
	if (check_dup(cub, x, y - 1))
		is_dup(cub, x, y - 1);

	return (1);
}

void check_x(t_map *cub)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (cub->is_dup[i])
    {
        j = 0;
        while (cub->is_dup[i][j])
        {
            if (cub->is_dup[i][j] != 'X' && cub->is_dup[i][j] != '\n' && !ft_whitespace(cub->is_dup[i][j]))
            {
                ft_error("Island on the map file!");
                cub_free(cub);
                exit(1);
            }
            j++;
        }
        i++;
    }
}
