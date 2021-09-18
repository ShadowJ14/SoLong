/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:41:21 by lprates           #+#    #+#             */
/*   Updated: 2021/09/18 05:00:52 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "solong.h"

int             key_hook(int keycode, t_alldata *all)
{
	static int mov = 0;

    printf("Hello, this is key: %i\n", keycode);
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(all->mlxwin.mlx, all->mlxwin.win);
		exit(1);
	}
	if (char_colision(all, keycode))
	{
		if (keycode == 13 || keycode == 119)
			vertical_char_sprite(CHAR_UP1, CHAR_UP2, -32, all);
		if (keycode == 1 || keycode == 115)
			vertical_char_sprite(CHAR_DOWN1, CHAR_DOWN2, 32, all);
		if (keycode == 0 || keycode == 97)
			horizontal_char_sprite(CHAR_LEFT1, CHAR_LEFT2, -32, all);
		if (keycode == 2 || keycode == 100)
			horizontal_char_sprite(CHAR_RIGHT1, CHAR_RIGHT2, 32, all);
		printf("Number of movements: %i\n", ++mov);
		all->mov = ft_itoa(mov);
	}
	return (0);
}

int	render_next_frame(t_alldata *all)
{
	int i;
	int j;

	i = 0;
	mlx_destroy_image(all->mlxwin.mlx, all->img.img);
	ft_repeat_init(all);
	while (i < all->v_size)
	{
		j = 0;
		while (j < all->h_size)
		{
			mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, all->sprites.background, j, i);
			//write(1, "Aqui\n", 5);
			put_elements(all, j, i);
			/*if (i == 0 || j == 0 || j == all->h_size - 32 || i == all->v_size - 32)
				mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, all->sprites.wall, j, i);*/
			j += 32;
		}
		i += 32;
	}
	mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, all->sprites.main_char, all->char_start_x, all->char_start_y);
	mlx_string_put(all->mlxwin.mlx, all->mlxwin.win, 5, 15, 0, all->mov);
	return (0);
}

int	ft_close(t_alldata *all)
{
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_alldata *all;

	all = malloc(sizeof(t_alldata));
	all->collectibles = 0;
	ft_handle_args(all, argc, argv[1]);
	for(int i = 0; i < all->v_size; i++)
		for (int j = 0; j < all->h_size; j++)
			if (all->map[i][j] == 'P')
			{
				all->char_start_x = 32 * j;
				all->char_start_y = 32 * i;
			}
	ft_init(all);
	//all->sprites.main_char = mlx_xpm_file_to_image(all->mlxwin.mlx, CHAR_START, &xpm_height, &xpm_width);
	// have to check how to implement auto repeat
	//mlx_do_key_autorepeaton(all->mlxwin.mlx);
	// loop that keeps rendering the next frame
	mlx_loop_hook(all->mlxwin.mlx, render_next_frame, all);
	// loop that listens to key press events
	mlx_key_hook(all->mlxwin.win, key_hook, all);
	mlx_hook(all->mlxwin.win, 17, 0L, ft_close, all);
	mlx_loop(all->mlxwin.mlx);
	return (0);
}
