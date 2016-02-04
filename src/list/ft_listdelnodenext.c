/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdelnodenext.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 11:35:44 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/03 23:45:32 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

t_node	    *ft_listdelnodenext(t_list *lst, t_node *node, void (del)(void **))
{
	t_node	*next;

	next= NULL;
	if (lst && node)
	{
		next = node->next;
		ft_listdelnode(lst, node, del);
	}
	return (next);
}
