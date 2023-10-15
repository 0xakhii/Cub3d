CC          = cc

NAME        = cub3D

LIBFT_NAME  = libft.a

SRCS        =   get_next_line/get_next_line.c get_next_line/get_next_line_utils.c main.c parse.c\
	utils.c map_check.c check_directions.c check_colors.c

OBJ         = $(SRCS:.c=.o)

CFLAGS      = -Wall -Wextra -Werror -g3 -fsanitize=address

IMAC_FLAGS	= -L libft -lft -lmlx -framework OpenGL -framework AppKit

LINUX_FLAGS = -L libft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

$(NAME): $(OBJ)
	@make -C libft
	@$(CC)  $(CFLAGS) $(OBJ) $(IMAC_FLAGS) -o $(NAME)

clean:
	@make -C libft clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)

re: fclean all
