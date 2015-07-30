/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casendel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 05:27:13 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 06:07:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_case      *ft_casendel(t_case *cases, int num)
{
    t_case  *jump;
    t_case  *prev;
    int     index;

    jump = cases;
    prev = NULL;
    index = 0;
    if (num == 0 && cases != NULL)
    {
        jump = cases->next;
        ft_casedelete(cases);
        return (jump);
    }
    while (jump)
    {
        if (index == num)
        {
            prev->next = jump->next;
            ft_casedelete(jump);
            return (cases);
        }
        prev = jump;    
        jump = prev->next;
    }
    return (cases);
}
