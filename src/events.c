/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:13:07 by lauriago          #+#    #+#             */
/*   Updated: 2024/05/29 12:56:13 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../mlx/mlx.h"
#include "../inc/libft.h"

void	handle_events(int keycode, t_fractal *f, int x, int y)
{
	//close window
	if (keycode == ESC)
		mlx_destroy_win(f->mlx, f->win);
	//make zoom
	else if (keycode == ZOOM_IN || keycode == MAS)
	{
		f->zoom *= 1.1;
		handle_pixel(x, y, f);
	}
	else if (keycode == ZOOM_OUT || keycode == MENOS)
	{
		f->zoom /= 1.1;
		handle_pixel(x, y, f);
	}
	//mouse move
	else if (keycode = ARROW_LEFT)
	{
		mlx_hook(f->win, 4, 0, mouse_realease, f); //press event
		mlx_hook(f->win, 5, 0, mouse_realease, f); //unpressed event
		mlx_hook(f->win, 6, 0, mouse_mouve, f); //move event
	}

}

int	mouse_press(int button, int x, int y, t_fractal *f)
{
	if (button == 1)
	{
		f->mouse_down = 1;
		f->last_mouse_x = x;
		f->last_mouse_y = y;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_fractal *f)
{
	if (button == 1)
		f->mouse_down = 0;
	return (0);
}

int	mouse_move(int x, int y, t_fractal *f)
{
	if (f->mouse_down)
	{
		f->offset_x = x - f->last_mouse_x;
		f->offset_y = y - f->last_mouse_y;
		f->last_mouse_x = x;
		f->last_mouse_y =  y;
		fractal_render(f);
	}
	return (0);
}
