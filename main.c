/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/19 21:31:00 by ntrancha         ###   ########.fr       */
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
    ptr = &ft_strlen;
    ft_calloc(ptr, 96, "DUMP STACK", "mem");
    ft_stack_infos();
    return 1;
}

FT_MAIN
