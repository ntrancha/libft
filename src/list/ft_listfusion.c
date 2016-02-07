/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listfusion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 12:19:43 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 12:45:47 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list      *ft_listfusion(t_list *first, t_list *second)
{
    t_node  *f_node;
    t_node  *s_node;

    if (!first || !first->start)
        return (NULL);
    if (!second || !second->start)
        return (first);
    f_node = first->end;
    s_node = second->start;
    first->size += second->size;
    f_node->next = s_node;
    s_node->previous = f_node;
    first->end = second->end;
    second->start = NULL;
    second->end = NULL;
    second->size = 0;
    return (first);
}
