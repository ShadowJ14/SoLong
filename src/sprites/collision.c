/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 12:18:34 by lprates           #+#    #+#             */
/*   Updated: 2021/09/25 16:31:16 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	vert_collision(t_alldata *all, int count, int keycode)
{
	if ((all->guy_y + 32) == all->element[count].posy && keycode == 1)
		return (0);
	if ((all->guy_y - 32) == all->element[count].posy && keycode == 13)
		return (0);
	return (1);
}

int	hori_collision(t_alldata *all, int count, int keycode)
{
	if ((all->guy_x + 32) == all->element[count].posx && keycode == 2)
		return (0);
	if ((all->guy_x - 32) == all->element[count].posx && keycode == 0)
		return (0);
	return (1);
}

int	char_colision(t_alldata *all, int keycode)
{
	int	count;

	count = -1;
	while (all->element[++count].type != 0)
	{
		if (all->element[count].type == '1'
			|| (all->element[count].type == 'E' && all->collectibles))
		{
			if (all->guy_x == all->element[count].posx)
				if (!vert_collision(all, count, keycode))
					return (0);
			if (all->guy_y == all->element[count].posy)
				if (!hori_collision(all, count, keycode))
					return (0);
		}
	}
	return (1);
}
