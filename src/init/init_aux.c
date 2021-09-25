/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:55:05 by lprates           #+#    #+#             */
/*   Updated: 2021/09/25 20:27:21 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	define_guy(t_alldata *all, int count)
{
	static int	unique_guy = 0;

	if (unique_guy != 0)
		error_handler(all, 5);
	all->guy_x = all->element[count].posx;
	all->guy_y = all->element[count].posy;
	unique_guy++;
}

void	ft_assign_element(t_alldata *all, int x, int y, int *count)
{
	all->element[*count].posy = y * 32;
	all->element[*count].posx = x * 32;
	all->element[*count].type = all->map[y][x];
	if (all->element[*count].type == 'C')
		all->collectibles++;
	if (all->element[*count].type == 'P')
		define_guy(all, *count);
	if (all->element[*count].type == 'E' && all->end_sprite == 0)
		all->end_sprite = 1;
	(*count)++;
	all->element = ft_realloc((void *)all->element, sizeof(t_element) * (*count),
			sizeof(t_element) * (*count + 1));
	if (!all->element)
		error_handler(all, 6);
}

static int	check_walls(t_alldata *all, int x, int y)
{
	return ((y == 0 || y == all->v_size || x == 0 || (x == all->h_size - 1))
		&& all->map[y][x] != '1');
}

void	ft_grab_elements(t_alldata *all)
{
	int	x;
	int	y;
	int	count;

	all->element = malloc(sizeof(t_element) * 1);
	if (!all->element)
		error_handler(all, 6);
	y = -1;
	count = 0;
	while (++y < all->v_size)
	{
		x = -1;
		while (++x < all->h_size)
		{
			if (check_walls(all, x, y))
				error_handler(all, 5);
			if (ft_strchr(ELEMENTS, all->map[y][x]))
				ft_assign_element(all, x, y, &count);
			else if (all->map[y][x] != '0')
				error_handler(all, 5);
		}
	}
	all->element[count].type = 0;
	all->element[count].posy = 0;
	all->element[count].posx = 0;
	if (all->guy_x == 0 || !all->collectibles || !all->end_sprite)
		error_handler(all, 5);
}
