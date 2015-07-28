/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bag_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 05:55:29 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/28 05:55:45 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/bag.h"

int     ft_bag_content(t_bag *bag, char *var)
{
    t_var   *node;

    if (!bag)
        return (-1);
    node = bag->start;
    while (node)
        if (ft_strcmp(var, node->var) == 0)
            return (1);
        else
            node = node->next;
    return (0);
}
