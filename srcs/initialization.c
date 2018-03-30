/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			fractal_src(t_s *s, char *src)
{
	if (ft_strcmp(src, "julia") == 0)
		s->src = 1;
	else if (ft_strcmp(src, "mandelbrot") == 0)
		s->src = 2;
	else if (ft_strcmp(src, "burning ship") == 0)
		s->src = 3;
	else if (ft_strcmp(src, "celtic mandelbar") == 0)
		s->src = 4;
	else if (ft_strcmp(src, "cubic mandelbar") == 0)
		s->src = 5;
	else if (ft_strcmp(src, "buffalo") == 0)
		s->src = 6;
	else if (ft_strcmp(src, "heart") == 0)
		s->src = 7;
	else if (ft_strcmp(src, "great axe") == 0)
		s->src = 8;
	else
	{
		write(2, "bad fractal name\n", 17);
		return (-1);
	}
	return (0);
}

void		fractal_choice(t_s *s)
{
	if (s->src == 1)
		julia(s);
	else if (s->src == 2)
		mandelbrot(s);
	else if (s->src == 3)
		burning_ship(s);
	else if (s->src == 4)
		celtic_mandelbar(s);
	else if (s->src == 5)
		cubic_mandelbar(s);
	else if (s->src == 6)
		buffalo(s);
	else if (s->src == 7)
		heart(s);
	else if (s->src == 8)
		great_axe(s);
}

void		window_datas(t_s *s)
{
	if (s->src >= 2 && s->src <= 8)
	{
		s->x1 = -2.1;
		s->x2 = 0.6;
		s->y1 = 1.2;
		s->y2 = -1.2;
		s->zr = 0;
		s->zi = 0;
	}
	else if (s->src == 1)
	{
		s->x1 = -1;
		s->x2 = 1;
		s->y1 = 1.2;
		s->y2 = -1.2;
		s->cr = 0.285;
		s->ci = 0.01;
	}
	s->i_max = 50;
	s->motion = 0;
	s->zoom = (WIN_X > WIN_Y) ? WIN_Y : WIN_X;
	s->color_choice = 1;
	s->i_zoom = 1;
}
