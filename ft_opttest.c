/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opttest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 21:06:26 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/28 21:06:53 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int         ft_opttest(t_opt *options, char *opt)
{
    t_node  *node;

    if (!opt || !options)
        return (-1);
    node = options->start;
    while (node)
        if (ft_strcmp((char*)node->content, opt) == 0)
            return (ft_isopt((char *)node->content));
        else
            node = node->next;
    return (0);
}
