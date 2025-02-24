/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 05:50:53 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/24 04:29:26 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdio.h>
# include <complex.h>
# include <mlx.h>
# include <math.h>

typedef	struct	s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*add;
	int		bpp;
	int		line_len;
	int		endian;
	int		iteration;
}	t_mlx;

#endif
