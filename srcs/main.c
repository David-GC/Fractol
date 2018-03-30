/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			main(int argc, char **argv)
{
	t_s		*s;

	if (!(s = (t_s*)ft_memalloc(sizeof(t_s))))
		return (0);
	if (argc == 2)
	{
		if (fractal_src(s, argv[1]) == -1)
			return (-1);
		window_datas(s);
		display_window(s);
	}
	else
	{
		write(2, "usage: ./fractol mandelbrot\n", 28);
		write(2, "                \"celtic mandelbar\"\n", 35);
		write(2, "                \"cubic mandelbar\"\n", 34);
		write(2, "                \"burning ship\"\n", 31);
		write(2, "                \"great axe\"\n", 28);
		write(2, "                 buffalo\n", 25);
		write(2, "                 heart\n", 23);
		write(2, "                 julia\n", 23);
		return (-1);
	}
	free(s);
	return (0);
}
