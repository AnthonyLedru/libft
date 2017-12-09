/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 01:12:08 by aledru            #+#    #+#             */
/*   Updated: 2017/11/09 02:32:37 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	i = 0;
	if (NULL != (res = ft_strnew(len)) && s != NULL)
	{
		while (s[start] && len--)
			res[i++] = s[start++];
		if (res != NULL)
			return (res);
	}
	return (NULL);
}
