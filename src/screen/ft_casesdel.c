/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casesdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 05:43:30 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:07:37 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen.h"

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
