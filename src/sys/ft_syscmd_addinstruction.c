/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_addinstruction.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:02:25 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/26 09:27:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/sys.h"
#include "../../includes/mem.h"
#include "../../includes/strings.h"

static t_pile   *ft_syscmd_newinstruction(char *str)
{
    t_pile      *new;
    t_pile      *pile;
    t_stacks    *stack;

    if (!(stack = ft_stack_init()))
        return (NULL);
    pile = stack->pile;
    while (pile && pile->next)
        pile = pile->next;
    if (!(new = ft_memalloc(sizeof(t_pile))))
        return (NULL);
    new->instruction = ft_strdup(str);
    new->ret = 0;
    if (!pile)
    {
        stack->pile = new;
        new->line = 1;
    }
    else
    {
        pile->next = new;
        new->line = pile->line + 1;
    }
    return (new);
}

static t_pile   *ft_syscmd_pile_offset(int offset)
{
    t_stacks    *stack;
    t_pile      *pile;

    stack = ft_stack_init();
    pile = stack->pile;
    while (pile)
    {
        if (offset == pile->line)
            return (pile);
        pile = pile->next;
    }
    return (NULL);
}

static void     ft_syscmd_pile(void)
{
    t_stacks    *stack;
    t_pile      *pile;

    stack = ft_stack_init();
    stack->offset++;
    pile = ft_syscmd_pile_offset(stack->offset);
    if (pile)
    {
        ft_syscmd(pile->instruction);
        ft_syscmd_pile();
    }
    else
        stack->offset--;
}

static void     ft_pile_free(void)
{
    t_stacks    *stack;
    t_pile      *pile;
    t_pile      *next;

    stack = ft_stack_init();
    pile = stack->pile;
    while (pile)
    {
        next = pile->next;
        ft_strdel(&(pile->instruction));
        ft_memdel((void**)&pile);
        pile = next;
    }
    stack->offset = 0;
    stack->pile = NULL;
}

void        ft_syscmd_addinstruction(char *str)
{
    char    **tab;
    char    *tmp;
    int     index;

    if (ft_strcchr(str, ";") != 0)
    {
        tab = ft_strsplit(str, ';');
        index = -1;
        while (tab[++index])
        {
            tmp = ft_strcleanfront(tab[index], ' ');
            ft_strdoublon(&tmp, ';');
            ft_syscmd_newinstruction(tmp);
            ft_strdel(&tmp);
        }
        ft_tabstrdel(&tab);
    }
    else
        ft_syscmd_newinstruction(tmp);
    ft_syscmd_pile();
    ft_pile_free();
}
