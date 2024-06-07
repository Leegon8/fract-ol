/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:30:36 by lauriago          #+#    #+#             */
/*   Updated: 2024/06/05 12:38:53 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/fractol.h"
#include "../mlx_linux/mlx.h"
//#include "../mlx/mlx.h"

static void	data_init(t_fractal *f)
{
	f->escape_value = 2.0;
	f->zx = 0.0;
	f->zy = 0.0;
	f->zoom = 1.0;
}


void	init_fractal(t_fractal *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->name);
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	//events_init(f); //TODO
	data_init(f);
}

/*void	init_fractal(t_fractal *f)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		malloc_error();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->name);
	if (NULL == f->win)
	{
		mlx_destroy_window(f->mlx, f->win);
		//mlx_destroy_display(f->mlx);
		free(f->mlx);
		malloc_error();
	}
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (f->img.img == NULL)
	{
		mlx_destroy_window(f->mlx, f->win);
		//mlx_destroy_display(f->mlx);
		free(f->mlx);
		malloc_error();
	}
	f->img.pixels_ptr = mlx_get_data_addr(f->img.img, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	//events_init(f); //TODO
	data_init(f);
}*/
