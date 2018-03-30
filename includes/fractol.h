/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_test.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:53:25 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 22:53:27 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

# define WIN_X 1000
# define WIN_Y 1000
# define THREADS 20

# define MOTION_NOTIFY 6
# define POINTER_MOTION_MASK (1L<<6)

# define BUTTON_PRESS 4
# define BUTTON_PRESS_MASK (1L<<2)

typedef struct		s_img
{
	void			*win_ptr;
	void			*mlx_ptr;
	void			*img_ptr;
	unsigned char	*data;
	int				l_size;
	int				bpp;
	int				endian;

	int				src;

	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				zoom;

	double			cr;
	double			ci;
	double			zr;
	double			zi;
	double			z_r;
	double			z_i;
	double			i;
	int				i_max;
	double			tmp;

	int				x;
	int				y;
	double			diff_x;
	double			diff_y;
	int				motion;
	int				color_choice;
	int				commands;
	int				color_frame;
	double			i_zoom;

	int				start;
	int				end;
}					t_s;

void				*thread_link(void *e);
void				multithreading(t_s *s, void *(*f)(void *param));
void				green(t_s *s, int nb_color);
void				red(t_s *s, int nb_color);
void				blue(t_s *s, int nb_color);
int					fractal_src(t_s *s, char *src);
void				fractal_choice(t_s *s);
void				refresh_image(t_s *s, int keycode);
void				display_commands(t_s *s);
void				key_move(int keycode, t_s *s);
int					mouse_zoom(int clic, int x, int y, t_s *s);
int					mouse_motion(int x, int y, t_s *s);
int					key_functions(int keycode, t_s *s);
void				colors(t_s *s, double z_r, double z_i);
void				mandelbrot_datas(t_s *s);
void				julia(t_s *s);
void				celtic_mandelbar(t_s *s);
void				buffalo(t_s *s);
void				heart(t_s *s);
void				great_axe(t_s *s);
void				burning_ship(t_s *s);
void				cubic_mandelbar(t_s *s);
void				mandelbrot(t_s *s);
void				window_datas(t_s *s);
void				display_window(t_s *s);

#endif
