/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 19:37:41 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/08 19:40:08 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t      ft_tabstrlen(char **str)
{
    int     index;
    size_t  size;

    index = -1;
    size = 0;
    if (!str)
        return (0);
    while (str[++index])
        size += ft_strlen(str[index]);
    return (size);
}
