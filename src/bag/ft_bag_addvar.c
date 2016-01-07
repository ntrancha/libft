/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bag_addvar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 05:50:44 by ntrancha          #+#    #+#             */
/*   Updated: 2016/01/05 13:51:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bag.h"
#include "../../includes/mem.h"
#include "../../includes/strings.h"

t_bag        *ft_bag_addvar(t_bag *bag, void *content, char *var)
{
    t_var   *node;

    if (!bag || !var || ft_bag_content(bag, var))
        return (NULL);
    node = ft_memalloc(sizeof(t_var));
    if (!node)
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
