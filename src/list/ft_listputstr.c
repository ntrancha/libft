/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listputstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 07:46:33 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:34:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

void		ft_listputstr(t_list * list, void (put)(char const *))
{
	t_node	*node;

	if (list)
	{
		node = list->start;
		while (node)
		{
			put(node->content);
			node = node->next;
		}
	}
}
