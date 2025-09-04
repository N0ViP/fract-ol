/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:01:13 by yjaafar           #+#    #+#             */
/*   Updated: 2025/03/12 21:01:14 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	exit_message(void)
{
	write(1, "./fract-ol brot\nOr\n./fract-ol poly\nOr\n./fract-ol julia x y\n", 59);
	exit(1);
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

static int	get_set(int ac, char *av[], t_mlx *mlx)
{
	if (!ft_strcmp(av[1], "brot"))
		return (0);
	else if (!ft_strcmp(av[1], "julia"))
	{
		if (ac != 4)
			exit_message();
		mlx->j_real = ft_atold(av[2]);
		mlx->j_imag = ft_atold(av[3]);
		return (1);
	}
	else if (!ft_strcmp(av[1], "poly"))
		return (2);
	else
		return (exit_message(), -1);
}

int	main(int ac, char *av[])
{
	t_mlx	mlx;
	int		set;

	mlx = (t_mlx){0};
	mlx.iteration = 50;
	mlx.zoom_factor = 4;
	if (ac == 1)
		exit_message();
	set = get_set(ac, av, &mlx);
	mlx.set = set;
	if (init_mlx(&mlx) == 1)
		exit(1);
	if (mlx.set == 0)
		mandelbrot_set(&mlx);
	else if (mlx.set == 1)
		julia_set(&mlx);
	else
		polynomial_set(&mlx);
	mlx_mouse_hook(mlx.win, mouse_handler, &mlx);
	mlx_key_hook(mlx.win, key_handler, &mlx);
	mlx_hook(mlx.win, 17, 1, exit_handler, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
