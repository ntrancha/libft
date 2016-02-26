/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sys_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:16:27 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/26 15:28:15 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"
#include "../../includes/count.h"
#include "../../includes/put.h"

static int      sizeofpile(t_pile *pile)
{
    int         ret;

    ret = 0;
    while (pile)
    {
        ret++;
        pile = pile->next;
    }
    return (ft_nbrlen(ret) - 1);
}

static void     put_color(char *str)
{
    char        *tmp;

    tmp = ft_strdup(str);
    ft_putstr(C_BLUE);
    ft_putendl(tmp);
    ft_putstr(C_NULL);
    ft_strdel(&tmp);
}

void            ft_sys_print(void)
{
    t_stacks    *stack;
    t_pile      *pile;
    int         size;

    stack = ft_stack_init();
    pile = stack->pile;
    size = sizeofpile(pile);
    while (pile)
    {
        ft_putspace(size - ft_nbrlen(pile->line));
        ft_putstr(C_YELLOW);
        ft_putnbr(pile->line);
        ft_putstr(": ");
        ft_putstr(C_NULL);
        if (stack->offset == pile->line)
        {
            ft_putstr_color(pile->instruction, C_GREEN);
            ft_putendl("");
        }
        else
            put_color(pile->instruction);
        pile = pile->next;
    }
}
