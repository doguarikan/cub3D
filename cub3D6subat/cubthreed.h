#ifndef CUBTHREED_H
# define CUBTHREED_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>


# ifndef SCREENHEIGHT
#  define SCREENHEIGHT 750
# endif

# ifndef SCREENWIDTH
#  define SCREENWIDTH 1200
# endif

# ifndef TILE
#  define TILE 64
# endif

typedef struct s_keycode
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
}				t_keycode;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_raycast
{
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	int			step_x;
	int			step_y;
	int			side1;
	int			hit;

	int			tex_x;
	int			tex_y;

	double		perp_dist;
	int			height;
	int			start_y;
	int			end_y;
}				t_raycast;

typedef struct s_textures
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}				t_textures;

typedef struct s_map
{
	int		index_ea;
	int		index_no;
	int		index_so;
	int		index_we;
	int		index_sky;
	int		index_floor;
	int		index_p;
	int		first_len;
	char	**sky_char;
	char	**floor_char;
	char	*tex_ea;
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	int		*col_floor;
	int		*col_sky;
	char	**map_line;
	char	**map_game;
	char	**tmp_map;
	int		player_count;
	int		map_x_line;
	int		map_y_line;
	char	*f_name;


	t_keycode	*key;
	t_player	*player;
	t_raycast	*raycast;
	t_textures	*walls[4];

	void		*mlx;
	void		*win;

	int			floor_texture;
	int			ceiling_texture;
	char		*floor;
	char		*ceiling;

	void		*img_ptr;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
	int			*mlx_data;

	char		**map;
	char		**copy_map;
	char		*mapname;

	int			playercount;
	char		playertype;
	int			loc_px;
	int			loc_py;
	int			row;
	int			col;
	
}				t_map;



int		create_xpm(t_map *cub);
int		safe_exit(t_map *cub);
int		read_chars(t_map *cub, char *f_name);
int		split_map(t_map *cub);
int		arg_checker(int argc, char **argv);
void	read_map(t_map *cub, char *f_name);
void	empty_map(t_map *cub);
void	split_line(t_map *cub, char* line, int i);
int		control_wall(t_map *cub);
int		is_valid(t_map *cub, int x, int y);
int		check_surround(t_map *cub, int x, int y);
int		map_check(t_map *cub);
int		map_line_fill(t_map *cub);
int		chr_find(const char *str, t_map *cub);
int		locate_p(t_map *cub);
int		ft_error(char *line);
int		handle_color(t_map *cub);
int		rgb_check(char a);
int		set_color(t_map* cub);
void	handle_texture(t_map* cub);
int		id_check(t_map *cub);
void	id_set(t_map *cub);
void	color_atoi(t_map *cub);
void	color_checker(t_map *cub);
int		color_range(t_map *cub);
int		create_xpm(t_map *cub);
void	set_cf_texture(t_map *cub);
void	draw_floor_ceiling(t_map *cub);
int		exit_game(t_map *cub);
void	player_game(t_map *cub);
int		game_hook(void *param);
void	init_player_pos(t_map *cub);
void	init_player(t_map *cub);
void	init_raycast(t_map *cub, int x);
int		key_released(int keycode, t_map *cub);
int		key_pressed(int keycode, t_map *cub);
void	move_ws(t_map *cub, int direction);
void	move_ad(t_map *cub, int direction);
void	rotate_player(t_map *cub, int direction);
void	calc_side(t_map *cub);
void	calc_ray(t_map *cub, int x);
void	dda(t_map *cub);;
void	init_screen(t_map *cub);
void	xpm_to_img(t_map *cub, char *path, int index);
void	set_walls(t_map *cub);
double	calc_dis(t_map *cub);
void	calc_wall(t_map *cub);
void	map_liner(t_map *cub, int x);
void	cub_free(t_map *cub);
void	ft_free_array(char **arr);
void	ft_free_struct(t_map *cub);
void	ft_free_color(t_map *cub);
void	ft_free_parse(t_map *cub);
int		is_invalid_char(char c);
void	map_control(t_map *cub);
int		map_control_2(int i, int j, t_map *cub);
int		is_invalid_char(char c);
#endif
