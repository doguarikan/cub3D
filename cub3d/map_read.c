
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
		if (c == '\n' || c == '\0')
			len++;
	}
	len++;
	cub->first_len = len - 1;
	close(fd);
	printf("%d\n",len);
	cub->tmp_map = malloc(sizeof(char *) * (len + 1));
	if (!cub->tmp_map)
		return ;
	//printf("hello\n");
	cub->tmp_map[len] = NULL;
	cub->map_y_line = len;
}

void	empty_map(t_map *cub)
{
	if (cub->map_y_line == 1)
	{
		free(cub);
		ft_error("empty map or invalid map!");
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

void	split_line(t_map *cub, char* line, int i)
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
	/*else
		ft_strlcpy(cub->map_line[i], line, ft_strlen(line)); // substr olması laızm seg alıyor
*/
}
