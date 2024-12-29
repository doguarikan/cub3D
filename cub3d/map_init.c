#include "cubthreed.h"

int handle_color(t_map *cub)
{
	int i;
	int ret;

	ret = 1;
	i = 1;
	while (cub->tmp_map[cub->index_floor][i] != '\n')
	{
		ret = rgb_check(cub->tmp_map[cub->index_floor][i]);
		if(ret == 0)
			return (ret);
		i++;
	}
	i = 1;
	while (cub->tmp_map[cub->index_sky][i] != '\n')
	{
		ret = rgb_check(cub->tmp_map[cub->index_sky][i]);
		if(ret == 0)
			return (ret);
		i++;
	}
	if(ret)
		set_color(cub);
	return (ret);
}

int rgb_check(char a)
{
    char *str;
    int i;

    i = 0;
    str = "0123456789, 	";
    while(str[i])
    {
        if(str[i] != a)
            i++;
        else
            return (1);
    }
    return (0);
}

void set_color(t_map* cub)
{
	char *tmp;
	int i;

	tmp = ft_strtrim(cub->tmp_map[cub->index_floor] + 1, " \n");
	if(ft_strchr(tmp , ' '))
		ft_error("Color error");
	cub->floor_char = ft_split(tmp, ',');
	i = 0;
	while(cub->floor_char[i])
		i++;
	if(i != 3)
		ft_error("Color error");
	tmp = ft_strtrim(cub->tmp_map[cub->index_sky] + 1, " \n");
	if(ft_strchr(tmp , ' '))
		ft_error("Color error");
	cub->sky_char = ft_split(tmp, ',');
	i = 0;
	while(cub->sky_char[i])
		i++;
	if(i != 3)
		ft_error("Color error");
}

void handle_texture(t_map* cub)
{
	cub->tex_ea = ft_strtrim((cub->tmp_map[cub->index_ea] + 2)," \n");
	cub->tex_no = ft_strtrim((cub->tmp_map[cub->index_no] + 2)," \n");
	cub->tex_so = ft_strtrim((cub->tmp_map[cub->index_so] + 2)," \n");
	cub->tex_we = ft_strtrim((cub->tmp_map[cub->index_we] + 2)," \n");
}