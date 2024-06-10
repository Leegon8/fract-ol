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
#include "../mlx_linux/mlx.h"

// 1. gestionar zoom -> segun coordenadas del ratón 
//	hacer la iteración multiplicado x 1.5
// 2. detectar click izquierdo y permitir que cuando
//	arrastre el plano, las coordenadas se muevan
// (bonus)---------------------
// 3. Al apretar la letra C, cambiar color
// 	hacer variaciones de colores
// 4. En el fractal de julia con las flechas del teclado
//	permitir que las coordenadas del fractal cambien
// 5. Al apretar la letra I, cambiar valor MAX_ITER
// 6. Al apretar la cruz de la ventana se para el programa
// (bonus)----------------------
// 7. Al apretar ESC finaliza el programa

int handle_key(int keycode, t_fractal *f)
{	
	if (keycode == ESC)
		ft_close(f);
	if (keycode == MAS)
	{
		if (f->max_iter < 300)
			f->max_iter += 50;
		fractal_render(f, g_color_schemes);
	}
	if (keycode == MENOS)
	{
		f->max_iter -= 42;
		fractal_render(f, g_color_schemes);
	}
	else if (keycode == COLOR)
	{
		f->color_scheme = (f->color_scheme + 1) % 7;
		fractal_render(f, g_color_schemes);
	}
	printf("Tecla presionada: %d\n", keycode);
	printf("MAX_ITER = %d\n", f->max_iter);
	return (0);
}

int mouse_move(int x, int y, t_fractal *fract)
{
    fract->mouse_x = x;
    fract->mouse_y = y;
    printf("Mouse position: (%d, %d)\n", fract->mouse_x, fract->mouse_y);
    return (0);
}

void	hook_init(t_fractal *f)
{
	mlx_hook(f->win, KeyPress, KeyPressMask, handle_key, f);
	mlx_hook(f->win, 6, 1L<<6, mouse_move, f);
	//mlx_hook(f->win, ButtonPress, ButtonPressMask, mouse_handler, f);
	//mlx_hook(f->win, MotionNotify, PointerMotionMask, &mouse_handler, f);
}