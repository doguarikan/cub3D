
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
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
}				t_keycode;

typedef struct s_player
{
	double		loc_x;
	double		loc_y;
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
	double		next_hit_dist_x;
	double		next_hit_dist_y;
	double		dist_x_pstep;
	double		dist_y_pstep;
	int			step_x;
	int			step_y;
	int			wall_hit_dir;
	int			wall_hit;

	int			tex_x;
	int			tex_y;

	double		perpend_dist;
	int			height;
	int			start_y;
	int			end_y;
}				t_raycast;

typedef struct s_textures
{
	void		*img;
	int			*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			w;
	int			h;
}				t_textures;

typedef struct s_map
{
	int			index_ea;
	int			index_no;
	int			index_so;
	int			index_we;
	int			index_sky;
	int			index_floor;
	int			index_p;
	int			first_len;
	char		**sky_char;
	char		**floor_char;
	char		*tex_ea;
	char		*tex_no;
	char		*tex_so;
	char		*tex_we;
	int			*col_floor;
	int			*col_sky;
	char		**map_line;
	char		**map_game;
	char		**tmp_map;
	char		**is_dup;
	int			map_x_line;
	int			map_y_line;
	char		*f_name;

	t_keycode	*key;
	t_player	*player;
	t_raycast	*raycast;
	t_textures	*walls[4];

	void		*mlx;
	void		*win;

	int			floor_texture;
	int			ceiling_texture;

	void		*img_ptr;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
	int			*mlx_data;

	int			playercount;
	char		playertype;
	int			loc_px_index;
	int			loc_py_index;
	int			row;
	int			col;

}				t_map;

//game_draw
void		set_texture(t_map *cub);
void		draw_fc(t_map *cub);
void		init_screen(t_map *cub);
void		id_set(t_map *cub);
void		ft_dupper(t_map *cub, int j, int i);
//game_free
void		ft_free_struct(t_map *cub);
int			ft_free_cub(t_map *cub);
void		ft_free_array(char **arr);
void		ft_free_color(t_map *cub);
void		ft_free_parse(t_map *cub);
//game_hook
int			exit_game(t_map *cub);
int			key_pressed(int keycode, t_map *cub);
int			key_released(int keycode, t_map *cub);
void		player_game(t_map *cub);
int			game_hook(void *param);
//game_move
void		move_ws(t_map *cub, int direction);
void		move_ad(t_map *cub, int direction);
void		rotate_player(t_map *cub, int direction);
int			ft_sp(int input);
void		count_check(t_map *cub, int count);
//game_textures
void		ft_free_texture(t_map *cub);
void		xpm_to_img(t_map *cub, char *path, int index);
void		set_walls(t_map *cub);
void		img_exit(t_map *cub, int index);
void		ft_free_img(t_map *cub, int index);
//main.c
int			arg_checker(int argc, char **argv);
int			map_read_check(t_map *cub, char *f_name);
void		game_start(t_map *cub);
void		ft_init(t_map *cub);
//map_check
int			control_sep(t_map *cub);
int			check_dup(t_map *cub, int x, int y);
int			is_dup(t_map *cub, int x, int y);
void		check_x(t_map *cub);
void		map_control(t_map *cub);
//map_color
void		handle_color(t_map *cub);
char		*process_color_line(char *line, t_map *cub);
int			rgb_check(char *a, t_map *cub);
int			coma_count(t_map *cub);
int			process_color_array(char **color_array);
//map_control
int			ft_whitespace(char c);
char		*ft_whitetrim(char const *s);
int			is_invalid_char(char c);
int			map_control_2(int i, int j, t_map *cub);
void		char_check(t_map *cub);
//map_flood_fill
void		ft_free_cut(t_map *cub);
int			control_wall(t_map *cub);
int			is_valid(t_map *cub, int x, int y);
int			check_surround(t_map *cub, int x, int y);
void		map_check(t_map *cub);
//map_init
int			set_color(t_map	*cub);
int			*allocate_color_array(t_map *cub, int is_floor);
void		convert_colors_to_int(t_map *cub);
void		color_atoi(t_map *cub);
int			color_range(t_map *cub);
//map_read
int			read_chars(t_map *cub, char *f_name);
void		read_map(t_map *cub, char *f_name);
void		split_map(t_map *cub);
int			id_check(t_map *cub);
void		split_line(t_map *cub, char	*line, int i);
//map_texture
char		*process_single_texture(char *line, t_map *cub);
void		handle_texture(t_map *cub);
void		empty_map(t_map *cub);
int			ft_error(char *line);
int			ft_handle_c(t_map *cub);
//map_utils
int			ft_allocater(t_map *cub);
void		ft_null(t_map *cub, int j);
int			map_line_fill(t_map *cub);
int			chr_find(const char *str, t_map *cub);
int			locate_p(t_map *cub);
//ray_cast_init
void		init_player_pos(t_map *cub);
void		init_player(t_map *cub);
void		init_raycast(t_map *cub, int x);
//ray_casting
void		calc_side(t_map *cub);
void		calc_ray(t_map *cub, int x);
void		dda(t_map *cub);
//ray_walldist
double		calc_dis(t_map *cub);
void		calc_wall(t_map *cub);
void		map_liner(t_map *cub, int x);

#endif
