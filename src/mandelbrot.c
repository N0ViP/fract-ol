/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:53:23 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/28 06:18:31 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_if_mandelbrot(int x, int y, t_mlx *mlx)
{
	int			i;
	t_complex	z;
	t_complex	c;
	double		tmp;

	c.real = (x - (WIDTH / 2)) * (mlx->size / (double)WIDTH);
	c.imag = ((HEIGHT / 2) - y) * (mlx->size / (double)HEIGHT);
	z.real = 0;
	z.imag = 0;
	i = 0;
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
