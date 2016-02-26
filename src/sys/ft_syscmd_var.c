/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:23:23 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/26 09:28:50 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"
#include "../../includes/test.h"
#include "../../includes/count.h"

static int  ft_syscmd_assigne(char *str)
{
    char    **tab;
    char    *var;
    char    *content;

    tab = ft_strsplit(str, '=');
    var = ft_strcleanback(tab[0], ' ');
    content = ft_strcleanfront(tab[1], ' ');
    if (ft_strisnum(content) == 1)
        ft_sysint_alloc(ft_atoi(content), var);
    else
        ft_calloc_erase((void*)content, ft_strlen(content) + 1, var, "str");
    ft_strdelt(&var, &content);
    ft_tabstrdel(&tab);
    return (1);
}

int         ft_syscmd_var(char *str)
{
    char    **tab;
    char    *tmp;
    char    *commande;
    char    *option;
    char    *var;

    if (ft_strcchr(str, ")") == 0)
        return (ft_syscmd_assigne(str));
    tab = ft_strsplit(str, '=');
    var = ft_strcleanback(tab[0], ' ');
    commande = ft_strcleanfront(tab[1], ' ');
    tmp = ft_strsub(commande, 0, ft_strlen(commande) - 1);
    if (tmp[ft_strlen(tmp) - 1] == '(')
        option = ft_strmjoin(tmp, var, ")");
    else
        option = ft_strmmjoin(tmp, ", ", var, ")");
    ft_syscmd(option);
    ft_strdelf(&var, &commande, &tmp, &option);
    ft_tabstrdel(&tab);
    return (0);
}
