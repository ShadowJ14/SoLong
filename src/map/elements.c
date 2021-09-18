/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:35:36 by lprates           #+#    #+#             */
/*   Updated: 2021/09/18 05:13:59 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	vert_collision(t_alldata *all, int count, int keycode)
{
	if ((all->char_start_y + 32) == all->element[count].posy && keycode == 1)
		return (0);
	if ((all->char_start_y - 32) == all->element[count].posy && keycode == 13)
		return (0);
	return (1);
}

int	hori_collision(t_alldata *all, int count, int keycode)
{
	if ((all->char_start_x + 32) == all->element[count].posx && keycode == 2)
		return (0);
	if ((all->char_start_x - 32) == all->element[count].posx && keycode == 0)
		return (0);
	return (1);
}

int	char_colision(t_alldata *all, int keycode)
{
	int count;

	count = -1;
	while(all->element[++count].type != 0)
	{
		if (all->element[count].type == '1')
		{
			if (all->char_start_x == all->element[count].posx)
				if (!vert_collision(all, count, keycode))
					return (0);
			if (all->char_start_y == all->element[count].posy)
				if (!hori_collision(all, count, keycode))
					return (0);
		}
	}
	return (1);
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
		ft_putstr(END_MESSAGE);
		mlx_string_put(all->mlxwin.mlx, all->mlxwin.win, 5, 35, 0, END_MESSAGE);
		// need to remove!!
		//sleep(5);
		//exit(1);
	}
}

void	put_elements(t_alldata *all, int x, int y)
{
	int count;

	count = 0;
	while(all->element[count].type != 0)
	{
		if (all->element[count].posy == y && all->element[count].posx == x)
		{
			if (all->char_start_x == x && all->char_start_y == y)
			{
				if (all->element[count].type == 'C')
					collect(all, count);
				if (all->element[count].type == 'E')
					end_game(all);
			}
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