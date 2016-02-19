/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/19 11:02:17 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int         ft_main(void)
{
    size_t  (*ptr)(const char *);
    char    *str;
    int     fork;

    DEBUG;
    ptr = &ft_strlen;
    ft_calloc(ptr, 48, "DUMP STACK", "mem");
    CSTR("42", "test_convert");
    ft_alloc_cnvrt("test_convert", "int");
    ft_alloc_cnvrt("test_convert", "str");
    ft_alloc_cnvrt("test_convert", "mem");
    /*ft_sysint_alloc(42, "42");*/
    /*ft_alloc_cnvrt("42", "mem");*/
    ft_stack_infos();
    return 1;
}

FT_MAIN
