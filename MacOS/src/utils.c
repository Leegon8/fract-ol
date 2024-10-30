/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:06:34 by lauriago          #+#    #+#             */
/*   Updated: 2024/07/02 12:00:49 by lauriago         ###   ########.fr       */
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

int	ft_close(t_fractal *f)
{
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
	return (0);
}

void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

/*void	instructions(void)
{
	ft_printf("Commands:\n '+' --> iteration + 50\n");
	ft_printf("'-' --> iteration -42\n");
	ft_printf("")
}*/
