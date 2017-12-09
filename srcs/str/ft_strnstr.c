/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 03:10:37 by aledru            #+#    #+#             */
/*   Updated: 2017/11/16 09:45:37 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[i] && i < (int)n)
	{
		while (str[i + j] == to_find[j] && i + j < (int)n)
		{
			if (to_find[j + 1] == '\0')
				return ((char*)&str[i]);
			j++;
		}
		i++;
		j = 0;
	}
	return (NULL);
}
