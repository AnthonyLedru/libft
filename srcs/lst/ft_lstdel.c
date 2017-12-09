/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 01:20:05 by aledru            #+#    #+#             */
/*   Updated: 2017/11/10 01:45:42 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *list;

	while (*alst)
	{
		list = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(list);
		*alst = list;
	}
	*alst = NULL;
}
