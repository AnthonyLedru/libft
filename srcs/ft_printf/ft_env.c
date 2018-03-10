/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 20:59:45 by aledru            #+#    #+#             */
/*   Updated: 2018/03/10 13:54:29 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_env	*create_env(char *str, int fd)
{
	t_env	*e;

	if (!(e = ft_memalloc(sizeof(t_env))))
		malloc_error();
	e->buf = ft_memalloc(sizeof(char *));
	e->str = str;
	e->i = 0;
	e->fd = fd;
	return (e);
}

void	reset_var(t_env *e)
{
	e->offset = 0;
	e->precision = 0;
	e->sharp = 0;
	e->dot = 0;
	e->is_precision_specified = 0;
	e->base = 0;
	e->plus = 0;
	e->minus = 0;
	e->space = 0;
	e->nb_digit = 0;
	e->is_unicode = 0;
}
