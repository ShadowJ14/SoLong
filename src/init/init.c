/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 23:19:37 by lprates           #+#    #+#             */
/*   Updated: 2021/09/25 17:39:40 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_handle_args(t_alldata *all, int argc, char *argv)
{
	int	fd;

	if (argc != 2)
		error_handler(all, 1);
	if (!check_filename_ext(argv, ".ber"))
		error_handler(all, 2);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_handler(all, 3);
	parse_map(all, fd);
	ft_grab_elements(all);
	printf("Collectibles left: %i\n", all->collectibles);
}

void	ft_repeat_init(t_alldata *all)
{
	all->img.img = mlx_new_image(all->mlx, all->h_size, all->v_size);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
			&all->img.line_length, &all->img.endian);
}

void	ft_init(t_alldata *all)
{
	int	placeholder_h;
	int	placeholder_w;

	all->h_size = (all->h_size) * 32;
	all->v_size = (all->v_size + 1) * 32;
	all->mov = ft_itoa(0);
	all->end = 0;
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, all->h_size,
			all->v_size, "The Guy Game!");
	all->sprt.guy = mlx_xpm_file_to_image(all->mlx, CHAR_START,
			&placeholder_h, &placeholder_w);
	ft_repeat_init(all);
	all->sprt.wall = mlx_xpm_file_to_image(all->mlx, WALL,
			&placeholder_h, &placeholder_w);
	all->sprt.clt = mlx_xpm_file_to_image(all->mlx, COLLECT,
			&placeholder_h, &placeholder_w);
	all->sprt.ground = mlx_xpm_file_to_image(all->mlx, BACKGROUND,
			&placeholder_h, &placeholder_w);
	all->sprt.end_portal = mlx_xpm_file_to_image(all->mlx,
			END_SPRITE, &placeholder_h, &placeholder_w);
}
