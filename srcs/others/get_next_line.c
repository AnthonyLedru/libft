/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:56:00 by aledru            #+#    #+#             */
/*   Updated: 2018/01/13 22:49:22 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

/*
** Get the link that correspond to the file descriptor given in param.
** If the link doesn't exist, a new one will be added to the linked list.
*/

static	t_list	*get_valid_lst(t_list **lst_save, int fd)
{
	t_list	*tmp;
	t_list	*first;

	if (*lst_save == NULL)
		*lst_save = (t_list*)ft_memalloc(sizeof(t_list));
	first = *lst_save;
	while (lst_save)
	{
		if (((int)(*lst_save)->content_size) == fd && (*lst_save)->content)
		{
			tmp = *lst_save;
			*lst_save = first;
			return (tmp);
		}
		if ((*lst_save)->next)
			*lst_save = (*lst_save)->next;
		else
			break ;
	}
	tmp = (t_list*)ft_memalloc(sizeof(t_list));
	tmp->content_size = fd;
	tmp->content = ft_memalloc(sizeof(char) * 1);
	(*lst_save)->next = tmp;
	*lst_save = first;
	return (tmp);
}

/*
** Get the string before the first '\n' encountered in the line read.
*/

static char		*get_line_before_n(char **last_line_read)
{
	char	**str;
	int		i;
	char	*line;

	i = 0;
	if (ft_strchr(*last_line_read, '\n'))
	{
		str = ft_strsplit(*last_line_read, '\n');
		if (str[0][0] == '\n')
			line = ft_strdup(str[1]);
		else
			line = ft_strdup(str[0]);
		while (str[i])
		{
			ft_memdel((void*)&str[i]);
			i++;
		}
		ft_memdel((void*)&str);
	}
	else
		line = ft_strdup(*last_line_read);
	return (line);
}

/*
** Get the string after the first '\n' or '\0' encountered in the line read.
*/

static void		*get_line_after_n(char **last_line_read)
{
	void	*to_free;

	to_free = *last_line_read;
	if (ft_strchr(*last_line_read, '\n'))
		*last_line_read = ft_strdup(&ft_strchr(*last_line_read, '\n')[1]);
	else if (ft_strchr(*last_line_read, '\0'))
		*last_line_read = ft_strdup(ft_strchr(*last_line_read, '\0'));
	ft_memdel((void*)&to_free);
	return (*last_line_read);
}

/*
** Read the file until it reach the end or if it found a new line in the
** read content.
*/

static int		read_file(char **content, t_list *lst)
{
	char	*buf;
	int		size;
	char	*to_free;

	buf = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	while ((size = read(lst->content_size, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		to_free = *content;
		*content = ft_strjoin(*content, buf);
		ft_memdel((void*)&to_free);
		if (ft_strchr(*content, '\n'))
			break ;
	}
	ft_memdel((void*)&buf);
	return (size);
}

/*
** Get the next line of the file descriptor given in param.
*/

int				get_next_line(const int fd, char **line)
{
	static	t_list	*lst_save;
	t_list			*lst;
	int				value;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	lst = get_valid_lst(&lst_save, fd);
	if ((value = read_file((char**)(&lst->content), lst)) == -1
			|| (value == 0 && ft_strlen(lst->content) == 0))
	{
		*line = NULL;
		return (value);
	}
	if (((char*)lst->content)[0] == '\n')
	{
		get_line_after_n((char**)(&lst->content));
		*line = ft_strnew(0);
		return (1);
	}
	*line = get_line_before_n((char**)(&lst->content));
	get_line_after_n((char**)(&lst->content));
	return (1);
}
