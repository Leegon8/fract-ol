/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:26:19 by lauriago          #+#    #+#             */
/*   Updated: 2024/06/07 23:25:40 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	set_mandelbrot(double r, double i, int max_iter, double escape_value)
{
	t_complex	z;
	t_complex	z2;
	int			iter;

	z.r = 0.0;
	z.i = 0.0;
	z2.r = 0.0;
	z2.i = 0.0;
	iter = 0;
	while (iter < max_iter)
	{
		z2.r = z.r * z.r;
		z2.i = z.i * z.i;
		if (z2.r + z2.i > escape_value * escape_value)
			return (iter);
		z.i = 2.0 * z.r * z.i + i;
		z.r = z2.r - z2.i + r;
		iter++;
	}
	return (max_iter);
}
/*
//Zn+1 = Zn^2 + C
//Function calculates if the coordenate is part of the set; 
//returns 1 if it is part and 0 if isn't part
*/