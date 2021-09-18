/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 23:19:37 by lprates           #+#    #+#             */
/*   Updated: 2021/09/18 05:01:24 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_grab_elements(t_alldata *all)
{
	int x;
	int y;
	int count;

	all->element = malloc(sizeof(t_element *) * 1);
	y = -1;
	count = 0;
	while(++y <= all->v_size)
	{
		x = -1;
		while(++x < all->h_size)
		{
			if (ft_strchr(ELEMENTS, all->map[y][x]))
			{
	//write(1, "Aqui\n", 5);
				all->element[count].posy = y * 32;
				all->element[count].posx = x * 32;
				all->element[count].type = all->map[y][x];
				if (all->element[count].type == 'C')
					all->collectibles++;
				count++;
				all->element = ft_realloc((void **)&all->element, sizeof(t_element) * (count + 1));
			}
		}
	}
	all->element[count].type = 0;
}

void	ft_handle_args(t_alldata *all, int argc, char *argv)
{
	int fd;

	if (argc != 2)
		error_handler(1);	
	if (!check_filename_ext(argv, ".ber"))
		error_handler(2);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_handler(3);
	parse_map(all, fd);
	ft_grab_elements(all);
	printf("Collectibles left: %i\n", all->collectibles);
}

void	ft_repeat_init(t_alldata *all)
{
	int placeholder_h;
	int placeholder_w;

    all->img.img = mlx_new_image(all->mlxwin.mlx, all->h_size, all->v_size);
    all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length,
                                 &all->img.endian);
	all->sprites.wall = mlx_xpm_file_to_image(all->mlxwin.mlx, WALL, &placeholder_h, &placeholder_w);
	all->sprites.collect = mlx_xpm_file_to_image(all->mlxwin.mlx, COLLECT, &placeholder_h, &placeholder_w);
	all->sprites.background = mlx_xpm_file_to_image(all->mlxwin.mlx, BACKGROUND, &placeholder_h, &placeholder_w);
	all->sprites.end_portal = mlx_xpm_file_to_image(all->mlxwin.mlx, END_SPRITE, &placeholder_h, &placeholder_w);
}

void	ft_init(t_alldata *all)
{
	int placeholder_h;
	int placeholder_w;

	all->h_size = (all->h_size) * 32;
	all->v_size = (all->v_size + 1) * 32;
	all->mov = ft_itoa(0);
	all->mlxwin.mlx = mlx_init();
	all->mlxwin.win = mlx_new_window(all->mlxwin.mlx, all->h_size, all->v_size, "Hello world!");
	all->sprites.main_char = mlx_xpm_file_to_image(all->mlxwin.mlx, CHAR_START, &placeholder_h, &placeholder_w);
    ft_repeat_init(all);
}