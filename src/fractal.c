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

//#include "../mlx/mlx.h"
#include "../inc/fractol.h"
#include "../mlx_linux/mlx.h"

/*typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef	struct s_fract
{
	//MLX
	void	*mlx;
	void	*win;
	char	*name;
	//IMG
	t_img	img;

	double	zx;
	double	zy;
	double	julia_x;
	double	julia_y;
	t_complex	r;
	t_complex	c;

	//other data
	double	escape_value;
	double	zoom;

	int		*palette;
	int		color_pattern;
	int		color;
}	t_fractal;*/


int	main(int ac, char **av)
{
	t_fractal	f;

	if ((ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
		|| (ac == 4 && ft_strcmp(av[1], "julia") == 0))
	{
		f.name = av[1];
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

/*
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} 				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}*/
