/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casedelete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 06:01:32 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:06:43 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen.h"
#include "../../includes/strings.h"
#include "../../includes/mem.h"

void    ft_casedelete(t_case *cases)
{
    if (cases != NULL)
    {
        if (cases->str != NULL)
            ft_strdel(&cases->str);
        if (cases->spec != NULL)
            ft_strdel(&cases->spec);
        ft_memdel((void**)&cases);
    }
}
