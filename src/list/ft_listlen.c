/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 08:06:41 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:34:33 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

size_t		ft_listlen(t_list *list)
{
	size_t	n;
	t_node	*node;

	n = 0;
	if (list)
	{
		node = list->start;
		while (node)
		{
			n++;
			node = node->next;
		}
	}
	return (n);
}
