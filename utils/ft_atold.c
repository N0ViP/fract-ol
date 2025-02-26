/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:11:35 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/26 00:12:31 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* ascii to long double */

double	ft_atold(char *s)
{
	double	result;
	double	i;
	int			sign;

	result = 0;
	while (ft_isspace(*s))
		s++;
	sign = -1 * (*s == 45) + (*s != 45);
	s += (*s == 45 || *s == 43);
	while (ft_isdigit(*s))
		result = ((result * 10) + (*s++ & 0X0F));
	if (*s == '.')
	{
		s++;
		i = 1.;
		while (ft_isdigit(*s))
		{
			i *= 10.;
			result += ((*s++ & 0X0F) / i);
		}
	}
	if (sign == -1)
		return (-result);
	return (result);
}
