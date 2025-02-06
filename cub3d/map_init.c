#include "cubthreed.h"

int handle_color(t_map *cub)
{
	int i;
	int ret;

	ret = 1;
	i = 1;
	while (cub->tmp_map[cub->index_floor][i] != '\n')
	{
		ret = rgb_check(cub->tmp_map[cub->index_floor][i]); // 0 ise hatalı
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
	if(ret && set_color(cub))
	{
		ft_error("Color error");
		cub_free(cub);
		exit (1);
	}
	return (ret); // 0 ise hatalı
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

int coma_count(t_map *cub)
{
	int i;
	int coma;

	i = 0;
	coma = 0;
	while(cub->tmp_map[cub->index_sky][i])
	{
		if(cub->tmp_map[cub->index_sky][i] == ',')
			coma++;
		i++;
	}
	if (coma != 2)
		return (1);
	i = 0;
	coma = 0;
	while(cub->tmp_map[cub->index_floor][i])
	{
		if(cub->tmp_map[cub->index_floor][i] == ',')
			coma++;
		i++;
	}
	if (coma != 2)
		return (1);
	return (0);
}

int set_color(t_map* cub)
{
	char *tmp;
	int i;

	if(coma_count(cub))
		return (1);
	tmp = ft_strtrim(cub->tmp_map[cub->index_floor] + 1, " \n");
	if(ft_strchr(tmp , ' '))
	{
		free(tmp);
		return (1);
	}
	cub->floor_char = ft_split(tmp, ',');
	i = 0;
	while(cub->floor_char[i])
		i++;
	if(i != 3)
	{
		free(tmp);
		ft_free_array(cub->floor_char);
		return (1);
	}
	free(tmp);
	tmp = ft_strtrim(cub->tmp_map[cub->index_sky] + 1, " \n");
	if(ft_strchr(tmp , ' '))
	{
		free(tmp);
		ft_free_array(cub->floor_char);
		return (1);
	}
	cub->sky_char = ft_split(tmp, ',');
	i = 0;
	while(cub->sky_char[i])
		i++;
	if(i != 3)
	{
		free(tmp);
		ft_free_array(cub->floor_char);
		ft_free_array(cub->sky_char);
		return (1);
	}
	color_checker(cub);
	return (0);
}

void color_checker(t_map *cub) // rgb aralığı
{
	int i;

	i = 0;
	while(cub->floor_char[i])
	{
		if(ft_strlen(cub->floor_char[i]) == 0 || ft_strlen(cub->floor_char[i]) > 3)
		{
			ft_free_color(cub);
			ft_error("Invalid RGB");
			exit (1);
		}
		i++;
	}
	while(cub->sky_char[i])
	{
		if(ft_strlen(cub->sky_char[i]) == 0 || ft_strlen(cub->sky_char[i]) > 3)
		{
			ft_free_color(cub);
			ft_error("Invalid RGB");
			exit (1);
		}
		i++;
	}
	color_atoi(cub);
}

void	color_atoi(t_map *cub)
{
	int i;

	i = 0;
	cub->col_floor = (int *)malloc(3 * sizeof(int));
	cub->col_sky = (int *)malloc(3 * sizeof(int)); // burası doğru mu
	while(cub->sky_char[i])
	{
		cub->col_sky[i] = ft_atoi(cub->sky_char[i]);
		i++;
	}
	i = 0;
	while(cub->floor_char[i])
	{
		cub->col_floor[i] = ft_atoi(cub->floor_char[i]);
		i++;
	}
	if(color_range(cub))
	{
		free(cub->col_floor);
		free(cub->col_sky);
		ft_free_color(cub);
		ft_error("Color range!");
		exit (0);
	}
}

int	color_range(t_map *cub)
{
	int i;

	i = 0;	
	while(i < 3)
	{
		if(cub->col_sky[i] > 255 || cub->col_sky[i] < 0)
			return (1);
		i++;
	}
	i = 0;
	while(i < 3)
	{
		if(cub->col_floor[i] > 255 || cub->col_floor[i] < 0)
			return (1);
		i++;
	}
	return (0);
}

void handle_texture(t_map* cub)// dosya var mı kontrolü eklencek/ open close
{
	char *ea;
	char *no;
	char *so;
	char *we;

	ea = ft_strtrim((cub->tmp_map[cub->index_ea] + 2), " ");
	no = ft_strtrim((cub->tmp_map[cub->index_no] + 2), " ");
	so = ft_strtrim((cub->tmp_map[cub->index_so] + 2), " ");
	we = ft_strtrim((cub->tmp_map[cub->index_we] + 2), " ");
	cub->tex_ea = ft_strtrim((ea), "\n");
	cub->tex_no = ft_strtrim((no), "\n");
	cub->tex_so = ft_strtrim((so), "\n");
	cub->tex_we = ft_strtrim((we), "\n");
	free(ea);
	free(no);
	free(so);
	free(we);
}

void ft_free_color(t_map *cub)
{
	ft_free_array(cub->floor_char);
	ft_free_array(cub->sky_char);
	cub_free(cub);
}