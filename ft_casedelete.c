/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casedelete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 06:01:32 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/12 21:19:08 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

void    ft_casedelete(t_case *cases)
{
    if (cases != NULL)
    {
        if (cases->str != NULL)
            ft_strdel(&cases->str);
        if (cases->spec != NULL)
            ft_strdel(&cases->spec);
        free(cases);
    }
}
