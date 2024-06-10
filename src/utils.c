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

#include "../inc/fractol.h"
#include <stdio.h>
#include <math.h>

double	map_to_real(int x, int width, double min_r, double max_r)
{
	return (x * (max_r - min_r) / width + min_r);
}

double	map_to_imaginary(int y, int height, double min_i, double max_i)
{
	return (y * (max_i - min_i) / height + min_i);
}

int	color_one(int iter, int max_iter)
{
    double t;
	int	r;
	int	g;
	int	b;
	
	t = (double)iter / max_iter;
    r = (unsigned char)(9 * (1 - t) * t * t * t * 255);
    g = (unsigned char)(15 * (1 - t) * (1 - t) * t * t * 255);
    b = (unsigned char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int color_two(int iter, int max_iter)
{
	double t;
	int	r;
	int	g;
	int	b;

	t = (double)iter / max_iter;
	r = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	g = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	b = (int)(9 * (1 - t) * t * t * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int color_wave(int iter, int max_iter) 
{
    double t;
	int	r;
	int	g;
	int b;

	t = (double)iter / max_iter;
    r = (int)(128.0 + 127.0 * cos(1.0 + t * 10.0));
    g = (int)(128.0 + 127.0 * cos(2.0 + t * 10.0));
    b = (int)(128.0 + 127.0 * cos(3.0 + t * 10.0));
    return ((r << 16) | (g << 8) | b);
}

int color_third(int iter, int max_iter)
{
	double t;
	int	r;
	int	g;
	int	b;

	t = (double)iter / max_iter;
	r = (int)(255.0 * t);
	g = (int)(255.0 * sin(5.0 * t));
	b = (int)(255.0 * (1 - t));
    return ((r << 16) | (g << 8) | b);
}

int color_nuclear(int iter, int max_iter)
{
	double t;
	int	r;
	int	g;
	int	b;

	t = (double)iter / max_iter;
	r = (int)(255 * t);
	g = 	(int)(255 * t * t);
	b = 0;
    return ((r << 16) | (g << 8) | b);
}

int color_five(int iter, int max_iter)
{
	double t;
	int	r;
	int	g;
	int	b;

	t = (double)iter / max_iter;
	r = (int)(255 * t);
	g = 0;
	b = (int)(255 * t * t);
    return ((r << 16) | (g << 8) | b);
}

int color_six(int iter, int max_iter)
{
    double t;
    int r;
    int g;
    int b;

    t = (double)iter / max_iter;
    r = (int)(255 * (1 - t));
    g = (int)(255 * sin(t * M_PI / 2));
    b = (int)(255 * cos(t * M_PI / 2));
    int l = (int)(127 + 128 * sin(t * M_PI));
    r = (r + l) / 2;
    g = (g + l) / 2;
    b = (b + l) / 2;
    return ((r << 16) | (g << 8) | b);
}

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
