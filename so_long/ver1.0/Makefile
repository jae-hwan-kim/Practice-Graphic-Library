NAME=so_long

CC=cc
CFLAGS= -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
OPENGL= -framework OpenGL
APPKIT= -framework AppKit
MLX_DIR= ./mlx
MLX_LIB= mlx
RM=rm -f
CP=cp
SRC= main.c \
	 init.c \
	 key.c \
	 get.c \
	 draw.c \
	 error.c \
	 close.c \
	 get_next_line.c \
	 get_next_line_utils.c 

OBJ=$(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -L$(MLX_DIR) -l$(MLX_LIB) $(OPENGL) $(APPKIT) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
