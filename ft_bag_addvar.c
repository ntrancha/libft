/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bag_addvar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 05:50:44 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/28 05:58:46 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/bag.h"

t_bag        *ft_bag_addvar(t_bag *bag, void *content, char *var)
{
    t_var   *node;

    if (!bag)
        bag = ft_bag_create();
    node = ft_memalloc(sizeof(t_var));
    if (!node || !bag)
        return (NULL);
    if (!content)
        node->content = NULL;
    else
        node->content = content;
    node->next = NULL;
    node->previous = bag->end;
    node->var = ft_strdup(var);
    if (!bag->end)
        bag->start = node;
    else
        bag->end->next = node;
    bag->end = node;
    bag->size++;
    return (bag);
}
