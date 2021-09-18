/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:41:21 by lprates           #+#    #+#             */
/*   Updated: 2021/09/18 15:18:57 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "solong.h"

int	key_hook(int keycode, t_alldata *all)
{
	static int	mov = 0;

	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(MLX_PTR, WIN_PTR);
		exit(1);
	}
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
	mlx_destroy_image(MLX_PTR, all->img.img);
	ft_repeat_init(all);
	while (i < all->v_size)
	{
		j = 0;
		while (j < all->h_size)
		{
			PUT_IMG_TO_WIN(MLX_PTR, WIN_PTR, all->sprites.ground, j, i);
			put_elements(all, j, i);
			j += 32;
		}
		i += 32;
	}
	PUT_IMG_TO_WIN(MLX_PTR, WIN_PTR, all->sprites.guy, all->guy_x, all->guy_y);
	mlx_string_put(MLX_PTR, WIN_PTR, 5, 15, 0, all->mov);
	return (0);
}

int	ft_close(t_alldata *all)
{
	free_elements(all);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_alldata	*all;

	all = malloc(sizeof(t_alldata));
	all->collectibles = 0;
	ft_handle_args(all, argc, argv[1]);
	ft_init(all);
	mlx_key_hook(WIN_PTR, key_hook, all);
	mlx_hook(WIN_PTR, 17, 0L, ft_close, all);
	mlx_loop_hook(MLX_PTR, render_next_frame, all);
	mlx_loop(MLX_PTR);
	return (0);
}
