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

double	map_to_real(int x, int width, double center_r, double zoom)
{
	return (center_r + (x - width / 2.0) * (4.0 / width) / zoom);
}

double	map_to_imaginary(int y, int height, double center_i, double zoom)
{
	return (center_i + (y - height / 2.0) * (4.0 / height) / zoom);
}

/*int	check_arg(char *name)
{
	t_fractal f;

	if (ft_strcmp(f.name, "mandelbrot") == 0)
		return (1);
	if (ft_strcmp(f.name, "julia") == 0)
		return (2);
	return (0);
}
*/
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

int	ft_close(t_fractal *f)
{
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
	return (0);
}
/*double	map_to_real(int x, int width, double min_r, double max_r)
{
	return (min_r + (double)x / width * (max_r - min_r));
}

double	map_to_imaginary(int y, int height, double min_i, double max_i)
{
	return (min_i + (double)y / height * (max_i - min_i));
}
*/
void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}
