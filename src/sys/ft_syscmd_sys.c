/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_sys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:12:42 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/26 09:13:32 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/stack.h"
#include "../../includes/sys.h"

void    ft_syscmd_sys(char *str)
{
    if (ft_strcmp(str, "#INFOS") == 0)
        ft_stack_infos();
    if (ft_strcmp(str, "#DBG_PROG") == 0)
        DBG_PROG;
    if (ft_strcmp(str, "#STACK") == 0)
        ft_sys_print();
}
