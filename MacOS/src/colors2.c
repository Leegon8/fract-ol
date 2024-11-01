/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:38:28 by lauriago          #+#    #+#             */
/*   Updated: 2024/07/02 12:38:58 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	color_wave(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / max_iter;
	r = (int)(128.0 + 127.0 * cos(1.0 + t * 10.0));
	g = (int)(128.0 + 127.0 * cos(2.0 + t * 10.0));
	b = (int)(128.0 + 127.0 * cos(3.0 + t * 10.0));
	return ((r << 16) | (g << 8) | b);
}

int	color_nuclear(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / max_iter;
	r = (int)(255 * t);
	g = (int)(255 * t * t);
	b = 0;
	return ((r << 16) | (g << 8) | b);
}

int	color_six(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		l;

	t = (double)iter / max_iter;
	r = (int)(255 * (1 - t));
	g = (int)(255 * sin(t * M_PI / 2));
	b = (int)(255 * cos(t * M_PI / 2));
	l = (int)(127 + 128 * sin(t * M_PI));
	r = (r + l) / 2;
	g = (g + l) / 2;
	b = (b + l) / 2;
	return ((r << 16) | (g << 8) | b);
}
