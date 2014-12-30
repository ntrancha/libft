/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listreverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 17:41:50 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/30 17:41:50 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_listreverse(t_list *list)
{
	t_node	*start;
	t_node	*end;
	t_node	*node;

	start = list->start;
	node = start;
	end = list->end;
	while (node && node != end)
	{
		node->next->previous = NULL;
		list->start = node->next;
		if (!ft_listaddafter(list, end, node->content))
			return (NULL);
		ft_memdel((void**)&node);
		node = node->next;
	}
	return (list);
}
