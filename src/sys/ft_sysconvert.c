/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysconvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:18:54 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/20 00:51:29 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sys.h"
#define SRC_CONTENT     ((t_alloc*)src)->content
#define SRC_NAME        ((t_alloc*)src)->name

static void ft_sysliststr_to_tabstr(void *src, char *dst)
{
    t_list  *list;
    t_node  *node;
    char    **tab;
    char    *old;
    int     count;

    list = (t_list*)SRC_CONTENT;
    if ((tab = ft_memalloc(sizeof(char*) * (ft_listlen(list) + 1))))
        if ((old = ft_strdup(SRC_NAME)))
        {
            node = list->start;
            count = 0;
            while (node && dst)
            {
                tab[count++] = ft_strdup((char*)node->content);
                node = node->next;
            }
            tab[count] = '\0';
            ft_alloc_erase((void*)tab, sizeof(char**), old, "tabstr"); 
            ft_strdel(&old);
        }
}

static void ft_systabstr_to_liststr(void *src, char *dst)
{
    t_list  *new;
    char    **tab;
    char    *old;
    int     count;

    if ((new = ft_listcreate()))
        if ((old = ft_strdup(SRC_NAME)))
        {
            tab = (char**)SRC_CONTENT;
            count = -1;
            while (tab[++count] && dst)
                ft_listadd(new, (void*)ft_strdup(tab[count]));
            ft_alloc_erase((void*)new, sizeof(t_list), old, "liststr"); 
            ft_strdel(&old);
        }
}

void    ft_sysconvert(void)
{
    ft_sysstr_convert();
    ft_alloc_cnvrt_add("liststr", "tabstr", ft_sysliststr_to_tabstr);
    ft_alloc_cnvrt_add("tabstr", "liststr", ft_systabstr_to_liststr);
}
