/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:53:23 by yjaafar           #+#    #+#             */
/*   Updated: 2025/03/06 14:12:37 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_if_mandelbrot(int x, int y, t_mlx *mlx)
{
	int			i;
	t_complex	z;
	t_complex	c;
	double		tmp;

	c.real = (x - (WIDTH / 2)) * (mlx->zoom_factor
			/ (double)WIDTH) + mlx->x_shift;
	c.imag = ((HEIGHT / 2) - y) * (mlx->zoom_factor
			/ (double)HEIGHT) + mlx->y_shift;
	z.real = 0;
	z.imag = 0;
	i = 0;
	if (mlx->iteration <= 0)
		mlx->iteration = 100;
	while (i < mlx->iteration)
	{
		tmp = z.real;
		z.real = ((z.real * z.real) - (z.imag * z.imag)) + c.real;
		z.imag = (2 * tmp * z.imag) + c.imag;
		if (((z.real * z.real) + (z.imag * z.imag)) >= 4)
			break ;
		i++;
	}
	return (i);
}

void	mandelbrot_set(t_mlx *mlx)
{
	int	i;
	int	j;
	int	it;
	int	color;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			it = check_if_mandelbrot(i, j, mlx);
			color = get_color(it, mlx);
			put_pixel(color, i, j, mlx);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
