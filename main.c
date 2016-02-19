/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/20 00:53:30 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int         ft_main(void)
{
    size_t  (*ptr)(const char *);
    size_t  (*ptr2)(int);
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
    return 1;
}

FT_MAIN
