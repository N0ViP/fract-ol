#include <stdio.h>
#include <complex.h>
#include <mlx.h>
#include "fract-ol.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	unsigned int	*offset;

	offset = (unsigned int *) (mlx->add + (y * mlx->line_len) + (x * (mlx->bpp / 8)));
	*offset = color;
}

int	ft_check_if_mandelbort(int x, int y, int iteration)
{
	double complex	z;
	double complex	c;
	int				i;

	z = 0 + 0 * I;
	c = ((x - 400) * 4) / 800. + ((y - 300) * 3) / 600. * I;
	i = 0;
	while (i < iteration)
	{
		z = (z * z) + c;
		if (cabs(z) > 2)
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
	mlx.iteration = 100;
	mlx.win = mlx_new_window(mlx.mlx, 800, 600, "fract-ol");
	mlx.img = mlx_new_image(mlx.mlx, 800, 600);
	mlx.add = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_len, &mlx.endian);
	for (int j = 0; j < 600; j++)
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
