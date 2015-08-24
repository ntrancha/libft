/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caseadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 05:22:37 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:05:15 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen.h"
#include "../../includes/strings.h"

t_case      *ft_caseadd(t_case *cases, char *str, char *spec)
{
    t_case  *new;
    t_case  *jump;

    if (cases && str)
    {
        jump = cases;
        while (jump->next)
            jump = jump->next;
        new = ft_casescreate();
        new->str = ft_strdup(str);
        if (spec)
            new->spec = ft_strdup(spec);
        jump->next = new;
    }
    else if (!cases)
    {
        cases = ft_casescreate();
        cases->str = ft_strdup(str);
        if (spec)
            cases->spec = ft_strdup(spec);
    }
    return (cases);
}
