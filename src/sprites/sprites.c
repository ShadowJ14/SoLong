/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 04:12:24 by lprates           #+#    #+#             */
/*   Updated: 2021/09/18 04:12:33 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	change_sprite(char *file1, char *file2, t_alldata *all)
{
	int			xpm_height;
	int			xpm_width;
	static int	count = 0;

	if (count % 2 == 0)
		all->sprites.main_char = mlx_xpm_file_to_image(all->mlxwin.mlx, file1, &xpm_height, &xpm_width);
	if (count % 2 != 0)
		all->sprites.main_char = mlx_xpm_file_to_image(all->mlxwin.mlx, file2, &xpm_height, &xpm_width);
	count++;
}

void	horizontal_char_sprite(char *file1, char *file2, int mov, t_alldata *all)
{
	all->char_start_x += mov;
	change_sprite(file1, file2, all);
}

void	vertical_char_sprite(char *file1, char *file2, int mov, t_alldata *all)
{
	all->char_start_y += mov;	
	change_sprite(file1, file2, all);
}