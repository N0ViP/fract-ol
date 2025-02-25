#include "fract-ol.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	unsigned int	*offset;

	offset = (unsigned int *) (mlx->add + (y * mlx->line_len) + (x * (mlx->bpp / 8)));
	*offset = color;
}

int get_color(int iterations, int max_iterations)
{
    if (iterations == max_iterations)
		return 0x000000;
	int color_value = (iterations * 255) / max_iterations;
    return ((color_value << 16) | (color_value << 8) | color_value);
}

int	ft_check_if_mandelbrot(int x, int y, t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			i;

	z.real = 0;
	z.imag = 0;
	c.real = (x - (WIDTH / 2)) * mlx->size / (double)WIDTH;
	c.imag = (y - (HEIGHT / 2)) * mlx->size / (double)HEIGHT;
	i = 0;
	while (i < mlx->iteration)
	{
		tmp = z.real;
		z.real = ((z.real * z.real) - (z.imag * z.imag)) + c.real;
		z.imag = (z.imag * tmp * 2) + c.imag;
		if (sqrt((z.real * z.real) + (z.imag * z.imag)) > 2)
			return (i);
		i++;
	}
	return (mlx->iteration);
}

void	ft_put_mandelbrot(t_mlx *mlx)
{
	int	i;
	int	j;
	int	color;
	int	it;

	i = 0;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
    	while (i < WIDTH)
		{
			it = ft_check_if_mandelbrot(i, j, mlx);
			color = get_color(it, mlx->iteration);
			put_pixel(mlx, i, j, color);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

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

	ft_put_mandelbrot(mlx);
	return (1);
}

int main(void)
{
	t_mlx	mlx;
	int		iteration;

	mlx.size = 4;
	mlx.mlx = mlx_init();
	mlx.iteration = 100;
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "fract-ol");
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.add = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_len, &mlx.endian);
	ft_put_mandelbrot(&mlx);
	mlx_mouse_hook(mlx.win, mouse_handler, &mlx);
	mlx_loop(mlx.mlx);
}
