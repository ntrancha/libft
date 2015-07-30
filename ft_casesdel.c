/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casesdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 05:43:30 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 06:06:19 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void        ft_casesdel(t_case *cases)
{
    t_case  *next;

    while (cases)
    {
        next = cases->next;
        ft_casedelete(cases);
        cases = next;
    }
}
