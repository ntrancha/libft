/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 11:37:39 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/17 11:40:55 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mem.h"
#include "../../includes/count.h"
#include "../../includes/convert.h"
#include "../../includes/strings.h"
#include "../../includes/put.h"

static void         ft_putmem_char(char **str, int count)
{
    while (count % 16 != 0)
    {
        if (count % 2 == 0)
            ft_putstr("   ");
        else
            ft_putstr("  ");
        count++;
    }
    ft_putstr(*str);
    ft_putendl("");
    ft_strdel(str);
    *str = ft_strdup("");
}

static void         ft_putmem_put(char *hexa, int count, char **carac)
{
    if (hexa[1] == '\0')
        ft_putchar('0');
    ft_putstr(hexa);
    if (count % 2 == 0)
        ft_putchar(' ');
    if (ft_isprint(ft_hextodec(hexa)))
        ft_straddchar(carac, (char)ft_hextodec(hexa));
    else
        ft_straddchar(carac, '.');
}

void                ft_putmem(void *mem, int len)
{
    unsigned char   *var;
    char            *hexa;
    char            *carac;
    int             count;

    var = (unsigned char *)mem;
    count = 0;
    carac = ft_strdup("");
    while (count < len)
    {
        hexa = ft_dectohex((int)var[count++]);
        ft_putmem_put(hexa, count, &carac);
        ft_strdel(&hexa);
        if (count % 16 == 0)
            ft_putmem_char(&carac, count);
    }
    if (carac[0] != '\0')
        ft_putmem_char(&carac, count);
    ft_strdel(&carac);
}

