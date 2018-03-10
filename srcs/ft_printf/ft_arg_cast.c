/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:39:41 by aledru            #+#    #+#             */
/*   Updated: 2018/03/10 13:53:26 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		cast_arg_h_hh(t_env *e, va_list arg)
{
	e->i++;
	if (e->str[e->i] == 'd' || e->str[e->i] == 'i')
		e->nbr = (short int)va_arg(arg, uintmax_t);
	else if (e->str[e->i] == 'u' || e->str[e->i] == 'o' ||
			e->str[e->i] == 'x' || e->str[e->i] == 'X')
		e->nbr = (unsigned short int)va_arg(arg, uintmax_t);
	while (e->str[e->i] == 'h')
	{
		e->i++;
		if (e->str[e->i] == 'd' || e->str[e->i] == 'i')
			e->nbr = (signed char)va_arg(arg, uintmax_t);
		else if (e->str[e->i] == 'o' || e->str[e->i] == 'u' ||
				e->str[e->i] == 'x' || e->str[e->i] == 'X')
			e->nbr = (unsigned char)va_arg(arg, uintmax_t);
	}
	if (e->str[e->i] == 'p')
		e->nbr = (unsigned long long int)va_arg(arg, uintmax_t);
	else if (e->str[e->i] == 'c' || e->str[e->i] == 'C')
	{
		e->nbr = (wchar_t)va_arg(arg, uintmax_t);
		e->is_unicode = 1;
	}
}

static void		cast_arg_l_ll(t_env *e, va_list arg)
{
	e->i++;
	if (e->str[e->i] == 'd' || e->str[e->i] == 'i')
		e->nbr = (long int)va_arg(arg, uintmax_t);
	else if (e->str[e->i] == 'u' || e->str[e->i] == 'o' ||
			e->str[e->i] == 'x' || e->str[e->i] == 'X')
		e->nbr = (unsigned long int)va_arg(arg, uintmax_t);
	while (e->str[e->i] == 'l')
	{
		e->i++;
		if (e->str[e->i] == 'd' || e->str[e->i] == 'i')
			e->nbr = (long long int)va_arg(arg, uintmax_t);
		else if (e->str[e->i] == 'o' || e->str[e->i] == 'u' ||
				e->str[e->i] == 'x' || e->str[e->i] == 'X')
			e->nbr = (unsigned long long int)va_arg(arg, uintmax_t);
	}
	if (e->str[e->i] == 'p')
		e->nbr = (unsigned long long int)va_arg(arg, uintmax_t);
	else if (e->str[e->i] == 'c' || e->str[e->i] == 'C')
	{
		e->nbr = (wchar_t)va_arg(arg, uintmax_t);
		e->is_unicode = 1;
	}
	else if (e->str[e->i] == 's')
		e->is_unicode = 1;
}

static void		cast_arg_z_j(t_env *e, va_list arg)
{
	while (e->str[e->i] == 'z' || e->str[e->i] == 'j')
		e->i++;
	if (e->str[e->i - 1] == 'z')
	{
		if (e->str[e->i] == 'd' || e->str[e->i] == 'i' ||
				e->str[e->i] == 'u' || e->str[e->i] == 'o' ||
				e->str[e->i] == 'x' || e->str[e->i] == 'X')
			e->nbr = (size_t)va_arg(arg, uintmax_t);
	}
	else
	{
		if (e->str[e->i] == 'd' || e->str[e->i] == 'i')
			e->nbr = (intmax_t)va_arg(arg, uintmax_t);
		else if (e->str[e->i] == 'u' || e->str[e->i] == 'o' ||
					e->str[e->i] == 'x' || e->str[e->i] == 'X')
			e->nbr = (uintmax_t)va_arg(arg, uintmax_t);
	}
	if (e->str[e->i] == 'p')
		e->nbr = (unsigned long long int)va_arg(arg, uintmax_t);
	else if (e->str[e->i] == 'c' || e->str[e->i] == 'C')
	{
		e->nbr = (wchar_t)va_arg(arg, uintmax_t);
		e->is_unicode = 1;
	}
}

static void		dou_cast(t_env *e, va_list arg)
{
	int	i;

	i = e->i;
	while (e->str[i] == 'h' || e->str[i] == 'l' || e->str[i] == 'j' ||
			e->str[i] == 'z')
		i++;
	if (e->str[i] == 'D' || e->str[i] == 'U' || e->str[i] == 'O')
		e->i = i;
	if (e->str[e->i] == 'D')
		e->nbr = (long int)va_arg(arg, uintmax_t);
	else if (e->str[e->i] == 'U' || e->str[e->i] == 'O')
		e->nbr = (unsigned long int)va_arg(arg, uintmax_t);
}

void			cast_arg(t_env *e, va_list arg)
{
	dou_cast(e, arg);
	if (e->str[e->i] == 'C')
		e->nbr = (wchar_t)va_arg(arg, uintmax_t);
	else if (e->str[e->i] == 'd' || e->str[e->i] == 'i')
		e->nbr = (int)va_arg(arg, uintmax_t);
	else if (e->str[e->i] == 'p')
		e->nbr = (unsigned long long int)va_arg(arg, uintmax_t);
	else if (e->str[e->i] == 'c')
		e->nbr = (unsigned char)va_arg(arg, uintmax_t);
	else if (e->str[e->i] == 'u' || e->str[e->i] == 'o' ||
				e->str[e->i] == 'X' || e->str[e->i] == 'x')
		e->nbr = (unsigned int)va_arg(arg, uintmax_t);
	else if (e->str[e->i] == 'h')
		cast_arg_h_hh(e, arg);
	else if (e->str[e->i] == 'l')
		cast_arg_l_ll(e, arg);
	else if (e->str[e->i] == 'z' || e->str[e->i] == 'j')
		cast_arg_z_j(e, arg);
}
