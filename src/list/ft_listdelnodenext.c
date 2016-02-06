/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdelnodenext.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 11:35:44 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/06 11:15:27 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

t_node	    *ft_listdelnodenext(t_list *lst, t_node *n, void (del)(void **))
{
	t_node	*next;

	next= NULL;
	if (lst && n)
	{
		next = n->next;
		ft_listdelnode(lst, n, del);
	}
	return (next);
}
