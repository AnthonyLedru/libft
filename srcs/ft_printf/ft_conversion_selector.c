/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_selector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:01:56 by aledru            #+#    #+#             */
/*   Updated: 2018/03/10 13:54:15 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		put_percent_to_buf(t_env *e)
{
	e->offset--;
	if (!e->minus)
		put_offset_to_buf(e);
	put_char_to_buf('%', e);
	if (e->minus)
		put_offset_to_buf(e);
}

static void		put_char_not_converter(t_env *e)
{
	if (!e->minus)
		put_offset_to_buf(e);
	e->count_before_reset += ft_strlen(e->buf);
	write(e->fd, e->buf, ft_strlen(e->buf));
	ft_memdel((void*)&e->buf);
	e->buf = ft_memalloc(sizeof(char));
	put_char_to_buf(e->str[e->i], e);
	if (e->minus)
		put_offset_to_buf(e);
}

static void		select_number_conversion(t_env *e)
{
	e->zero = e->precision != 0 ? 0 : e->zero;
	set_base(e);
	set_nb_digit(e);
	e->caps = e->str[e->i] == 'X' ? 1 : 0;
	e->sharp = e->str[e->i] == 'p' ? 1 : e->sharp;
	if ((e->str[e->i] == 'X' || e->str[e->i] == 'x') && e->sharp == 1)
		e->sharp = 2;
	if (e->str[e->i] == 'u' || e->str[e->i] == 'U' || e->str[e->i] == 'd' ||
			e->str[e->i] == 'D' || e->str[e->i] == 'i')
		int_conversion(e);
	if (e->str[e->i] == 'X' || e->str[e->i] == 'x' || e->str[e->i] == 'p')
		hexa_conversion(e);
	if (e->str[e->i] == 'o' || e->str[e->i] == 'O')
		octal_conversion(e);
}

void			select_conversion(t_env *e, va_list arg)
{
	cast_arg(e, arg);
	if (e->str[e->i] == '%')
		put_percent_to_buf(e);
	else if (e->str[e->i] == 's' && !e->is_unicode)
		string_conversion(e, arg);
	else if (e->str[e->i] == 'S' || (e->str[e->i] == 's' && e->is_unicode))
	{
		e->is_unicode = 1;
		string_unicode_conversion(e, arg);
	}
	else if (e->str[e->i] == 'c' && !e->is_unicode)
		char_conversion(e, 1);
	else if (e->str[e->i] == 'C' || (e->is_unicode && e->str[e->i] == 'c'))
		char_unicode_conversion(e);
	else if (e->str[e->i] == 'd' || e->str[e->i] == 'D' ||
		e->str[e->i] == 'u' || e->str[e->i] == 'U' || e->str[e->i] == 'X' ||
		e->str[e->i] == 'x' || e->str[e->i] == 'o' || e->str[e->i] == 'O' ||
		e->str[e->i] == 'p' || e->str[e->i] == 'l' || e->str[e->i] == 'h' ||
		e->str[e->i] == 'j' || e->str[e->i] == 'z' || e->str[e->i] == 'i')
		select_number_conversion(e);
	e->offset -= !is_a_flag(e->str[e->i]) && !ft_isdigit(e->str[e->i]) ? 1 : 0;
	if (!is_a_flag(e->str[e->i]) && !ft_isdigit(e->str[e->i]))
		put_char_not_converter(e);
}
