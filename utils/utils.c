/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:42:47 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/26 03:46:42 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int it, t_mlx *mlx)
{
	int	tmp;

	if (it == mlx->iteration)
		return (0X00000000);
	tmp = ((it * 255) / mlx->iteration);
	return ((tmp << 16) | (tmp << 8) | tmp);
}

void	put_pixel(int color, int i, int j, t_mlx *mlx)
{
	unsigned int	*offset;

	offset = (unsigned int *)(mlx->add + (j * mlx->line_len)
			+ (i * (mlx->bpp / 8)));
	*offset = color;
}
