/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdelnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 06:09:07 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/30 06:09:07 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_listdelnode(t_list *list, t_node *node, void (del)(void **))
{
	if (list && node && ft_listcontent(list, node))
	{
		if (node->previous)
			node->previous->next = node->next;
		if (node->next)
			node->next->previous = node->previous;
		if (list->end == node)
			list->end = node->previous;
		if (list->start == node)
			list->start = node->next;
		if (node->content)
			del(&(node->content));
		list->size--;
		ft_memdel((void**)&node);
	}
}
