/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 06:42:43 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/15 23:45:25 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"
#include "../../includes/mem.h"

void		ft_listdel(t_list **list, void (del)(void **))
{
	t_node	*node;
	t_node	*tmp;

	if (*list)
	{
		node = (*list)->start;
		while (node)
		{
			tmp = node->next;
			ft_listdelnode(*list, node, del);
			node = tmp;
		}
	}
	ft_memdel((void**)list);
}
