/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/20 14:11:30 by ntrancha         ###   ########.fr       */
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

    DBG_FILE;
    DBG_PROG;

    ptr = &ft_strlen;
    ft_alloc_cnvrt("OPTIONS", "liststr");
    ft_alloc_cnvrt("OPTIONS", "tabstr");
    ft_alloc_cnvrt("OPTIONS", "mem");
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
