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

#include "includes/libft.h"

static void			ft_listsplitnext(t_list *ret, char *str, char **tmp, char c)
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
				*tmp = ft_strnew(0);
			}
			else
				ft_straddchar(tmp, str[index]);
			index++;
		}
}

static t_list		*ft_listsplit(t_list *list, char c)
{
	t_list			*ret;
	t_node			*node;
	char			*tmp;
	void			(*del)(void **);

	ret = ft_listcreate();
	node = list->start;
	tmp = ft_strnew(0);
	del = ft_memdel;
	while (node)
	{
		ft_listsplitnext(ret, node->content, &tmp, c);
		node = node->next;
	}
	ret = ft_listadd(ret, tmp);
	ft_listdel(list, del);
	return (ret);
}

int					ft_gnl_list(int const fd, char **line)
{
	static t_list	*all[100];
	char			ret;
	void			(*del)(void **);

	if (!all[fd])
	{
		all[fd] = ft_listcreate();
		if ((ret = ft_readfilelist(fd, all[fd])) == -1)
			return (EXIT_FAIL);
		all[fd] = ft_listsplit(all[fd], '\n');
	}
	if (all[fd]->size == 0)
		return (0);
	ft_strdel(line);
	del = ft_memdel;
	if (all[fd] && all[fd]->start->content)
		*line = ft_strdup(all[fd]->start->content);
	ft_listdelnode(all[fd], all[fd]->start, del);
	if (all[fd]->size == 0)
		return (0);
	return (1);
}
