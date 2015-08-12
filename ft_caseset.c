/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caseset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 00:50:32 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/12 21:22:28 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int         ft_caseset(t_case *cases, int num, char *str, char *spec)
{
    if (!cases || num < 0)
        return (-1);
    while (cases)
    {
        if (num == 0)
        {
            if (str)
            {
                if (cases->str)
                    ft_strdel(&cases->str);
                cases->str = ft_strdup(str);
            }
            if (spec)
            {
                if (cases->spec)
                    ft_strdel(&cases->spec);
                cases->spec = ft_strdup(spec);
            }
            return (1);
        }
        num--;
        cases = cases->next;
    }
    return (-1);
}
