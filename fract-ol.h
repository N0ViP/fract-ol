/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 05:50:53 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/26 01:34:45 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdio.h>
# include <complex.h>
# include <mlx.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

# define WIDTH	600
# define HEIGHT	600

/* long double for more precesion */

typedef	struct	s_complex
{
	long double	real;
	long double	imag;
}	t_complex;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*add;
	int			bpp;
	int			line_len;
	int			endian;
	int			iteration;
	long double	size;
}	t_mlx;

long double	ft_atold(char *s);
int			ft_isdigit(char c);
int			ft_isspace(char c);
void		mandelbrot_set(t_mlx *mlx);

#endif
