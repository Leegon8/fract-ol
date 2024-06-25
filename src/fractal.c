/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:35:32 by lauriago          #+#    #+#             */
/*   Updated: 2024/06/04 11:26:22 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../mlx_linux/mlx.h"

color_func	g_color_schemes[] = {
	color_one,
	color_two,
	color_wave,
	color_third,
	color_nuclear,
	color_five,
	color_six};



int	main(int ac, char **av)
{
	t_fractal	f;

	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
	{
		f.name = av[1];
		init_fractal(&f);
		fractal_render(&f);
		mlx_loop(f.mlx);
	}
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		f.name = av[1];
		f.jr = ft_atod(av[2]);
		f.ji = ft_atod(av[3]);
		init_fractal(&f);
		fractal_render(&f);
		mlx_loop(f.mlx);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		ft_putstr_fd(CORRECT_MANDELBROT_SET, STDERR_FILENO);
		ft_putstr_fd(CORRECT_JULIA_SET, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
