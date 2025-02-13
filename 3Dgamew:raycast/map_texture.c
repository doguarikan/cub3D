
#include "cubthreed.h"

char	*process_single_texture(char *line, t_map *cub)
{
	char	*tmp;
	char	*path;
	char	*sp;

	sp = ft_whitetrim(line);
	if (!ft_whitespace(sp[2]))
	{	
		ft_error("Texture doesn't work!");
		ft_free_array(cub->floor_char);
		ft_free_array(cub->sky_char);
		free(cub->col_floor);
		free(cub->col_sky);
		ft_free_cub(cub);
		free(sp);
		exit(1);
	}
	tmp = ft_strtrim(sp, "\n");
	path = ft_whitetrim(tmp + 2);
	free (tmp);
	free (sp);
	return (path);
}

void	handle_texture(t_map *cub)
{
	cub->tex_ea = process_single_texture(cub->tmp_map[cub->index_ea], cub);
	cub->tex_no = process_single_texture(cub->tmp_map[cub->index_no], cub);
	cub->tex_so = process_single_texture(cub->tmp_map[cub->index_so], cub);
	cub->tex_we = process_single_texture(cub->tmp_map[cub->index_we], cub);
}

void	empty_map(t_map *cub)
{
	if (cub->map_y_line == 1)
	{
		ft_free_array(cub->tmp_map);
		free(cub);
		ft_error("Empty map or invalid map!");
		exit (0);
	}
}

int	ft_error(char *line)
{
	printf("Error\n%s\n", line);
	return (1);
}

int	ft_handle_c(t_map *cub)
{
	ft_free_array(cub->floor_char);
	ft_free_cub(cub);
	ft_error("Color error");
	return (1);
}
