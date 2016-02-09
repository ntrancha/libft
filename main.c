/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/09 09:20:58 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void        ft_mandisplay(char *lib)
{
    char    *path;
    char    *content;
    char    **tab;
    int     index;

    index = -1;
    ft_putendl(lib);
    path = ft_strmjoin("conf/man/", lib, ".man");
    content = ft_get_file(path);
    tab = ft_strsplit(content, '\n');
    while (tab[++index])
    {
        ft_putendl(tab[index]);
    }
    ft_tabstrdel(tab);
    ft_strdel(&path);
    ft_strdel(&content);
}

void        ft_man(void)
{
    int     status;
    char    *buffer;
    char    *man;
    int     ret;
    int     col;

    status = 1;
    buffer = NULL;
    col = ft_atoi(GET(COL_PROG));
    XSTR(libft, MAN_LIB);
    ft_putcenter("MAN LIBFT", col);
    ft_putendl("");
    while (status)
    {
        ft_mandisplay(GET(MAN_LIB));
        ret = ft_readstdin(&buffer);
        if (ft_strcmp(buffer, "exit\n") == 0)
            status = 0;
        ft_strdel(&buffer);
    }
}

int         ft_main(void)
{
    char    **tab;

    tab = ft_getdirtab_f(".", NULL, 'd');
    ft_calloc(tab, ft_tabstrlen(tab) + 1, "TAB_TEST", "tabstr"); 
    ft_stack_infos();
    //ft_man();
}

FT_MAIN
