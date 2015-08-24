/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bag_delnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 05:52:58 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 05:57:35 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bag.h"
#include "../../includes/mem.h"

t_var   *ft_bag_delnode(t_bag *bag, t_var *node, void (del)(void **))
{
    t_var   *ret;

    if (node->next)
        ret = node->next;
    else
        ret = node->previous;
    if (node->previous)
        node->previous->next = node->next;
    if (node->next)
        node->next->previous = node->previous;
    if (bag->end == node)
        bag->end = node->previous;
    if (bag->start == node)
        bag->start = node->next;
    if (node->content)
        del(&(node->content));
    bag->size--;
    ft_memdel((void**)&node);
    return (ret);
}
