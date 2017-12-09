/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:40:03 by aledru            #+#    #+#             */
/*   Updated: 2017/11/08 23:57:00 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;

	if ((res = (void*)malloc(sizeof(void) * size)) != NULL)
	{
		ft_memset(res, 0, size);
		return (res);
	}
	return (NULL);
}
