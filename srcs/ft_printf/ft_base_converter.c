/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 09:25:18 by aledru            #+#    #+#             */
/*   Updated: 2018/03/10 13:53:57 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*base_converter_d_u(t_env *e)
{
	int			nb_digit;
	char		*res;

	if ((unsigned long int)e->nbr == -9223372036854775808U)
		return (ft_strdup("9223372036854775808"));
	if ((intmax_t)e->nbr < 0 && e->str[e->i] != 'u' && e->str[e->i] != 'U')
		e->nbr = -e->nbr;
	set_nb_digit(e);
	nb_digit = e->nb_digit;
	if (!(res = (char*)ft_memalloc(sizeof(char) * nb_digit + 1)))
		malloc_error();
	res[nb_digit] = '\0';
	while (nb_digit--)
	{
		res[nb_digit] = e->nbr % e->base + '0';
		e->nbr /= e->base;
	}
	return (res);
}

char	*base_converter_x_o(t_env *e)
{
	int				nb_digit;
	char			*res;
	int				char_ref;

	char_ref = e->caps == 1 ? 55 : 87;
	set_nb_digit(e);
	nb_digit = e->nb_digit;
	if (!(res = (char*)ft_memalloc(sizeof(char) * nb_digit + 1)))
		malloc_error();
	res[nb_digit] = '\0';
	while (nb_digit--)
	{
		if ((e->nbr % e->base >= 10 || e->nbr % e->base <= 15))
			res[nb_digit] = char_ref + (e->nbr % e->base);
		if (e->nbr % e->base < 10)
			res[nb_digit] = e->nbr % e->base + '0';
		e->nbr /= e->base;
	}
	return (res);
}
