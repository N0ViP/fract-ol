/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:58:44 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/26 03:44:28 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_if_julia(int x, int y, t_mlx *mlx)
{
	int			i;
	t_complex	z;
	t_complex	c;
	long double	tmp;

	z.real = (x - (WIDTH / 2)) * (mlx->size / (long double)WIDTH);
	z.imag = (y - (HEIGHT / 2)) * (mlx->size / (long double)HEIGHT);
	c.real = mlx->j_real;
	c.imag = mlx->j_imag;
	i = 0;
	while (i < mlx->iteration)
	{
		tmp = z.real;
		z.real = ((z.real * z.real) - (z.imag * z.imag)) + c.real;
		z.imag = (2 * tmp * z.imag) + c.imag;
		if (sqrt((z.real * z.real) + (z.imag * z.imag)) >= 2)
			break ;
		i++;
	}
	return (i);
}

void	julia_set(t_mlx *mlx)
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
			it = check_if_julia(i, j, mlx);
			color = get_color(it, mlx);
			put_pixel(color, i, j, mlx);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
