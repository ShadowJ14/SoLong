/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:35:36 by lprates           #+#    #+#             */
/*   Updated: 2021/09/12 21:45:03 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	put_elements(t_alldata *all, int x, int y)
{
	int count;

	count = 0;
	while(all->element[count].type != 0)
	{
		if (all->element[count].posx == y && all->element[count].posy == x)
		{
			if (all->element[count].type == 'C')
				mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, all->sprites.collect, x, y);
			if (all->element[count].type == '1')
				mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, all->sprites.wall, x, y);
			if (all->element[count].type == 'E')
				mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, all->sprites.end_portal, x, y);
			break;
		}
		count++;
	}
}