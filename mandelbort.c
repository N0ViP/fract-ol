/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:53:23 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/26 02:00:09 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

static int	check_if_mandelbrot(int x, int y, t_mlx *mlx)
{
	int			i;
	t_complex	z;
	t_complex	c;
	long double	tmp;

	c.real = (x - (WIDTH / 2)) * (mlx->size / WIDTH);
	c.imag = (y - (HEIGHT / 2)) * (mlx->size / HEIGHT);
	z.real = 0;
	z.imag = 0;
	i = 0;
	while (i < mlx->iteration)
	{
		tmp = z.real;
		z.real = ((z.real * z.real) - (z.imag * z.imag)) + c.real;
		z.imag = (2 * tmp * z.imag) + c.imag;
		if (sqrt((z.real * z.real) + (z.imag * z.imag)) > 2)
			break ;
		i++;
	}
	return (i);
}

static int	get_color(int it, t_mlx *mlx)
{
	char	tmp;

	if (it == mlx->iteration)
		return (0X00000000);
	tmp = (it / mlx->iteration) * 255;
	return ((tmp << 16) | (tmp << 8) | tmp);
}

static void	put_pixel(int color, int i, int j, t_mlx *mlx)
{
	unsigned int	*offset;

	offset = (unsigned int *) (mlx->add + (j * mlx->line_len) + (i * (mlx->bpp / 8)));
	*offset = color;
}

void	mandelbrot_set(t_mlx *mlx)
{
	int	i;
	int	j;
	int	it;
	int	color;

	i = 0;
	j = 0;
	while (j < HEIGHT)
	{
		while (i < WIDTH)
		{
			it = check_if_mandelbrot(i, j, mlx);
			color = get_color(it, mlx);
	printf("color = %d\n", color);
			put_pixel(color, i, j, mlx);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx, mlx->win, mlx->img, 0, 0);
}
