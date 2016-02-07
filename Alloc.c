/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:56:33 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 16:28:17 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/stack.h"

int     main(int argc, char **argv)
{
    t_stacks    *stack;

    ft_alloc("1", 2, "A", "str");
    ft_alloc(NULL, 2, "B", "str");
    ft_alloc("3", 2, "C", "str");
    ft_alloc_copy("B", "E");
    ft_alloc("4", 2, "D", "str");
    DEL(A);
    ft_stack_infos();
    ft_stack_free();
    return (1);
}
