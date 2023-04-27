CFLAGS = -Wall -Wextra -Werror -I./minilibx -g
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx
MLX = -I./minilibx/libmlx.a
PRINTF = -I./printf
SRCS = get_next_line_utils.c get_next_line.c libft_functions.c map_check.c \
	pec_control.c player_walk.c image_set.c so_long.c close_set.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(NAME)

$(NAME) : $(MLX) $(OBJS)
	gcc $(OBJS) $(CFLAGS) $(LFLAGS) ./printf/libftprintf.a -o $(NAME)

$(MLX) :
	make -sC PRINTF
	make -sC ./minilibx

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(NAME)

fclean:
	rm -rf $(OBJS) $(NAME)
	make clean -C ./minilibx
	make fclean -C ./printf

norm:
	norminette ./*.c

re : fclean all

.PHONY: clean fclean re all
