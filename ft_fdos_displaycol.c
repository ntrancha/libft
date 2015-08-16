/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdos_displaycol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 00:26:26 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/17 00:32:08 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static t_file       *fileinfo_get(t_node *node)
{
    return (node->content);
}

int             ft_namefiles_max(t_fdos *list, int colone, int colones)
{
    t_node      *node;
    int         count;
    int         max;

    max = 0;
    if (list && colones > 0 && colone > 0)
    {
        node = list->start;
        count = 1;
        while (count++ < colone)
            node = node->next;
        while (node)
        {
            if (max < (int)ft_strlen(fileinfo_get(node)->name))
                max = ft_strlen(fileinfo_get(node)->name);
            count = 0;
            while (count++ < colones && node)
                node = node->next;
        }
    } 
    return (max);
}

int             ft_namefiles_all(t_fdos *list, int col)
{
    int         colone;
    int         ret;

    colone = 1;
    ret = 0;
    while (colone <= col)
        ret += ft_namefiles_max(list, colone++, col) + 2;
    return (ret);
}

int             ft_findcol_opti(t_fdos *list)
{
    int         col;
    int         ret;

    col = ft_getcol();
    ret = 1;
    while (col > ft_namefiles_all(list, ret))
        ret++;
    return (ret - 1);
}

void            ft_fdos_displaycol(t_fdos *list, int col)
{
    t_node      *node;
    int         count;
    int         count2;
    int         max;

    count = 0;
    col = ft_findcol_opti(list);
    if (list)
    {
        node = list->start;
        while (node)
        {
            count++;
            if (count > col)
            {
                ft_putchar('\n');
                count = 1;
            }
            ft_putstr(fileinfo_get(node)->name);
            count2 = ft_strlen(fileinfo_get(node)->name);
            max = ft_namefiles_max(list, count, col); 
            while (count2++ < max + 2)
                ft_putchar(' ');
            node = node->next;
        }
        ft_putchar('\n');
    }
}
