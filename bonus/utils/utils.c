/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:02:51 by yjaafar           #+#    #+#             */
/*   Updated: 2025/03/12 21:19:36 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iteration, t_mlx *mlx)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	double			t;

	if (iteration == mlx->iteration)
		return (0);
	t = ((double)iteration + 2) / mlx->iteration;
	r = (unsigned char)(9 * (1 - t) * t * t * t * 255);
	g = (unsigned char)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (unsigned char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}

void	put_pixel(int color, int i, int j, t_mlx *mlx)
{
	unsigned int	*offset;

	offset = (unsigned int *)(mlx->add + (j * mlx->line_len)
			+ (i * (mlx->bpp / 8)));
	*offset = color;
}

int	exit_handler(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
	return (0);
}

void	zoom_handler(int button, t_mlx *mlx)
{
	if (button == PLUS)
		mlx->iteration += 10;
	else if (button == MINS)
		mlx->iteration -= 10;
	else
	{
		mlx->iteration = 50;
		mlx->zoom_factor = 4;
		mlx->x_shift = 0;
		mlx->y_shift = 0;
	}
	if (mlx->set == 0)
		mandelbrot_set(mlx);
	else if (mlx->set == 1)
		julia_set(mlx);
	else
		polynomial_set(mlx);
}

void	offset_handler(int button, t_mlx *mlx)
{
	if (button == TOP)
		mlx->y_shift -= mlx->zoom_factor * 0.005;
	else if (button == DOWN)
		mlx->y_shift += mlx->zoom_factor * 0.005;
	else if (button == LEFT)
		mlx->x_shift += mlx->zoom_factor * 0.005;
	else
		mlx->x_shift -= mlx->zoom_factor * 0.005;
	if (mlx->set == 0)
		mandelbrot_set(mlx);
	else if (mlx->set == 1)
		julia_set(mlx);
	else
		polynomial_set(mlx);
}
