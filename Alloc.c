/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:56:33 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 12:46:13 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/stack.h"

int     main(int argc, char **argv)
{
    t_stacks    *stack;
    char        *str;
    t_list      *a;
    t_list      *b;

    a = ft_listcreate();
    b = ft_listcreate();
    ft_listadd(a, ft_strdup("a"));
    ft_listadd(a, ft_strdup("b"));
    ft_listadd(a, ft_strdup("c"));
    ft_listadd(b, ft_strdup("z"));
    ft_listadd(b, ft_strdup("y"));
    ft_listfusion(a, b);
    ft_listputstr(a, ft_putendl);
    ft_listdel(a, ft_memdel);
    ft_listdel(b, ft_memdel);
    return (1);
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
