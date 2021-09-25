/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:12:38 by lprates           #+#    #+#             */
/*   Updated: 2021/09/25 16:44:56 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	put_error(t_alldata *all, int error, char *msg)
{
	printf("%s\n", msg);
	ft_close(all, error);
}

void	error_handler(t_alldata *all, int error)
{
	if (error == 1)
		put_error(all, error, "Error\nWrong number of arguments!");
	if (error == 2)
		put_error(all, error, "Error\nIncorrect file extension!");
	if (error == 3)
		put_error(all, error, "Error\nCouldn't read file!");
	if (error == 4)
		put_error(all, error, "Error\nError parsing map!");
	if (error == 5)
		put_error(all, error, "Error\nBad map!");
	if (error == 6)
		put_error(all, error, "Error\nCouldn't allocate memory.");
}
