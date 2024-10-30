/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:51:53 by lauriago          #+#    #+#             */
/*   Updated: 2024/07/02 12:01:17 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
	Formula Julia set:
	Zn+1 = Zn^2 + C
	Z and C are complex numbers

*/

int	set_julia(t_fractal *f, double zr, double zi)
{
	double	tmp;
	int		iter;

	iter = 0;
	while (iter < f->max_iter)
	{
		if ((zr * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->ji;
		zr = zr * zr - zi * zi + f->jr;
		zi = tmp;
		iter++;
	}
	return (iter);
}
