/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_windows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		display_commands(t_s *s)
{
	mlx_string_put(s->mlx_ptr, s->win_ptr,
		50, 30, 0x3D99D6, "               commmands");
	mlx_string_put(s->mlx_ptr, s->win_ptr,
		50, 60, 0x57D9F0, "translation:            a | s | w | d");
	mlx_string_put(s->mlx_ptr, s->win_ptr,
		50, 80, 0x57D9F0, "zoom:             scroll down | scroll up");
	mlx_string_put(s->mlx_ptr, s->win_ptr,
		50, 100, 0x57D9F0, "iteration:               down | up");
	mlx_string_put(s->mlx_ptr, s->win_ptr,
		50, 120, 0x57D9F0, "change fractale:           <- | ->");
	mlx_string_put(s->mlx_ptr, s->win_ptr,
		50, 140, 0x57D9F0, "change color:                 c");
	mlx_string_put(s->mlx_ptr, s->win_ptr,
		50, 160, 0x57D9F0, "motion:                       m");
	mlx_string_put(s->mlx_ptr, s->win_ptr,
		50, 180, 0x57D9F0, "refresh:                    space");
	mlx_string_put(s->mlx_ptr, s->win_ptr,
		50, 210, 0x66FFFF, "exit:                        esc");
}

void		display_window(t_s *s)
{
	s->mlx_ptr = mlx_init();
	s->win_ptr = mlx_new_window(s->mlx_ptr, WIN_X, WIN_Y, "mlx_window");
	s->img_ptr = mlx_new_image(s->mlx_ptr, WIN_X, WIN_Y);
	s->data = (unsigned char*)mlx_get_data_addr(s->img_ptr,
		&s->bpp, &s->l_size, &s->endian);
	multithreading(s, thread_link);
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
	mlx_hook(s->win_ptr, BUTTON_PRESS, BUTTON_PRESS_MASK, mouse_zoom, s);
	mlx_hook(s->win_ptr, MOTION_NOTIFY, POINTER_MOTION_MASK, mouse_motion, s);
	mlx_hook(s->win_ptr, 2, (1L << 0), key_functions, s);
	mlx_loop(s->mlx_ptr);
}
