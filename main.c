/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/14 23:49:12 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

char        *ft_getcwd(void)
{
    char    *str;
    int     size;

    size = 1;
    str = ft_strnew(size + 1);
    while (!getcwd(str, size))
    {
        ft_strdel(&str);
        size += 10;
        str = ft_strnew(size + 1);
    }
    return (str);
}

int         ft_main(void)
{
    char    **tab;
    char    *str;

    ft_timer(10);
    //ft_stack_infos();
}

FT_MAIN
