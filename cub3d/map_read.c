
#include "cubthreed.h"

int	read_chars(t_map *cub, char *f_name)
{
	int	fd;
	int	i;

	read_map(cub, f_name);
	empty_map(cub);
	if (!(cub->tmp_map) || cub->map_y_line <= 0)
	{
		cub->tmp_map = NULL;
		return (1);
	}
	fd = open(f_name, O_RDONLY);
	if (fd == -1)
	{
		printf("%s\n", f_name);
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
	close(fd);
	cub->tmp_map = malloc(sizeof(char *) * len + 1);
	if (!cub->tmp_map)
		return ;
	printf("hello\n"); // kaldırınca abort alıyor
	cub->tmp_map[len + 1] = NULL;
	cub->map_y_line = len;
}

void	empty_map(t_map *cub)
{
	if (cub->map_y_line == 1)
	{
		printf("Error : empty map or invalid map!\n");
		exit (0);
	}
}

int split_map(t_map *cub)
{
	int	i;

	i = 0;
	while(cub->tmp_map[i])
	{
		split_line(cub, cub->tmp_map[i], i);
		i++;
	}
	return i;
}

void	split_line(t_map *cub, char* line, int i) //??????!!! sırayı tutalım
{
	if(!ft_strncmp(line, "NO", 2))
		cub->index_no = i + 1;
	else if(!ft_strncmp(line, "SO", 2))
		cub->index_so = i + 1;
	else if(!ft_strncmp(line, "EA", 2))
		cub->index_ea = i + 1;
	else if(!ft_strncmp(line, "WE", 2))
		cub->index_we = i + 1;
	else if(!ft_strncmp(line, "F", 1))
		cub->index_floor = i + 1;
	else if(!ft_strncmp(line, "C", 1))
		cub->index_sky = i + 1;
	else if(!ft_strncmp(line, "R", 1))
		cub->index_screen = i + 1;
	else if(line && (ft_strchr(line, 'N') || ft_strchr(line, 'S') || ft_strchr(line, 'E') || ft_strchr(line, 'W')))
	{
		cub->index_p = i + 1;
	}
	/*else
		ft_strlcpy(cub->map_line[i], line, ft_strlen(line)); // substr olması laızm seg alıyor
*/
}
