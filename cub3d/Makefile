NAME = cub3D
CC = gcc
FLAGS = -Wall -Wextra -Werror
FRAMES = -framework OpenGL -framework AppKit
SOURCES =  main.c win.c
OBJS = $(SOURCES:.c=.o)

MLX = ./mlx/libmlx.a
LIBFT = ./libft/libft.a


all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT) $(GNL) $(PRINTF) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(FRAMES)

$(OBJS): $(SOURCES)
	$(CC) $(FLAGS) -c ${SOURCES}

$(MLX):
	@${MAKE} -C ./mlx

$(LIBFT):
	@${MAKE} -C ./libft

clean:
	rm -f ${OBJS}
	@${MAKE} clean -C ./mlx

fclean: clean
	rm -f so_long
	
re:fclean all
