#ifndef CUBTHREED_H
# define CUBTHREED_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	void	*floor;
	void	*sky;
	void	*wall_ea;
	void	*wall_no;
	void	*wall_so;
	void	*wall_we;
	char	**map_line;
	int		p_x;
	int		p_y;
	int		exit_count;
	int		player_count;
	int		coin_count;
	int		playermove;
	int		map_x_line;
	int		map_y_line;
	char	*f_name;
	void	*mlx;
	void	*mlx_win;
}				t_map;

int	create_xpm(t_map *cub);
int	safe_exit(t_map *cub);

#endif