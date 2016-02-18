/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/18 16:19:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int         ft_main(void)
{
    size_t  (*ptr)(const char *);
    char    *str;

    DEBUG;
    ptr = &ft_strlen;
    ft_calloc(ptr, 50, "DUMP STACK", "mem");
    CSTR("-42", "test_convert");
    ft_alloc_cnvrt("test_convert", "int");
    ft_alloc_cnvrt("test_convert", "str");
    ft_stack_infos();
    str = ft_getkey();
    ft_putnbr_endl((int)str[0]);
    ft_putnbr_endl((int)str[1]);
    ft_putnbr_endl((int)str[2]);
    return 1;
}

FT_MAIN
