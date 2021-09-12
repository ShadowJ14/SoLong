/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:35:36 by lprates           #+#    #+#             */
/*   Updated: 2021/09/12 20:49:33 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	put_elements(t_alldata *all, int x, int y)
{
	int count;

	write(1, "Aqui\n", 5);
	while(&all->element[count])
	{
		if (all->element[count].posx == x && all->element[count].posy == y)
		{
			if (all->element[count].type == 'C')
				mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, COLLECT, x, y);
			if (all->element[count].type == '1')
				mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, WALL, x, y);
			if (all->element[count].type == 'E')
				mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, END_SPRITE, x, y);
			break;
		}
		count++;
	}
}