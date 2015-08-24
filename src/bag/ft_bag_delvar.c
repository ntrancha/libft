/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bag_delvar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 05:51:31 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 05:57:52 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bag.h"
#include "../../includes/strings.h"

t_var       *ft_bag_delvar(t_bag *bag, char *var, void(del)(void **))
{
    t_var   *node;

    if (!bag)
        return (NULL);
    node = bag->start;
    while (node)
        if (ft_strcmp(var, node->var) == 0)
            return (ft_bag_delnode(bag, node, del));
        else
            node = node->next;
    return (NULL);
}
