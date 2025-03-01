/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:56:27 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/26 05:32:13 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"

# define WIDTH	600
# define HEIGHT	600
# define ESC	65307
/* long double for more precesion */

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_mlx
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
}	t_mlx;

double	ft_atold(char *s);
int		ft_isdigit(char c);
int		ft_isspace(char c);
void	julia_set(t_mlx *mlx);
void	mandelbrot_set(t_mlx *mlx);
int		get_color(int it, t_mlx *mlx);
int		ft_strcmp(const char *s1, const char *s2);
void	put_pixel(int color, int i, int j, t_mlx *mlx);
int		mouse_handler(int button, int x, int y, t_mlx *mlx);

#endif
