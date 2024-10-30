/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:46:15 by lauriago          #+#    #+#             */
/*   Updated: 2024/07/02 11:52:59 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
/*# define NULL "__null"*/

/*	Dimentions	*/
# define MAX_ITER 42
# define ESCAPE_RADIUS 2.0
# define WIDTH 1024
# define HEIGHT 780
# define COLOR_SCHEME_COUNT 5

/*	Hooks	*/
# define ESC 65307
# define COLOR 99
# define MAS 65451
# define MENOS 65453
// # define ARROW_UP 126
// # define ARROW_DOWN 125
// # define ARROW_LEFT 124
// # define ARROW_RIGHT 123
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define LEFT_CLICK 1
# define SPC 32

/*	Fractal sets	*/
# define MANDELBROT 83
# define JULIA 84
# define NUM_3 85

/*	Message error	*/
# define ERROR_MESSAGE "Wrong arguments!\nPlease enter:\n"
# define CORRECT_MANDELBROT_SET "\t\"./fractol mandelbrot\" OR\n"
# define CORRECT_JULIA_SET "\t\"./fractol julia <value 1> <value 2>\"\n"

typedef int			(*t_color_func)(int, int);

/*		Complex number struct	 */
typedef struct s_complex
{
	double			r;
	double			i;
}					t_complex;

/*		image variables struct	 */
typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;

/*		general fractal struct	 */
typedef struct s_fract
{
	void			*mlx;
	void			*win;
	char			*name;
	t_img			img;
	double			zx;
	double			zy;
	double			jr;
	double			ji;
	double			escape_value;
	double			zoom;
	t_complex		z;
	t_complex		c;
	// other data
	unsigned int	color;
	int				max_iter;
	int				color_scheme;
	int				mouse_x;
	int				mouse_y;
	int				is_dragging;
	// unsigned int	color;
}					t_fractal;

/*____________SET INIT____________*/
void				init_fractal(t_fractal *f);

/*____________RENDER______________*/
void				fractal_render(t_fractal *f);
int					handle_pixel(t_fractal *f);

/*___________FRACTALS SETS_______*/
int					set_mandelbrot(double r, double i, int max_iter,
						double escape_value);
int					set_julia(t_fractal *f, double zr, double zi);

/*____________UTILS______________*/
// double		map_to_real(int x, int width, double min_r, double max_r);
// double		map_to_imaginary(int y, int height, double min_i, double max_i);
double				map_to_real(int x, int width, double center_r, double zoom);
double				map_to_imaginary(int y, int height, double center_i,
						double zoom);

int					color_one(int iter, int max_iter);
int					color_two(int iter, int max_iter);
int					color_wave(int iter, int max_iter);
int					color_third(int iter, int max_iter);
int					color_nuclear(int iter, int max_iter);
int					color_five(int iter, int max_iter);
int					color_six(int iter, int max_iter);
void				malloc_error(void);
int					ft_close(t_fractal *f);

/*___________HOOKS_____________*/
// void	hooks_init(t_fractal *f);
int					handle_key(int keycode, t_fractal *f);
int					mouse_handler(int button, int x, int y, t_fractal *f);
int					mouse_move(int x, int y, t_fractal *f);
int					mouse_press(int button, int x, int y, t_fractal *f);
int					mouse_release(int button);
void				hook_init(t_fractal *f);

extern t_color_func	g_color_schemes[];

#endif
