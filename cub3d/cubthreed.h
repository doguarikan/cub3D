#ifndef CUBTHREED_H
# define CUBTHREED_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	void	*floor;
	void	*sky;
	void	*wall_ea;
	void	*wall_no;
	void	*wall_so;
	void	*wall_we;
	int		index_ea;
	int		index_no;
	int		index_so;
	int		index_we;
	int		index_sky;
	int		index_floor;
	int		index_p;
	int		first_len;
	char	**map_line;
	char	**tmp_map;
	char	p_direction;
	int		p_x;
	int		p_y;
	int		player_count;
	int		map_x_line;
	int		map_y_line;
	char	*f_name;
	void	*mlx;
	void	*mlx_win;
}				t_map;


int		create_xpm(t_map *cub);
int		safe_exit(t_map *cub);
int		read_chars(t_map *cub, char *f_name);
int		split_map(t_map *cub);
int		arg_checker(int argc, char *argv);
void	read_map(t_map *cub, char *f_name);
void	empty_map(t_map *cub);
void	split_line(t_map *cub, char* line, int i);
int control_wall(t_map *cub);
int is_valid(t_map *cub, int x, int y);
int	check_surround(t_map *cub, int x, int y);
void	cub_free(t_map *cub);
int map_check(t_map *cub);
int    map_line_fill(t_map *cub);
char	chr_find(const char *str, t_map *cub);
int locate_p(t_map *cub);
int ft_error(char *line);

#endif