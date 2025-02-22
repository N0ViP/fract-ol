#include <stdio.h>
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

int main()
{
	t_mlx  mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 600, 400, "fract-ol");
	mlx.img = mlx_new_image(mlx.mlx, 600, 400);
	mlx.add = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_len, &mlx.endian);
	for (int j = 0; j < 200; j++)
	{
		for (int i = 0; i < 300; i++)
		{
			if (i < j)
				put_pixel(&mlx, i, j, 0XFFFF0000);
		}
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
}
