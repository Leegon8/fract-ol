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
#define N_F 10

const char* inspo_key[N_F] = {
    "Los fractales nos enseñan que la belleza y la complejidad pueden surgir de patrones simples repetidos una y otra vez.",
    "En los fractales, cada pequeño detalle refleja la grandeza del todo. Así también, en la vida, cada pequeño esfuerzo cuenta.",
    "La geometría de los fractales nos recuerda que en el caos hay orden y en la simplicidad, infinitas posibilidades.",
    "Observa los fractales y descubre cómo la naturaleza encuentra la armonía en la repetición y la variación.",
    "Los fractales nos inspiran a ver más allá de lo visible, a encontrar la magia en lo aparentemente caótico.",
    "Al igual que un fractal, cada paso que das en tu camino puede parecer pequeño, pero forma parte de un diseño grandioso.",
    "Los fractales nos enseñan que la perfección no está en la ausencia de complejidad, sino en la armonía dentro del caos.",
    "En el mundo de los fractales, las formas más asombrosas surgen de reglas simples, recordándonos que la grandeza puede empezar desde lo básico.",
    "La matemática de los fractales nos muestra que lo infinito puede estar contenido en lo finito, y que dentro de nosotros mismos hay universos por descubrir.",
    "Como un fractal, tu potencial es ilimitado y está lleno de posibilidades infinitas, esperando ser exploradas."
};

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

void	inspiration_key(void)
{
	int randomIndex = rand() % N_F;
            ft_printf(GREEN "%s\n\n" RESET, inspo_key[randomIndex]);
}

