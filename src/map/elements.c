/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:35:36 by lprates           #+#    #+#             */
/*   Updated: 2021/09/25 16:35:17 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_elements(t_alldata *all)
{
	free(all->element);
}

void	collect(t_alldata *all, int count)
{
	all->element[count].posx = -1;
	all->collectibles--;
	printf("Collectibles left: %i\n", all->collectibles);
}

void	end_game(t_alldata *all)
{
	if (!all->collectibles)
	{
		if (all->end == 0)
		{
			all->end = 1;
			ft_putstr(END_MESSAGE);
		}
		mlx_string_put(all->mlx, all->win, 50, 15, 0, END_MESSAGE);
		if (all->end == 2)
			ft_close(all, 0);
	}
}

void	put_to_window(t_alldata *all, int count, int x, int y)
{
	if (all->element[count].type == 'C')
		mlx_put_image_to_window(all->mlx, all->win, all->sprt.clt, x, y);
	if (all->element[count].type == '1')
		mlx_put_image_to_window(all->mlx, all->win, all->sprt.wall, x, y);
	if (all->element[count].type == 'E')
		mlx_put_image_to_window(all->mlx, all->win, all->sprt.end_portal, x, y);
}

void	put_elements(t_alldata *all, int x, int y)
{
	int	count;

	count = 0;
	while (all->element[count].type != 0)
	{
		if (all->element[count].posy == y && all->element[count].posx == x)
		{
			if (all->guy_x == x && all->guy_y == y)
			{
				if (all->element[count].type == 'C')
					collect(all, count);
				if (all->element[count].type == 'E')
					end_game(all);
			}
			put_to_window(all, count, x, y);
			break ;
		}
		count++;
	}
}
