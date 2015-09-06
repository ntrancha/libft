/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 11:25:33 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/06 04:18:10 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../../includes/list.h"
#include "../../includes/strings.h"
#include "../../includes/convert.h"
#include "../../includes/mem.h"

static int  strf_add(t_list *list, int ret, char *add)
{
    ft_listadd(list, (void*)add);
    return (ret);
}

static int  strf_float(t_list *list, int ret, double n)
{
    int     index;
    
    if (n < 0)
    {
        ft_listadd(list, (void*)ft_ctos('-'));
        n *= (double)-1.0; 
    }
    ft_listadd(list, (void*)ft_itoa((int)n));
    ft_listadd(list, (void*)ft_ctos('.'));
    n -= (int)n;
    index = 0;
    while (index++ < 6)
        n *= (double)10.0;
    ft_listadd(list, (void*)ft_itoa((int)n));
    return (ret);
}


static int  strf_type(char *format, t_list *list, va_list *ap)
{
    if (!(format && format[0] == '%'))
        return (1);
    if (format[1] == 'd' || format[1] == 'i')
        return (strf_add(list, 1, ft_itoa(va_arg(ap, int))));
    else if (format[1] == 's')
        return (strf_add(list, 1, ft_strdup(va_arg(ap, char *))));
    else if (format[1] == 'c')
        return (strf_add(list, 1, ft_ctos((char)va_arg(ap, int))));
    else if (format[1] == 'f')
        return (strf_float(list, 1, (double)va_arg(ap, double)));
    return (0);
}

char        *ft_strf(char const *format, ...)
{
    va_list ap;
    t_list  *list;
    char    *str;
    int     index;

    list = ft_listcreate();
    va_start(ap, format);
    index = -1;
    while (format[++index])
    {
        if (format[index] == '%')
            index += strf_type((char*)format, list, &ap);
        else
            ft_listadd(list, ft_ctos(format[index]));
    }
    str = ft_listtostr(list);
    ft_listdel(list, ft_memdel);
    va_end(ap);
    return (str);
}
