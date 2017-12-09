/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 05:54:34 by aledru            #+#    #+#             */
/*   Updated: 2017/11/09 23:00:36 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	is_negative(int *n, int *is_neg)
{
	if (*n < 0)
	{
		*n = -*n;
		*is_neg = 1;
	}
}

char		*ft_itoa(int n)
{
	int		is_neg;
	int		size;
	char	*s;
	int		n_cpy;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = 1;
	is_neg = 0;
	is_negative(&n, &is_neg);
	n_cpy = n;
	while (n_cpy /= 10)
		size++;
	if (NULL != (s = ft_strnew(size += is_neg)))
	{
		while (size--)
		{
			s[size] = n % 10 + '0';
			n /= 10;
		}
		if (is_neg)
			s[0] = '-';
		return (s);
	}
	return (NULL);
}
