
#include "cubthreed.h"

int	ft_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r');
}

char	*ft_whitetrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	if (!s)
		return (NULL);
	while (s[start] && ft_whitespace(s[start]))
		start++;
	end = ft_strlen(s);
	while (end > start && ft_whitespace(s[end - 1]))
		end--;
	len = end - start;
	return (ft_substr(s, start, len));
}

int	is_invalid_char(char c)
{
	return (!(c == '0' || c == '1' || c == 'N' || c == 'W'
			|| c == 'S' || c == 'E'));
}

int	map_control_2(int i, int j, t_map *cub)
{
	if (cub->map_line[i][j] == '0')
	{
		if (i == 0 || !cub->map_line[i - 1]
			|| is_invalid_char(cub->map_line[i - 1][j]))
			return (1);
		if (!cub->map_line[i + 1] || is_invalid_char(cub->map_line[i + 1][j]))
			return (1);
		if (j == 0 || is_invalid_char(cub->map_line[i][j - 1]))
			return (1);
		if (!cub->map_line[i][j + 1]
			|| is_invalid_char(cub->map_line[i][j + 1]))
			return (1);
	}
	return (0);
}

void	char_check(t_map *cub)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (cub->map_line[i])
	{
		j = 0;
		while (cub->map_line[i][j])
		{
			if (cub->playertype == cub->map_line[i][j])
				count++;
			if (is_invalid_char(cub->map_line[i][j])
				&& ft_sp(cub->map_line[i][j]))
			{
				ft_free_cub(cub);
				exit(ft_error("Invalid object on the map file!"));
			}
			j++;
		}
		i++;
	}
	count_check(cub, count);
}
