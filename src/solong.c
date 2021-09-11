/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:41:21 by lprates           #+#    #+#             */
/*   Updated: 2021/09/11 23:47:58 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "solong.h"

static void	change_sprite(char *file1, char *file2, t_alldata *all)
{
	int			xpm_height;
	int			xpm_width;
	static int	count = 0;

	if (count == 0)
	{
		all->sprites.main_char = mlx_xpm_file_to_image(all->mlxwin.mlx, file1, &xpm_height, &xpm_width);
		count = 1;
	}
	else if (count == 1)
	{
		all->sprites.main_char = mlx_xpm_file_to_image(all->mlxwin.mlx, file2, &xpm_height, &xpm_width);
		count = 0;
	}
	return ;
}

int             key_hook(int keycode, t_alldata *all)
{
    printf("Hello, this is key: %i\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(all->mlxwin.mlx, all->mlxwin.win);
		exit(1);
	}
	if (keycode == 13)
	{
		all->char_start_y -= 32;
		change_sprite(CHAR_UP1, CHAR_UP2, all);
	}
	if (keycode == 1)
	{
		all->char_start_y += 32;
		change_sprite(CHAR_DOWN1, CHAR_DOWN2, all);
	}
	if (keycode == 0)
	{
		all->char_start_x -= 32;
		change_sprite(CHAR_LEFT1, CHAR_LEFT2, all);
	}
	if (keycode == 2)
	{
		all->char_start_x += 32;
		change_sprite(CHAR_RIGHT1, CHAR_RIGHT2, all);
	}
	return (0);
}

int	render_next_frame(t_alldata *all)
{
	int i;
	int j;
	int xpm_height;
	int xpm_width;

	i = 0;
	mlx_destroy_image(all->mlxwin.mlx, all->img.img);
	all->img.img = mlx_new_image(all->mlxwin.mlx, all->h_size, all->v_size);
	mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, all->img.img, 0, 0);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length,
                                 &all->img.endian);
	all->sprites.background = mlx_xpm_file_to_image(all->mlxwin.mlx, BACKGROUND, &xpm_height, &xpm_width);
	all->sprites.wall = mlx_xpm_file_to_image(all->mlxwin.mlx, WALL, &xpm_height, &xpm_width);
	while (i < all->v_size)
	{
		j = 0;
		while (j < all->h_size)
		{
			mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, all->sprites.background, j, i);
			mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, all->sprites.main_char, all->char_start_x, all->char_start_y);
			if (i == 0 || j == 0 || j == all->h_size - xpm_width || i == all->v_size - xpm_height)
				mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, all->sprites.wall, j, i);
			j += (xpm_width);
		}
		i += (xpm_height);
	}
	//mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, background, 0, 0);
	return (0);
}

int	ft_close(t_alldata *all)
{
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_alldata *all;
	int xpm_height;
	int xpm_width;

	all = malloc(sizeof(t_alldata));
	ft_handle_args(all, argc, argv[1]);
	for(int i = 0; i < all->v_size; i++)
		for (int j = 0; j < all->h_size; j++)
			if (all->map[i][j] == 'P')
			{
				all->char_start_x = 32 * j;
				all->char_start_y = 32 * i;
			}
	ft_init(all);
	all->sprites.main_char = mlx_xpm_file_to_image(all->mlxwin.mlx, CHAR_START, &xpm_height, &xpm_width);
	// have to check how to implement auto repeat
	//mlx_do_key_autorepeaton(all->mlxwin.mlx);
	// loop that keeps rendering the next frame
	mlx_loop_hook(all->mlxwin.mlx, render_next_frame, all);
	// loop that listens to key press events
	mlx_key_hook(all->mlxwin.win, key_hook, all);
	mlx_hook(all->mlxwin.win, 17, 0L, ft_close, all);
	//mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, all->img.img, 0, 0);
	mlx_loop(all->mlxwin.mlx);
	return (0);
}
