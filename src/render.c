/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:38:11 by lauriago          #+#    #+#             */
/*   Updated: 2024/07/02 11:57:26 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*offset;

	offset = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)offset = color;
}

static void	set_render(t_complex *z, t_complex *c, t_fractal *f)
{
	if (ft_strcmp(f->name, "julia") == 0)
	{
		c->r = f->jr;
		c->i = f->ji;
	}
	else
	{
		c->r = z->r;
		c->i = z->i;
	}
}

// Mapeo las coordenadas X e Y para interpretarlas en un
// plano complejo (Zn = Zn² + C) --> C = a + bi;
// la A es un num real y Bi uno imaginario.
void	fractal_render(t_fractal *f)
{
	int	y;
	int	x;
	int	iter;

	iter = 0;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			f->z.r = map_to_real(x, WIDTH, f->zx, f->zoom);
			f->z.i = map_to_imaginary(y, HEIGHT, f->zy, f->zoom);
			set_render(&f->z, &f->c, f);
			iter = handle_pixel(f);
			f->color = g_color_schemes[f->color_scheme](iter, MAX_ITER);
			my_pixel_put(&f->img, x, y, f->color);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}

int	handle_pixel(t_fractal *f)
{
	int	iter;

	iter = 0;
	if (ft_strcmp(f->name, "mandelbrot") == 0)
		iter = set_mandelbrot(f->z.r, f->z.i, f->max_iter, f->escape_value);
	else if (ft_strcmp(f->name, "julia") == 0)
		iter = set_julia(f, f->z.r, f->z.i);
	return (iter);
}
