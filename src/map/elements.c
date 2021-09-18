/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:35:36 by lprates           #+#    #+#             */
/*   Updated: 2021/09/18 15:21:03 by lprates          ###   ########.fr       */
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
		mlx_string_put(MLX_PTR, WIN_PTR, 50, 15, 0, END_MESSAGE);
		if (all->end == 2)
		{
			free_elements(all);
			exit(1);
		}
	}
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
			if (all->element[count].type == 'C')
				PUT_IMG_TO_WIN(MLX_PTR, WIN_PTR, all->sprites.collect, x, y);
			if (all->element[count].type == '1')
				PUT_IMG_TO_WIN(MLX_PTR, WIN_PTR, all->sprites.wall, x, y);
			if (all->element[count].type == 'E')
				PUT_IMG_TO_WIN(MLX_PTR, WIN_PTR, all->sprites.end_portal, x, y);
			break ;
		}
		count++;
	}
}
