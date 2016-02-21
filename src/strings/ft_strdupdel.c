/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 13:35:05 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/21 13:36:59 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

char    *ft_strdupdel(char *dup, char **del)
{
    if (!dup)
        return (NULL);
    if (del && *del)
        ft_strdel(del);
    *del = ft_strdup(dup);
    return (*del);
}
