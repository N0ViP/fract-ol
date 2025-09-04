/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:01:22 by yjaafar           #+#    #+#             */
/*   Updated: 2025/03/12 21:01:24 by yjaafar          ###   ########.fr       */
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
		mlx->iteration = 50;
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
	pthread_t	threads[8];

	init_threads(threads, mlx, check_if_mandelbrot);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
