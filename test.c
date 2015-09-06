/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 11:25:33 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/06 03:08:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "includes/libft.h"

int         printf_add(t_list *list, int ret, char *add)
{
    ft_listadd(list, (void*)add);
    return (ret);
}

int         printf_type(char *format, t_list *list, va_list *ap, int count)
{
    int     index;

    if (!(format && format[0] == '%'))
        return (1);
    index = 0;
    while (format[++index])
        if (format[index] == 'd')
            return (printf_add(list, 1, ft_itoa(va_arg(ap, int))));
        else if (format[index] == 's')
            return (printf_add(list, 1, ft_strdup(va_arg(ap, char *))));
    return (0);
}

char        *ft_printf(char const *format, ...)
{
    va_list ap;
    t_list  *list;
    char    *str;
    int     ret;
    int     count;

    count = 0;
    list = ft_listcreate();
    va_start(ap, format);
    while (*format != 0)
    {
        ret = 1;
        if (*format == '%')
            ret += printf_type((char*)format, list, &ap, ++count);
        else
            ft_listadd(list, ft_ctos(*format));
        while (ret--)
            *format++;
    }
    str = ft_listtostr(list);
    ft_listdel(list, ft_memdel);
    va_end(ap);
    return (str);
}

int         main(void)
{
    char    *str;
    char    *coucou;
    char    *coucou2;
    char    *format;
    int     coco;

    coucou = ft_strdup("NK");
    coucou2 = ft_strdup("-N-K-");
    format = ft_strdup("%scoucou%d%s");
    coco = 42;
    //str = ft_printf("coucou%d", coco);
    str = ft_printf(format, coucou, coco, coucou2);
    ft_putendl(str);
    printf(format, coucou, coco, coucou2);
    ft_strdel(&str);
    ft_strdel(&coucou);
    ft_strdel(&coucou2);
    ft_strdel(&format);
    return (0);
}
