/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:46:07 by aledru            #+#    #+#             */
/*   Updated: 2018/03/10 13:54:22 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_dprintf(int fd, const char *str, ...)
{
	va_list arg;
	int		res;
	t_env	*e;

	va_start(arg, str);
	e = create_env((char*)str, fd);
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
