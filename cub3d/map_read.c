#include "cubthreed.h"

int map_reader(t_map *cub)
{

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcan <rcan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:33:13 by rcan              #+#    #+#             */
/*   Updated: 2024/05/09 18:33:13 by rcan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_chars(t_map *so, char *f_name)
{
	int	fd;
	int	i;

	read_map(so, f_name);
	empty_map(so);
	if (!(so->map_line) || so->map_y_line <= 0)
	{
		so->map_line = NULL;
		return (1);
	}
	fd = open(f_name, O_RDONLY);
	if (fd == -1)
	{
		free(so->map_line);
		return (1);
	}
	i = 0;
	so->map_line[i] = get_next_line(fd);
	while (so->map_line[i])
	{
		i++;
		so->map_line[i] = get_next_line(fd);
	}
	close(fd);
	return (0);
}

void	read_map(t_map *so, char *f_name)
{
	int		len;
	int		fd;
	char	c;

	fd = open(f_name, O_RDONLY);
	if (fd == -1)
	{
		so->map_y_line = 0;
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
	so->map_line = malloc(sizeof(char *) * len + 1);
	if (!so->map_line)
		return ;
	so->map_line[len + 1] = NULL;
	so->map_y_line = len;
}

void	free_map(t_map *so)
{
	int	i;

	i = 0;
	while (i < so->map_y_line)
	{
		free(so->map_line[i]);
		i++;
	}
	free(so->map_line);
}



void	empty_map(t_map *so)
{
	if (so->map_y_line == 1)
	{
		ft_printf("Error : empty map or invalid map!\n");
		exit (0);
	}
}