/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interactions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		refresh_image(t_s *s, int keycode)
{
	ft_bzero(s->data, WIN_X * WIN_Y * 4);
	multithreading(s, thread_link);
	if (keycode == 262)
		s->commands = (s->commands == 0) ? 1 : 0;
	if (s->commands == 1)
	{
		s->x = 0;
		while (s->x < 490)
		{
			s->y = 0;
			while (s->y < 265)
			{
				s->color_frame = (s->x == 0 || s->x == 489 ||
					s->y == 0 || s->y == 264) ? 200 : 40;
				s->data[(s->x + s->y * WIN_X) * 4 + 2] = s->color_frame;
				s->data[(s->x + s->y * WIN_X) * 4 + 1] = s->color_frame;
				s->data[(s->x + s->y * WIN_X) * 4] = s->color_frame;
				s->y++;
			}
			s->x++;
		}
	}
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
	if (s->commands == 1)
		display_commands(s);
}

int			mouse_zoom(int clic, int x, int y, t_s *s)
{
	if (x >= 0 && y >= 0 && x < WIN_X && y < WIN_Y)
	{
		s->diff_x = (s->x2 - s->x1) * 0.2;
		s->diff_y = (s->y2 - s->y1) * 0.2;
		if (clic == 4)
		{
			s->i_zoom += 0.9;
			s->x1 = (s->x1 + s->diff_x * ((double)x / WIN_X));
			s->x2 = (s->x2 - s->diff_x * (1 - ((double)x / WIN_X)));
			s->y1 = (s->y1 + s->diff_y * ((double)y / WIN_Y));
			s->y2 = (s->y2 - s->diff_y * (1 - ((double)y / WIN_Y)));
		}
		else if (clic == 5)
		{
			s->i_zoom = (s->i_zoom <= 1.8) ? 1 : s->i_zoom - 0.9;
			s->x1 = (s->x1 - s->diff_x * ((double)x / WIN_X));
			s->x2 = (s->x2 + s->diff_x * (1 - ((double)x / WIN_X)));
			s->y1 = (s->y1 - s->diff_y * ((double)y / WIN_Y));
			s->y2 = (s->y2 + s->diff_y * (1 - ((double)y / WIN_Y)));
		}
		refresh_image(s, 0);
	}
	return (0);
}

int			mouse_motion(int x, int y, t_s *s)
{
	if (x >= 0 && y >= 0 && x < WIN_X && y < WIN_Y && s->motion == 1)
	{
		if (s->src >= 2 && s->src <= 8)
		{
			s->zr = (double)x / (double)WIN_X * 4 - 2;
			s->zi = (double)y / (double)WIN_Y * 4 - 2;
		}
		if (s->src == 1)
		{
			s->cr = (double)x / (double)WIN_X * 4 - 2;
			s->ci = (double)y / (double)WIN_Y * 4 - 2;
		}
	}
	refresh_image(s, 0);
	return (0);
}

void		key_move(int keycode, t_s *s)
{
	if (keycode == 2)
	{
		s->x1 -= 0.01 / s->i_zoom;
		s->x2 -= 0.01 / s->i_zoom;
	}
	if (keycode == 0)
	{
		s->x1 += 0.01 / s->i_zoom;
		s->x2 += 0.01 / s->i_zoom;
	}
	if (keycode == 13)
	{
		s->y1 -= 0.01 / s->i_zoom;
		s->y2 -= 0.01 / s->i_zoom;
	}
	if (keycode == 1)
	{
		s->y1 += 0.01 / s->i_zoom;
		s->y2 += 0.01 / s->i_zoom;
	}
}

int			key_functions(int keycode, t_s *s)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 46)
		s->motion = (s->motion == 1) ? 0 : 1;
	else if (keycode == 126)
		s->i_max += 10;
	else if (keycode == 125)
		s->i_max -= 10;
	else if (keycode == 8)
		s->color_choice = (s->color_choice == 3) ? 0 + 1 : s->color_choice + 1;
	else if (keycode == 49)
		window_datas(s);
	else if (keycode == 123 || keycode == 124)
	{
		if (keycode == 123)
			s->src = (s->src == 1) ? 8 : s->src - 1;
		else if (keycode == 124)
			s->src = (s->src == 8) ? 1 : s->src + 1;
		window_datas(s);
	}
	else if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		key_move(keycode, s);
	refresh_image(s, keycode);
	return (0);
}
