/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:13:07 by lauriago          #+#    #+#             */
/*   Updated: 2024/07/02 11:58:27 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// 1. gestionar zoom -> segun coordenadas del ratón
//	hacer la iteración multiplicado x 1.5
//	Al apretar 1 (49) -> Fractol Mandelbrot
//	Al apretar 2 (50) -> Fractol Julia
// 2. detectar click izquierdo y permitir que cuando
//	arrastre el plano, las coordenadas se muevan
// (bonus)---------------------
// 3. Al apretar la letra C, cambiar color
// 	hacer variaciones de colores
// 4. En el fractal de julia con las flechas del teclado
//	permitir que las coordenadas del fractal cambien
// 5. Al apretar la letra +, cambiar valor MAX_ITER
// 6. Al apretar la cruz de la ventana se para el programa
// (bonus)----------------------
// 7. Al apretar ESC finaliza el programa

int	handle_key(int keycode, t_fractal *f)
{
	if (keycode == ESC)
		ft_close(f);
	if (keycode == MAS)
	{
		if (f->max_iter < 300)
			f->max_iter += 50;
		fractal_render(f);
	}
	if (keycode == MENOS)
	{
		f->max_iter -= 42;
		fractal_render(f);
	}
	else if (keycode == COLOR)
	{
		f->color_scheme = (f->color_scheme + 1) % 7;
		fractal_render(f);
	}
	return (0);
}

/*int mouse_move(int x, int y, t_fractal *f)
{
	double	mouse_r;
	double	mouse_i;

	mouse_r = map_to_real(x, WIDTH, f->zx - 2.0 / f->zoom, f->zx + 2.0
			/ f->zoom);
	mouse_i = map_to_imaginary(y, HEIGHT, f->zy - 2.0 / f->zoom, f->zy + 2.0
			/ f->zoom);
	//if (mouse_press(LEFT_CLICK, x, y, f) == 0)
	//{
		f->zx = mouse_r;
		f->zy = mouse_i;
	//}
	fractal_render(f);
	return (0);
}

int	mouse_press(int button, int x, int y, t_fractal *f)
{
	while (button == LEFT_CLICK)
	{
		f->is_dragging = 1;
		mouse_move(x, y, f);
	}
	f->is_dragging = 0;
	return (0);
}

int	mouse_release(int button)
{
	double	mouse_r;
	double	mouse_i;
	double	interpolation;

	if (button == 1) // Botón izquierdo del ratón
		return (1);
	return (0);
}*/
int	mouse_handler(int button, int x, int y, t_fractal *f)
{
	double	mouse_r;
	double	mouse_i;
	double	interpolation;

	mouse_r = map_to_real(x, WIDTH, f->zx, f->zoom);
	mouse_i = map_to_imaginary(y, HEIGHT, f->zy, f->zoom);
	if (button == ZOOM_IN)
		interpolation = 1.1;
	else if (button == ZOOM_OUT)
		interpolation = 1 / 1.1;
	else if (button == 1)
		return (0);
	else
		return (0);
	f->zx = mouse_r + (f->zx - mouse_r) * interpolation;
	f->zy = mouse_i + (f->zy - mouse_i) * interpolation;
	f->zoom *= interpolation;
	fractal_render(f);
	return (0);
}

void	hook_init(t_fractal *f)
{
	mlx_hook(f->win, 2, 1L << 0, handle_key, f);
	mlx_hook(f->win, 4, 1L << 2, mouse_handler, f);
	mlx_hook(f->win, 17, 0, ft_close, f);
}
