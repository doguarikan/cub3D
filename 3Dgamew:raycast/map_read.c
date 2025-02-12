
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
	fd = open (f_name, O_RDONLY);
	if (fd == -1)
	{
		free (cub->tmp_map);
		return (1);
	}
	i = 0;
	cub->tmp_map[i] = get_next_line(fd);
	while (cub->tmp_map[i++])
		cub->tmp_map[i] = get_next_line(fd);
	if (i < cub->map_y_line)
		cub->tmp_map[i] = NULL;
	close (fd);
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
		cub->tmp_map = NULL;
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
	cub->tmp_map = malloc(sizeof(char *) * (len + 1));
	if (!cub->tmp_map)
		return ;
	cub->tmp_map[len] = NULL;
	cub->map_y_line = len;
}

void	split_map(t_map *cub)
{
	int	i;

	i = 0;
	id_set(cub);
	while (cub->tmp_map[i])
	{
		split_line(cub, cub->tmp_map[i], i);
		i++;
	}
	if (id_check(cub))
	{
		ft_error("Missing identifier!");
		ft_free_array(cub->tmp_map);
		ft_free_struct(cub);
		free(cub);
		exit (0);
	}
	if (cub->playercount != 1)
	{
		ft_error("Invalid player count!");
		ft_free_array(cub->tmp_map);
		ft_free_struct(cub);
		free(cub);
		exit (0);
	}
}

int	id_check(t_map *cub)
{
	if (cub->index_ea == -1 || cub->index_so == -1 || cub->index_no == -1
		|| cub->index_we == -1 || cub->index_floor == -1
		|| cub->index_sky == -1)
		return (1);
	return (0);
}

void	split_line(t_map *cub, char	*line, int i)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)) != NULL)
		cub->index_no = i;
	else if (ft_strnstr(line, "SO", ft_strlen(line)) != NULL)
		cub->index_so = i;
	else if (ft_strnstr(line, "EA", ft_strlen(line)) != NULL)
		cub->index_ea = i;
	else if (ft_strnstr(line, "WE", ft_strlen(line)) != NULL)
		cub->index_we = i;
	else if (ft_strnstr(line, "F", ft_strlen(line)) != NULL)
		cub->index_floor = i;
	else if (ft_strnstr(line, "C", ft_strlen(line)) != NULL)
		cub->index_sky = i;
	else if (line && (ft_strchr(line, 'N') || ft_strchr(line, 'S')
			|| ft_strchr(line, 'E') || ft_strchr(line, 'W')))
	{
		cub->playercount++;
		cub->index_p = i;
	}
}
