/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liststrlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 19:45:30 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/30 19:45:30 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_liststrlen(t_list *list)
{
	size_t	size;
	t_node	*node;

	size = 0;
	if (!list)
		return (0);
	node = list->start;
	while (node)
	{
		size += (int)ft_strlen((char *)node->content);
		node = node->next;
	}
	return (size);
}
