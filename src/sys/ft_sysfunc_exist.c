/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysfunc_exist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:11:43 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/23 11:14:09 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/sys.h"
#include "../../includes/strings.h"

int ft_sysfunc_exist(t_funcs *funcs, char *name)
{
    while (funcs)
    {
        if (ft_strcmp(name, funcs->name) == 0)
            return (1);
        funcs = funcs->next;
    }
    return (0);
}
