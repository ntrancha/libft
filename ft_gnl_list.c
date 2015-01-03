/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 17:50:48 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/30 17:50:48 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

static int			readfile(int const fd, t_list *list)
{
	int				ret;
	char			*line;
	char			*tmp;

	ret = BUFF_SIZE;
	line = NULL;
	if (!list)
		return (EXIT_FAIL);
	while (ret)
	{
		line = ft_strnew(BUFF_SIZE + 2);
		if ( line == NULL || (ret = read(fd, line, BUFF_SIZE)) == -1 )
			return (EXIT_FAIL);
		line[ret] = '\0';
		while ((int)ft_strlen(line) != ret)
			line[ft_strlen(line)] = '\a';
		tmp = ft_ctos('\a');
		ft_strnrpl(&line, tmp, "", -1);
		ft_strdel(&tmp);
		list = ft_listadd(list, line);
	}
	return (EXIT_NULL);
}

static int			cut(int const fd, char **line, t_list **all)
{
	void			(*del)(void **);

	ft_strdel(line);
	del = ft_memdel;
	if (all[fd] && all[fd]->start->content)
	{
		*line = ft_strdup(all[fd]->start->content);
		if (GNL_ILLIMITY == 1)
		{
			ft_listadd(all[fd], ft_strdup(*line));
			all[fd]->size--;
		}
	}
	ft_listdelnode(all[fd], all[fd]->start, del);
	if (all[fd]->size == 0)
	{
		all[fd]->size = ft_listlen(all[fd]);
		RETURN_NULL
	}
	RETURN_SUCCES
}

static void			splitnext(t_list *ret, char *str, char **tmp, char c)
{
	int				index;

	index = 0;
	if (!ft_cinstr(str, c))
		ft_strfusion(tmp, &str);
	else
		while (str[index])
		{
			if (str[index] == c)
			{
				ret = ft_listadd(ret, *tmp);
				*tmp = STR_EMPTY;
			}
			else
				ft_straddchar(tmp, str[index]);
			index++;
		}
}

static t_list		*split(t_list *list, char c)
{
	t_list			*ret;
	t_node			*node;
	char			*tmp;
	void			(*del)(void **);

	ret = ft_listcreate();
	node = list->start;
	tmp = STR_EMPTY;
	del = ft_memdel;
	while (node)
	{
		splitnext(ret, node->content, &tmp, c);
		node = node->next;
	}
	ret = ft_listadd(ret, tmp);
	ft_listdel(list, del);
	return (ret);
}

int					ft_gnl_list(int const fd, char **line)
{
	static t_list	*all[GNL_FD_MAX];
	char			ret;

	if (!all[fd])
	{
		all[fd] = ft_listcreate();
		if ((ret = readfile(fd, all[fd])) == -1)
		{
			ft_strdel(line);
			*line = STR_EMPTY;
			RETURN_FAIL
		}
		all[fd] = split(all[fd], '\n');
	}
	if (all[fd]->size == 0)
	{
		ft_strdel(line);
		*line = STR_EMPTY;
		RETURN_FAIL
	}
	return (cut(fd, line, all));
}
