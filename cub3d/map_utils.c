
#include "cubthreed.h"

int map_check(t_map *cub)
{
    map_line_fill(cub);
    if(cub->index_p < cub->index_no || cub->index_p < cub->index_so || cub->index_p < cub->index_ea ||\
        cub->index_p < cub->index_we || cub->index_p < cub->index_floor || cub->index_p < cub->index_sky)
    {
        cub_free(cub);
        ft_error("Invalid map!");
        return (1);
    }
    if (locate_p(cub))
    {
        cub_free(cub);
        ft_error("Invalid map! more than one player");
        return (1); // hata birden fazla player var
    }
    return (0);
}

int    map_line_fill(t_map *cub)
{
    int index_tot;
    int i;
    int j;

    index_tot = 6; // r ne = index_screen
    cub->map_line = malloc(sizeof(char *) * (cub->first_len) + 1 - index_tot);
    i = 0;
    j = 0;
    while((cub->first_len - index_tot) > j)
    {
        if (i != cub->index_no && i != cub->index_so && i != cub->index_ea && i != cub->index_we &&\
            i != cub->index_sky && i != cub->index_floor)
        {
            cub->map_line[j] = ft_strdup(cub->tmp_map[i]);
            j++;
        }
        i++;
    }
    return (0);
}

char	chr_find(const char *str, t_map *cub)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == 'S' || str[i] == 'W' ||\
			str[i] == 'N' || str[i] == 'E')
		{
            cub->p_direction = str[i];
			return (i);
		}
		i++;
	}
	return (0);
}

int locate_p(t_map *cub)
{
    int count;
    int i;

    i = 0;
    count = 0;
    while(cub->map_line[i])
    {
		if(chr_find(cub->map_line[i], cub))
		{
			count++;
			cub->p_y = i;
			cub->p_x = chr_find(cub->map_line[i], cub);
		}
		i++;
    }
    if(count != 1)
    {
        return(1);
    }
    return (0);
}
