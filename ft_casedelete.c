/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casedelete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 06:01:32 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 21:23:16 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

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
