NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAMES = -framework OpenGL -framework AppKit
SOURCES =  main.c map_read.c map_utils.c flood_fill.c
OBJS = $(SOURCES:.c=.o)

#MLX = ./mlx/libmlx_Linux.a
LIBFT = ./libft/libft.a
GNL = ./get_next_line/gnl.a

all: $(NAME)

$(NAME): $(OBJS)  $(LIBFT) $(GNL) #$(MLX)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(GNL) $(LIBFT)  
#	$(FRAMES) $(MLX)

$(OBJS): $(SOURCES)
	$(CC) $(FLAGS) -c $(SOURCES)

#$(MLX):
#	@$(MAKE) -C ./mlx

$(LIBFT):
	@$(MAKE) -C ./libft
	
$(GNL):
	@$(MAKE) -C ./get_next_line

clean:
	rm -f $(OBJS)
#	@$(MAKE) clean -C ./mlx

fclean: clean
	rm -f cub3D
	
re:fclean all