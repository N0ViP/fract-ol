NAME	=	fractol

CC		=	cc

FLAGS	=	-g

SRC		=	src/main.c	\
			src/julia.c	\
			src/mandelbrot.c

UTILS	=	utils/ft_atold.c	\
			utils/ft_isspace.c	\
			utils/utils.c		\
			utils/ft_isdigit.c	\
			utils/ft_strcmp.c

LIBS	=	-Lmlx_linux -lmlx_Linux -L/usr/include/minilibx-linux -lXext -lX11 -lm -lz

INCLUDE	=	-Iinclude/ -I/usr/include/minilibx-linux/

OBJS	=	$(SRC:.c=.o) $(UTILS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
