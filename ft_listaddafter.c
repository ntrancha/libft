/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listaddafter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 17:27:39 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/30 17:27:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_listaddafter(t_list *list, t_node *prev, void *content)
{
	t_node	*node;
	t_node	*next;

	if (!prev)
		return (NULL);
	if (!list)
		list = ft_listcreate();
	if (!(node = ft_memalloc(sizeof(t_node))))
		return (NULL);
	if (!content)
		node->content = NULL;
	else
		node->content = content;
	next = prev->next;
	if (next)
		next->previous = node;
	else
		list->end = node;
	prev->next = node;
	node->previous = prev;
	node->next = next;
	list->size++;
	return (list);
}

