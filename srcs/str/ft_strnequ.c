/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:55:28 by aledru            #+#    #+#             */
/*   Updated: 2017/11/10 00:09:38 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (n == 0)
		return (1);
	if (s1 != NULL && s2 != NULL)
	{
		while (*s1 && *s2 && *s1 == *s2 && n--)
		{
			s1++;
			s2++;
			if (n == 1 && *s1 == *s2)
				return (1);
		}
		if (*s1 == '\0' && *s2 == '\0')
			return (1);
	}
	return (0);
}
