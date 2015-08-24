/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listcontent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 06:49:51 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:32:56 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

int			ft_listcontent(t_list *list, t_node *node)
{
	t_node  *tmp;

	tmp = list->start;
	while (tmp)
	{
		if (tmp == node)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
