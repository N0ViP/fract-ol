#include <stdio.h>
#include <complex.h>
#include <mlx.h>

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*add;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	unsigned int	*offset;

	offset = (unsigned int *) (mlx->add + (y * mlx->line_len) + (x * (mlx->bpp / 8)));
	*offset = color;
}

int	ft_check_if_mandelbort(int x, int y)
{
	double complex	z0;
	double complex	z;
	double complex	tmp;
	int				i;

	z0 = 0;
	z = x + y * I;
	tmp = z;
	i = 0;
	while (i < 100)
	{
		tmp = (tmp * tmp) + z;
		if (tmp >= (double)1000000000)
			return (1);
		i++;
	}
	return (0);

}

int main()
{
	t_mlx  mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 600, 400, "fract-ol");
	mlx.img = mlx_new_image(mlx.mlx, 600, 400);
	mlx.add = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_len, &mlx.endian);
	for (int j = 0; j < 400; j++)
	{
		for (int i = 0; i < 600; i++)
		{
			if (!ft_check_if_mandelbort(i, j))
				put_pixel(&mlx, i, j, 0X00FFFFFF);
		}
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
}
