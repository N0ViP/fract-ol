/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:42:47 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/26 03:46:42 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int it, t_mlx *mlx)
{
	if (it == mlx->iteration)
		return (0x000000);
	return ((it * 5) << 16 | (it * 3) << 8 | (it * 7));
}

void	put_pixel(int color, int i, int j, t_mlx *mlx)
{
	unsigned int	*offset;

	offset = (unsigned int *)(mlx->add + (j * mlx->line_len)
			+ (i * (mlx->bpp / 8)));
	*offset = color;
}

void	esc_handler(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}

void	zoom_handler(int button, t_mlx *mlx)
{
	if (button == PLUS)
		mlx->zoom_factor *= 0,9;
	else if (button == MINS)
		mlx->zoom_factor *= 1.1;
	else
	{
		mlx->iteration = 100;
		mlx->zoom_factor = 4;
	}
	mlx->x_shift = 0;
	mlx->y_shift = 0;
	if (mlx->set == 0)
		mandelbrot_set(mlx);
	else
		julia_set(mlx);
}

#include <stdio.h>

void	offset_handler(int button, t_mlx *mlx)
{
	if (button == W)
		mlx->y_shift += 0.1;
	else if (button == S)
		mlx->y_shift -= 0.1;
	else if (button == A)
		mlx->x_shift -= 0.1;
	else
		mlx->x_shift += 0.1;
	if (mlx->set == 0)
		mandelbrot_set(mlx);
	else
		julia_set(mlx);
}

void	iteration_handler(t_mlx *mlx)
{
	mlx->iteration += 100;
	if (mlx->set == 0)
		mandelbrot_set(mlx);
	else
		julia_set(mlx);
}