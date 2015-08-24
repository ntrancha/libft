/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optgetopt_simple.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 21:07:48 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:33:11 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/opt.h"
#include "../../includes/list.h"
#include "../../includes/strings.h"
#include "../../includes/mem.h"

char        *ft_optgetopt_simple(t_opt *options, char *opt)
{
    t_node  *node;
    char    *tmp;

    if (ft_opttest(options, opt) < 1)
        return (NULL);
    node = ((t_list*)options)->start;
    tmp = NULL;
    while (node)
        if (ft_strcmp((char*)node->content, opt) == 0)
        {
            tmp = ft_strdup((char *)node->content);
            if (!tmp)
                return (NULL);
            ft_listdelnode((t_list *)options, node, ft_memdel);
            return (tmp);
        }
        else
            node = node->next;
    return (NULL);
}
