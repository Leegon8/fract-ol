/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:26:19 by lauriago          #+#    #+#             */
/*   Updated: 2024/06/07 12:03:11 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/fractol.h"

int	is_mandel(char *name)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
		return (1);
	return (0);
}
/*
int mandelbrot_iterations(double real, double imag) {
    double z_real = 0.0, z_imag = 0.0;  // Inicializar z = 0 + 0i
    double z_real_squared = 0.0, z_imag_squared = 0.0;

    for (int i = 0; i < MAX_ITER; ++i) {
        z_real_squared = z_real * z_real;
        z_imag_squared = z_imag * z_imag;

        // Verificar la condición de escape
        if (z_real_squared + z_imag_squared > ESCAPE_RADIUS * ESCAPE_RADIUS) {
            return i;  // Retornar el número de iteraciones antes de escapar
        }

        // z = z^2 + c
        z_imag = 2.0 * z_real * z_imag + imag;
        z_real = z_real_squared - z_imag_squared + real;
    }
    return MAX_ITER;  // Si no escapa, retornar el número máximo de iteraciones
}

int	set_mandelbrot(t_fractal *f)
{
	double	zr;
	double	zi;
	int	iter;

	f->zx = 0;
	f->zy = 0;
	zr = 0.0;
	zi = 0.0;
	iter = 0;
	while (iter < MAX_ITER)
	{
		zr = f->zx * f->zx;
		zi = f->zy * f->zy;
		if (zr + zi > ESCAPE_RADIUS * ESCAPE_RADIUS)
			return (iter);
		f->zy = 2.0 * f->zx * f->zy - f->zy;
		f->zx = zr - zi + f->zx;
		iter++;
	}
	return (MAX_ITER);
}*/
//Zn+1 = Zn^2 + C
//Function calculates if the coordenate is part of the set; 
//returns 1 if it is part and 0 if isn't part

int	set_mandelbrot(double r, double i)
{
	t_complex	z;
	t_complex	z2;
	int		iter;

	z.r = 0.0;
	z.i = 0.0;
	z2.r = 0.0;
	z2.i = 0.0;
	iter = 0;
	while (++iter < MAX_ITER)
	{
		z2.r = z.r * z.r;
		z2.i = z.i * z.i;
		if (z2.r + z2.i > ESCAPE_RADIUS * ESCAPE_RADIUS)
			return (0);
		z.i = 2.0 * z.r * z.i + i;
		z.r = z2.r - z2.i + r;
	}
	return (1);
}
