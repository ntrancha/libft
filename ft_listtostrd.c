/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listtostrd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 19:49:57 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/30 19:49:57 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_listtostrd(t_list *list, char *del)
{
	t_node	*node;
	int		count;
	int		index;
	char	*str;
	char	*tmp;

	if (!list)
		return (NULL);
	count = ft_strlen(del) * list->size;
	if (!(str = ft_strnew(ft_liststrlen(list) + count + 1)))
		return (NULL);
	count = 0;
	node = list->start;
	while (node)
	{
		index = 0;
		tmp = (char*)node->content;
		while (tmp[index])
			str[count++] = tmp[index++];
		index = 0;
		while (del[index])
			str[count++] = del[index++];
		node = node->next;
	}
	return (str);
}
