/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 17:50:48 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/30 17:50:48 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		count_next(t_list *list)
{
	t_node	*node;
	char	*tmp;
	int		size;
	int		test;
	int		index;

	node = list->start;
	size = 0;
	test =1;
	while (node && test)
	{
		tmp = (char*)node->content;
		index = 0;
		while (tmp[index] && test)
		{
			if (tmp[index] == '\n')
				test = 0;
			size++;
			index++;
		}
		node = node->next;
	}
	return (size);
}

int		main(void)
{
	t_list	*list;
	t_node	*node;
	int		size;
	char	*str;
	char	*tmp;
	void	(*del)(void **);
	void	(*put)(char const *);

	del = ft_memdel;
	put = ft_putstr;
	str = NULL;
	/*ft_readfile(0, &str);
	ft_putendl(str);
	return (0);*/
	list = ft_listcreate();
	ft_readfilelist(0, list);
	node = list->start;
	size = count_next(list);
	str = ft_strnew(size);
	size = 1;
	while (node && size)
	{
		//ft_strfusion(&str, (char **)&(node->content));
		if (ft_cinstr(node->content, '\n') != 0)
		{
			tmp = ft_strdup(str);
			while (*tmp && *tmp == '\n')
				if (*++tmp == '\n')
				{
					*tmp = '\0';
					size = 0;
				}
			ft_strfusiondel(&str, &tmp);
		}
		else if (ft_cinstr(node->content, '\0') != 0)
		{
			ft_strfusion(&str, (char **)&(node->content));
		}
		else
		{
			ft_strfusion(&str, (char **)&(node->content));
		}
		node = node->next;
	}
	ft_listputstr(list, put);
	PUT_ENDL;
	ft_putendl("\n=====");
	ft_putendl(str);
	ft_listdel(list, del);
	ft_strdel(&str);
}
