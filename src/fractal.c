/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:35:32 by lauriago          #+#    #+#             */
/*   Updated: 2024/07/02 11:59:30 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../mlx_linux/mlx.h"

t_color_func	g_color_schemes[] = {color_one, color_two, color_wave,
	color_third, color_nuclear, color_five, color_six};

int	fractal(int ac, char **av)
{
	t_fractal	f;

	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
	{
		f.name = av[1];
		init_fractal(&f);
		fractal_render(&f);
		mlx_loop(f.mlx);
		return (1);
	}
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		f.name = av[1];
		f.jr = ft_atod(av[2]);
		f.ji = ft_atod(av[3]);
		init_fractal(&f);
		fractal_render(&f);
		mlx_loop(f.mlx);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	fractal(ac, av);
	if (fractal(ac, av) == 0)
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		ft_putstr_fd(CORRECT_MANDELBROT_SET, STDERR_FILENO);
		ft_putstr_fd(CORRECT_JULIA_SET, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
