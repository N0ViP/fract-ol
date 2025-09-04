/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:56:27 by yjaafar           #+#    #+#             */
/*   Updated: 2025/03/12 21:26:12 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define WIDTH 800
# define HEIGHT	800
# define ESC	65307
# define ZERO	48
# define PLUS	61
# define MINS	45
# define TOP	65362
# define DOWN	65364
# define LEFT	65361
# define RIGHT	65363
# define SPACE	32

/* long double for more precesion */

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;


typedef	struct s_mlx	t_mlx;

typedef struct s_calcul_info_height
{
	int				height_from;
	int				height_to;
	int				(*calcul_fct)(int, int, t_mlx *mlx);
	t_mlx			*mlx;
}	t_height_info;

struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*add;
	int		bpp;
	int		line_len;
	int		endian;
	int		iteration;
	double	j_real;
	double	j_imag;
	double	zoom_factor;
	int		set;
	double	x_shift;
	double	y_shift;		
};

double	ft_atold(char *s);
int		ft_isdigit(char c);
int		ft_isspace(char c);
void	julia_set(t_mlx *mlx);
int		exit_handler(t_mlx *mlx);
void	mandelbrot_set(t_mlx *mlx);
void	polynomial_set(t_mlx *mlx);
int		get_color(int it, t_mlx *mlx);
int		key_handler(int button, t_mlx *mlx);
void	zoom_handler(int button, t_mlx *mlx);
void	offset_handler(int button, t_mlx *mlx);
int		ft_strcmp(const char *s1, const char *s2);
void	put_pixel(int color, int i, int j, t_mlx *mlx);
int		mouse_handler(int button, int x, int y, t_mlx *mlx);
void	init_threads(pthread_t *threads, t_mlx *mlx, int (calcul_fct)(int, int, t_mlx *mlx));

#endif
