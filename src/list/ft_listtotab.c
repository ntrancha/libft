/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listtotab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 23:01:20 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/22 23:08:46 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"
#include "../../includes/mem.h"
#include "../../includes/strings.h"

char        **ft_listtotab(t_list *list)
{
    int     count;
    char    **tab;
    t_node  *node;

    if (list == NULL)
        return (NULL);
    count = (int)ft_listlen(list);
    tab = ft_memalloc(sizeof(char*) * (count + 1));
    if (tab == NULL)
        return (NULL);
    node = list->start;
    count = 0;
    while (node)
    {
        tab[count++] = ft_strdup(node->content);
        node = node->next;
    }
    tab[count] = NULL;
    return (tab);
}

