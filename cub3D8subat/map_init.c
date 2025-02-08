#include "cubthreed.h"

static char *process_color_line(char *line)
{
	char *tmp;
	char *tmp2;

	tmp = ft_whitetrim(line);
	if (!tmp)
		return (NULL);
	
	if (ft_whitespace(tmp[1]))
	{
		tmp2 = ft_whitetrim(tmp + 2);
		free(tmp);
		if (!tmp2)
			return (NULL);
		tmp = tmp2;
	}
	return tmp;
}

int handle_color(t_map *cub)
{
	char *floor_tmp;
	char *sky_tmp;

	floor_tmp = process_color_line(cub->tmp_map[cub->index_floor]);
	if (!floor_tmp)
		return (0);
	cub->tmp_map[cub->index_floor] = floor_tmp;

	sky_tmp = process_color_line(cub->tmp_map[cub->index_sky]);
	if (!sky_tmp)
		return (0);
	cub->tmp_map[cub->index_sky] = sky_tmp;
	if (set_color(cub))
	{
		ft_error("Color error");
		cub_free(cub);
		exit(1);
	}
	return (1);
}

int rgb_check(char a)
{
	const char *str = "0123456789,";
	int i = 0;

	while (str[i])
	{
		if (a == str[i])
			return (1);
		i++;
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

int process_color_array(char **color_array, t_map *cub)
{
	int i = 0;
	char *tmp;

	while (color_array[i])
	{
		tmp = ft_whitetrim(color_array[i]);
		if (!tmp)
		{
			ft_free_array(cub->floor_char);
			ft_free_array(cub->sky_char);
			return (1);
		}
		free(color_array[i]);
		color_array[i] = tmp;
		i++;
	}
	if (i != 3)
	{
		ft_free_array(cub->floor_char);
		ft_free_array(cub->sky_char);
		return (1);
	}
	return (0);
}
int set_color(t_map* cub)
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

	if (process_color_array(cub->floor_char, cub) || 
		process_color_array(cub->sky_char, cub))
		return (1);

	color_atoi(cub);
	return (0);
}

void color_checker(t_map *cub)
{
	color_atoi(cub);
}

static int *allocate_color_array(t_map *cub, int is_floor)
{
	int *array = (int *)malloc(3 * sizeof(int));
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
		}
		ft_error("Memory allocation failed!");
		exit(1);
	}
	return array;
}

static void convert_colors_to_int(t_map *cub)
{
	for (int i = 0; i < 3; i++)
	{
		cub->col_sky[i] = ft_atoi(cub->sky_char[i]);
		cub->col_floor[i] = ft_atoi(cub->floor_char[i]);
	}
}

void color_atoi(t_map *cub)
{
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

char *process_single_texture(char *line, t_map *cub)
{
	char *tmp;
	char *path;

	tmp = ft_whitetrim(line);
	if(!ft_whitespace(tmp[2]))
	{	
		ft_error("Texture doesn't work!");
		cub_free(cub);
		exit(1);
	}
	path = ft_whitetrim(tmp + 2);
	tmp = ft_strtrim(path,"\n");
	free(path);
	return tmp;
}

void handle_texture(t_map *cub)
{
	cub->tex_ea = process_single_texture(cub->tmp_map[cub->index_ea], cub);
	cub->tex_no = process_single_texture(cub->tmp_map[cub->index_no], cub);
	cub->tex_so = process_single_texture(cub->tmp_map[cub->index_so], cub);
	cub->tex_we = process_single_texture(cub->tmp_map[cub->index_we], cub);
}
