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

static int			ft_gnl_cut(int const fd, char **line, t_list **all)
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
		if ((ret = ft_readfilelist(fd, all[fd])) == -1)
			RETURN_FAIL
		if (all[fd]->size == 0)
			RETURN_FAIL
		all[fd] = ft_listsplit(all[fd], '\n');
	}
	if (all[fd]->size == 0)
	{
		*line = ft_strdup("");
		RETURN_FAIL
	}
	return (ft_gnl_cut(fd, line, all));
}

int	main(void)
{
	char	*str;
	int		ret;

	str = NULL;
	ret = 42;
	while ((ret = ft_gnl_list(0, &str)) == 1)
	{
		ft_putnbr(ret);
		ft_putstr(" : ");
		ft_putendl(str);
	}
	ft_putnbr(ret);
	ft_putstr(" := ");
	if (ret != -1)
		ft_putstr(str);
	else
		ft_putstr("NULL");
	PUT_ENDL;
	ret = 42;
	while ((ret = ft_gnl_list(0, &str)) == 1)
	{
		ft_putnbr(ret);
		ft_putstr(" : ");
		ft_putendl(str);
	}
	ft_putnbr(ret);
	ft_putstr(" =: ");
	if (ret != -1)
		ft_putstr(str);
	else
		ft_putstr("NULL");
}
