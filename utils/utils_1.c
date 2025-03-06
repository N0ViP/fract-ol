/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:51:52 by yjaafar           #+#    #+#             */
/*   Updated: 2025/03/06 14:04:10 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int button, t_mlx *mlx)
{
	if (button == ESC)
		esc_handler(mlx);
	else if (button == PLUS || button == MINS || button == ZERO)
		zoom_handler(button, mlx);
	else if (button == W || button == A || button == S || button == D)
		offset_handler(button, mlx);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_mlx *mlx)
{
	double	mouse_real;
	double	mouse_imag;
	double	zoom_factor;

	mouse_real = (x - (WIDTH / 2)) * (mlx->zoom_factor / (double)WIDTH);
	mouse_imag = ((HEIGHT / 2) - y) * (mlx->zoom_factor / (double)HEIGHT);
	if (button == 4)
		zoom_factor = 1.10;
	else if (button == 5)
		zoom_factor = 0.90;
	else
		return (1);
	mlx->zoom_factor *= zoom_factor;
	mlx->x_shift += mouse_real * (1 - zoom_factor);
	mlx->y_shift += mouse_imag * (1 - zoom_factor);
	if (mlx->set == 0)
		mandelbrot_set(mlx);
	else if (mlx->set == 1)
		julia_set(mlx);
	return (1);
}
