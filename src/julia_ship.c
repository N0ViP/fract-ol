#include "fractol.h"

static int	check_if_polynomial(int x, int y, t_mlx * mlx)
{
	int			i;
	t_complex	z;
	double		tmp;

	i = 0;
	z.real = (x - WIDTH / 2) * (mlx->zoom_factor
		/ (double)WIDTH) + mlx->x_shift;
	z.imag = (WIDTH / 2 - y) * (mlx->zoom_factor
		/ (double)WIDTH) + mlx->y_shift;
	while (i < mlx->iteration)
	{
		tmp = z.real;
		z.real = pow(z.real, 6) - (15 * pow(z.real, 4) * pow(z.imag, 2))
			+ (15 * pow(z.real, 2) * pow(z.imag, 4)) - (pow(z.imag, 6)) + 0.736;
		z.imag = (6 * pow(tmp, 5) * z.imag) - (20 * pow(tmp, 3) * pow(z.imag, 3))
			+ (6 * tmp * pow(z.imag, 5)) - 0.417355;
		if ((z.real * z.real) + (z.imag * z.imag) > 4)
			break ;
		i++;
	}
	return (i);
}

void	polynomial_set(t_mlx *mlx)
{
	int	color;
	int	iteration;
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			iteration = check_if_polynomial(i, j, mlx);
			color = get_color(iteration, mlx);
			put_pixel(color, i, j, mlx);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}