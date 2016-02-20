/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/20 03:19:11 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int         ft_main(void)
{
    size_t  (*ptr)(const char *);
    size_t  (*ptr2)(int);
    char    *str;
    char    **dos;
    int     fork;

    DBG_FILE;
    DBG_PROG;
    ptr = &ft_strlen;
    ft_calloc(ptr, 8, "DUMP1", "mem");
    ptr2 = &ft_nbrlen;
    ft_calloc(ptr2, 8, "DUMP2", "mem");
    ft_alloc_fusion("DUMP1", "DUMP2", "DUMP1 + DUMP2");
    ft_stack_infos();
    str = ft_strdup("éà");
    ft_putnbr_endl((int)str[0]);
    ft_putnbr_endl((int)str[1]);
    ft_putnbr_endl((int)str[2]);
    ft_putnbr_endl((int)str[3]);
    ft_putnbr_endl((int)str[4]);
    ft_putnbr_endl((int)ft_strlen("éeeàæ‰é"));
    ft_putnbr_endl((int)ft_wstrlen("éeeàæ‰é"));
    str = ft_strdup("æ‰*");
    ft_putnbr_endl(str[0]);
    ft_putnbr_endl(str[1]);
    ft_putnbr_endl(str[2]);
    ft_putnbr_endl(str[3]);
    ft_putnbr_endl(str[4]);
    ft_putnbr_endl(str[5]);
    ft_putendl("éà@");
    ft_putendl("");
    ft_putnbr_endl((int)sizeof(wchar_t));
    ft_putnbr_endl((int)sizeof(char));
    return 1;
}

FT_MAIN
