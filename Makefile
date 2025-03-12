NAME		=	fractol

CC			=	cc

FLAGS		=	-Wall -Wextra -Werror

SRC			=	mandatory/src/main.c			\
				mandatory/src/julia.c			\
				mandatory/src/mandelbrot.c

UTILS		=	mandatory/utils/ft_atold.c		\
				mandatory/utils/ft_isspace.c	\
				mandatory/utils/utils.c			\
				mandatory/utils/utils_1.c		\
				mandatory/utils/ft_isdigit.c	\
				mandatory/utils/ft_strcmp.c

LIBS		=	-Lmlx_linux -lmlx_Linux -L/usr/include/minilibx-linux -lXext -lX11 -lm -lz

INCLUDE		=	-Iinclude/ -I/usr/include/minilibx-linux/

OBJS		=	$(SRC:.c=.o) $(UTILS:.c=.o)

NAME_BONUS	=	fractol_bonus

SRC_BONUS	= 	bonus/src/main_bonus.c			\
				bonus/src/julia_bonus.c			\
				bonus/src/mandelbrot_bonus.c	\
				bonus/src/polynomial_bonus.c	

UTILS_BONUS	=	bonus/utils/ft_atold_bonus.c		\
				bonus/utils/ft_isspace_bonus.c		\
				bonus/utils/utils_bonus.c			\
				bonus/utils/utils_1_bonus.c			\
				bonus/utils/ft_isdigit_bonus.c		\
				bonus/utils/ft_strcmp_bonus.c

OBJS_BONUS = $(SRC_BONUS:.c=.o) $(UTILS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(FLAGS) $(OBJS_BONUS) $(LIBS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus

