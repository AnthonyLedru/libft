/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 04:11:59 by aledru            #+#    #+#             */
/*   Updated: 2017/11/08 05:11:44 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	is_negative;
	int	nb;

	nb = 0;
	i = 0;
	is_negative = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f'
			|| str[i] == '\b' || str[i] == '\a')
		i++;
	if (str[i] == '-')
		is_negative = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] > 47) && (str[i] < 58))
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	if (is_negative == 1)
		nb = -nb;
	return (nb);
}
