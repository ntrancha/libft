/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casedel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 05:37:43 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 06:07:31 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_case      *ft_casedel(t_case *cases, t_case *casedel)
{
    t_case  *jump;
    t_case  *prev;

    jump = cases;
    prev = NULL;
    if (cases == casedel && cases != NULL)
    {
        jump = casedel->next;
        ft_casedelete(casedel);
        return (jump);
    }
    while (jump)
    {
        if (jump == casedel)
        {
            prev->next = jump->next;
            ft_casedelete(casedel);
            return (cases);
        }
        prev = jump;
        jump = prev->next;
    }
    return (cases);
}
