/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysfunc_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:45:43 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/23 11:46:48 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/sys.h"
#include "../../includes/strings.h"

t_funcs     *ft_sysfunc_find(t_funcs *funcs, char *name)
{
    while (funcs)
    {
        if (ft_strcmp(name, funcs->name) == 0)
            return (funcs);
        funcs = funcs->next;
    }
    return (NULL);
}
