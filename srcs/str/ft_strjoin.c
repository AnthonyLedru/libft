/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 02:32:52 by aledru            #+#    #+#             */
/*   Updated: 2017/11/09 02:47:46 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*res;
	int		i;

	i = 0;
	size = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1);
	size += ft_strlen(s2);
	if (NULL != (res = ft_strnew(size)))
	{
		while (*s1)
		{
			res[i++] = *s1;
			s1++;
		}
		while (*s2)
		{
			res[i++] = *s2;
			s2++;
		}
		return (res);
	}
	return (NULL);
}
