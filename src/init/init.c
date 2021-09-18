/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 23:19:37 by lprates           #+#    #+#             */
/*   Updated: 2021/09/18 15:23:57 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	define_char(t_alldata *all, int count)
{
	all->guy_x = all->element[count].posx;
	all->guy_y = all->element[count].posy;
}

void	ft_grab_elements(t_alldata *all)
{
	int	x;
	int	y;
	int	count;

	all->element = malloc(sizeof(t_element *) * 1);
	y = -1;
	count = 0;
	while (++y <= all->v_size)
	{
		x = -1;
		while (++x < all->h_size)
		{
			if (ft_strchr(ELEMENTS, all->map[y][x]))
			{
				all->element[count].posy = y * 32;
				all->element[count].posx = x * 32;
				all->element[count].type = all->map[y][x];
				if (all->element[count].type == 'C')
					all->collectibles++;
				if (all->element[count].type == 'P')
					define_char(all, count);
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

    all->img.img = mlx_new_image(MLX_PTR, all->h_size, all->v_size);
    all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length,
                                 &all->img.endian);
}

void	ft_init(t_alldata *all)
{
	int placeholder_h;
	int placeholder_w;

	all->h_size = (all->h_size) * 32;
	all->v_size = (all->v_size + 1) * 32;
	all->mov = ft_itoa(0);
	all->end = 0;
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, all->h_size, all->v_size, "Hello world!");
	all->sprites.guy = XPM_TO_IMG(MLX_PTR, CHAR_START, &placeholder_h, &placeholder_w);
    ft_repeat_init(all);
	all->sprites.wall = XPM_TO_IMG(MLX_PTR, WALL, &placeholder_h, &placeholder_w);
	all->sprites.collect = XPM_TO_IMG(MLX_PTR, COLLECT, &placeholder_h, &placeholder_w);
	all->sprites.ground = XPM_TO_IMG(MLX_PTR, BACKGROUND, &placeholder_h, &placeholder_w);
	all->sprites.end_portal = XPM_TO_IMG(MLX_PTR, END_SPRITE, &placeholder_h, &placeholder_w);
}