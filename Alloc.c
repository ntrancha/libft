/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:56:33 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 01:30:04 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/stack.h"

int     main(int argc, char **argv)
{
    t_stacks    *stack;
    char        *str;

    ft_alloc("1", 2, "A", "str");
    ft_alloc(NULL, 2, "B", "str");
    ft_alloc("3", 2, "C", "str");
    ft_alloc_copy("B", "E");
    str = ft_strdup("a");
    ft_alloc_include(str, 7);
    ft_alloc("4", 2, "D", "str");
    ft_stack_infos();
    DEL(A);
    ft_stack_infos();
    ft_stack_free();
    ft_strdel(&str);
    return (1);
}
