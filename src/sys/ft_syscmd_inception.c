/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_inception.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:21:51 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/26 15:34:18 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/sys.h"
#include "../../includes/strings.h"

int         ft_syscmd_inception(char *var, char *func, char *options)
{
    char    **tab;
    char    *commande;
    char    *tmp;
    char    *var_tmp;
    int     index;
    int     count;
    int     test;

    tab = NULL;
    index = 0;
    if (ft_strcchr(options, ",") != 0)
    {
        tab = ft_strsplit(options, ',');
        while (tab[index])
        {
            if (ft_strcchr(tab[index], "(") != 0)
            {
                tmp = ft_itoa(index);
                var_tmp = ft_strjoin("TMP_", tmp);
                commande = ft_strmjoin(var_tmp, " = ", tab[index]);
                ft_syscmd(commande);
                ft_strdelth(&tmp, &var_tmp, &commande);
            }
            index++;
        }
        ft_tabstrdel(&tab);
    }
    else
    {
        tmp = ft_itoa(index);
        var_tmp = ft_strjoin("TMP_", tmp);
        commande = ft_strmjoin(var_tmp, " = ", options);
        ft_syscmd(commande);
        ft_strdelth(&tmp, &var_tmp, &commande);
    }
    count = -1;
    test = 0;
    commande = ft_strmmjoin(var, " = ", func, "(");
    while (++count < index -1)
    {
        tmp = ft_itoa(count);
        if (!test)
            var_tmp = ft_strmjoin(commande, "TMP_", tmp);
        else
            var_tmp = ft_strmjoin(commande, ", TMP_", tmp);
        ft_strdel(&commande);
        commande = ft_strdup(var_tmp);
        ft_strdelt(&tmp, &var_tmp);
        test++;
    }
    tmp = ft_strjoin(commande, ")");
    ft_strdelt(&tmp, &commande);
    ft_syscmd("TMP_0.del()");
    ft_syscmd("TMP_1.del()");
    ft_syscmd("TMP_2.del()");
    ft_syscmd("TMP_3.del()");
    ft_syscmd("TMP_4.del()");
    return (1);
}
