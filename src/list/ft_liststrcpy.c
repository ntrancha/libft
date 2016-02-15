/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liststrcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 07:43:47 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/15 23:53:05 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/strings.h"

t_list      *ft_liststrcpy(t_list *list)
{
    t_list  *new;
    t_node  *node;

    if (!list || !list->size || !(new = ft_listcreate()))
        return (NULL);
    node = list->start;
    while (node)
    {
        if (!ft_listadd(new, (void*)(ft_strdup((char*)node->content))))
        {
            ft_listdel(&new, ft_memdel);
            return (NULL);
        }
        node = node->next;
    }
    return (new);
}
