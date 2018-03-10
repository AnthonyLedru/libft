/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:16:58 by aledru            #+#    #+#             */
/*   Updated: 2018/03/10 13:56:01 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_string_unicode_size(wchar_t unicode)
{
	if (unicode <= 255)
		return (1);
	else if (unicode <= 2047)
		return (2);
	else if (unicode <= 65535)
		return (3);
	else if (unicode <= 1114111)
		return (4);
	return (0);
}

int			get_char_unicode_size(wchar_t unicode)
{
	if (unicode <= 127)
		return (1);
	else if (unicode <= 2047)
		return (2);
	else if (unicode <= 65535)
		return (3);
	else if (unicode <= 1114111)
		return (4);
	return (0);
}

void		unicode_conversion(t_env *e, int put_offset)
{
	int	unicode_size;

	unicode_size = get_char_unicode_size(e->nbr);
	if (unicode_size == 1)
		char_conversion(e, put_offset);
	if (unicode_size == 2)
	{
		put_char_to_buf((e->nbr >> 6 & 31) + 192 & 2047, e);
		put_char_to_buf((e->nbr & 63) + 128 & 2047, e);
	}
	if (unicode_size == 3)
	{
		put_char_to_buf((e->nbr >> 12 & 15) + 224 & 65535, e);
		put_char_to_buf((e->nbr >> 6 & 63) + 128 & 65535, e);
		put_char_to_buf((e->nbr & 63) + 128 & 65535, e);
	}
	if (unicode_size == 4)
	{
		put_char_to_buf((e->nbr >> 18 & 7) + 240 & 1114111, e);
		put_char_to_buf((e->nbr >> 12 & 63) + 128 & 1114111, e);
		put_char_to_buf((e->nbr >> 6 & 63) + 128 & 1114111, e);
		put_char_to_buf((e->nbr & 63) + 128 & 1114111, e);
	}
}
