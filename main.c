/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/08 19:30:07 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void        ft_man(void)
{
    int     status;
    char    *buffer;
    int     ret;
    int     col;

    status = 1;
    buffer = NULL;
    col = ft_atoi(GET(COL_PROG));
    ft_putcenter("MAN LIBFT", col);
    ft_putendl("");
    while (status)
    {
        ret = ft_readstdin(&buffer);
        if (ft_strcmp(buffer, "exit\n") == 0)
            status = 0;
        ft_putstr(":");
        ft_putstr(buffer);
        ft_strdel(&buffer);
    }
}

int         ft_main(void)
{
    ft_stack_infos();
    ft_man();
}

FT_MAIN
