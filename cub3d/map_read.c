
#include "cubthreed.h"

int	read_chars(t_map *cub, char *f_name)
{
	int	fd;
	int	i;

	read_map(cub, f_name);
	empty_map(cub);
	if (!(cub->tmp_map))
	{
		cub->tmp_map = NULL;
		return (1);
	}
	fd = open(f_name, O_RDONLY);
	if (fd == -1)
	{
		free(cub->tmp_map);
		return (1);
	}
	i = 0;
	cub->tmp_map[i] = get_next_line(fd);
	while (cub->tmp_map[i])
	{
		i++;
		cub->tmp_map[i] = get_next_line(fd);
	}
	if (i < cub->map_y_line) // Eğer beklenen satır sayısı dolmamışsa
        cub->tmp_map[i] = NULL; //fvg
	close(fd);
	return (0);
}

void	read_map(t_map *cub, char *f_name)
{
	int		len;
	int		fd;
	char	c;

	fd = open(f_name, O_RDONLY);
	if (fd == -1)
	{
		cub->map_y_line = 0;
		return ;
	}
	len = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			len++;
	}
	len++;
	cub->first_len = len - 1;
	close(fd);
	cub->tmp_map = malloc(sizeof(char *) * (len + 1)); // dosyanın tamamını açıp okur ve kaç satır varsa double arrayin ilk düzlem buyukuluğunu bulur
	if (!cub->tmp_map)								  // sonuna null atar ve dosya satır sayısını tutar
		return ;
	cub->tmp_map[len] = NULL;
	cub->map_y_line = len;
}

void	empty_map(t_map *cub)
{
	if (cub->map_y_line == 1) // map 1 satırsa her turlu gecersiz
	{
		free(cub);
		ft_error("Empty map or invalid map!");
		exit (0);
	}
}

int split_map(t_map *cub)
{
	int	i;

	i = 0;
	id_set(cub);
	while(cub->tmp_map[i])
	{
		split_line(cub, cub->tmp_map[i], i);
		i++;
	}
	if(id_check(cub))
	{
		ft_error("Missing identifier!");
		return (0);
	}
	return i;
}

void	id_set(t_map *cub)
{
	cub->index_ea = -1;
	cub->index_so = -1;
	cub->index_no = -1;
	cub->index_we = -1;
	cub->index_floor = -1;
	cub->index_sky = -1;
}

int	id_check(t_map *cub)
{
	if(cub->index_ea == -1 || cub->index_so == -1 || cub->index_no == -1 
			|| cub->index_we == -1 || cub->index_floor == -1 || cub->index_sky == -1)
			return (1);
	return (0);
}

void	split_line(t_map *cub, char* line, int i) // xpm ve karakterin hangi satırlarda olduğunu kayıt altına alır
{
	if(!ft_strncmp(line, "NO", 2))
		cub->index_no = i;
	else if(!ft_strncmp(line, "SO", 2))
		cub->index_so = i;
	else if(!ft_strncmp(line, "EA", 2))
		cub->index_ea = i;
	else if(!ft_strncmp(line, "WE", 2))
		cub->index_we = i;
	else if(!ft_strncmp(line, "F", 1))
		cub->index_floor = i;
	else if(!ft_strncmp(line, "C", 1))
		cub->index_sky = i;
	else if(line && (ft_strchr(line, 'N') || ft_strchr(line, 'S') || ft_strchr(line, 'E') || ft_strchr(line, 'W')))
	{
		cub->index_p = i;
	}
}
