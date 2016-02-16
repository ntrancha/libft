/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:26:28 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/16 16:30:38 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void        ft_debug(char *file, int line)
{
    char    *str;

    if (file)
    {
        str = ft_strdup(file);
        ASTR(str, "__FILE__");
        str = ft_itoa(line);
        ASTR(str, "__LINE__");
    }
}
