/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 12:33:56 by ntrancha          #+#    #+#             */
/*   Updated: 2016/03/01 12:49:18 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"
#include "../../includes/put.h"

void            ft_syscmd_if(char *str)
{
    char        **tab;
    char        *condition;

    tab = ft_strsplit(str, '(');
    if (tab && tab[1])
    {
        condition = ft_strsub(tab[1], 0, ft_strlen(tab[1]) - 1);
        //traiter la condition jusqu'a true/false

        //avancer l'offset en fonction
        ft_putendl(condition);
        ft_strdel(&condition);
        ft_tabstrdel(&tab);
    }
}
