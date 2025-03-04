/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:58:44 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/28 06:18:46 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_if_julia(int x, int y, t_mlx *mlx)
{
	int			i;
	t_complex	z;
	double		tmp;

	z.real = (x - (WIDTH / 2)) * (mlx->zoom_factor / (double)WIDTH) + mlx->x_shift;
	z.imag = ((HEIGHT / 2) - y) * (mlx->zoom_factor / (double)HEIGHT) + mlx->y_shift;
	i = 0;
	while (i < mlx->iteration)
	{
		tmp = z.real;
		z.real = ((z.real * z.real) - (z.imag * z.imag)) + mlx->j_real;
		z.imag = (2 * tmp * z.imag) + mlx->j_imag;
		if (((z.real * z.real) + (z.imag * z.imag)) >= 4)
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
