/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optgetopt_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 21:08:18 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:31:59 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/opt.h"
#include "../../includes/list.h"
#include "../../includes/strings.h"
#include "../../includes/mem.h"

char        *ft_optgetopt_double(t_opt *options, char *opt)
{
    char    *tmp;
    t_node  *node;
    t_node  *option;

    tmp = NULL;
    if (ft_opttest(options, opt) < 1)
        return (NULL);
    node = ((t_list*)options)->start;
    while (node)
        if (ft_strcmp((char*)node->content, opt) == 0)
        {
            option = node->next;
            if (!option)
                tmp = ft_strdup((char *)node->content);
            ft_listdelnode((t_list *)options, node, ft_memdel);
            if (!option)
                return (tmp);
            tmp = ft_strdup((char *)option->content);
            ft_listdelnode((t_list *)options, option, ft_memdel);
            return (tmp);
        }
        else
            node = node->next;
    return (NULL);
}
