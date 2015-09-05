/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 11:25:33 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/05 22:02:12 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "includes/libft.h"

int         printf_type(char *format, t_list *list, va_list *ap, int count)
{
    int     index;

    if (!(format && format[0] == '%'))
        return (1);
    index = 0;
    while (format[++index])
        if (format[index] == 'd')
        {
            ft_listadd(list, ft_itoa(va_arg(ap, int)));
            return (1);
        }
        else if (format[index] == 's')
        {
            ft_listadd(list, va_arg(ap, char*));
            return (1);
        }
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
    int     coco;

    coucou = ft_strdup("NK");
    coco = 42;
    str = ft_printf("%scoucou%d", coucou, coco);
    ft_putendl(str);
    ft_strdel(&str);
    return (0);
}
