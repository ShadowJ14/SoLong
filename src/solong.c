/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:41:21 by lprates           #+#    #+#             */
/*   Updated: 2021/09/25 18:02:07 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "solong.h"

static int	cross_click(t_alldata *all)
{
	ft_close(all, 0);
	return (0);
}

int	ft_close(t_alldata *all, int code)
{
	if (all->mlx)
		mlx_destroy_window(all->mlx, all->win);
	if (all->element)
		free_elements(all);
	if (all->map)
		free(all->map);
	free(all);
	exit(code);
}

int	key_hook(int keycode, t_alldata *all)
{
	static int	mov = 0;

	if (keycode == 53 || keycode == 65307)
		ft_close(all, 0);
	if (char_colision(all, keycode) && !all->end)
	{
		if (keycode == W || keycode == 119)
			vert_char_sprite(CHAR_UP1, CHAR_UP2, -32, all);
		else if (keycode == S || keycode == 115)
			vert_char_sprite(CHAR_DOWN1, CHAR_DOWN2, 32, all);
		else if (keycode == A || keycode == 97)
			hor_char_sprite(CHAR_LEFT1, CHAR_LEFT2, -32, all);
		else if (keycode == D || keycode == 100)
			hor_char_sprite(CHAR_RIGHT1, CHAR_RIGHT2, 32, all);
		else
			return (0);
		printf("Number of movements: %i\n", ++mov);
		all->mov = ft_itoa(mov);
	}
	if (all->collectibles == 0 && all->end == 1 && keycode == 49)
		all->end = 2;
	return (1);
}

int	render_next_frame(t_alldata *all)
{
	int	i;
	int	j;

	i = 0;
	mlx_destroy_image(all->mlx, all->img.img);
	ft_repeat_init(all);
	while (i < all->v_size)
	{
		j = 0;
		while (j < all->h_size)
		{
			mlx_put_image_to_window(all->mlx, all->win, all->sprt.ground, j, i);
			put_elements(all, j, i);
			j += 32;
		}
		i += 32;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->sprt.guy,
		all->guy_x, all->guy_y);
	mlx_string_put(all->mlx, all->win, 5, 15, 0, all->mov);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_alldata	*all;

	all = malloc(sizeof(t_alldata));
	if (!all)
	{
		printf("Error\nCouldn't allocate memory.");
		exit(-1);
	}
	all->collectibles = 0;
	all->guy_x = 0;
	all->end_sprite = 0;
	all->mlx = NULL;
	all->element = NULL;
	all->map = NULL;
	ft_handle_args(all, argc, argv[1]);
	ft_init(all);
	mlx_key_hook(all->win, key_hook, all);
	mlx_hook(all->win, 17, 0L, cross_click, all);
	mlx_loop_hook(all->mlx, render_next_frame, all);
	mlx_loop(all->mlx);
	return (0);
}
