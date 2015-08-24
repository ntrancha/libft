/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listaddfirst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 17:20:13 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:32:46 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"
#include "../../includes/mem.h"

t_list		*ft_listaddfirst(t_list *list, void *content)
{
	t_node	*node;

	if (!list)
		list = ft_listcreate();
	node = ft_memalloc(sizeof(t_node));
	if (!node)
		return (NULL);
	if (!content)
		node->content = NULL;
	else
		node->content = content;
	node->next = list->start;
	node->previous = NULL;
	if (list->start)
		list->start->previous = node;
	else
		list->end = node;
	list->start = node;
	list->size++;
	return (list);
}
