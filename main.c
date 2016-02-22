/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/22 17:09:36 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int         testb(void *v, void *d)
{
    v = d;
    d = v;
    return (-42);
}

int         testa(void *v)
{
    if (v)
        return (42);
    return (4242);
}

void        testons(char *str)
{
    int     index;

    index = -1;
    while (str[++index])
        if (str[index] != 42)
            ft_putnbr_endl(str[index]);
        else
            ft_putendl("");
    ft_putendl(str);
}

void        func(char *name, char *func_name, void *function)
{
    t_func  *func;

    name = func_name;
    func_name = name;
    func = ft_memalloc(sizeof(t_func));
    func->f_int_a = function;
    ft_putnbr_endl(func->f_int_a(NULL));
}

int         ft_main(void)
{
    size_t  (*ptr)(const char *);
    size_t  (*ptr2)(int);
    char    **tab;

    DBG_FILE;
    DBG_PROG;

    func(NULL, NULL, testb);
    /*ft_putendl(ft_alloc_convert("ft_opt", "int"));*/
    ft_alloc_convert("OPTIONS", "tabstr");
    tab = (char**)ft_alloc_vget("OPTIONS");
    ft_tabstrsort(&tab, -1);
    ptr = &ft_strlen;
    ft_calloc(ptr, 8, "DUMP1", "mem");
    ptr2 = &ft_nbrlen;
    ft_calloc(ptr2, 8, "DUMP2", "mem");
    ft_alloc_fusion("DUMP1", "DUMP2", "DUMP1 + DUMP2");
    ft_stack_infos();
    /*testons("*æ*‰*€*ß*α*⠇*ฆ*☮*♒*♣*⌦*⌥*━*␥*▓*♫*♂");*/
    /*testons("*æ*‰*€*ß*α*⠇*ฆ");*/
    /*ft_putnbr_endl(ft_strlen("*æ*‰*€*ß*α*⠇*ฆ"));*/
    /*ft_putnbr_endl(ft_wstrlen("*æ*‰*€*ß*α*⠇*ฆ"));*/
    return 1;
}

FT_MAIN
