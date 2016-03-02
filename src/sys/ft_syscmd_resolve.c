/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_resolve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 22:03:12 by ntrancha          #+#    #+#             */
/*   Updated: 2016/03/02 22:06:54 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/sys.h"


int         return_int(char *str)
{
    int     type;
    int     *tmp;

    type = ft_syscmd_vartype(str);
    if (type == 11)
    {
        tmp = ft_alloc_vget(str);
        return (*tmp);
    }
    else if (type == 1)
        return (ft_atoi(str));
    return (0);
}

char        *return_str(char *str)
{
    int     type;
    char    *ret;

    type = ft_syscmd_vartype(str);
    if (type == 22)
    {
        ret = (char*)ft_alloc_vget(str);
        return (ret);
    }
    else if (type == 2)
        return (str);
    return (NULL);
}

int         ft_syscmd_resolve(char *one, char *two, char *operation)
{
    int     t_one;
    int     t_two;

    t_one = ft_syscmd_vartype(one);
    t_two = ft_syscmd_vartype(two);
    if ((t_one == 11 || t_one == 1) && (t_two == 11 || t_two == 1))
        return (ft_syscmd_op_int(return_int(one), return_int(two) , operation));
    if ((t_one == 22 || t_one == 2) && (t_two == 22 || t_two == 2))
        return (ft_syscmd_op_str(return_str(one), return_str(two) , operation));
    return (0);
}
