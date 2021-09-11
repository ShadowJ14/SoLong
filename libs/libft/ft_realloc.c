/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:00:27 by lprates           #+#    #+#             */
/*   Updated: 2021/09/11 22:00:29 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **src, size_t size)
{
	void	*dst;

	dst = malloc(size);
	if (!dst)
	{
		free((*src));
		return (NULL);
	}
	if (!(*src))
	{
		free(dst);
		return (NULL);
	}
	ft_memmove(dst, (*src), size);
	free((*src));
	(*src) = NULL;
	return (dst);
}