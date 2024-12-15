/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcan <rcan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:27:41 by rcan              #+#    #+#             */
/*   Updated: 2024/05/09 18:27:43 by rcan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *left)
{
	char	*buffer;
	int		r_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	r_bytes = 1;
	while (!finder(left) && r_bytes != 0)
	{
		r_bytes = read(fd, buffer, BUFFER_SIZE);
		if (r_bytes == -1)
		{
			free(buffer);
			free(left);
			return (0);
		}
		buffer[r_bytes] = '\0';
		left = strjoin(left, buffer);
	}
	free(buffer);
	return (left);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left = read_line(fd, left);
	if (!left)
		return (0);
	line = getbefore(left);
	left = getafter(left);
	return (line);
}
