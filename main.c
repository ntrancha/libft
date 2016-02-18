/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/18 19:41:29 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void        parent(void)
{
    ft_putendl("parent");
}

void        child(void)
{
    ft_putendl("enfant");
}

int         ft_main(void)
{
    size_t  (*ptr)(const char *);
    char    *str;
    int     fork;

    DEBUG;
    ptr = &ft_strlen;
    ft_calloc(ptr, 50, "DUMP STACK", "mem");
    CSTR("-42", "test_convert");
    ft_alloc_cnvrt("test_convert", "int");
    ft_alloc_cnvrt("test_convert", "str");
    str = ft_getkey();
    ft_putnbr_endl((int)str[0]);
    ft_putnbr_endl((int)str[1]);
    ft_putnbr_endl((int)str[2]);
    ft_strdel(&str);
    ft_stack_infos();
    str = ft_read_psswd();
    ft_putendl(str);
    ft_strdel(&str);
    fork = ft_fork_goto(parent, child);
    if (fork != 0)
        fork = ft_fork_goto(parent, child);
    if (fork != 0)
        ft_putnbr_endl(fork);
    return 1;
}

FT_MAIN
