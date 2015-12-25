/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bag_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 08:03:37 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/25 08:08:25 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bag.h"
#include "../../includes/mem.h"

void		*ft_bag_get(t_bag *bag, char *var)
{
	t_var	*node;

	if (!bag || !var || !ft_bag_content(bag, var))
		return (NULL);
	node = bag->start;
	while (node)
		if (ft_strcmp(var, node->var) == 0)
			return (node->content);
		else
			node = node->next;
	return (NULL);
}
