/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:01:01 by yjaafar           #+#    #+#             */
/*   Updated: 2025/03/12 21:01:03 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_if_julia(int x, int y, t_mlx *mlx)
{
	int			i;
	t_complex	z;
	double		tmp;

	z.real = (x - (WIDTH / 2)) * (mlx->zoom_factor
			/ (double)WIDTH) + mlx->x_shift;
	z.imag = ((HEIGHT / 2) - y) * (mlx->zoom_factor
			/ (double)HEIGHT) + mlx->y_shift;
	i = 0;
	if (mlx->iteration <= 0)
		mlx->iteration = 50;
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
	pthread_t	threads[8];

	init_threads(threads, mlx, check_if_julia);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
