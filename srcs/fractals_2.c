/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		burning_ship(t_s *s)
{
	s->x = s->start;
	while (s->x < s->end)
	{
		s->y = 0;
		while (s->y < WIN_Y)
		{
			mandelbrot_datas(s);
			while ((s->z_r * s->z_r + s->z_i * s->z_i < 4) && (s->i < s->i_max))
			{
				s->tmp = s->z_r;
				s->z_r = s->z_r * s->z_r - s->z_i * s->z_i + s->cr;
				s->z_i = -2 * fabs(s->z_i * s->tmp) + s->ci;
				s->i++;
			}
			(s->i != s->i_max) ? colors(s, s->z_r, s->z_i) : s->i == s->i_max;
			s->y++;
		}
		s->x++;
	}
}

void		buffalo(t_s *s)
{
	s->x = s->start;
	while (s->x < s->end)
	{
		s->y = 0;
		while (s->y < WIN_Y)
		{
			mandelbrot_datas(s);
			while ((s->z_r * s->z_r + s->z_i * s->z_i < 4) && (s->i < s->i_max))
			{
				s->tmp = s->z_r;
				s->z_r = fabs(s->z_r * s->z_r - s->z_i * s->z_i) + s->cr;
				s->z_i = -2 * fabs(s->z_i * s->tmp) + s->ci;
				s->i++;
			}
			(s->i != s->i_max) ? colors(s, s->z_r, s->z_i) : s->i == s->i_max;
			s->y++;
		}
		s->x++;
	}
}

void		heart(t_s *s)
{
	s->x = s->start;
	while (s->x < s->end)
	{
		s->y = 0;
		while (s->y < WIN_Y)
		{
			mandelbrot_datas(s);
			while ((s->z_r * s->z_r + s->z_i * s->z_i < 4) && (s->i < s->i_max))
			{
				s->tmp = s->z_r;
				s->z_r = s->z_r * s->z_r - s->z_i * s->z_i + s->cr;
				s->z_i = 2 * s->z_i * fabs(s->tmp) + s->ci;
				s->i++;
			}
			(s->i != s->i_max) ? colors(s, s->z_r, s->z_i) : s->i == s->i_max;
			s->y++;
		}
		s->x++;
	}
}

void		great_axe(t_s *s)
{
	s->x = s->start;
	while (s->x < s->end)
	{
		s->y = 0;
		while (s->y < WIN_Y)
		{
			mandelbrot_datas(s);
			while ((s->z_r * s->z_r + s->z_i * s->z_i < 4) && (s->i < s->i_max))
			{
				s->tmp = s->z_r;
				s->z_r = (s->z_r * s->z_r -
					(s->z_i * s->z_i * 3)) * fabs(s->z_r) + s->cr;
				s->z_i = ((3 * s->tmp * s->tmp) -
					s->z_i * s->z_i) * fabs(s->z_i) + s->ci;
				s->i++;
			}
			(s->i != s->i_max) ? colors(s, s->z_r, s->z_i) : s->i == s->i_max;
			s->y++;
		}
		s->x++;
	}
}

void		julia(t_s *s)
{
	s->x = s->start;
	while (s->x < s->end)
	{
		s->y = 0;
		while (s->y < WIN_Y)
		{
			s->zr = s->x1 + (s->x2 - s->x1) / (double)s->zoom * (double)s->x;
			s->zi = s->y1 + (s->y2 - s->y1) / (double)s->zoom * (double)s->y;
			s->i = 0;
			while ((s->zr * s->zr + s->zi * s->zi < 4) && (s->i < s->i_max))
			{
				s->tmp = s->zr;
				s->zr = s->zr * s->zr - s->zi * s->zi + s->cr;
				s->zi = 2 * s->zi * s->tmp + s->ci;
				s->i++;
			}
			(s->i != s->i_max) ? colors(s, s->zr, s->zi) : s->i == s->i_max;
			s->y++;
		}
		s->x++;
	}
}
