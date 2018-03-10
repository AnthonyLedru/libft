/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:46:07 by aledru            #+#    #+#             */
/*   Updated: 2018/03/10 13:55:21 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			remove_string_from_buf_before_unicode_error(t_env *e)
{
	int		buf_size;
	int		nb_char_before_percent;
	char	*new_buf;
	int		i;

	i = 0;
	buf_size = ft_strlen(e->buf);
	nb_char_before_percent = e->percent_pos - e->first_char_pos;
	if (!(new_buf = ft_memalloc(sizeof(char) *
					buf_size - nb_char_before_percent + 1)))
		malloc_error();
	while (i < buf_size - nb_char_before_percent)
	{
		new_buf[i] = e->buf[i];
		i++;
	}
	ft_memdel((void*)&e->buf);
	e->buf = ft_strdup(new_buf);
	ft_memdel((void*)&new_buf);
}

void			put_to_buf_until_percent(t_env *e)
{
	e->first_char_pos = e->i;
	while (e->str[e->i] && e->str[e->i] != '%')
	{
		put_char_to_buf(e->str[e->i], e);
		e->i++;
	}
	if (e->str[e->i] == '%')
		e->percent_pos = e->i;
}

int				ft_printf(const char *format, ...)
{
	va_list arg;
	int		res;
	t_env	*e;

	va_start(arg, format);
	e = create_env((char*)format, 1);
	while (e->str[e->i])
	{
		put_to_buf_until_percent(e);
		if (!e->str[e->i])
			break ;
		e->i++;
		parse_after_percent(e, arg);
		if (e->unicode_error == 1)
			break ;
		e->i++;
	}
	if (e->unicode_error == 1)
		remove_string_from_buf_before_unicode_error(e);
	write(e->fd, e->buf, ft_strlen(e->buf));
	va_end(arg);
	res = !e->unicode_error ? ft_strlen(e->buf) + e->count_before_reset : -1;
	ft_memdel((void*)&e->buf);
	ft_memdel((void*)&e);
	return (res);
}
