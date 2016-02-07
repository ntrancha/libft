/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liststrsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 17:45:47 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 19:55:37 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/list.h"
#include "../../includes/count.h"

size_t      ft_liststrsize(t_list *list)
{
    size_t 	len;

    len = (ft_liststrlen(list) + list->size) * sizeof(char);
    len += sizeof(t_node) * list->size;
    len += sizeof(t_list);
    return (len);
}
