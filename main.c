/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/19 21:21:29 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int         ft_main(void)
{
    size_t  (*ptr)(const char *);
    char    **dos;
    int     fork;

    DBG_FILE;
    DBG_PROG;
    ft_alloc_copy("OPTIONS", "OPTIONS2");
    dos = ft_getdirtab(".", NULL);
    ft_alloc(dos, ft_tabstrlen(dos), "TAB", "tabstr"); 
    ft_alloc_fusion("DOS_PROG", "OPTION_1", "NEW");
    ft_alloc_fusion("TAB", "TAB", "NEW_TAB");
    ptr = &ft_strlen;
    ft_calloc(ptr, 48, "DUMP STACK", "mem");
    ft_stack_infos();
    return 1;
}

FT_MAIN
