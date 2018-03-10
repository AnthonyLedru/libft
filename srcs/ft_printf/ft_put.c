/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:31:59 by aledru            #+#    #+#             */
/*   Updated: 2018/03/10 13:55:27 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_str_to_buf(char *str, t_env *e)
{
	char *to_free;

	to_free = e->buf;
	e->buf = ft_strjoin(e->buf, str);
	ft_memdel((void*)&to_free);
	ft_memdel((void*)&str);
}

void	put_char_to_buf(char c, t_env *e)
{
	char	*str_c;

	if (!(str_c = ft_memalloc(sizeof(char) * 2)))
		malloc_error();
	str_c[0] = c;
	str_c[1] = '\0';
	put_str_to_buf(str_c, e);
}

void	put_zero_to_buf(t_env *e)
{
	char	*zero;

	if (e->offset > 0)
	{
		if (!(zero = ft_memalloc(sizeof(char) * e->offset + 1)))
			malloc_error();
		ft_memset(zero, '0', e->offset);
		put_str_to_buf(zero, e);
	}
	e->offset = 0;
}

void	put_offset_to_buf(t_env *e)
{
	char	*offset;

	if (e->offset > 0)
	{
		if (!(offset = ft_memalloc(sizeof(char) * e->offset + 1)))
			malloc_error();
		if (e->zero == 1)
			ft_memset(offset, '0', e->offset);
		else
			ft_memset(offset, ' ', e->offset);
		put_str_to_buf(offset, e);
	}
}

void	put_precision_to_buf(t_env *e, int arg_size)
{
	char	*prec;

	if (e->precision > arg_size)
	{
		if (!(prec = ft_memalloc(sizeof(char) * e->precision - arg_size + 1)))
			malloc_error();
		ft_memset(prec, '0', e->precision - arg_size);
		put_str_to_buf(prec, e);
	}
}
