NAME		=	fract-ol

CC			=	gcc

FLAGS		=	-O3 -g

LIBS		=	-Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz

INCLUDE		=	-Iinclude/ -Iminilibx-linux

SRC_BONUS	= 	bonus/src/main.c			\
				bonus/src/julia.c			\
				bonus/src/mandelbrot.c	\
				bonus/src/polynomial.c	

UTILS_BONUS	=	bonus/utils/ft_atold.c		\
				bonus/utils/ft_isspace.c		\
				bonus/utils/utils.c			\
				bonus/utils/utils_1.c			\
				bonus/utils/ft_isdigit.c		\
				bonus/utils/ft_strcmp.c		\
				bonus/utils/utils_2.c

OBJS_BONUS = $(SRC_BONUS:.c=.o) $(UTILS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS_BONUS)
	$(CC) $(FLAGS) $(OBJS_BONUS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

