/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:22:42 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/26 09:28:17 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"

int         ft_syscmd_base(char *var, char *func, char *options)
{
    int     base;
    char    **tab;

    if (ft_strcchr(options, ",") != 0)
        tab = ft_strsplit(options, ',');
    base = ft_vartype_func(func);
    if (base == 1)
        ft_alloc_del(var);
    if (base == 2)
        ft_alloc_put(var);
    if (base == 3 && options && ft_strcchr(options, ",") == 0)
        ft_alloc_copy(var, options);
    if (base == 4 && options && ft_strcchr(options, ",") == 1)
        ft_sysint_alloc(ft_alloc_cmp(var, tab[0]), tab[1]);
    if (base == 5 && options && ft_strcchr(options, ",") == 1)
        ft_alloc_fusion(var, tab[0], tab[1]);
    if (base == 6 && options && ft_strcchr(options, ",") == 0)
        ft_sysint_alloc(ft_alloc_len(var), options);
    if (base == 7 && options && ft_strcchr(options, ",") == 0)
        ft_sysint_alloc(ft_alloc_count(var), options);
    if (base == 8 && options && ft_strcchr(options, ",") == 0)
        ft_alloc_convert(var, options);
    if (ft_strcchr(options, ",") != 0)
        ft_tabstrdel(&tab);
    return (1);
}
