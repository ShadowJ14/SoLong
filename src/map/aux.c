/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:38:07 by lprates           #+#    #+#             */
/*   Updated: 2021/09/11 22:39:22 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int check_filename_ext(const char *filename, const char *ext)
{
    const char *dot;
	
	dot = ft_strrchr(filename, '.');
    if (!dot || dot == filename)
		return (0);
	if (!ft_strcmp((char *)dot, (char *)ext))
		return (1);
    return (0);
}

int		parse_map(t_alldata *all, int fd)
{
	int finish;
	size_t nsi;

	all->v_size = 0;
	all->map = malloc(sizeof(char **) * 1);
	finish = get_next_line(fd, &all->map[all->v_size]);
	while (finish == 1)
	{
		all->h_size = ft_strlen(all->map[all->v_size]);
		printf("line %i string: %s\n", all->v_size, all->map[all->v_size]);
		all->v_size++;
		nsi = sizeof(char **) * (all->v_size + 1);
		//finish = get_next_line(fd, map);
		if (finish == -1)
			error_handler(4);
		all->map = ft_realloc((void **)&all->map, nsi);
		printf("Aqui!");
		finish = get_next_line(fd, &all->map[all->v_size]);
	}
	return (1);
}