/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:38:07 by lprates           #+#    #+#             */
/*   Updated: 2021/09/25 20:27:07 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_filename_ext(const char *filename, const char *ext)
{
	const char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename)
		return (0);
	if (!ft_strcmp((char *)dot, (char *)ext))
		return (1);
	return (0);
}

void	check_map(t_alldata *all)
{
	if (all->h_size == (all->v_size + 1))
		error_handler(all, 5);
}

int	parse_map(t_alldata *all, int fd)
{
	int		finish;
	size_t	nsi;
	size_t	tmp;

	all->v_size = 0;
	all->map = malloc(sizeof(char *) * 1);
	if (!all->map)
		error_handler(all, 6);
	finish = get_next_line(fd, &all->map[all->v_size]);
	while (finish == 1)
	{
		all->h_size = ft_strlen(all->map[all->v_size]);
		all->v_size++;
		tmp = sizeof(char *) * (all->v_size);
		nsi = sizeof(char *) * (all->v_size + 1);
		if (finish == -1)
			error_handler(all, 4);
		all->map = ft_realloc((void *)all->map, tmp, nsi);
		if (!all->map)
			error_handler(all, 6);
		finish = get_next_line(fd, &all->map[all->v_size]);
	}
	//nsi = sizeof(char *) * (all->v_size + 2);
	//all->map = ft_realloc((void **)&all->map, nsi);
	//all->map[all->v_size + 1] = 0; 
	all->v_size++;
	close(fd);
	check_map(all);
	return (1);
}
