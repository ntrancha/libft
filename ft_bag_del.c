/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bag_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 05:54:24 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/28 05:55:17 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/bag.h"

void    ft_bag_del(t_bag *bag, void(del)(void**))
{
    t_var   *node;

    if (bag)
    {
        node = bag->start;
        while (node)
            node = ft_bag_delnode(bag, node, del);
        ft_memdel((void**)&bag);
    }
}
