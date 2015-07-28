/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bag_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 05:49:48 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/28 05:50:29 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/bag.h"

t_bag       *ft_bag_create(void)
{
    t_bag   *bag;

    bag = ft_memalloc(sizeof(t_bag));
    if (!bag)
        return (NULL);
    bag->size = 0;
    bag->start = NULL;
    bag->end = NULL;
    return (bag);
}
