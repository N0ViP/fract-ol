#include <stdio.h>
#include <mlx.h>

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

int main()
{
	t_mlx  mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 600, 400, "fract-ol");
	mlx_loop(mlx.mlx);
}
