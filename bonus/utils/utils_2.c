#include "fractol.h"

static void	*calcul_height(void *arg)
{
	t_height_info   *height_info;
	int		        i;
	int		        it;
	int		        color;

	height_info = (t_height_info *)arg;
	while (height_info->height_from < height_info->height_to)
	{
		i = 0;
		while (i < WIDTH)
		{
			it = height_info->calcul_fct(i, height_info->height_from, height_info->mlx);
			color = get_color(it, height_info->mlx);
			put_pixel(color, i, height_info->height_from, height_info->mlx);
			i++;
		}
		height_info->height_from++;
	}
	return (NULL);
}

void	init_threads(pthread_t *threads, t_mlx *mlx, int (*calcul_fct)(int, int, t_mlx *mlx))
{
	t_height_info	height_info[8];
	int		        div = 8;
	int		        rows_per_thread = HEIGHT / div;

	for (int i = 0; i < div; i++)
	{
		height_info[i].mlx = mlx;
		height_info[i].height_from = i * rows_per_thread;
		height_info[i].height_to = (i == div - 1) ? HEIGHT : (i + 1) * rows_per_thread;
		height_info[i].calcul_fct = calcul_fct;	
		if (pthread_create(&threads[i], NULL, calcul_height, &height_info[i]))
		{
			perror("pthread_create");
			exit(EXIT_FAILURE);
		}
	}
	for (int i = 0; i < div; i++)
	{
		pthread_join(threads[i], NULL);
	}
}

