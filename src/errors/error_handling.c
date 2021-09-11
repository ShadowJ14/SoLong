/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:12:38 by lprates           #+#    #+#             */
/*   Updated: 2021/09/11 21:27:45 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	error_handler(int error)
{
	
	if (error == 1)
	{
		printf("Wrong number of arguments!");
		exit (1);
	}
	if (error == 2)
	{
		printf("Incorrect file extension!");
		exit (2);
	}
	if (error == 3)
	{
		perror(NULL);
		exit (3);
	}
	if (error == 4)
	{
		printf("Error parsing map!");
		exit (4);
	}
}