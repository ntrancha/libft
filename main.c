/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/17 08:13:57 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int         ft_main(void)
{
    int     *a;
    int     num;

    DEBUG;
    a = ft_memalloc(sizeof(int));
    *a = 42;
    ft_alloc_create(a, 1, "INT", "int");
    DEBUG;
    ft_stack_infos();
    return 1;
}

FT_MAIN
