NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = mlx
FRAMES = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz 
SOURCES =  main.c map_flood_fill.c map_init.c map_read.c map_utils.c \
           game_draw_fs.c game_free.c game_hook.c game_key.c game_move.c game_screen.c game_textures.c \
           ray_cast_init.c ray_casting.c ray_walldist.c

OBJS = $(SOURCES:.c=.o)

MLX = ./mlx/libmlx_Linux.a
LIBFT = ./libft/libft.a
GNL = ./get_next_line/gnl.a

all: $(NAME)

$(NAME): $(OBJS)  $(LIBFT) $(GNL) $(MLX) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(GNL) $(LIBFT) $(FRAMES) $(MLX)
	

$(OBJS): $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)

$(MLX):
	@$(MAKE) -C ./mlx

$(LIBFT):
	@$(MAKE) -C ./libft
	
$(GNL):
	@$(MAKE) -C ./get_next_line

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./get_next_line
	@$(MAKE) clean -C ./mlx

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C ./libft
	@$(MAKE) fclean -C ./get_next_line
	@$(MAKE) fclean -C ./mlx
	
re:fclean all