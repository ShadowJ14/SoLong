/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manip_argb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:53:46 by lprates           #+#    #+#             */
/*   Updated: 2021/09/05 20:51:35 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

// seems to work
int	add_shade(double distance, int color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_t(color);
	r = get_r(color);
	r -= ((int)((r >> 16) * distance) << 16);
	g = get_g(color);
	g -= ((int)((g >> 8) * distance) << 8);
	b = get_b(color);
	b -= (b * distance);
	return (t | r | g | b);
}

// seems to work
int	get_oposite(int color)
{
	int	opos_color;

	opos_color = 0xFFFFFF - color;
	return (opos_color);
}
