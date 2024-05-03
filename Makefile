NAME = so_long

SRCS = src/main.c \
       src/check_map.c \
       src/check_path.c \
	   libmlx_Linux.a \
	   libmlx.a \
	   src/init_game.c \
	   src/moves.c \
	   src/extras.c \
	   src/check_map_ex.c \
	   src/check_void.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LDFLAGS = -Llibft -lft -lm -lX11 -lXext

all: libft minilibx $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -L. -lmlx_Linux -lmlx

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

libft:
	make -C libft

minilibx:
	make -C minilibx-linux
	cp minilibx-linux/libmlx.a .
	cp minilibx-linux/libmlx_Linux.a .

clean:
	rm -f $(OBJS)
	make -C libft clean
	make -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C minilibx-linux clean
	rm -f libmlx.a libmlx_Linux.a

re: fclean all

.PHONY: all clean fclean re libft minilibx


