/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:38:11 by lauriago          #+#    #+#             */
/*   Updated: 2024/06/07 13:09:33 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*offset;

	offset = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)offset = color;
}

void	fractal_render(t_fractal *f)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			//Mapeo las coordenadas X e Y para interpretarlas en un
			//plano complejo (Zn = Zn² + C) --> C = a + bi;
			//la A es un num real y Bi uno imaginario. 
			f->r.r = map_to_real(x, WIDTH, -2.0, 2.0);
			f->r.i = map_to_imaginary(y, HEIGHT, -2.0, 2.0);
			if (set_mandelbrot(f->r.r, f->r.i) == 1)
			{
				my_pixel_put(&f->img, x, y, NEON_ORANGE);	
			}
			else if (set_mandelbrot(f->r.r, f->r.i) == 0)
			{
				my_pixel_put(&f->img, x, y, AQUA_DREAM);	
			}
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}

/*
//	handle_pixel function tells the coordinates of the window map for verify
//	if the actual iteration is part of the set.
void	handle_pixel(int x, int y, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	int	iter;

	iter = 0;
	z.r = (map(x, -2, +2, 0, WIDTH) * (f->zoom)) + f->zx;
	z.i = (map(y, +2, -2, 0, HEIGHT) * (f->zoom)) + f->zy;
	while (iter < MAX_ITER)
	{
		//If hipotenuse > 2 I assume is scaped
		if ((z.r * z.r) + (z.i * z.i) > f->escape_value)
		{
			f->color =  map(iter, BLACK, WHITE, 0, 100);
			//mlx_pixel_put(f->mlx, f->win, WIDTH, HEIGHT, 0x33CCCC);
			my_pixel_put(x, y, 0x33CCCC, &f->img);
		}
		iter++;
	}
	my_pixel_put(x, y, LAVA_RED, &f->img);
}*/
