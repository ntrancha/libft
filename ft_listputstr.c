/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listputstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 07:46:33 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/30 07:46:33 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

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
