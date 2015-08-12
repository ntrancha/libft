/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdelnodenext.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 11:35:44 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/12 21:26:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_node	    *ft_listdelnoden(t_list *list, t_node *node, void (del)(void **))
{
	t_node	*next;

	next= NULL;
	if (list && node)
	{
		next = node->next;
		ft_listdelnode(list, node, del);
	}
	return (next);
}
