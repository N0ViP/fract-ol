/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:31:22 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/26 05:13:22 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_handler(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4)
	{
		mlx->size *= 1.1;
	}
	else
	{
		mlx->size *= 0.9;
	}
	if (mlx->set == 0)
		mandelbrot_set(mlx);
	else if (mlx->set == 1)
		julia_set(mlx);
	return (1);
}

int	init_mlx(t_mlx *mlx)
{
	mlx->size = 4;
	mlx->mlx = mlx_init();
	mlx->iteration = 100;
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fract-ol");
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->add = mlx_get_data_addr(mlx->img,
			&mlx->bpp, &mlx->line_len, &mlx->endian);
}

int	main(int ac, char *av[])
{
	t_mlx	mlx;
	int		iteration;

	if (ac != 1 && (!ft_strcmp(av[1], "brot") || !ft_strcmp(av[1], "julia")))
	{
		init_mlx(&mlx);
		if (!ft_strcmp(av[1], "brot"))
			mlx.set = 0;
		else if (!ft_strcmp(av[1], "julia"))
		{
			mlx.j_real = ft_atold(av[2]);
			mlx.j_imag = ft_atold(av[3]);
			mlx.set = 1;
		}
		if (mlx.set == 0)
			mandelbrot_set(&mlx);
		else
			julia_set(&mlx);
		mlx_mouse_hook(mlx.win, mouse_handler, &mlx);
		mlx_loop(mlx.mlx);
	}
	else
		write(1, "./fract-ol mandelbrot\nOr\n./fract-ol julia x y\n", 47);
	return (0);
}
