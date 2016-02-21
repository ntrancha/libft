/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/21 14:00:19 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void        testons(char *str)
{
    int     index;

    index = -1;
    while (str[++index])
        if (str[index] != 42)
            ft_putnbr_endl(str[index]);
        else
            ft_putendl("");
    ft_putendl(str);
}

char            *ft_alloc_convertion(char *src, char *dst, int deep)
{
    t_stacks    *stack;
    t_cnvrt     *conv;
    int         max;
    char        *tmp;
    char        *ret;

    stack = ft_stack_init();
    conv = stack->convert;
    max = 10;
    ret = NULL;
    while (conv && deep < 4)
    {
        if (ft_strcmp(conv->src, src) == 0)
        {
            if (ft_strcmp(conv->dst, dst) == 0)
            {
                ft_strdel(&ret);
                ret = ft_strdup(conv->src);
                ft_straddcharf(&ret, (char)deep);
                return (ret);
            }
            else
            {
                if ((tmp = ft_alloc_convertion(conv->dst, dst, deep + 1)))
                {
                    if (deep == 0)
                        ft_strdupdel(tmp, &ret);
                    if (tmp[0] < max)
                    {
                        ret = ft_strdupdel(&tmp[1], &ret);
                        max = tmp[0];
                    }
                    ft_memdel((void**)&tmp);
                }
            }
        }
        conv = conv->next;
    }
    return (ret);
}

int             ft_alloc_convert_test(char *src, char *dst)
{
    t_stacks    *stack;
    t_cnvrt     *conv;
    
    if ((stack = ft_stack_init()) && stack->convert)
    {
        conv = stack->convert;
        while (conv)
        {
            if (ft_strcmp(src, conv->src) == 0 && ft_strcmp(conv->dst, dst) == 0)
                return (1);
            conv = conv->next;
        }
    }
    return (0);
}

void            ft_alloc_convert_do(char **tab, char *src)
{
    int         index;

    index = 0;
    while (tab[index])
        index++;
    while (--index > 0)
        ft_alloc_cnvrt(src, tab[index - 1]);
}

void            ft_alloc_convert_find(char *src, char *dst, char *alloc)
{
    char        *tmp;
    char        *tmp2;
    char        **tab;
    int         index;

    index = 0;
    tab = ft_memalloc(sizeof(char*) * 10);
    tab[index++] = ft_strdup(dst);
    if (tmp = ft_alloc_convertion(src, dst, 0))
        tab[index++] = ft_strdup(tmp);
    while (tmp)
    {
        if ((tmp2 = ft_alloc_convertion(src, tmp, 0)) && ft_strlen(tmp2) > 0)
        {
            tmp = ft_strdupdel(tmp2, &tmp);
            ft_strdel(&tmp2);
            tab[index++] = ft_strdup(tmp);
        }
        else
            ft_strdelt(&tmp, &tmp2);
    }
    ft_strdel(&tmp);
    tab[index] = ft_strdup(src);
    ft_alloc_convert_do(tab, alloc);
    ft_tabstrdel(&tab);
}

char            *ft_alloc_convert(char *src, char *type_dst)
{
    t_stacks    *stack;
    t_cnvrt     *conv;
    t_alloc     *alloc;
    char        *src_type;
    
    if (!src || !type_dst)
        return (NULL);
    if (!(stack = ft_stack_init()) || !stack->convert)
        return (NULL);
    conv = stack->convert;
    if (!(alloc = ft_alloc_get(src)) || !alloc->type)
        return (NULL);
    src_type = alloc->type;
    if (ft_alloc_convert_test(src_type, type_dst))
        ft_alloc_cnvrt(src, type_dst);
    else
        ft_alloc_convert_find(src_type, type_dst, src);
    return (NULL);
}

int         ft_main(void)
{
    size_t  (*ptr)(const char *);
    size_t  (*ptr2)(int);
    int     num;

    DBG_FILE;
    DBG_PROG;

    num = 0;
    /*ft_putendl(ft_alloc_convert("ft_opt", "int"));*/
    ft_alloc_convert("OPTIONS", "liststr");
    ptr = &ft_strlen;
    ft_calloc(ptr, 8, "DUMP1", "mem");
    ptr2 = &ft_nbrlen;
    ft_calloc(ptr2, 8, "DUMP2", "mem");
    ft_alloc_fusion("DUMP1", "DUMP2", "DUMP1 + DUMP2");
    ft_stack_infos();
    /*testons("*æ*‰*€*ß*α*⠇*ฆ*☮*♒*♣*⌦*⌥*━*␥*▓*♫*♂");*/
    /*testons("*æ*‰*€*ß*α*⠇*ฆ");*/
    /*ft_putnbr_endl(ft_strlen("*æ*‰*€*ß*α*⠇*ฆ"));*/
    /*ft_putnbr_endl(ft_wstrlen("*æ*‰*€*ß*α*⠇*ฆ"));*/
    return 1;
}

FT_MAIN
