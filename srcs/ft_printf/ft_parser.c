/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:03:30 by aledru            #+#    #+#             */
/*   Updated: 2018/03/10 13:55:09 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_a_pre_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+' || c == '.')
		return (1);
	return (0);
}

static void		get_flags_before_converter(t_env *e)
{
	while (is_a_pre_flag(e->str[e->i]))
	{
		if (e->str[e->i] == '#')
			e->sharp = 1;
		else if (e->str[e->i] == '0' && e->str[e->i + 1] != '.')
			e->zero = 1;
		else if (e->str[e->i] == '-')
			e->minus = 1;
		else if (e->str[e->i] == ' ')
			e->space = 1;
		else if (e->str[e->i] == '+')
			e->plus = 1;
		else if (e->str[e->i] == '.')
		{
			e->zero = 0;
			e->dot = 1;
			e->is_precision_specified = 1;
			e->i++;
			break ;
		}
		e->i++;
	}
}

int				is_a_flag(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
		c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' ||
		c == 'c' || c == 'C' || c == '.' || c == '%' || c == 'h' || c == 'l' ||
		c == 'j' || c == 'z' || ft_isdigit(c))
		return (1);
	return (0);
}

void			parse_after_percent(t_env *e, va_list arg)
{
	reset_var(e);
	get_flags_before_converter(e);
	if (!is_a_flag(e->str[e->i]))
	{
		e->i--;
		return ;
	}
	e->space = e->plus == 1 && e->space == 1 ? 0 : e->space;
	e->zero = e->zero == 1 && e->minus == 1 ? 0 : e->zero;
	if (e->dot == 0 || e->zero != 0)
		set_offset(e->i, e);
	set_precision(e->i, e);
	e->offset -= e->space == 1 && e->offset != 0 ? 1 : e->space;
	select_conversion(e, arg);
}
