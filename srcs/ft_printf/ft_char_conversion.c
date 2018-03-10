/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:34:56 by aledru            #+#    #+#             */
/*   Updated: 2018/03/10 13:54:08 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_char_unicode_error(t_env *e)
{
	if ((e->nbr >= 55296 && e->nbr <= 57343))
		e->unicode_error = 1;
	if ((e->nbr > 127 && e->nbr <= 2047) && MB_CUR_MAX < 2)
		e->unicode_error = 1;
	if (e->nbr > 2047 && e->nbr <= 65535 && MB_CUR_MAX < 3)
		e->unicode_error = 1;
	if (e->nbr > 65535 && e->nbr <= 1114111 && MB_CUR_MAX < 4)
		e->unicode_error = 1;
	if (e->nbr > 1114111)
		e->unicode_error = 1;
	if (e->nbr <= 255 && e->unicode_error)
	{
		e->unicode_error = 0;
		char_conversion(e, 1);
		return (1);
	}
	if (e->unicode_error == 1)
		return (1);
	return (0);
}

void			char_unicode_conversion(t_env *e)
{
	if (get_char_unicode_error(e) == 1)
		return ;
	if ((e->nbr > 127 && e->nbr <= 2047))
		e->offset -= 2;
	if (e->nbr > 2047 && e->nbr <= 65535)
		e->offset -= 3;
	if (e->nbr > 65535 && e->nbr <= 1114111)
		e->offset -= 4;
	if (!e->minus && e->nbr > 127)
		put_offset_to_buf(e);
	unicode_conversion(e, 1);
	if (e->minus && e->nbr > 127)
		put_offset_to_buf(e);
}

void			char_conversion(t_env *e, int put_offset)
{
	if (put_offset == 1)
		e->offset--;
	if (!e->minus && put_offset == 1)
		put_offset_to_buf(e);
	if (!e->nbr)
	{
		e->count_before_reset += ft_strlen(e->buf) + 1;
		put_char_to_buf('\0', e);
		write(e->fd, e->buf, ft_strlen(e->buf) + 1);
		ft_memdel((void*)&e->buf);
		e->buf = ft_memalloc(sizeof(char));
	}
	put_char_to_buf(e->nbr, e);
	if (e->minus && put_offset == 1)
		put_offset_to_buf(e);
}
