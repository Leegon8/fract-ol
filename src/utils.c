/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:06:34 by lauriago          #+#    #+#             */
/*   Updated: 2024/06/07 11:35:53 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/fractol.h"
#include "../mlx_linux/mlx.h"
#include <stdio.h>

double	map_to_real(int x, int width, double min_r, double max_r)
{
	return (x * (max_r - min_r) / width + min_r);
}
double	map_to_imaginary(int y, int height, double min_i, double max_i)
{
	return (y * (max_i - min_i) / height + min_i);
}

/*double  map(double unscaled_num, double new_min, double new_max,
    double old_min, double old_max)
{
	if (old_max == old_min)
	exit(EXIT_FAILURE);
    return ((new_max - new_min) * (unscaled_num - old_min) /
        (old_max - old_min) + new_min);
}

// General formula -->	Zn^2 = Zn + C
// This function calculates the (Zn + C)
t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;
	
	result.r = z1.r + z2.r;
	result.i = z1.i + z2.i;
	return (result);
}

//real = (x^2 - y^2)
//i = 2*x*y
t_complex	square_complex(t_complex z)
{
	t_complex	result;
	
	result.r = (z.r * z.r) - (z.i * z.i);
	result.i = 2 * z.r * z.i;
	return (result);
}*/

// In case of malloc errors...
void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

int	ft_close(t_fractal *f)
{
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
	return (0);
}
