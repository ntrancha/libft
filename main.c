/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/21 14:27:20 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

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

int         ft_main(void)
{
    size_t  (*ptr)(const char *);
    size_t  (*ptr2)(int);
    int     num;

    DBG_FILE;
    DBG_PROG;

    num = 0;
    /*ft_putendl(ft_alloc_convert("ft_opt", "int"));*/
    ft_alloc_convert("OPTIONS", "mem");
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
