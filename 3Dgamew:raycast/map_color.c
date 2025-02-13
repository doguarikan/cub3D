
#include "cubthreed.h"

void	handle_color(t_map *cub)
{
	char	*floor_tmp;
	char	*sky_tmp;
	char	*floor;
	char	*sky;

	floor = cub->tmp_map[cub->index_floor];
	floor_tmp = process_color_line(floor, cub);
	if (!floor_tmp)
	{
		ft_free_cub(cub);
		exit (ft_error("Color error"));
	}
	cub->tmp_map[cub->index_floor] = floor_tmp;
	sky = cub->tmp_map[cub->index_sky];
	sky_tmp = process_color_line(sky, cub);
	if (!sky_tmp)
		exit (ft_handle_c(cub));
	cub->tmp_map[cub->index_sky] = sky_tmp;
	free(floor);
	free(sky);
	if (set_color(cub))
	{
		ft_free_color(cub);
		exit (ft_error("Color error"));
	}
}

char	*process_color_line(char *line, t_map *cub)
{
	char	*tmp;
	char	*tmp2;
	char	*tm;

	tm = ft_strtrim(line, "\n");
	tmp = ft_whitetrim(tm);
	free(tm);
	if (!tmp)
		return (NULL);
	if (ft_whitespace(tmp[1]))
	{
		tmp2 = ft_whitetrim(tmp + 2);
		free(tmp);
		if (!tmp2)
		{
			ft_error("Color error");
			ft_free_cub(cub);
			exit (1);
		}	
		tmp = tmp2;
	}
	return (tmp);
}

int	rgb_check(char *a, t_map *cub)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = "0123456789,";
	while (a[i])
	{
		j = 0;
		while (str[j])
		{
			if (a[i] == str[j])
				break ;
			j++;
		}
		if (!str[j])
		{
			ft_free_color(cub);
			ft_error("Color error");
			exit(1);
		}
		i++;
	}
	return (1);
}

int	coma_count(t_map *cub)
{
	int	i;
	int	coma;

	i = 0;
	coma = 0;
	while (cub->tmp_map[cub->index_sky][i])
		if (cub->tmp_map[cub->index_sky][i++] == ',')
			coma++;
	if (coma != 2)
	{
		ft_free_cub(cub);
		exit (ft_error("Color coma error"));
	}
	i = 0;
	coma = 0;
	while (cub->tmp_map[cub->index_floor][i])
		if (cub->tmp_map[cub->index_floor][i++] == ',')
			coma++;
	if (coma != 2)
	{
		ft_free_cub(cub);
		exit (ft_error("Color coma error"));
	}
	return (0);
}

int	process_color_array(char **color_array)
{
	int		i;
	char	*tmp;

	i = 0;
	while (color_array[i])
	{
		tmp = ft_whitetrim(color_array[i]);
		if (!tmp || tmp[0] == '\n')
		{
			free(tmp);
			return (1);
		}
		free(color_array[i]);
		color_array[i] = tmp;
		i++;
	}
	if (i != 3)
	{
		return (1);
	}
	return (0);
}
