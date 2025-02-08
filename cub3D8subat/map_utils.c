
#include "cubthreed.h"

int map_check(t_map *cub)
{
    map_line_fill(cub);
    if(cub->index_p < cub->index_no || cub->index_p < cub->index_so || cub->index_p < cub->index_ea ||\
        cub->index_p < cub->index_we || cub->index_p < cub->index_floor || cub->index_p < cub->index_sky)
    { // map en altta olması gerektiği için player satır indexi ve xpm rgb indekslerini karşılaştırp ona göre hata verir
        ft_error("Invalid map, map location fail!");
        return (1);
    }
    if (locate_p(cub))
    {
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

    index_tot = 6;
    cub->map_line = malloc(sizeof(char *) * (cub->first_len) + 1 - index_tot);
    cub->map_game = malloc(sizeof(char *) * (cub->first_len) + 1 - index_tot); // xpm ve rgb dısşındaki satır sayısı kadar yer aç
    cub->is_dup = malloc(sizeof(char *) * (cub->first_len) + 1 - index_tot);
    i = 0;
    j = 0;
    while((cub->first_len - index_tot) >= j)
    {
        if (i != cub->index_no && i != cub->index_so && i != cub->index_ea && i != cub->index_we &&\
            i != cub->index_sky && i != cub->index_floor) // xpm ve rgb dışındaki indexleri döner ve boş satırları da map_line içine atar
        {
            if(cub->tmp_map[i])
            {
                cub->map_game[j] = ft_strdup(cub->tmp_map[i]);
                cub->map_line[j] = ft_strdup(cub->tmp_map[i]);
                cub->is_dup[j] = ft_strdup(cub->tmp_map[i]);
            }
            j++;
        }
        i++;
    }
    cub->map_line[j] = NULL;
    cub->map_game[j] = NULL;
    cub->is_dup[j] = NULL;
    return (0);
}

int     chr_find(const char *str, t_map *cub)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == 'S' || str[i] == 'W' ||\
			str[i] == 'N' || str[i] == 'E')
		{
            cub->playertype = str[i];
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
			cub->player->y = (double)i;
			cub->player->x = (double)chr_find(cub->map_line[i], cub);
            cub->loc_py = i;
			cub->loc_px = chr_find(cub->map_line[i], cub);
		}
		i++;
    }
    cub->map_game[cub->loc_py][cub->loc_px] = '0';
    if(count != 1)
    {
        return(1);
    }
    return (0);
}
