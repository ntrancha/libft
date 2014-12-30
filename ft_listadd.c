/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 05:46:30 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/30 05:46:30 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_listadd(t_list *list, void *content)
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
	node->next = NULL;
	node->previous = list->end;
	if (!list->end)
		list->start = node;
	else
		list->end->next = node;
	list->end = node;
	list->size++;
	return (list);
}
