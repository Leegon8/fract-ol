/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:00:14 by lauriago          #+#    #+#             */
/*   Updated: 2024/06/12 11:00:32 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	color_one(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / max_iter;
	r = (unsigned char)(9 * (1 - t) * t * t * t * 255);
	g = (unsigned char)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (unsigned char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	color_two(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / max_iter;
	r = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	g = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	b = (int)(9 * (1 - t) * t * t * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	color_third(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / max_iter;
	r = (int)(255.0 * t);
	g = (int)(255.0 * sin(5.0 * t));
	b = (int)(255.0 * (1 - t));
	return ((r << 16) | (g << 8) | b);
}

int	color_five(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / max_iter;
	r = (int)(255 * t);
	g = 0;
	b = (int)(255 * t * t);
	return ((r << 16) | (g << 8) | b);
}
