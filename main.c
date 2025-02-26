#include "fract-ol.h"

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

	mandelbrot_set(mlx);
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
	mandelbrot_set(&mlx);
	mlx_mouse_hook(mlx.win, mouse_handler, &mlx);
	mlx_loop(mlx.mlx);
}
