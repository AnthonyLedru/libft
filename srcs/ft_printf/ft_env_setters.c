/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:13:47 by aledru            #+#    #+#             */
/*   Updated: 2018/03/10 13:54:41 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_base(t_env *e)
{
	if (e->str[e->i] == 'u' || e->str[e->i] == 'U' || e->str[e->i] == 'd' ||
			e->str[e->i] == 'D' || e->str[e->i] == 'i')
		e->base = 10;
	if (e->str[e->i] == 'X' || e->str[e->i] == 'x' || e->str[e->i] == 'p')
		e->base = 16;
	if (e->str[e->i] == 'o' || e->str[e->i] == 'O')
		e->base = 8;
}

void	set_nb_digit(t_env *e)
{
	int			nb_digit;
	uintmax_t	nbr_cp;

	nbr_cp = e->nbr;
	nb_digit = 0;
	if ((intmax_t)nbr_cp < 0 && (e->str[e->i] == 'd' || e->str[e->i] == 'i'))
		nbr_cp = -nbr_cp;
	if ((intmax_t)nbr_cp == 0)
		e->nb_digit = 1;
	else
		while (nbr_cp /= e->base)
			nb_digit++;
	nb_digit -= e->nbr == 0 && e->precision == 0 &&
				e->is_precision_specified == 1 &&
				e->str[e->i] != 'x' && e->str[e->i] != 'X' &&
				e->str[e->i] != 'o' && e->str[e->i] != 'O'
				? 1 : 0;
	e->nb_digit = nb_digit + 1;
}

void	set_offset(int init_index, t_env *e)
{
	char	*num;
	int		i;
	int		max;

	i = 0;
	if (e->str[e->i] == '0' && !e->minus)
	{
		e->i++;
		return ;
	}
	while (ft_isdigit(e->str[e->i]))
		e->i++;
	if (!(num = ft_memalloc(sizeof(char) * e->i - init_index + 1)))
		malloc_error();
	max = e->i;
	e->i = e->i - (e->i - init_index);
	while (e->i < max)
		num[i++] = e->str[e->i++];
	num[i] = '\0';
	e->offset = ft_atoi(num);
	ft_memdel((void*)&num);
}

void	set_precision(int init_index, t_env *e)
{
	char	*num;
	int		max;

	if (e->str[e->i] == '+' && e->str[e->i++])
		e->plus = 1;
	if (e->str[e->i] == '.' && e->str[e->i++])
		e->is_precision_specified = 1;
	while (ft_isdigit(e->str[e->i]))
		e->i++;
	if (e->i - init_index == 0)
		return ;
	init_index += e->str[init_index] == '.' ? 1 : 0;
	if (!(num = ft_memalloc(sizeof(char) * e->i - init_index + 1)))
		malloc_error();
	max = e->i;
	e->i = e->i - (e->i - init_index);
	ft_memcpy(num, &e->str[e->i], max - e->i);
	e->i = max;
	e->precision = ft_atoi(num);
	if (e->precision == 0 || e->dot == 1)
		e->is_precision_specified = 1;
	ft_memdel((void*)&num);
}
