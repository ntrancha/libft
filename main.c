/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/16 01:27:22 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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
    ft_tabstrdel(&tab);
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
    //ft_putnbr_endl((int)ft_get_timestamp());
    //ft_putnbr_endl((int)ft_time());
    ft_stack_infos();
    /*ft_putnbr_endl(ft_rand(1,10));
    ft_putnbr_endl(ft_rand(1,10));
    ft_putnbr_endl(ft_rand(1,10));
    ft_putnbr_endl(ft_rand(1,10));
    ft_putnbr_endl(ft_rand(1,100));
    ft_putnbr_endl(ft_rand(1,100));
    ft_putnbr_endl(ft_rand(1,100));
    ft_putnbr_endl(ft_rand(1,100));
    ft_putnbr_endl(ft_rand(1,100));
    ft_putnbr_endl(ft_rand(1,100));
    ft_putnbr_endl(ft_random());
    ft_putnbr_endl(ft_random());
    ft_putnbr_endl(ft_random());*/
    return 1;
}

FT_MAIN
