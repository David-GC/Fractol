/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		green(t_s *s, int nb_color)
{
	if (nb_color < 256)
	{
		s->data[(s->x + s->y * WIN_X) * 4 + 2] = 0;
		s->data[(s->x + s->y * WIN_X) * 4 + 1] = nb_color;
		s->data[(s->x + s->y * WIN_X) * 4] = 0;
	}
	else if (nb_color >= 256 && nb_color < 512)
	{
		s->data[(s->x + s->y * WIN_X) * 4 + 2] = 256 - nb_color;
		s->data[(s->x + s->y * WIN_X) * 4 + 1] = 255;
		s->data[(s->x + s->y * WIN_X) * 4] = 0;
	}
	else
	{
		s->data[(s->x + s->y * WIN_X) * 4 + 2] = 255;
		s->data[(s->x + s->y * WIN_X) * 4 + 1] = 255;
		s->data[(s->x + s->y * WIN_X) * 4] = 512 - nb_color;
	}
}

void		red(t_s *s, int nb_color)
{
	if (nb_color < 256)
	{
		s->data[(s->x + s->y * WIN_X) * 4 + 2] = nb_color;
		s->data[(s->x + s->y * WIN_X) * 4 + 1] = 0;
		s->data[(s->x + s->y * WIN_X) * 4] = 0;
	}
	else if (nb_color >= 256 && nb_color < 512)
	{
		s->data[(s->x + s->y * WIN_X) * 4 + 2] = 255;
		s->data[(s->x + s->y * WIN_X) * 4 + 1] = 256 - nb_color;
		s->data[(s->x + s->y * WIN_X) * 4] = 0;
	}
	else
	{
		s->data[(s->x + s->y * WIN_X) * 4 + 2] = 255;
		s->data[(s->x + s->y * WIN_X) * 4 + 1] = 255;
		s->data[(s->x + s->y * WIN_X) * 4] = 512 - nb_color;
	}
}

void		blue(t_s *s, int nb_color)
{
	if (nb_color < 256)
	{
		s->data[(s->x + s->y * WIN_X) * 4 + 2] = 0;
		s->data[(s->x + s->y * WIN_X) * 4 + 1] = 0;
		s->data[(s->x + s->y * WIN_X) * 4] = nb_color;
	}
	else if (nb_color >= 256 && nb_color < 512)
	{
		s->data[(s->x + s->y * WIN_X) * 4 + 2] = 0;
		s->data[(s->x + s->y * WIN_X) * 4 + 1] = 256 - nb_color;
		s->data[(s->x + s->y * WIN_X) * 4] = 255;
	}
	else
	{
		s->data[(s->x + s->y * WIN_X) * 4 + 2] = 512 - nb_color;
		s->data[(s->x + s->y * WIN_X) * 4 + 1] = 255;
		s->data[(s->x + s->y * WIN_X) * 4] = 255;
	}
}

void		colors(t_s *s, double zr, double zi)
{
	double		nb_color;

	s->i = s->i + 1 - log(log(sqrt(zr * zr + zi * zi))) / log(2);
	nb_color = (s->i * 768) / s->i_max;
	if (s->color_choice == 1)
		blue(s, nb_color);
	else if (s->color_choice == 2)
		red(s, nb_color);
	else if (s->color_choice == 3)
		green(s, nb_color);
}
