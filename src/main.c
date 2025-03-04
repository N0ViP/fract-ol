/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:31:22 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/26 05:35:34 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	exit_message(void)
{
	write(1, "./fract-ol mandelbrot\nOr\n./fract-ol julia x y\n", 47);
	exit(1);
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

static int	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (1);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fract-ol");
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->add = mlx_get_data_addr(mlx->img,
			&mlx->bpp, &mlx->line_len, &mlx->endian);
	return (0);
}

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

static void	get_set(int ac, char *av[], t_mlx *mlx)
{
	if (!ft_strcmp(av[1], "brot"))
		mlx->set = 0;
	else if (!ft_strcmp(av[1], "julia"))
	{
		if (ac != 4)
			exit_message();
		mlx->j_real = ft_atold(av[2]);
		mlx->j_imag = ft_atold(av[3]);
		mlx->set = 1;
	}
	else
		exit_message();
	if (init_mlx(mlx) == 1)
		exit(1);
	if (mlx->set == 0)
		mandelbrot_set(mlx);
	else
		julia_set(mlx);
	mlx_mouse_hook(mlx->win, mouse_handler, mlx);
	mlx_key_hook(mlx->win, key_handler, mlx);
	mlx_loop(mlx->mlx);
}

int	main(int ac, char *av[])
{
	t_mlx	mlx;

	mlx.mlx = NULL;
	mlx.win = NULL;
	mlx.img = NULL;
	mlx.add = NULL;
	mlx.bpp = 0;
	mlx.line_len = 0;
	mlx.endian = 0;
	mlx.iteration = 100;
	mlx.j_real = 0;
	mlx.j_imag = 0;
	mlx.zoom_factor = 4;
	mlx.set = 0;
	mlx.x_shift = 0;
	mlx.y_shift = 0;
	if (ac == 1)
		exit_message();
	get_set(ac, av, &mlx);
	return (0);
}
