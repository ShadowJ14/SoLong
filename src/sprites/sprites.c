/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 04:12:24 by lprates           #+#    #+#             */
/*   Updated: 2021/09/25 15:31:02 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	change_sprite(char *file1, char *file2, t_alldata *all)
{
	int			xpm_h;
	int			xpm_w;
	static int	count = 0;

	if (count % 2 == 0)
		all->sprt.guy = mlx_xpm_file_to_image(all->mlx, file1, &xpm_h, &xpm_w);
	if (count % 2 != 0)
		all->sprt.guy = mlx_xpm_file_to_image(all->mlx, file2, &xpm_h, &xpm_w);
	count++;
}

void	hor_char_sprite(char *file1, char *file2, int mov, t_alldata *all)
{
	all->guy_x += mov;
	change_sprite(file1, file2, all);
}

void	vert_char_sprite(char *file1, char *file2, int mov, t_alldata *all)
{
	all->guy_y += mov;
	change_sprite(file1, file2, all);
}
