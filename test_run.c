/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:29:43 by lauriago          #+#    #+#             */
/*   Updated: 2024/04/26 17:32:31 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 120, 85, "Testing window! :D");
	mlx_loop(mlx);
}
