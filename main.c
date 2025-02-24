#include "fract-ol.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	unsigned int	*offset;

	offset = (unsigned int *) (mlx->add + (y * mlx->line_len) + (x * (mlx->bpp / 8)));
	*offset = color;
}

int	ft_check_if_mandelbort(int x, int y, int iteration)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			i;

	z.real = 0;
	z.imag = 0;
	c.real = ((x - 400) * 4) / 800.;
	c.imag = ((y - 400) * 4) / 800.;
	i = 0;
	while (i < iteration)
	{
		tmp = z.real;
		z.real = ((z.real * z.real) - (z.imag * z.imag)) + c.real;
		z.imag = (z.imag * tmp * 2) + c.imag;
		if (sqrt(pow(z.real, 2) + pow(z.imag, 2)) > 2)
			return (i);
		i++;
	}
	return (iteration);
}

int get_color(int iterations, int max_iterations)
{
    if (iterations == max_iterations)
		return 0x000000;
	int color_value = (iterations * 255) / max_iterations;
    return ((color_value << 16) | (color_value << 8) | color_value);
}

int main()
{
	t_mlx	mlx;
	int		iteration;
	int		color;

	mlx.mlx = mlx_init();
	mlx.iteration = 250;
	mlx.win = mlx_new_window(mlx.mlx, 800, 800, "fract-ol");
	mlx.img = mlx_new_image(mlx.mlx, 800, 800);
	mlx.add = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_len, &mlx.endian);
	for (int j = 0; j < 800; j++)
	{
		for (int i = 0; i < 800; i++)
		{
			iteration = ft_check_if_mandelbort(i, j, mlx.iteration);
			color = get_color(iteration, mlx.iteration);
			put_pixel(&mlx, i, j, color);
		}
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
}
