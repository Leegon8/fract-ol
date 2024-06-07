/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:46:15 by lauriago          #+#    #+#             */
/*   Updated: 2024/06/05 12:50:53 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../mlx_linux/mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>

/*# define NULL "__null"*/

/*	Dimentions	*/
# define MAX_ITER 42
# define ESCAPE_RADIUS 2.0
# define WIDTH 1024
# define HEIGHT 780

/*	Hooks	*/
# define ESC 53 
// # define ARROW_UP 126
// # define ARROW_DOWN 125
// # define ARROW_LEFT 124
// # define ARROW_RIGHT 123
# define ZOOM_IN 5
# define ZOOM_OUT 4
# define LEFT_CLICK 1
# define ESPACE 49
# define MAS 69
# define MENOS 78

/*	 Fractal sets	*/
# define MANDELBROT 83
# define JULIA 84
# define NUM_3 85

/*	Message error	*/
# define ERROR_MESSAGE "Wrong arguments!\nPlease enter:\n"
# define CORRECT_MANDELBROT_SET "\t\"./fractol mandelbrot\" OR\n"
# define CORRECT_JULIA_SET "\t\"./fractol julia <value 1> <value 2>\"\n"

/*	 Color definitions	*/
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

/*	 Complex number struct	 */
typedef	struct s_complex
{
	double	r;
	double	i;
}	t_complex;

/*	 image variables struct	 */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/*	 general fractal struct	 */
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
}	t_fractal;

/*____________SET INIT____________*/
void		init_fractal(t_fractal *f);
//static void	data_init(t_fractal *f);

/*____________RENDER______________*/
void		fractal_render(t_fractal *f);
//void		handle_pixel(int x, int y, t_fractal *f);
/*___________MANDELBROT SET_______*/
int	is_mandel(char *name);
int	set_mandelbrot(double r, double i);

/*____________UTILS______________*/
double		map_to_real(int x, int width, double min_r, double max_r);
double		map_to_imaginary(int y, int height, double min_i, double max_i);
void		malloc_error(void);
int		ft_close(t_fractal *f);

# endif
