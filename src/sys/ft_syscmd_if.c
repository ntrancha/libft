/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 12:33:56 by ntrancha          #+#    #+#             */
/*   Updated: 2016/03/02 23:16:02 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"
#include "../../includes/put.h"

static void     syscmd_if(int ret)
{
   int          offset;

   offset = ft_stack_offset();
   if (ret)
       ft_putendl(ft_stack_instruction(offset + 1));
}

void            ft_syscmd_if(char *str)
{
    char        *inside;
    char        *old;
    char        *ret;
    char        *tmp;

    tmp = ft_strsub(str, 3, ft_strlen(str) - 3);
    while (!ft_strisnum(tmp) && ft_strcchr(tmp, "(") != 0)
    {
        if (ft_strcchr(tmp, "(") != 0 && ft_strcchr(tmp, ")") != 0)
            inside = ft_strinside(tmp, '(', ')');
        else
            inside = ft_strdup(tmp);
        old = ft_strmjoin("(", inside, ")");
        ret = ft_itoa(ft_syscmd_resolve_all(inside));
        ft_strreplace(&tmp, old, ret, -1);
        ft_strdelth(&inside, &ret, &old);
    }
    syscmd_if(ft_atoi(tmp));
    ft_strdel(&tmp);
}
