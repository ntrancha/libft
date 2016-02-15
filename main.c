/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/15 02:12:33 by ntrancha         ###   ########.fr       */
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
    int     a9;
    int     a8;
    int     a7;
    int     a6;
    int     a5;
    int     a4;
    int     a3;
    int     a2;
    int     a1;
    int     a0;
    int     count;
    int     rand;

    count = 0;
    a0 = 0;
    a1 = 0;
    a2 = 0;
    a3 = 0;
    a4 = 0;
    a5 = 0;
    a6 = 0;
    a7 = 0;
    a8 = 0;
    a9 = 0;
    while (++count < 5000)
    {
        rand = ft_random();
        if (rand == 0)
            a0++;
        if (rand == 1)
            a1++;
        if (rand == 2)
            a2++;
        if (rand == 3)
            a3++;
        if (rand == 4)
            a4++;
        if (rand == 5)
            a5++;
        if (rand == 6)
            a6++;
        if (rand == 7)
            a7++;
        if (rand == 8)
            a8++;
        if (rand == 9)
            a9++;
    }
    ft_putnbr(a0);
    ft_putstr(" ");
    ft_putnbr(a1);
    ft_putstr(" ");
    ft_putnbr(a2);
    ft_putstr(" ");
    ft_putnbr(a3);
    ft_putstr(" ");
    ft_putnbr(a4);
    ft_putstr(" ");
    ft_putnbr(a5);
    ft_putstr(" ");
    ft_putnbr(a6);
    ft_putstr(" ");
    ft_putnbr(a7);
    ft_putstr(" ");
    ft_putnbr(a8);
    ft_putstr(" ");
    ft_putnbr(a9);
    ft_putstr("\n");
}

FT_MAIN
