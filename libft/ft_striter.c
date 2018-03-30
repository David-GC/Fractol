/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 18:21:39 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/05/04 19:58:56 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	while (*s != '\0')
	{
		(*f)(s);
		s++;
	}
}